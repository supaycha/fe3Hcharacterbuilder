#include <AvailablePanel/SkillLevelPanel/ListBoxASLA.h>

ListBoxASLA::ListBoxASLA(std::map<wxString, wxClientData*> uskilllevelabilitymap, std::map<wxString, wxClientData*> uclassmasteryabilitymap,  wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxPoint(x, y), wxSize(x2, y2), choices, style)
{
	skilllevelabilitymap = uskilllevelabilitymap;
	classmasteryabilitymap = uclassmasteryabilitymap;
	//SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void ListBoxASLA::OnSelection(wxCommandEvent& event) {
	//selectedabilities = UpdateSelectionsFromInternalSelection();
	//selectedabilities = AccountforProwessRedudancies(selectedabilities);
	//AbilitySelections* selections = new AbilitySelections(selectedabilities);
	//wxClientData* trueselections = dynamic_cast<wxClientData*>(selections);
	//wxCommandEvent transmission(TRANSMIT_LBASLA_SELECTION, (int)ID_SINGLE_CONTROL::ID_LBASLA);
	//transmission.SetClientObject(trueselections);
	//ProcessEvent(transmission);

	FactorInInternalChange();
}

void ListBoxASLA::ReceiveSLInfo(SKILLLEVELPACKAGE* slpackage) {
	SLfilter[slpackage->index] = slpackage->sl;
	FactorInExternalChange();
}

void ListBoxASLA::ReceiveforAbilityExclusivityCheck(wxString charactername) {
	currentDDCHselection = charactername;
	FactorInExternalChange();
}

void ListBoxASLA::ReceiveClassMasteryExclusivity(wxString classmasterycheck) {
	currentDDCLselection = classmasterycheck;
	FactorInExternalChange();
}

void ListBoxASLA::ReceiveClassMasteryButtonStatus(bool isPressed) {
	isClassMasteryToggleButtonPressed = isPressed;
	FactorInExternalChange();
}

void ListBoxASLA::FactorInInternalChange() {
	previouslyselectedabilities = GetToBeErasedSelectedAbilities();
	if (CheckForClearSignal()) {
		stillpresentabilities = ClearSelections();
	}

	else {
		stillpresentabilities = AccountforProwessRedudancies(previouslyselectedabilities);	
	}
	
	recalculate();
}

bool ListBoxASLA::CheckForClearSignal() {
	for (auto selection : previouslyselectedabilities) {
		if (selection == "---") {
			return true;
		}
	}

	return false;
}

std::vector<wxString> ListBoxASLA::ClearSelections() {
	wxArrayInt selections;
	this->GetSelections(selections);
	for (auto& selection : selections) {
		switch (selection) {
			case 0: {
				continue;
			}

			default: {
				this->Deselect(selection);
				break;
			}
		}
	}
	
	std::vector<wxString> tempemptyvector{ "---" };
	return tempemptyvector;
}

std::vector<wxString> ListBoxASLA::AccountforProwessRedudancies(std::vector<wxString> previouslyselectedabilities) {
	std::map<PROWESSTYPE, wxString> tempmap;
	std::vector<wxString> stillpresentabilities;
	for (auto selectionname : previouslyselectedabilities) {
		for (auto ability : skilllevelabilitymap) {
			if (selectionname == ability.first) {
				if (SkillLevelGeneralProwessAbility* temp = dynamic_cast<SkillLevelGeneralProwessAbility*>(ability.second)) {
					PROWESSTYPE tempabilityprowesstype = temp->getProwessType();
					auto success = tempmap.insert(std::make_pair(tempabilityprowesstype, ability.first));
					if (!success.second) {
						std::wstring currentprowess = tempmap[tempabilityprowesstype];
						wchar_t currentfinalchar = currentprowess.back();

						std::wstring newprowess = ability.first;
						wchar_t newfinalchar = newprowess.back();

						if (newfinalchar > currentfinalchar) {
							tempmap.insert_or_assign(tempabilityprowesstype, ability.first);
						}
					}
				}

				else {
					stillpresentabilities.push_back(selectionname);
				}
			}
		}
	}

	for (auto element : tempmap) {
		stillpresentabilities.push_back(element.second);
	}

	return stillpresentabilities;
}

void ListBoxASLA::FactorInExternalChange() {
	allavailableabilities = CreateListOfAvailableAbilities();
	previouslyselectedabilities = GetToBeErasedSelectedAbilities();
	stillpresentabilities = GetStillPresentAbilities(allavailableabilities, previouslyselectedabilities);		
	recalculate();
}

void ListBoxASLA::recalculate() {
	
	Freeze();
	repopulate();
	Thaw();	
	
	ReselectAbilities(stillpresentabilities);	
	
	AbilitySelections* selections = new AbilitySelections(stillpresentabilities);
	wxClientData* trueselections = dynamic_cast<wxClientData*>(selections);
	wxCommandEvent transmission(TRANSMIT_LBASLA_SELECTION, (int)ID_SINGLE_CONTROL::ID_LBASLA);
	transmission.SetClientObject(trueselections);
	ProcessEvent(transmission);
}

std::vector<wxString> ListBoxASLA::CreateListOfAvailableAbilities() {
	std::vector<wxString> abilitynames;
	std::map<PROWESSTYPE, wxString> maptocrosscheckprowessabilities;

	for (auto element : skilllevelabilitymap) {
		SkillLevelAbility* tempsla = dynamic_cast<SkillLevelAbility*>(element.second);
		if ((int)tempsla->getSkillType() == -1) {
			abilitynames.push_back(tempsla->getName());
		}

		else if (SkillLevelGeneralAbility* tempgeneralability = dynamic_cast<SkillLevelGeneralAbility*>(element.second)) {
			int skilltypenum = (int)tempgeneralability->getSkillType();
			SL controlsl = SLfilter[skilltypenum];
			SL abilitysl = tempgeneralability->getSL();
			if (abilitysl <= controlsl) {
				if (SkillLevelGeneralProwessAbility* temp = dynamic_cast<SkillLevelGeneralProwessAbility*>(element.second)) {
					PROWESSTYPE tempabilityprowesstype = temp->getProwessType();
					auto success = maptocrosscheckprowessabilities.insert(std::make_pair(tempabilityprowesstype, element.first));
					if (!success.second) {
						std::wstring currentprowess = maptocrosscheckprowessabilities[tempabilityprowesstype];
						wchar_t currentfinalchar = currentprowess.back();

						std::wstring newprowess = element.first;
						wchar_t newfinalchar = newprowess.back();

						if (newfinalchar > currentfinalchar) {
							maptocrosscheckprowessabilities.insert_or_assign(tempabilityprowesstype, element.first);
						}
					}
				}
				else {
					abilitynames.push_back(tempgeneralability->getName());
				}
			}
		}

		else if (SkillLevelCharacterAbility* tempcharacterability = dynamic_cast<SkillLevelCharacterAbility*>(element.second)) {
			for (auto holderofability : tempcharacterability->getCharSL()) {
				if (holderofability.charactername == currentDDCHselection) {
					if (holderofability.sl <= SLfilter[(int)tempcharacterability->getSkillType()]) {
						abilitynames.push_back(tempcharacterability->getName());
					}
				}
			}
		}
	}

	for (auto element : maptocrosscheckprowessabilities) {
		abilitynames.push_back(element.second);
	}

	if (isClassMasteryToggleButtonPressed) {
		for (auto element : classmasteryabilitymap) {
			ClassMasteryAbility* tempclassability = dynamic_cast<ClassMasteryAbility*>(element.second);
			std::wstring abilityns = tempclassability->getSource(), buffer;
			std::wstringstream stream(abilityns);
			std::vector<std::wstring> namesfromstream;

			while (std::getline(stream, buffer, L',')) {
				namesfromstream.push_back(buffer);
			}

			for (auto possiblematch : namesfromstream) {
				if (possiblematch == currentDDCLselection) {
					abilitynames.push_back(tempclassability->getName());
				}
			}
		}
	}

	return abilitynames;
}

std::vector<wxString> ListBoxASLA::GetToBeErasedSelectedAbilities() {
	wxArrayInt selections;
	std::vector<wxString> tempvector;
	this->GetSelections(selections);

	for (auto selection : selections) {
		tempvector.push_back(this->GetString(selection));
	}

	return tempvector;
}

void ListBoxASLA::repopulate() {
	this->Set(ToArrayString(allavailableabilities));	
}

std::vector<wxString> ListBoxASLA::GetStillPresentAbilities(std::vector<wxString> allavailableabilities, std::vector<wxString> previouslyselectedabilities) {
	std::vector<wxString> stillpresentabilities;
	for (auto availableselection : allavailableabilities) {
		for (auto previousselection : previouslyselectedabilities) {
			if (previousselection == availableselection) {
				stillpresentabilities.push_back(availableselection);
				break;
			}
		}
	}

	return stillpresentabilities;
}

void ListBoxASLA::ReselectAbilities(std::vector<wxString> stillpresentabilities) {
	for (auto selection : stillpresentabilities) {
		int index = this->FindString(selection);
		if (!(this->IsSelected(index))) {
			this->SetSelection(index);
		}
	}
}

//std::vector<wxString> ListBoxASLA::UpdateSelectionsFromInternalSelection() {
//	wxArrayInt selections;	
//	this->GetSelections(selections);
//
//	bool isClearBeingSignaled = CheckForClearSignal(selections);	
//	std::vector<wxString> tempvector;
//	switch (isClearBeingSignaled) {
//		case 0: {	
//			tempvector = UpdateSelectionsFromExternalSelection();
//			return tempvector;
//			break;
//		}
//
//		default: {
//			tempvector = ClearSelections();
//			return tempvector;
//			break;
//		}
//	}
//
//	for (auto selection : selections) {
//		tempvector.push_back(this->GetString(selection));
//	}
//
//
//	return tempvector;
//}

wxArrayString ListBoxASLA::ToArrayString(std::vector<wxString> names) {
	wxArrayString temparraystring;
	for (auto name : names) {
		temparraystring.Add(name);
	}

	return temparraystring;
}

wxBEGIN_EVENT_TABLE(ListBoxASLA, wxListBox)
	EVT_LISTBOX((int)ID_SINGLE_CONTROL::ID_LBASLA, ListBoxASLA::OnSelection)
wxEND_EVENT_TABLE()
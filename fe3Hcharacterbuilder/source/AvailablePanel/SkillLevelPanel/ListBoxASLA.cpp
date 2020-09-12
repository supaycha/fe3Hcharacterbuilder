#include <AvailablePanel/SkillLevelPanel/ListBoxASLA.h>

ListBoxASLA::ListBoxASLA(std::map<wxString, wxClientData*> uskilllevelabilitymap, std::map<wxString, wxClientData*> uclassmasteryabilitymap,  wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxPoint(x, y), wxSize(x2, y2), choices, style)
{
	skilllevelabilitymap = uskilllevelabilitymap;
	classmasteryabilitymap = uclassmasteryabilitymap;
	//SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void ListBoxASLA::OnSelection(wxCommandEvent& event) {
	selectedAAnames = UpdateSelections();
	AbilitySelections* selections = new AbilitySelections(selectedAAnames);
	wxClientData* trueselections = dynamic_cast<wxClientData*>(selections);
	wxCommandEvent transmission(TRANSMIT_LBASLA_SELECTION, (int)ID_SINGLE_CONTROL::ID_LBASLA);
	transmission.SetClientObject(trueselections);
	ProcessEvent(transmission);

	int i = 9;
}

std::vector<wxString> ListBoxASLA::UpdateSelections() {
	wxArrayInt selections;
	std::vector<wxString> tempvector;
	this->GetSelections(selections);

	for (auto selection : selections) {
		tempvector.push_back(this->GetString(selection));
	}

	return tempvector;
}

void ListBoxASLA::ReceiveSLInfo(SKILLLEVELPACKAGE* slpackage) {
	SLfilter[slpackage->index] = slpackage->sl;
	FilterAbilities();
}

void ListBoxASLA::ReceiveforAbilityExclusivityCheck(wxString charactername) {
	currentDDCHselection = charactername;
	FilterAbilities();
}
void ListBoxASLA::ReceiveClassMasteryExclusivity(wxString classmasterycheck) {
	currentDDCLselection = classmasterycheck;
	FilterAbilities();
}
void ListBoxASLA::ReceiveClassMasteryButtonStatus(bool isPressed) {
	isClassMasteryToggleButtonPressed = isPressed;
	FilterAbilities();
}

void ListBoxASLA::FilterAbilities() {
	//std::vector<wxString> generalabilitynames;
	//std::vector<wxString> characterabilitynames;

	//std::vector<SkillLevelAbility*> skilllevelabilities;
	std::vector<wxString> abilitynames;

	for (auto element : skilllevelabilitymap) {
		SkillLevelAbility* test = dynamic_cast<SkillLevelAbility*>(element.second);
		if ((int)test->getSkillType() == -1) {
			abilitynames.push_back(test->getName());
		}

		else if (SkillLevelGeneralAbility* tempgeneralability = dynamic_cast<SkillLevelGeneralAbility*>(test)) {
			int skilltypenum = (int)tempgeneralability->getSkillType();
			SL controlsl = SLfilter[skilltypenum];
			SL abilitysl = tempgeneralability->getSL();
			if (abilitysl <= controlsl) {
				abilitynames.push_back(tempgeneralability->getName());
			}
		}

		else if (SkillLevelCharacterAbility* tempcharacterability = dynamic_cast<SkillLevelCharacterAbility*>(test)) {
			for (auto holderofability : tempcharacterability->getCharSL()) {
				if (holderofability.charactername == currentDDCHselection) {
					if (holderofability.sl <= SLfilter[(int)tempcharacterability->getSkillType()]) {
						abilitynames.push_back(tempcharacterability->getName());
					}
				}
			}
		}
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
	


	//for (auto ability : skilllevelabilities) {
	//	SL abilitySL = ability->getSL();
	//	if ((int)ability->getSkillType() == -1) {
	//		abilitynames.push_back(ability->getName());
	//		continue;
	//	}

	//	else if (abilitySL <= SLfilter[(int)ability->getSkillType()]) {
	//		abilitynames.push_back(ability->getName());
	//	}
	//}

	ReceiveAbilityFiltration(abilitynames);
}

void ListBoxASLA::ReceiveAbilityFiltration(std::vector<wxString> dirtynames) {
	filteredAAnames = dirtynames;

	std::vector<wxString> tempselected;

	for (auto newname : dirtynames) {
		for (auto oldname : selectedAAnames) {
			if (newname == oldname) {
				tempselected.push_back(newname);
				break;
			}
		}
	}
	selectedAAnames = tempselected;

	Freeze();
	repopulate();
	Thaw();

	selectedAAnames = UpdateSelections();
	AbilitySelections* selections = new AbilitySelections(selectedAAnames);
	wxClientData* trueselections = dynamic_cast<wxClientData*>(selections);
	wxCommandEvent transmission(TRANSMIT_LBASLA_SELECTION, (int)ID_SINGLE_CONTROL::ID_LBASLA);
	transmission.SetClientObject(trueselections);
	ProcessEvent(transmission);
}

void ListBoxASLA::repopulate() {
	this->Set(ToArrayString(filteredAAnames));

	reselection();
}

void ListBoxASLA::reselection() {
	for (auto selection : selectedAAnames) {
		int index = this->FindString(selection);
		if (!(this->IsSelected(index))) {
			this->SetSelection(index);
		}
	}
}

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
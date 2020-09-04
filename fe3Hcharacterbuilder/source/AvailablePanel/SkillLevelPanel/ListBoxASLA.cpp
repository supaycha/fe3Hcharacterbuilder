#include <AvailablePanel/SkillLevelPanel/ListBoxASLA.h>

ListBoxASLA::ListBoxASLA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxPoint(x, y), wxSize(x2, y2), choices, style)
{
	std::vector<wxString> abilitynames;
	std::vector<wxClientData*> abilitydata;
	AbilityList alist;

	for (unsigned int i = 0; i < alist.getSize(); ++i) {
		abilitynames.push_back(alist[i]->getName());
		abilitydata.push_back(alist[i]->clone());
	}

	for (unsigned int i = 0; i < alist.getSize(); ++i) {
		abilitymap.emplace(abilitynames[i], abilitydata[i]);
	}

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

void ListBoxASLA::ReceiveSLInfo(SLPACKAGE* slpackage) {
	SLfilter[slpackage->index] = slpackage->sl;
	FilterAbilities();
}

void ListBoxASLA::FilterAbilities() {
	std::vector<SkillLevelAbility*> skilllevelabilities;
	std::vector<wxString> abilitynames;

	for (auto element : abilitymap) {
		Ability* tempability = dynamic_cast<Ability*>(element.second)->clone();
		if (SkillLevelAbility* tempsla = dynamic_cast<SkillLevelAbility*>(tempability)) {
			skilllevelabilities.push_back(tempsla);
		}
	}

	for (auto ability : skilllevelabilities) {
		SL abilitySL = ability->getSL();

		if (abilitySL <= SLfilter[(int)ability->getWeaponType()]) {
			abilitynames.push_back(ability->getName());
		}
	}

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
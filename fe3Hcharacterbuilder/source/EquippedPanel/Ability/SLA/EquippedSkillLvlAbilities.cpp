#include <EquippedPanel/Ability/SLA/EquippedSkillLvlAbilities.h>

EquippedSkillLvlAbilities::EquippedSkillLvlAbilities(std::map<wxString, wxClientData*> skilllevelabilities, wxWindow* parent, wxWindowID id, const wxString& label) :
	wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize)
{

}

void EquippedSkillLvlAbilities::ReceiveSkillLevelAbility(wxString slname) {
	if (slname.empty()) {
		currentLBASLAselection == "---";
	}

	else {
		currentLBASLAselection = slname;
	}

	repopulate();
}

void EquippedSkillLvlAbilities::repopulate() {
	this->SetLabelText(currentLBASLAselection);
}
//void EquippedSkillLvlAbilities::OnSelection(wxCommandEvent& event) {
//	selectedSAnames = UpdateSelections();
//}
//
//std::vector<wxString> EquippedSkillLvlAbilities::UpdateSelections() {
//	wxArrayInt selections;
//	std::vector<wxString> tempvector;
//	this->GetSelections(selections);
//
//	for (auto selection : selections) {
//		tempvector.push_back(this->GetString(selection));
//	}
//
//	return tempvector;
//}
//
//void EquippedSkillLvlAbilities::ReceiveAbilityFiltration(std::vector<wxString> dirtynames) {
//	std::vector<wxString> tempfiltered;
//	std::vector<wxString> tempselected;
//
//	for (auto newname : dirtynames) {
//		for (auto oldname : filteredSAnames) {
//			if (newname == oldname) {
//				tempfiltered.push_back(newname);
//				break;
//			}
//		}
//	}
//
//	for (auto newname : tempfiltered) {
//		for (auto oldname : selectedSAnames) {
//			if (newname == oldname) {
//				tempselected.push_back(newname);
//				break;
//			}
//		}
//	}
//
//	filteredSAnames = tempfiltered;
//	selectedSAnames = tempselected;
//
//	Freeze();
//	repopulate();
//	Thaw();
//}
//
//void EquippedSkillLvlAbilities::ReceiveSelectionsfromBounceR(std::vector<wxString> uSelections) {
//	filteredSAnames = uSelections;
//	Freeze();
//	repopulate();
//	Thaw();
//}
//
//void EquippedSkillLvlAbilities::repopulate() {
//	this->Set(ToArrayString(filteredSAnames));
//
//	reselection();
//}
//
//void EquippedSkillLvlAbilities::reselection() {
//	for (auto selection : selectedSAnames) {
//		int index = this->FindString(selection);
//		if (!(this->IsSelected(index))) {
//			this->SetSelection(index);
//		}
//	}
//}
//
//std::vector<wxString> EquippedSkillLvlAbilities::GetSelectionsSAAndClear() {
//	std::vector<wxString> temp;
//
//	for (auto element : selectedSAnames) {
//		std::erase(filteredSAnames, element);
//	}
//
//	temp = selectedSAnames;
//	selectedSAnames.clear();
//	Freeze();
//	repopulate();
//	Thaw();
//	return temp;
//}
//
//wxArrayString EquippedSkillLvlAbilities::ToArrayString(std::vector<wxString> names) {
//	wxArrayString temparraystring;
//	for (auto name : names) {
//		temparraystring.Add(name);
//	}
//
//	return temparraystring;
//}
//
//wxBEGIN_EVENT_TABLE(EquippedSkillLvlAbilities, wxListBox)
//	EVT_LISTBOX((int)ID_SINGLE_CONTROL::ID_LBSSLA, EquippedSkillLvlAbilities::OnSelection)
//wxEND_EVENT_TABLE()
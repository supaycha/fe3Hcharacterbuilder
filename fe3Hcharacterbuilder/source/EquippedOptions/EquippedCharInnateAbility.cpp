#include <EquippedOptions/EquippedCharInnateAbility.h>

EquippedCharInnateAbility::EquippedCharInnateAbility(std::map<wxString, wxClientData*> characterinnateabilities, wxWindow* parent, wxWindowID id) :
	wxTextCtrl(parent, id)
{
	//std::vector<wxString> abilitynames;
	//std::vector<wxClientData*> abilitydata;
	//AbilityList alist;

	//for (unsigned int i = 0; i < alist.getSize(); ++i) {
	//	abilitynames.push_back(alist[i]->getName());
	//	abilitydata.push_back(alist[i]->clone());
	//}

	//for (unsigned int i = 0; i < alist.getSize(); ++i) {
	//	abilitymap.emplace(abilitynames[i], abilitydata[i]);
	//}
}
//void EquippedCharInnateAbility::FilterAbilities() {
//	std::vector<CharacterInnateAbility*> characterinnateabilities;
//
//	for (auto element : abilitymap) {
//		Ability* tempability = dynamic_cast<Ability*>(element.second)->clone();
//		if (CharacterInnateAbility* tempchia = dynamic_cast<CharacterInnateAbility*>(tempability)) {
//			characterinnateabilities.push_back(tempchia);
//		}
//	}
//
//	for (auto ability : characterinnateabilities) {
//		if (ability->getSource() == currentDDCselection) {
//			abilityname = ability->getName();
//		}
//	}
//
//	//ReceiveAbilityFiltration(abilitynames);
//	//Freeze();
//	repopulate();
//	//Thaw();
//
//}

void EquippedCharInnateAbility::ReceiveAbilityName(wxString abilityname) {
	currentchianame = abilityname;

	Freeze();
	repopulate();
	Thaw();
}

void EquippedCharInnateAbility::repopulate() {
	this->SetLabelText(currentchianame);

	//reselection();
}

//void EquippedCharInnateAbility::reselection() {
//	for (auto selection : selectedAAnames) {
//		int index = this->FindString(selection);
//		if (!(this->IsSelected(index))) {
//			this->SetSelection(index);
//		}
//	}
//}
//
//wxArrayString EquippedCharInnateAbility::ToArrayString(std::vector<wxString> names) {
//	wxArrayString temparraystring;
//	for (auto name : names) {
//		temparraystring.Add(name);
//	}
//
//	return temparraystring;
//}
#include <EquippedOptions/EquippedClassInnateAbility.h>

EquippedClassInnateAbility::EquippedClassInnateAbility(std::map<wxString, wxClientData*> classinnateabilities, wxWindow* parent, wxWindowID id) :
	wxTextCtrl(parent, id)
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
}

void EquippedClassInnateAbility::ReceiveClassInnate(wxString classname) {
	currentLBCselection = classname;
	FilterAbilities();
}

void EquippedClassInnateAbility::FilterAbilities() {
	std::vector<ClassInnateAbility*> classinnateabilities;
	std::vector<wxString> abilitynames;

	for (auto element : abilitymap) {
		Ability* tempability = dynamic_cast<Ability*>(element.second)->clone();
		if (ClassInnateAbility* tempclia = dynamic_cast<ClassInnateAbility*>(tempability)) {
			classinnateabilities.push_back(tempclia);
		}
	}

	for (auto ability : classinnateabilities) {
		std::wstring abilityns = ability->getSource(), buffer;
		std::wstringstream stream(abilityns);
		std::vector<std::wstring> namesfromstream;

		while (std::getline(stream, buffer, L',')) {
			namesfromstream.push_back(buffer);
		}

		for (auto possiblematch : namesfromstream) {
			if (possiblematch == currentLBCselection) {
				abilitynames.push_back(ability->getName());
			}
		}
	}

	ReceiveAbilityFiltration(abilitynames);
}

void EquippedClassInnateAbility::ReceiveAbilityFiltration(std::vector<wxString> dirtynames) {
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

	//Freeze();
	repopulate();
	//Thaw();
}

//void EquippedClassInnateAbility::ReceiveSelectionsfromBounceL(std::vector<wxString> uSelections) {
//	for (auto newselect : uSelections) {
//		std::erase(selectedAAnames, newselect);
//	}
//
//	//Freeze();
//	repopulate();
//	//Thaw();
//}

void EquippedClassInnateAbility::repopulate() {
	//this->Set(ToArrayString(filteredAAnames));
	//reselection();
}

//void EquippedClassInnateAbility::reselection() {
//	for (auto selection : selectedAAnames) {
//		int index = this->FindString(selection);
//		if (!(this->IsSelected(index))) {
//			this->SetSelection(index);
//		}
//	}
//}

wxArrayString EquippedClassInnateAbility::ToArrayString(std::vector<wxString> names) {
	wxArrayString temparraystring;
	for (auto name : names) {
		temparraystring.Add(name);
	}

	return temparraystring;
}

//#include <CurrentAbilities/ListBoxCLIA.h>
//
//ListBoxCLIA::ListBoxCLIA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style) :
//	wxListBox(panel, id, wxPoint(x, y), wxSize(x2, y2), choices, style)
//{
//	std::vector<wxString> abilitynames;
//	std::vector<wxClientData*> abilitydata;
//	AbilityList alist;
//
//	for (unsigned int i = 0; i < alist.getSize(); ++i) {
//		abilitynames.push_back(alist[i]->getName());
//		abilitydata.push_back(alist[i]->clone());
//	}
//
//	for (unsigned int i = 0; i < alist.getSize(); ++i) {
//		abilitymap.emplace(abilitynames[i], abilitydata[i]);
//	}
//
//	//SetBackgroundStyle(wxBG_STYLE_PAINT);
//}
//
//void ListBoxCLIA::ReceiveClassInnate(wxString classname) {
//	currentLBCselection = classname;
//	FilterAbilities();
//}
//
//void ListBoxCLIA::FilterAbilities() {
//	//std::vector<CharacterInnateAbility*> characterinnateabilities;
//	std::vector<ClassInnateAbility*> classinnateabilities;
//	//std::vector<SkillLevelAbility*> skilllevelabilities;
//	//std::vector<ClassMasteryAbility*> exclusiveweapons;
//
//	std::vector<wxString> abilitynames;
//
//	for (auto element : abilitymap) {
//		Ability* tempability = dynamic_cast<Ability*>(element.second)->clone();
//		//if (CharacterInnateAbility* tempchia = dynamic_cast<CharacterInnateAbility*>(tempability)) {
//		//	characterinnateabilities.push_back(tempchia);
//		//}
//		if (ClassInnateAbility* tempclia = dynamic_cast<ClassInnateAbility*>(tempability)) {
//			classinnateabilities.push_back(tempclia);
//		}
//		//if (SkillLevelAbility* tempsla = dynamic_cast<SkillLevelAbility*>(tempability)) {
//		//	skilllevelabilities.push_back(tempsla);
//		//}
//	}
//
//	//for (auto ability : characterinnateabilities) {
//	//	if (ability->getSource() == currentDDCselection) {
//	//		abilitynames.push_back(ability->getName());
//	//	}
//	//}
//
//	for (auto ability : classinnateabilities) {
//		std::wstring abilityns = ability->getSource(), buffer;
//		std::wstringstream stream(abilityns);
//		std::vector<std::wstring> namesfromstream;
//
//		while (std::getline(stream, buffer, L',')) {
//			namesfromstream.push_back(buffer);
//		}
//
//		for (auto possiblematch : namesfromstream) {
//			if (possiblematch == currentLBCselection) {
//				abilitynames.push_back(ability->getName());
//			}
//		}
//	}
//
//	//for (auto ability : skilllevelabilities) {
//	//	SL abilitySL = ability->getSL();
//
//	//	if (abilitySL <= SLfilter[(int)ability->getWeaponType()]) {
//	//		abilitynames.push_back(ability->getName());
//	//	}
//	//}
//
//	ReceiveAbilityFiltration(abilitynames);
//	//lbsa->ReceiveAbilityFiltration(abilitynames);
//}
//
//void ListBoxCLIA::ReceiveAbilityFiltration(std::vector<wxString> dirtynames) {
//	filteredAAnames = dirtynames;
//
//	std::vector<wxString> tempselected;
//
//	for (auto newname : dirtynames) {
//		for (auto oldname : selectedAAnames) {
//			if (newname == oldname) {
//				tempselected.push_back(newname);
//				break;
//			}
//		}
//	}
//	selectedAAnames = tempselected;
//
//	Freeze();
//	repopulate();
//	Thaw();
//}
//
//void ListBoxCLIA::ReceiveSelectionsfromBounceL(std::vector<wxString> uSelections) {
//	for (auto newselect : uSelections) {
//		std::erase(selectedAAnames, newselect);
//	}
//
//	Freeze();
//	repopulate();
//	Thaw();
//}
//
//void ListBoxCLIA::repopulate() {
//	this->Set(ToArrayString(filteredAAnames));
//
//	reselection();
//}
//
//void ListBoxCLIA::reselection() {
//	for (auto selection : selectedAAnames) {
//		int index = this->FindString(selection);
//		if (!(this->IsSelected(index))) {
//			this->SetSelection(index);
//		}
//	}
//}
//
//wxArrayString ListBoxCLIA::ToArrayString(std::vector<wxString> names) {
//	wxArrayString temparraystring;
//	for (auto name : names) {
//		temparraystring.Add(name);
//	}
//
//	return temparraystring;
//}

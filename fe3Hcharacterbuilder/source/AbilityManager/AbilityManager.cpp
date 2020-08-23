#include "C:\Users\these\Desktop\fe3Hcharacterbuilder\fe3Hcharacterbuilder\include\AbilityManager"

AbilityManager::AbilityManager(MyFrame* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
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

	const wxArrayString buffer{};

	lbaa = new ListBoxAA(this, (int)ID_SINGLE_CONTROL::ID_LBAA, 0, 0, 150, 400, buffer, wxLB_MULTIPLE);
	lbsa = new ListBoxSA(this, (int)ID_SINGLE_CONTROL::ID_LBSA, 200, 0, 150, 400, buffer, wxLB_MULTIPLE);
	bmr = new ButtonMoveRight(this, (int)ID_SINGLE_CONTROL::ID_BMR, "->", 150, 50, 50, 50);
	bml = new ButtonMoveLeft(this, (int)ID_SINGLE_CONTROL::ID_BML, "<-", 150, 100, 50, 50);

	Bind(SELECTION_HAS_CHANGED, &AbilityManager::BounceSelectionstoRight, this, (int)ID_SINGLE_CONTROL::ID_BMR);
	Bind(SELECTION_HAS_CHANGED, &AbilityManager::BounceSelectionstoLeft, this, (int)ID_SINGLE_CONTROL::ID_BML);
}

void AbilityManager::ReceiveExclusivity(wxString charactername) {
	currentDDCselection = charactername;
	FilterAbilities();
}

void AbilityManager::ReceiveClassInnate(wxString classname) {
	currentLBCselection = classname;
	FilterAbilities();
}

void AbilityManager::ReceiveSLInfo(SLPACKAGE* slpackage) {
	SLfilter[slpackage->index] = slpackage->sl;
	FilterAbilities();
}

void AbilityManager::FilterAbilities() {
	std::vector<CharacterInnateAbility*> characterinnateabilities;
	std::vector<ClassInnateAbility*> classinnateabilities;
	std::vector<SkillLevelAbility*> skilllevelabilities;
	//std::vector<ClassMasteryAbility*> exclusiveweapons;

	std::vector<wxString> abilitynames;

	for (auto element : abilitymap) {
		Ability* tempability = dynamic_cast<Ability*>(element.second)->clone();
		if (CharacterInnateAbility* tempchia = dynamic_cast<CharacterInnateAbility*>(tempability)) {
			characterinnateabilities.push_back(tempchia);
		}
		if (ClassInnateAbility* tempclia = dynamic_cast<ClassInnateAbility*>(tempability)) {
			classinnateabilities.push_back(tempclia);
		}
		if (SkillLevelAbility* tempsla = dynamic_cast<SkillLevelAbility*>(tempability)) {
			skilllevelabilities.push_back(tempsla);
		}
	}

	for (auto ability : characterinnateabilities) {
		if (ability->getSource() == currentDDCselection) {
			abilitynames.push_back(ability->getName());
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

	for (auto ability : skilllevelabilities) {
		SL abilitySL = ability->getSL();

		if (abilitySL <= SLfilter[(int)ability->getWeaponType()]) {
			abilitynames.push_back(ability->getName());
		}
	}

	lbaa->ReceiveAbilityFiltration(abilitynames);
	lbsa->ReceiveAbilityFiltration(abilitynames);
}

void AbilityManager::BounceSelectionstoRight(wxCommandEvent& eventfromOnClick) {
	lbsa->ReceiveSelectionsfromBounceR(lbaa->GetSelectionsAA());
}

void AbilityManager::BounceSelectionstoLeft(wxCommandEvent& eventfromOnClick) {
	lbaa->ReceiveSelectionsfromBounceL(lbsa->GetSelectionsSAAndClear());
}

wxBEGIN_EVENT_TABLE(AbilityManager, wxPanel)
wxEND_EVENT_TABLE()
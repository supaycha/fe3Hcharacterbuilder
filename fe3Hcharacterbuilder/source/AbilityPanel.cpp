#include "AbilityPanel.h"

AbilityPanel::AbilityPanel(std::map<wxString, wxClientData*> abilitymap, wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	FilterAbilitiesAndInitCollPanes(abilitymap);
	panelsizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText* charinnatelabel = new wxStaticText(this, wxID_ANY, "Character Innate Ability");
	wxStaticText* classinnatelabel = new wxStaticText(this, wxID_ANY, "Class Innate Ability");
	wxStaticText* skilllevellabel = new wxStaticText(this, wxID_ANY, "Skill Level Ability");

	panelsizer->Add(charinnatelabel);
	panelsizer->Add(echia);

	panelsizer->Add(classinnatelabel);
	for (int i = 0; i < 3; ++i) {
		panelsizer->Add(ecliaVector[i]);
	}

	panelsizer->Add(skilllevellabel);
	for (int i = 0; i < 5; ++i) {
		panelsizer->Add(eslaVector[i]);
	}

	this->SetSizer(panelsizer);
}

void AbilityPanel::FilterAbilitiesAndInitCollPanes(std::map<wxString, wxClientData*> abilitymap) {
	//std::vector<CharacterInnateAbility*> characterinnateabilities;
	//std::vector<ClassInnateAbility*> classinnateabilities;
	//std::vector<SkillLevelAbility*> skilllevelabilities;
	std::map<wxString, wxClientData*> characterinnateabilities;
	std::map<wxString, wxClientData*> skilllevelabilities;
	//std::vector<ClassMasteryAbility*> exclusiveweapons;

	std::vector<wxString> abilitynames;
	const wxString buffer;

	for (auto element : abilitymap) {
		Ability* tempability = dynamic_cast<Ability*>(element.second)->clone();
		if (CharacterInnateAbility* tempchia = dynamic_cast<CharacterInnateAbility*>(tempability)) {
			characterinnateabilities.insert(element);
		}
		if (ClassInnateAbility* tempclia = dynamic_cast<ClassInnateAbility*>(tempability)) {
			classinnateabilities.insert(element);
		}
		if (SkillLevelAbility* tempsla = dynamic_cast<SkillLevelAbility*>(tempability)) {
			skilllevelabilities.insert(element);
		}
	}

	echia = new EquippedCharInnateAbility(characterinnateabilities, this, (int)ID_SINGLE_CONTROL::ID_ECHIA, buffer);
	for (int i = 0; i < 3; ++i) {
		ecliaVector.push_back(new EquippedClassInnateAbility(classinnateabilities, this, ((int)ID_SINGLE_CONTROL::ID_ECLIA + i), buffer));
	}

	for (int i = 0; i < 5; ++i) {
		eslaVector.push_back(new EquippedSkillLvlAbilities(skilllevelabilities, this, ((int)ID_SINGLE_CONTROL::ID_ESLA + i), buffer));
	}

	//for (auto ability : characterinnateabilities) {
	//	if (ability->getSource() == currentDDCselection) {
	//		abilitynames.push_back(ability->getName());
	//	}
	//}

	//for (auto ability : classinnateabilities) {
	//	std::wstring abilityns = ability->getSource(), buffer;
	//	std::wstringstream stream(abilityns);
	//	std::vector<std::wstring> namesfromstream;

	//	while (std::getline(stream, buffer, L',')) {
	//		namesfromstream.push_back(buffer);
	//	}

	//	for (auto possiblematch : namesfromstream) {
	//		if (possiblematch == currentLBCselection) {
	//			abilitynames.push_back(ability->getName());
	//		}
	//	}
	//}

	//for (auto ability : skilllevelabilities) {
	//	SL abilitySL = ability->getSL();

	//	if (abilitySL <= SLfilter[(int)ability->getWeaponType()]) {
	//		abilitynames.push_back(ability->getName());
	//	}
	//}

	//lbaa->ReceiveAbilityFiltration(abilitynames);
	//lbsa->ReceiveAbilityFiltration(abilitynames);
}

void AbilityPanel::ReceiveCharacterInnateExclusivity(wxString charactername) {
	echia->ReceiveCharacterInnateExclusivity(charactername);
}

void AbilityPanel::ReceiveClassInnateExclusivity(wxString classname) {
	currentLBCselection = classname;
	this->CreateCLIAList();
}

void AbilityPanel::CreateCLIAList() {
	std::wstring abilityname;
	abilitynames.clear();
	for (auto element : classinnateabilities) {
		ClassInnateAbility* tempability = dynamic_cast<ClassInnateAbility*>(element.second)->clone();
		std::wstring abilityns = tempability->getSource(), buffer;
		std::wstringstream stream(abilityns);
		std::vector<std::wstring> namesfromstream;
	
		while (std::getline(stream, buffer, L',')) {
			namesfromstream.push_back(buffer);
		}
	
		for (auto possiblematch : namesfromstream) {
			if (possiblematch == currentLBCselection) {
				abilitynames.push_back(tempability->getName());
			}
		}
	}

	while (abilitynames.size() < 3) {
		abilitynames.push_back("---");
	}

	PopulateECLIAVector();
}

void AbilityPanel::PopulateECLIAVector() {
	if (!abilitynames.empty()) {
		for (unsigned i = 0; i < abilitynames.size(); ++i){
			ecliaVector[i]->ReceiveClassInnateAbility(abilitynames[i]);
		}
	}
}

wxBEGIN_EVENT_TABLE(AbilityPanel, wxPanel)
	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPCHIA, AbilityPanel::OnCollChange)
	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPCLIA, AbilityPanel::OnCollChange)
	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPSLA, AbilityPanel::OnCollChange)
wxEND_EVENT_TABLE()
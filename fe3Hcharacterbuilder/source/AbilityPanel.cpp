#include "AbilityPanel.h"

AbilityPanel::AbilityPanel(std::map<wxString, wxClientData*> abilitymap, wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	FilterAbilitiesAndInitCollPanes(abilitymap);
	panelsizer = new wxBoxSizer(wxVERTICAL);
	panelsizer->Add(cpchia);
	panelsizer->Add(cpclia);
	panelsizer->Add(cpsla);
	this->SetSizer(panelsizer);
}

void AbilityPanel::FilterAbilitiesAndInitCollPanes(std::map<wxString, wxClientData*> abilitymap) {
	//std::vector<CharacterInnateAbility*> characterinnateabilities;
	//std::vector<ClassInnateAbility*> classinnateabilities;
	//std::vector<SkillLevelAbility*> skilllevelabilities;
	std::map<wxString, wxClientData*> characterinnateabilities;
	std::map<wxString, wxClientData*> classinnateabilities;
	std::map<wxString, wxClientData*> skilllevelabilities;
	//std::vector<ClassMasteryAbility*> exclusiveweapons;

	std::vector<wxString> abilitynames;

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

	cpchia = new CollPaneCharInnateAbility(characterinnateabilities, this, (int)ID_SINGLE_CONTROL::ID_CPCHIA, "Character Innate Ability");
	cpclia = new CollPaneClassInnateAbility(classinnateabilities, this, (int)ID_SINGLE_CONTROL::ID_CPCLIA, "Class Innate Ability");
	cpsla = new CollPaneSkillLevelAbility(skilllevelabilities, this, (int)ID_SINGLE_CONTROL::ID_CPSLA, "Skill Level Ability");

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
	cpchia->ReceiveCharacterInnateExclusivity(charactername);
}

void AbilityPanel::ReceiveClassInnateExclusivity(wxString classname) {
	cpclia->ReceiveClassInnateExclusivity(classname);
}

void AbilityPanel::OnCollChange(wxCollapsiblePaneEvent& event) {
	SendSizeEventToParent();
}

wxBEGIN_EVENT_TABLE(AbilityPanel, wxPanel)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPCHIA, AbilityPanel::OnCollChange)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPCLIA, AbilityPanel::OnCollChange)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPSLA, AbilityPanel::OnCollChange)
wxEND_EVENT_TABLE()
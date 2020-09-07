#include <EquippedPanel/Ability/AbilityPanel.h>


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
	std::map<wxString, wxClientData*> characterinnateabilities;
	std::map<wxString, wxClientData*> skilllevelabilities;

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
	CLIAnames.clear();
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
				CLIAnames.push_back(tempability->getName());
			}
		}
	}

	while (CLIAnames.size() < 3) {
		CLIAnames.push_back("---");
	}

	PopulateECLIAVector();
	wxCommandEvent event(TRANSMIT_CLIA_SELECTION, (int)ID_SINGLE_CONTROL::ID_AP);
	AbilitySelections* testing = new AbilitySelections(CLIAnames);
	wxClientData* testing2 = dynamic_cast<wxClientData*>(testing);
	event.SetClientObject(testing2);
	ProcessEvent(event);
}

void AbilityPanel::PopulateECLIAVector() {
	if (!CLIAnames.empty()) {
		for (unsigned i = 0; i < CLIAnames.size(); ++i){
			ecliaVector[i]->ReceiveClassInnateAbility(CLIAnames[i]);
		}
	}
}

void AbilityPanel::ReceiveSLASelections(AbilitySelections* uselections) {
	SLAnames.clear();
	SLAnames = uselections->GetSelections();
	this->CreateSLAList();
}

void AbilityPanel::CreateSLAList() {
	while (SLAnames.size() < 5) {
		SLAnames.push_back("---");
	}

	PopulateSLAVector();
}

void AbilityPanel::PopulateSLAVector() {
	if (!SLAnames.empty()) {
		for (unsigned i = 0; i < SLAnames.size(); ++i) {
			eslaVector[i]->ReceiveSkillLevelAbility(SLAnames[i]);
		}
	}
}
#include <Stats Panel/CPOptionalStats/CPOptionalStats.h>

CPOptionalStats::CPOptionalStats(std::map<wxString, wxClientData*> uabilitymap, wxWindow* parent, wxWindowID id, const wxString& buffer) :
	wxCollapsiblePane(parent, id, buffer)
{
	abilitymap = uabilitymap;
	mainsizer = new wxBoxSizer(wxVERTICAL);
	wxWindow* mainwindow = this->GetPane();

	std::map<wxString, wxClientData*> characterinnateabilities;
	std::map<wxString, wxClientData*> classinnateabilities;
	std::map<wxString, wxClientData*> skilllevelabilities;

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

	gws = new GridWeaponStats(mainwindow, (int)ID_SINGLE_CONTROL::ID_GWS);
	ges = new GridEquipmentStats(mainwindow, (int)ID_SINGLE_CONTROL::ID_GES);
	gbs = new GridBattalionStats(mainwindow, (int)ID_SINGLE_CONTROL::ID_GBS);
	gchias = new GridCharInnateAbilityStats(characterinnateabilities, mainwindow, (int)ID_SINGLE_CONTROL::ID_GCHIAS);

	for (int i = 0; i < 3; ++i) {
		gcliasVector.push_back(new GridClassInnateAbilityStats(classinnateabilities, mainwindow, ((int)ID_SINGLE_CONTROL::ID_GCLIAS + i)));
	}

	for (int i = 0; i < 5; ++i) {
		gslasVector.push_back(new GridSkillLevelAbilityStats(skilllevelabilities, mainwindow, ((int)ID_SINGLE_CONTROL::ID_GSLAS + i)));
	}

	wxBoxSizer* statssizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* column1 = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* column2 = new wxBoxSizer(wxVERTICAL);

	column1->Add(gws);
	column1->Add(ges);
	column1->Add(gbs);
	column1->Add(gchias);

	for (auto gridclias : gcliasVector) {
		column2->Add(gridclias);
	}

	for (auto gridslas : gslasVector) {
		column2->Add(gridslas);
	}

	statssizer->Add(column1);
	statssizer->Add(column2);
	mainwindow->SetSizer(statssizer);
	statssizer->SetSizeHints(mainwindow);
	this->SetSizer(mainsizer);
}

void CPOptionalStats::ReceiveLBWSelection(Stats stats) {
	gws->ReceiveLBWSelection(stats);
}

void CPOptionalStats::ReceiveLBESelection(Stats stats) {
	ges->ReceiveLBESelection(stats);
}

void CPOptionalStats::ReceiveLBBSelection(Stats stats) {
	gbs->ReceiveLBBSelection(stats);
}

void CPOptionalStats::ReceiveCHIASelection(wxString abilityname) {
	gchias->ReceiveCHIASelection(abilityname);
}

void CPOptionalStats::ReceiveCLIASelection(std::vector<wxString> abilityselections) {
	for (unsigned int i = 0; i < abilityselections.size(); ++i) {
		gcliasVector[i]->ReceiveCLIASelection(abilityselections[i]);
	}
}

void CPOptionalStats::ReceiveSLASelection(std::vector<wxString> abilityselections) {
	for (unsigned int i = 0; i < abilityselections.size(); ++i) {
		gslasVector[i]->ReceiveSLASelection(abilityselections[i]);
	}
}
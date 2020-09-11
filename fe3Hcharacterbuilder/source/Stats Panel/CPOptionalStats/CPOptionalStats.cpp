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
	wxStaticText* weaponstatslabel = new wxStaticText(mainwindow, wxID_ANY, "Weapon Stats");
	wxStaticText* equipmentstatslabel = new wxStaticText(mainwindow, wxID_ANY, "Equipment Stats");
	wxStaticText* battalionstatslabel = new wxStaticText(mainwindow, wxID_ANY, "Battalion Stats");
	wxStaticText* gambitstatslabel = new wxStaticText(mainwindow, wxID_ANY, "Gambit Stats");
	wxStaticText* characterinnatestatslabel = new wxStaticText(mainwindow, wxID_ANY, "Character Innate Ability Stats");
	wxStaticText* classinnatestatslabel = new wxStaticText(mainwindow, wxID_ANY, "Class Innate Ability Stats");
	wxStaticText* skilllevelabilitystatslabel = new wxStaticText(mainwindow, wxID_ANY, "Skill Level Ability Stats");

	gws = new GridWeaponStats(mainwindow, (int)ID_SINGLE_CONTROL::ID_GWS);
	ges = new GridEquipmentStats(mainwindow, (int)ID_SINGLE_CONTROL::ID_GES);
	gbs = new GridBattalionStats(mainwindow, (int)ID_SINGLE_CONTROL::ID_GBS);
	ggs = new GridGambitStats(mainwindow, (int)ID_SINGLE_CONTROL::ID_GGS);
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

	column1->Add(weaponstatslabel);
	column1->Add(gws);
	column1->Add(equipmentstatslabel);
	column1->Add(ges);
	column1->Add(battalionstatslabel);
	column1->Add(gbs);
	column1->Add(gambitstatslabel);
	column1->Add(ggs);
	column2->Add(characterinnatestatslabel);
	column2->Add(gchias);

	column2->Add(classinnatestatslabel);
	for (auto gridclias : gcliasVector) {
		column2->Add(gridclias);
	}

	column2->Add(skilllevelabilitystatslabel);
	for (auto gridslas : gslasVector) {
		column2->Add(gridslas);
	}
	
	statssizer->Add(column1);
	statssizer->Add(column2);
	mainwindow->SetSizer(statssizer);
	statssizer->SetSizeHints(mainwindow);
	this->SetSizer(mainsizer);
}

void CPOptionalStats::ReceiveLBWSelection(Stats stats, WEAPONTYPE type) {
	gws->ReceiveLBWSelection(stats);
	for (unsigned int i = 0; i < 3; ++i) {
		gslasVector[i]->ReceiveLBWSelection_weapontypeifneeded(type);
		gslasVector[i]->ForceRefresh();
	}
}

void CPOptionalStats::ReceiveLBESelection(Stats stats) {
	ges->ReceiveLBESelection(stats);
}

void CPOptionalStats::ReceiveLBBSelection(Stats battalionstats, Stats gambitstats) {
	gbs->ReceiveLBBSelection(battalionstats);
	ggs->ReceiveLBBSelection(gambitstats);
	
}

void CPOptionalStats::ReceiveCHIASelection(wxString abilityname) {
	gchias->ReceiveCHIASelection(abilityname);
}

void CPOptionalStats::ReceiveCLIASelection(std::vector<wxString> abilityselections) {
	for (unsigned int i = 0; i < abilityselections.size(); ++i) {
		gcliasVector[i]->ReceiveCLIASelection(abilityselections[i]);
		gcliasVector[i]->ForceRefresh();
	}
}

void CPOptionalStats::ReceiveSLASelection(std::vector<wxString> abilityselections) {
	for (unsigned int i = 0; i < abilityselections.size(); ++i) {
		gslasVector[i]->ReceiveSLASelection(abilityselections[i]);
		gslasVector[i]->ForceRefresh();
	}

}
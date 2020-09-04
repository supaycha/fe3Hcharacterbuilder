#include "CPOptionalStats.h"

CPOptionalStats::CPOptionalStats(wxWindow* parent, wxWindowID id, const wxString& buffer) :
	wxCollapsiblePane(parent, id, buffer)
{
	mainsizer = new wxBoxSizer(wxVERTICAL);
	wxWindow* mainwindow = this->GetPane();

	gws = new GridWeaponStats(mainwindow, (int)ID_SINGLE_CONTROL::ID_GWS);
	ges = new GridEquipmentStats(mainwindow, (int)ID_SINGLE_CONTROL::ID_GES);
	gbs = new GridBattalionStats(mainwindow, (int)ID_SINGLE_CONTROL::ID_GBS);
	gchias = new GridCharInnateAbilityStats(mainwindow, (int)ID_SINGLE_CONTROL::ID_GCHIAS);

	for (int i = 0; i < 3; ++i) {
		gcliasVector.push_back(new GridClassInnateAbilityStats(mainwindow, ((int)ID_SINGLE_CONTROL::ID_GCLIAS + i)));
	}

	for (int i = 0; i < 5; ++i) {
		gslasVector.push_back(new GridSkillLevelAbilityStats(mainwindow, ((int)ID_SINGLE_CONTROL::ID_GSLAS + i)));
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
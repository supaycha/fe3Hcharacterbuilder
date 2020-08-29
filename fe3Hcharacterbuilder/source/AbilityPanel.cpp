#include "AbilityPanel.h"

AbilityPanel::AbilityPanel(wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	panelsizer = new wxBoxSizer(wxVERTICAL);
	cpchia = new CollPaneCharInnateAbility(this, (int)ID_SINGLE_CONTROL::ID_CPCHIA, "Character Innate Ability");
	cpclia = new CollPaneClassInnateAbility(this, (int)ID_SINGLE_CONTROL::ID_CPCLIA, "Class Innate Ability");
	cpsla = new CollPaneSkillLevelAbility(this, (int)ID_SINGLE_CONTROL::ID_CPSLA, "Skill Level Ability");
	panelsizer->Add(cpchia);
	panelsizer->Add(cpclia);
	panelsizer->Add(cpsla);
	this->SetSizer(panelsizer);
}

void AbilityPanel::OnCollChange(wxCollapsiblePaneEvent& event) {
	SendSizeEventToParent();
}

wxBEGIN_EVENT_TABLE(AbilityPanel, wxPanel)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPCHIA, AbilityPanel::OnCollChange)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPCLIA, AbilityPanel::OnCollChange)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPSLA, AbilityPanel::OnCollChange)
wxEND_EVENT_TABLE()
#include "EquippedPanel.h"

EquippedPanel::EquippedPanel(std::map<wxString, wxClientData*> abilitymap, wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	panelsizer = new wxBoxSizer(wxVERTICAL);
	cpb = new CollPaneBattalion(this, (int)ID_SINGLE_CONTROL::ID_CPB, "Battalion Stats");
	cpw = new CollPaneWeapon(this, (int)ID_SINGLE_CONTROL::ID_CPW, "Weapon Stats");
	cpe = new CollPaneEquipment(this, (int)ID_SINGLE_CONTROL::ID_CPE, "Equipment Stats");
	ap = new AbilityPanel(abilitymap, this, (int)ID_SINGLE_CONTROL::ID_AP);
	panelsizer->Add(cpb);
	panelsizer->Add(cpw);
	panelsizer->Add(cpe);
	panelsizer->Add(ap);
	this->SetSizer(panelsizer);
}

void EquippedPanel::ReceiveCharacterInnateExclusivity(wxString charactername) {
	ap->ReceiveCharacterInnateExclusivity(charactername);
}

void EquippedPanel::ReceiveClassInnateExclusivity(wxString classname) {
	ap->ReceiveClassInnateExclusivity(classname);
}

void EquippedPanel::ReceiveLBWSelection(Stats stats) {
	cpw->ReceiveLBWSelection(stats);
}

void EquippedPanel::OnSize(wxSizeEvent& event) {
	if (ap) {
		ap->Fit();
		ap->GetParent()->Fit();
	}

	wxSize test = this->GetMinSize();
	event.Skip();
}

void EquippedPanel::OnCollChange(wxCollapsiblePaneEvent& event) {
	SendSizeEventToParent();
}

wxBEGIN_EVENT_TABLE(EquippedPanel, wxPanel)
	EVT_SIZE(EquippedPanel::OnSize)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPB, EquippedPanel::OnCollChange)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPW, EquippedPanel::OnCollChange)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPE, EquippedPanel::OnCollChange)
wxEND_EVENT_TABLE()
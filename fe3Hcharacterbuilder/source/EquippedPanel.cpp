#include "EquippedPanel.h"

EquippedPanel::EquippedPanel(std::map<wxString, wxClientData*> abilitymap, wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	panelsizer = new wxBoxSizer(wxVERTICAL);
	eb = new EquippedBattalion(this, (int)ID_SINGLE_CONTROL::ID_EB);
	ew = new EquippedWeapon(this, (int)ID_SINGLE_CONTROL::ID_EW);
	ee = new EquippedEquipment(this, (int)ID_SINGLE_CONTROL::ID_EE);
	ap = new AbilityPanel(abilitymap, this, (int)ID_SINGLE_CONTROL::ID_AP);
	panelsizer->Add(eb);
	panelsizer->Add(ew);
	panelsizer->Add(ee);
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
	//cpw->ReceiveLBWSelection(stats);
}

void EquippedPanel::ReceiveLBESelection(Stats stats) {
	//cpe->ReceiveLBESelection(stats);
}

void EquippedPanel::ReceiveLBBSelection(Stats stats) {
	//cpb->ReceiveLBBSelection(stats);
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
	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPB, EquippedPanel::OnCollChange)
	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPW, EquippedPanel::OnCollChange)
	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPE, EquippedPanel::OnCollChange)
wxEND_EVENT_TABLE()
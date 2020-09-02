#include "CollPaneWeapon.h"

CollPaneWeapon::CollPaneWeapon(wxWindow* parent, wxWindowID id, const wxString& label) :
	wxCollapsiblePane(parent, id, label, wxDefaultPosition, wxSize(-1, -1))
{
	
	//mainsizer = new wxBoxSizer(wxVERTICAL);
	wxWindow* weaponwindow = this->GetPane();
	gws = new GridWeaponStats(weaponwindow, (int)ID_SINGLE_CONTROL::ID_GWS);

	wxBoxSizer* weaponsizer = new wxBoxSizer(wxVERTICAL);
	weaponsizer->Add(gws, 0, wxEXPAND, 0);

	weaponwindow->SetSizer(weaponsizer);
	weaponsizer->SetSizeHints(weaponwindow);
	//this->SetSizer(mainsizer);
}

void CollPaneWeapon::ReceiveLBWSelection(Stats stats) {
	gws->ReceiveLBWSelection(stats);
}

void CollPaneWeapon::OnCollPaneChange(wxCollapsiblePaneEvent& event) {
	//SendSizeEventToParent();
	//this->GetParent()->Layout();
	event.Skip();
}

wxBEGIN_EVENT_TABLE(CollPaneWeapon, wxCollapsiblePane)
	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPW, CollPaneWeapon::OnCollPaneChange)
wxEND_EVENT_TABLE()
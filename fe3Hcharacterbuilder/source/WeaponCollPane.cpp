#include "WeaponCollPane.h"

WeaponCollPane::WeaponCollPane(wxWindow* parent, wxWindowID id, const wxString& label) :
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

void WeaponCollPane::OnCollPaneChange(wxCollapsiblePaneEvent& event) {
	//SendSizeEventToParent();
	//this->GetParent()->Layout();
	event.Skip();
}

wxBEGIN_EVENT_TABLE(WeaponCollPane, wxCollapsiblePane)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_WCP, WeaponCollPane::OnCollPaneChange)
wxEND_EVENT_TABLE()

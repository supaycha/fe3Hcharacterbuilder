#include "EquippedPanel.h"

EquippedPanel::EquippedPanel(wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	panelsizer = new wxBoxSizer(wxVERTICAL);
	//bcp = new BattalionCollPane(this, (int)ID_SINGLE_CONTROL::ID_BCP, "Battalion Stats");	
	wcp = new WeaponCollPane(this, (int)ID_SINGLE_CONTROL::ID_WCP, "Weapon Stats");
	//panelsizer->Add(bcp);
	panelsizer->Add(wcp);
	this->SetSizer(panelsizer);

	//Layout();
}

void EquippedPanel::OnCollChange(wxCollapsiblePaneEvent& event) {
	SendSizeEventToParent();
}

wxBEGIN_EVENT_TABLE(EquippedPanel, wxPanel)
	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_BCP, MyFrame::OnCollPaneChange)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_WCP, EquippedPanel::OnCollChange)
wxEND_EVENT_TABLE()

#include "BattalionCollPane.h"

BattalionCollPane::BattalionCollPane(wxWindow* parent, wxWindowID id, const wxString& label) :
	wxCollapsiblePane(parent, id, label, wxDefaultPosition, wxSize(-1, -1))
{
	mainsizer = new wxBoxSizer(wxVERTICAL);
	wxWindow* battalionwindow = this->GetPane();
	wxBoxSizer* battalionsizer = new wxBoxSizer(wxVERTICAL);
	gbs = new GridBattalionStats(battalionwindow, (int)ID_SINGLE_CONTROL::ID_GBS);

	this->SetSizer(mainsizer);
}

void BattalionCollPane::OnCollPaneChange(wxCollapsiblePaneEvent& event) {
	
	//this->GetParent()->Layout();
	event.Skip();
}

wxBEGIN_EVENT_TABLE(BattalionCollPane, wxCollapsiblePane)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_BCP, BattalionCollPane::OnCollPaneChange)
wxEND_EVENT_TABLE()

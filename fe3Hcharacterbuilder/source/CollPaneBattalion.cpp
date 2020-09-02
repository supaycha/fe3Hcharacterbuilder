#include "CollPaneBattalion.h"

CollPaneBattalion::CollPaneBattalion(wxWindow* parent, wxWindowID id, const wxString& label) :
	wxCollapsiblePane(parent, id, label, wxDefaultPosition, wxSize(-1, -1))
{
	/*mainsizer = new wxBoxSizer(wxVERTICAL);*/
	wxWindow* battalionwindow = this->GetPane();
	gbs = new GridBattalionStats(battalionwindow, (int)ID_SINGLE_CONTROL::ID_GBS);

	wxBoxSizer* battalionsizer = new wxBoxSizer(wxVERTICAL);
	battalionsizer->Add(gbs, 0, wxEXPAND, 0);

	battalionwindow->SetSizer(battalionsizer);
	battalionsizer->SetSizeHints(battalionwindow);
	//this->SetSizer(mainsizer);
}

void CollPaneBattalion::ReceiveLBBSelection(Stats stats) {
	gbs->ReceiveLBBSelection(stats);
}

void CollPaneBattalion::OnCollPaneChange(wxCollapsiblePaneEvent& event) {
	
	//this->GetParent()->Layout();
	event.Skip();
}

wxBEGIN_EVENT_TABLE(CollPaneBattalion, wxCollapsiblePane)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPB, CollPaneBattalion::OnCollPaneChange)
wxEND_EVENT_TABLE()

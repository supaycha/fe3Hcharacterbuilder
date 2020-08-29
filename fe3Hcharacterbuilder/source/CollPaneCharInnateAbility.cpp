#include "CollPaneCharInnateAbility.h"

CollPaneCharInnateAbility::CollPaneCharInnateAbility(wxWindow* parent, wxWindowID id, const wxString& label) :
	wxCollapsiblePane(parent, id, label, wxDefaultPosition, wxSize(-1, -1))
{
	/*mainsizer = new wxBoxSizer(wxVERTICAL);*/
	wxWindow* ciawindow = this->GetPane();
	gcias = new GridCharInnateAbilityStats(ciawindow, (int)ID_SINGLE_CONTROL::ID_GCHIAS);

	wxBoxSizer* ciasizer = new wxBoxSizer(wxVERTICAL);
	ciasizer->Add(gcias, 0, wxEXPAND, 0);

	ciawindow->SetSizer(ciasizer);
	ciasizer->SetSizeHints(ciawindow);
	//this->SetSizer(mainsizer);
}

void CollPaneCharInnateAbility::OnCollPaneChange(wxCollapsiblePaneEvent& event) {

	//this->GetParent()->Layout();
	event.Skip();
}

wxBEGIN_EVENT_TABLE(CollPaneCharInnateAbility, wxCollapsiblePane)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPCHIA, CollPaneCharInnateAbility::OnCollPaneChange)
wxEND_EVENT_TABLE()
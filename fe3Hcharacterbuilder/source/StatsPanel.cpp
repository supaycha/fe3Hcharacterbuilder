#include "StatsPanel.h"

StatsPanel::StatsPanel(wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id)
{	
	spSizer = new wxBoxSizer(wxVERTICAL);

	optionalstats = new CPOptionalStats(this, (int)ID_SINGLE_CONTROL::ID_CPOS, "Optional Stats");
	gts = new GridTotalStats(this, (int)ID_SINGLE_CONTROL::ID_GTS);
	spSizer->Add(optionalstats);
	spSizer->Add(gts);
	this->SetSizer(spSizer);
	Layout();
}

void StatsPanel::OnCollChange(wxCollapsiblePaneEvent& event) {
	SendSizeEventToParent();
}

wxBEGIN_EVENT_TABLE(StatsPanel, wxPanel)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPOS, StatsPanel::OnCollChange)
wxEND_EVENT_TABLE()
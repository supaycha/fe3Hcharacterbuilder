#include "StatsPanel.h"

wxDEFINE_EVENT(TRANSMIT_GWS_STATS, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_GES_STATS, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_GBS_STATS, wxCommandEvent);

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

	Bind(TRANSMIT_GWS_STATS, &StatsPanel::BounceGWSStats_partoftotalstats, this, (int)ID_SINGLE_CONTROL::ID_GWS);
	Bind(TRANSMIT_GES_STATS, &StatsPanel::BounceGESStats_partoftotalstats, this, (int)ID_SINGLE_CONTROL::ID_GES);
	Bind(TRANSMIT_GBS_STATS, &StatsPanel::BounceGBSStats_partoftotalstats, this, (int)ID_SINGLE_CONTROL::ID_GBS);
}

void StatsPanel::ReceiveLBWSelection(Stats stats) {
	optionalstats->ReceiveLBWSelection(stats);
}

void StatsPanel::ReceiveLBESelection(Stats stats) {
	optionalstats->ReceiveLBESelection(stats);
}

void StatsPanel::ReceiveLBBSelection(Stats stats) {
	optionalstats->ReceiveLBBSelection(stats);
}
void StatsPanel::ReceiveGMTStats(Stats stats) {
	gts->ReceiveGMTStats(stats);
}

void StatsPanel::BounceGWSStats_partoftotalstats(wxCommandEvent& eventfromGWS) {
	Stats* temp = dynamic_cast<Stats*>(eventfromGWS.GetClientObject());
	gts->ReceiveGWSStats(*temp);
}

void StatsPanel::BounceGESStats_partoftotalstats(wxCommandEvent& eventfromGES) {
	Stats* temp = dynamic_cast<Stats*>(eventfromGES.GetClientObject());
	gts->ReceiveGESStats(*temp);
}

void StatsPanel::BounceGBSStats_partoftotalstats(wxCommandEvent& eventfromGBS) {
	Stats* temp = dynamic_cast<Stats*>(eventfromGBS.GetClientObject());
	gts->ReceiveGBSStats(*temp);
}

void StatsPanel::OnCollChange(wxCollapsiblePaneEvent& event) {
	SendSizeEventToParent();
}

wxBEGIN_EVENT_TABLE(StatsPanel, wxPanel)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPOS, StatsPanel::OnCollChange)
wxEND_EVENT_TABLE()
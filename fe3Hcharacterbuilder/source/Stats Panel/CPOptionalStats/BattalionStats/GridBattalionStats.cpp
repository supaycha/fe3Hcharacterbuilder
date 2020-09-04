#include <Stats Panel/CPOptionalStats/BattalionStats/GridBattalionStats.h>

GridBattalionStats::GridBattalionStats(wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbbs = new GTBBattalionStats;

	CreateGrid(1, gtbbs->GetColsCount());
	for (int i = 0; i < gtbbs->GetColsCount(); ++i) {
		SetColLabelValue(i, gtbbs->GetHeader(i));
		AutoSizeColLabelSize(i);
	}
	SetUseNativeColLabels(true);

	SetRowLabelSize(0);
	initpopulate();
}

void GridBattalionStats::initpopulate() {
	for (int i = 0; i < gtbbs->GetColsCount(); ++i) {
		SetCellValue(0, i, L"0");
		int k = 0;
	}
}

void GridBattalionStats::ReceiveLBBSelection(Stats stats) {
	gtbbs->ReceiveLBBSelection(stats);
	Freeze();
	repopulate();
	Thaw();
}

void GridBattalionStats::repopulate() {
	std::vector<Stat> tempvectforstats;
	int col = 1;

	for (int i = 0; i < gtbbs->GetColsCount(); ++i) {
		wxString colvalue = gtbbs->GetValue(0, i);
		SetCellValue(0, i, colvalue);
		tempvectforstats.push_back(Stat(colvalue));
		int k = 0;
	}

	Stats* ptrtostats = new Stats(tempvectforstats);
	wxCommandEvent event(TRANSMIT_GBS_STATS, (int)ID_SINGLE_CONTROL::ID_GBS);
	wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);
}

//void GridBattalionStats::OnSize(wxSizeEvent& event) {
//	Layout();
//	event.Skip();
//}
//
//wxBEGIN_EVENT_TABLE(GridBattalionStats, wxGrid)
//	EVT_SIZE(GridBattalionStats::OnSize)
//wxEND_EVENT_TABLE()

#include <Stats Panel/CPOptionalStats/GambitStats/GridGambitStats.h>

GridGambitStats::GridGambitStats(wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbgs = new GTBGambitStats;

	CreateGrid(1, gtbgs->GetColsCount());
	for (int i = 0; i < gtbgs->GetColsCount(); ++i) {
		SetColLabelValue(i, gtbgs->GetHeader(i));
		AutoSizeColLabelSize(i);
	}
	SetUseNativeColLabels(true);

	SetRowLabelSize(0);
	initpopulate();
}

void GridGambitStats::initpopulate() {
	for (int i = 0; i < gtbgs->GetColsCount(); ++i) {
		SetCellValue(0, i, L"0");
		int k = 0;
	}
}

void GridGambitStats::ReceiveLBBSelection(Stats stats) {
	gtbgs->ReceiveLBBSelection(stats);
	Freeze();
	repopulate();
	Thaw();
}

void GridGambitStats::ReceiveAugmenttoStats(wxString value) {
	gtbgs->ReceiveAugmenttoStats(value);
	Freeze();
	repopulate();
	Thaw();
}

void GridGambitStats::repopulate() {
	std::vector<Stat> tempvectforstats;
	int col = 1;

	for (int i = 0; i < gtbgs->GetColsCount(); ++i) {
		wxString colvalue = gtbgs->GetValue(0, i);
		SetCellValue(0, i, colvalue);
		tempvectforstats.push_back(Stat(colvalue));
		int k = 0;
	}

	//Stats* ptrtostats = new Stats(tempvectforstats);
	//wxCommandEvent event(TRANSMIT_GGS_STATS, (int)ID_SINGLE_CONTROL::ID_GGS);
	//wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	//event.SetClientObject(tempdata);
	//ProcessEvent(event);
}
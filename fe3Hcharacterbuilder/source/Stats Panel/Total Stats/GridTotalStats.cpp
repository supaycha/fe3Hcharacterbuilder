#include <Stats Panel/Total Stats/GridTotalStats.h>

GridTotalStats::GridTotalStats(wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbts = new GTBTotalStats;

	CreateGrid(1, gtbts->GetColsCount());
	for (int i = 0; i < gtbts->GetColsCount(); ++i) {
		SetColLabelValue(i, gtbts->GetHeader(i));
		AutoSizeColLabelSize(i);
	}
	SetUseNativeColLabels(true);

	SetRowLabelSize(0);
	initpopulate();
}

void GridTotalStats::initpopulate() {
	for (int i = 0; i < gtbts->GetColsCount(); ++i) {
		SetCellValue(0, i, L"0");
		int k = 0;
	}
}

void GridTotalStats::ReceiveGMTStats(Stats stats) {
	gtbts->ReceiveGMTStats(stats);
	gtbts->recalculate();
	Freeze();
	repopulate();
	Thaw();
}

void GridTotalStats::ReceiveGWSStats(Stats stats) {
	gtbts->ReceiveGWSStats(stats);
	gtbts->recalculate();
	Freeze();
	repopulate();
	Thaw();
}

void GridTotalStats::ReceiveGESStats(Stats stats) {
	gtbts->ReceiveGESStats(stats);
	gtbts->recalculate();
	Freeze();
	repopulate();
	Thaw();
}

void GridTotalStats::ReceiveGBSStats(Stats stats) {
	gtbts->ReceiveGBSStats(stats);
	gtbts->recalculate();
	Freeze();
	repopulate();
	Thaw();
}

void GridTotalStats::ReceiveGCHIASStats(Stats stats) {
	gtbts->ReceiveGCHIASStats(stats);
	gtbts->recalculate();
	Freeze();
	repopulate();
	Thaw();
}

void GridTotalStats::ReceiveGCLIASStats(Stats stats, int index) {
	gtbts->ReceiveGCLIASStats(stats, index);
	gtbts->recalculate();
	Freeze();
	repopulate();
	Thaw();
}

void GridTotalStats::ReceiveGSLASStats(Stats stats, int index) {
	gtbts->ReceiveGSLASStats(stats, index);
	gtbts->recalculate();
	Freeze();
	repopulate();
	Thaw();
}

void GridTotalStats::repopulate() {
	int col = 1;

	for (int i = 0; i < gtbts->GetColsCount(); ++i) {
		wxString colvalue = gtbts->GetValue(0, i);
		SetCellValue(0, i, colvalue);
		int k = 0;
	}
}
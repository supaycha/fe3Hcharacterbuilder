#include "../include/Gridmain.h"

GridWeaponStats::GridWeaponStats(wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbws = new GTBWeaponStats;

	CreateGrid(1, gtbws->GetColsCount());
	for (int i = 0; i < gtbws->GetColsCount(); ++i) {
		SetColLabelValue(i, gtbws->GetHeader(i));
		AutoSizeColLabelSize(i);
	}
	SetUseNativeColLabels(true);

	SetRowLabelSize(0);
	initpopulate();
}

void GridWeaponStats::initpopulate() {
	for (int i = 0; i < gtbws->GetColsCount(); ++i) {
		SetCellValue(0, i, L"0");
		int k = 0;
	}
}

void GridWeaponStats::ReceiveLBWSelection(Stats stats) {
	gtbws->ReceiveLBWSelection(stats);
	Freeze();
	repopulate();
	Thaw();
}

void GridWeaponStats::repopulate() {
	std::vector<Stat> tempvectforstats;
	for (int i = 0; i < gtbws->GetColsCount(); ++i) {
		wxString colvalue = gtbws->GetValue(0, i);
		SetCellValue(0, i, colvalue);
		tempvectforstats.push_back(Stat(colvalue));
		int k = 0;
	}

	Stats* ptrtostats = new Stats(tempvectforstats);
	wxCommandEvent event(TRANSMIT_GWS_STATS, (int)ID_SINGLE_CONTROL::ID_GWS);
	wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);
}

GridEquipmentStats::GridEquipmentStats(wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbes = new GTBEquipmentStats;

	CreateGrid(1, gtbes->GetColsCount());
	for (int i = 0; i < gtbes->GetColsCount(); ++i) {
		SetColLabelValue(i, gtbes->GetHeader(i));
		AutoSizeColLabelSize(i);
	}
	SetUseNativeColLabels(true);

	SetRowLabelSize(0);
	initpopulate();
}

void GridEquipmentStats::initpopulate() {
	for (int i = 0; i < gtbes->GetColsCount(); ++i) {
		SetCellValue(0, i, L"0");
		int k = 0;
	}
}

void GridEquipmentStats::ReceiveLBESelection(Stats stats) {
	gtbes->ReceiveLBESelection(stats);
	Freeze();
	repopulate();
	Thaw();
}

void GridEquipmentStats::repopulate() {
	std::vector<Stat> tempvectforstats;
	int col = 1;

	for (int i = 0; i < gtbes->GetColsCount(); ++i) {
		wxString colvalue = gtbes->GetValue(0, i);
		SetCellValue(0, i, colvalue);
		tempvectforstats.push_back(Stat(colvalue));
		int k = 0;
	}

	Stats* ptrtostats = new Stats(tempvectforstats);
	wxCommandEvent event(TRANSMIT_GES_STATS, (int)ID_SINGLE_CONTROL::ID_GES);
	wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);
}

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

void GridTotalStats::repopulate() {
	int col = 1;

	for (int i = 0; i < gtbts->GetColsCount(); ++i) {
		wxString colvalue = gtbts->GetValue(0, i);
		SetCellValue(0, i, colvalue);
		int k = 0;
	}
}

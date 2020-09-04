#include <Stats Panel/CPOptionalStats/WeaponStats/GridWeaponStats.h>

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
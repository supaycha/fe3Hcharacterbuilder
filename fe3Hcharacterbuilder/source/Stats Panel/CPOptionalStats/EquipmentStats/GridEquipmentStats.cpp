#include <Stats Panel/CPOptionalStats/EquipmentStats/GridEquipmentStats.h>

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
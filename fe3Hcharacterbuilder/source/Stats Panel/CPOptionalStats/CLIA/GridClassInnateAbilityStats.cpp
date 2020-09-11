#include <Stats Panel/CPOptionalStats/CLIA/GridClassInnateAbilityStats.h>

GridClassInnateAbilityStats::GridClassInnateAbilityStats(std::map<wxString, wxClientData*> uclassinnateabilities, wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	classinnateabilities = uclassinnateabilities;
	//SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbclias = new GTBClassInnateAbilityStats;

	CreateGrid(1, 3);
	for (int i = 0; i < 3; ++i) {
		SetColLabelValue(i, "---");
		SetCellValue(0, i, "---");
		AutoSizeColumn(i, true);
	}

	SetUseNativeColLabels(true);
	EnableEditing(false);
	DisableDragGridSize();
	SetRowLabelSize(0);
	//SetColLabelSize(0);
	//initpopulate();
}

void GridClassInnateAbilityStats::initpopulate() {
	//for (int i = 0; i < gtbcias->GetColsCount(); ++i) {
	//	SetCellValue(0, i, L"0");
	//	int k = 0;
	//}
}

void GridClassInnateAbilityStats::ReceiveCLIASelection(wxString abilityname) {
	currentCLIAselection = abilityname;
	bool hasStats = DetermineStatsPresence(currentCLIAselection);
	if (hasStats) {
		STATPACKAGE statp = RetrieveSTATPackage(currentCLIAselection);
		gtbclias->ReceiveCLIASSelection(statp);

		//Freeze();
		repopulate();
		SendSizeEventToParent();

		//Thaw();
	}
	else {
		//Freeze();
		ClearGrid();
		for (int i = 0; i < 3; ++i) {
			SetColLabelValue(i, "---");
			SetCellValue(0, i, "---");
			AutoSizeColLabelSize(i);
		}
		SendSizeEventToParent();
		//Thaw();
	}

}

void GridClassInnateAbilityStats::repopulate() {
	std::vector<Stat> tempvectforstats;
	SetColLabelSize(wxGRID_AUTOSIZE);
	int colcount = gtbclias->GetColsCount();

	for (int i = 0; i < colcount; ++i) {
		wxString colvalue = gtbclias->GetValue(0, i);
		SetColLabelValue(i, gtbclias->GetHeader(i));
		AutoSizeColLabelSize(i);
		SetCellValue(0, i, colvalue);
		int k = 0;
	}	
	
	tempvectforstats.push_back(Stat(gtbclias->GetValue(0, 0)));
	Stats* ptrtostats = new Stats(tempvectforstats);
	wxCommandEvent event(TRANSMIT_GCLIAS_STATS, GetId());
	wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);
}

bool GridClassInnateAbilityStats::DetermineStatsPresence(wxString currentCHIAselection) {
	for (auto element : classinnateabilities) {
		if (currentCHIAselection == element.first) {
			ClassInnateAbility* tempability = dynamic_cast<ClassInnateAbility*>(element.second)->clone();
			return tempability->getHasStatUp();
		}
	}

	return false;
}

STATPACKAGE GridClassInnateAbilityStats::RetrieveSTATPackage(wxString currentCHIAselection) {
	for (auto element : classinnateabilities) {
		if (currentCHIAselection == element.first) {
			ClassInnateAbility* tempability = dynamic_cast<ClassInnateAbility*>(element.second)->clone();
			return tempability->getSTATPACKAGE();
		}
	}

	return STATPACKAGE();
}
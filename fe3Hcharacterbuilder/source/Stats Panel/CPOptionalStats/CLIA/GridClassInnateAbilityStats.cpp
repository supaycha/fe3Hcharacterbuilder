#include <Stats Panel/CPOptionalStats/CLIA/GridClassInnateAbilityStats.h>

GridClassInnateAbilityStats::GridClassInnateAbilityStats(std::map<wxString, wxClientData*> uclassinnateabilities, wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	classinnateabilities = uclassinnateabilities;
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbcias = new GTBClassInnateAbilityStats;

	CreateGrid(1, 1);
	SetCellValue(0, 0, "---");
	AutoSizeColumn(0, true);
	SetUseNativeColLabels(true);
	EnableEditing(false);
	DisableDragGridSize();
	SetRowLabelSize(0);
	SetColLabelSize(0);
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
		STPACKAGE stp = RetrieveSTPackage(currentCLIAselection);
		gtbcias->ReceiveCLIASSelection(stp);

		Freeze();
		repopulate();
		SendSizeEventToParent();

		Thaw();
	}
	else {
		Freeze();
		SetColLabelSize(0);
		SetCellValue(0, 0, "---");
		SendSizeEventToParent();
		Thaw();
	}

}

void GridClassInnateAbilityStats::repopulate() {
	//std::vector<Stat> tempvectforstats;
	SetColLabelSize(wxGRID_AUTOSIZE);

	//SetColLabelValue(0, gtbcias->GetHeader(1));
	//SetCellValue(0, 0, gtbcias->GetValue(0, 0));
	//tempvectforstats.push_back(Stat(gtbcias->GetValue(0, 0)));

	for (int i = 0; i < gtbcias->GetColsCount(); ++i) {
		wxString colvalue = gtbcias->GetValue(0, i);
		SetColLabelValue(i, gtbcias->GetHeader(i));	
		AutoSizeColLabelSize(i);

		SetCellValue(0, i, colvalue);
		int k = 0;
	}

	//Stats* ptrtostats = new Stats(tempvectforstats);
	//wxCommandEvent event(TRANSMIT_GBS_STATS, (int)ID_SINGLE_CONTROL::ID_GTBCHIAS);
	//wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	//event.SetClientObject(tempdata);
	//ProcessEvent(event);
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

STPACKAGE GridClassInnateAbilityStats::RetrieveSTPackage(wxString currentCHIAselection) {
	for (auto element : classinnateabilities) {
		if (currentCHIAselection == element.first) {
			ClassInnateAbility* tempability = dynamic_cast<ClassInnateAbility*>(element.second)->clone();
			return tempability->getSTP();
		}
	}

	return STPACKAGE();
}
#include <Stats Panel/CPOptionalStats/SLA/GridSkillLevelAbilityStats.h>

GridSkillLevelAbilityStats::GridSkillLevelAbilityStats(std::map<wxString, wxClientData*> uskilllevelabilities, wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	skilllevelabilities = uskilllevelabilities;
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbslas = new GTBSkillLevelAbilityStats;

	CreateGrid(1, 3);
	for (int i = 0; i < gtbslas->GetColsCount(); ++i) {
		SetColLabelValue(i, gtbslas->GetHeader(i));
		AutoSizeColLabelSize(i);
	}
	SetUseNativeColLabels(true);

	SetRowLabelSize(0);
	initpopulate();
}

void GridSkillLevelAbilityStats::initpopulate() {
	for (int i = 0; i < gtbslas->GetColsCount(); ++i) {
		SetCellValue(0, i, L"0");
		int k = 0;
	}
}

void GridSkillLevelAbilityStats::ReceiveSLASelection(wxString abilityname) {
	currentSLAselection = abilityname;
	bool hasStats = DetermineStatsPresence(currentSLAselection);
	if (hasStats) {
		std::vector<STPACKAGE> stpVector = RetrieveSTPackage(currentSLAselection);
		gtbslas->ReceiveSLASSelection(stpVector);

		Freeze();
		repopulate();
		SendSizeEventToParent();

		Thaw();
	}

	else {
		Freeze();
		DeleteCols(0);
		SetColLabelValue(0, "");
		AppendCols(1);
		SendSizeEventToParent();
		Thaw();
	}

}

void GridSkillLevelAbilityStats::repopulate() {
	std::vector<Stat> tempvectforstats;
	int colcount = gtbslas->GetColsCount();

	for (int i = 0; i < colcount; ++i) {
		
		SetColLabelValue(i, gtbslas->GetHeader(i));	
		AutoSizeColLabelSize(i);	
		SetCellValue(0, i, gtbslas->GetValue(0, i));
	}
	tempvectforstats.push_back(Stat(gtbslas->GetValue(0, 0)));

	//for (int i = 0; i < gtbslas->GetColsCount(); ++i) {
	//	wxString colvalue = gtbslas->GetValue(0, i);
	//	SetColLabelValue(i, gtbslas->GetHeader(i));

	//	SetCellValue(0, i, colvalue);
	//	int k = 0;
	//}

	Stats* ptrtostats = new Stats(tempvectforstats);
	wxCommandEvent event(TRANSMIT_GBS_STATS, (int)ID_SINGLE_CONTROL::ID_GTBCHIAS);
	wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);
}

bool GridSkillLevelAbilityStats::DetermineStatsPresence(wxString currentCSLAselection) {
	for (auto element : skilllevelabilities) {
		if (currentCSLAselection == element.first) {
			SkillLevelAbility* tempability = dynamic_cast<SkillLevelAbility*>(element.second)->clone();
			return tempability->getHasStatUp();
		}
	}

	return false;
}

std::vector<STPACKAGE> GridSkillLevelAbilityStats::RetrieveSTPackage(wxString currentCHIAselection) {
	for (auto element : skilllevelabilities) {
		if (currentCHIAselection == element.first) {
			SkillLevelAbility* tempability = dynamic_cast<SkillLevelAbility*>(element.second)->clone();
			int test = 9;
			return tempability->getSTP();
		}
	}

	return std::vector<STPACKAGE> ();
}

#include <GridSkillLevelAbilityStats.h>

GridSkillLevelAbilityStats::GridSkillLevelAbilityStats(wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbcias = new GTBSkillLevelAbilityStats;

	CreateGrid(1, gtbcias->GetColsCount());
	for (int i = 0; i < gtbcias->GetColsCount(); ++i) {
		SetColLabelValue(i, gtbcias->GetHeader(i));
		AutoSizeColLabelSize(i);
	}
	SetUseNativeColLabels(true);

	SetRowLabelSize(0);
	initpopulate();
}

void GridSkillLevelAbilityStats::initpopulate() {
	for (int i = 0; i < gtbcias->GetColsCount(); ++i) {
		SetCellValue(0, i, L"0");
		int k = 0;
	}
}

void GridSkillLevelAbilityStats::ReceiveLBBSelection(Stats stats) {
	gtbcias->ReceiveLBBSelection(stats);
	Freeze();
	repopulate();
	Thaw();
}

void GridSkillLevelAbilityStats::repopulate() {
	std::vector<Stat> tempvectforstats;
	int col = 1;

	for (int i = 0; i < gtbcias->GetColsCount(); ++i) {
		wxString colvalue = gtbcias->GetValue(0, i);
		SetCellValue(0, i, colvalue);
		tempvectforstats.push_back(Stat(colvalue));
		int k = 0;
	}

	Stats* ptrtostats = new Stats(tempvectforstats);
	wxCommandEvent event(TRANSMIT_GBS_STATS, (int)ID_SINGLE_CONTROL::ID_GTBSLAS);
	wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);
}
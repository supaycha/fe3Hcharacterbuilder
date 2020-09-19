#include <Stats Panel/CPOptionalStats/SLA/GridSkillLevelAbilityStats.h>

GridSkillLevelAbilityStats::GridSkillLevelAbilityStats(std::map<wxString, wxClientData*> uskilllevelabilities, wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	//SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbslas = new GTBSkillLevelAbilityStats(uskilllevelabilities);

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

void GridSkillLevelAbilityStats::initpopulate() {
	//for (int i = 0; i < gtbslas->GetColsCount(); ++i) {
	//	SetCellValue(0, i, L"0");
	//	int k = 0;
	//}
}

void GridSkillLevelAbilityStats::ReceiveSLASelection(wxString abilityname) {
	gtbslas->ReceiveSLASSelection(abilityname);
	repopulate();
	SendSizeEventToParent();
}

void GridSkillLevelAbilityStats::ReceiveLBWSelection_weapontypeifneeded(WEAPONTYPE type) {
	gtbslas->ReceiveLBWSelection_weapontypeifneeded(type);
	repopulate();
	SendSizeEventToParent();
}

//void GridSkillLevelAbilityStats::ReceiveLBBSelection(bool ubattalionselectionmade) {
//	gtbslas->ReceiveLBBSelection(ubattalionselectionmade);
//	repopulate();
//	SendSizeEventToParent();
//}

void GridSkillLevelAbilityStats::repopulate() {
	SetColLabelSize(wxGRID_AUTOSIZE);
	int colcount = gtbslas->GetColsCount();
	
	for (int i = 0; i < colcount; ++i) {
		wxString colvalue = gtbslas->GetValue(0, i);
		SetColLabelValue(i, gtbslas->GetHeader(i));
		AutoSizeColLabelSize(i);
		SetCellValue(0, i, colvalue);
	}
	std::vector<STATPACKAGE> temp = gtbslas->getSTATP();
	STATPACKAGEVECTOR* tempvectforstats = new STATPACKAGEVECTOR(temp);
	wxCommandEvent event(TRANSMIT_GSLAS_STATS, GetId());
	wxClientData* tempdata = dynamic_cast<wxClientData*>(tempvectforstats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);
}
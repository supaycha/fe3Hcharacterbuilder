#include <Stats Panel/CPOptionalStats/CLIA/GridClassInnateAbilityStats.h>

GridClassInnateAbilityStats::GridClassInnateAbilityStats(std::map<wxString, wxClientData*> uclassinnateabilities, wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	//SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbclias = new GTBClassInnateAbilityStats(uclassinnateabilities);

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
	gtbclias->ReceiveCLIASSelection(abilityname);
	repopulate();
	SendSizeEventToParent();
}

void GridClassInnateAbilityStats::ReceiveLBWSelection_weapontypeifneeded(WEAPONTYPE type) {
	gtbclias->ReceiveLBWSelection_weapontypeifneeded(type);
	repopulate();
	SendSizeEventToParent();
}

void GridClassInnateAbilityStats::repopulate() {
	SetColLabelSize(wxGRID_AUTOSIZE);
	int colcount = gtbclias->GetColsCount();

	for (int i = 0; i < colcount; ++i) {
		wxString colvalue = gtbclias->GetValue(0, i);
		SetColLabelValue(i, gtbclias->GetHeader(i));
		AutoSizeColLabelSize(i);
		SetCellValue(0, i, colvalue);
	}	
	
	STATPACKAGEVECTOR* tempvectforstats = new STATPACKAGEVECTOR(gtbclias->getSTATP());
	wxCommandEvent event(TRANSMIT_GCLIAS_STATS, GetId());
	wxClientData* tempdata = dynamic_cast<wxClientData*>(tempvectforstats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);
}
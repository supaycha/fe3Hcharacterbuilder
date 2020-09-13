#include <Stats Panel/CPOptionalStats/CHIA/GridCharInnateAbilityStats.h>

GridCharInnateAbilityStats::GridCharInnateAbilityStats(std::map<wxString, wxClientData*> ucharacterinnateabilities, wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	//SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbchias = new GTBCharInnateAbilityStats(ucharacterinnateabilities);

	CreateGrid(1, 2);
	for (int i = 0; i < 2; ++i) {
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

void GridCharInnateAbilityStats::initpopulate() {
	//for (int i = 0; i < gtbcias->GetColsCount(); ++i) {
	//	SetCellValue(0, i, L"0");
	//	int k = 0;
	//}
}

void GridCharInnateAbilityStats::ReceiveCHIASelection(wxString abilityname) {
	/*currentCHIAselection = abilityname;*/
	gtbchias->ReceiveCHIASSelection(abilityname);
	repopulate();
	SendSizeEventToParent();
}

void GridCharInnateAbilityStats::ReceiveLBBSelection(bool ubattalionselectionmade) {
	gtbchias->ReceiveLBBSelection(ubattalionselectionmade);
	repopulate();
	SendSizeEventToParent();
}

void GridCharInnateAbilityStats::repopulate() {
	SetColLabelSize(wxGRID_AUTOSIZE);
	int colcount = gtbchias->GetColsCount();

	for (int i = 0; i < colcount; ++i) {
		wxString colvalue = gtbchias->GetValue(0, i);
		SetColLabelValue(i, gtbchias->GetHeader(i));
		AutoSizeColLabelSize(i);
		SetCellValue(0, i, colvalue);
	}

	STATPACKAGEVECTOR* tempvectforstats = new STATPACKAGEVECTOR(gtbchias->RetrieveSTATPackage());
	wxCommandEvent event(TRANSMIT_GCHIAS_STATS, (int)ID_SINGLE_CONTROL::ID_GTBCHIAS);
	wxClientData* tempdata = dynamic_cast<wxClientData*>(tempvectforstats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);
}
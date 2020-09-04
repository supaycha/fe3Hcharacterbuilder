#ifndef STATSPANEL_H
#define STATSPANEL_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <constants.h>
#include <GridMain/GridWeaponStats.h>
#include <GridMain/GridEquipmentStats.h>
#include <GridMain/GridBattalionStats.h>
#include <GridCharInnateAbilityStats.h>
#include <GridClassInnateAbilityStats.h>
#include <GridSkillLevelAbilityStats.h>
#include <GridMain/GridTotalStats.h>
#include <CPOptionalStats.h>

class StatsPanel : public wxPanel {
private:
	CPOptionalStats* optionalstats;
	wxBoxSizer* spSizer;

	GridTotalStats* gts;

	wxDECLARE_EVENT_TABLE();
public:
	StatsPanel(wxWindow* parent, wxWindowID id);
	~StatsPanel() {}
	void ReceiveLBWSelection(Stats stats);
	void ReceiveLBESelection(Stats stats);
	void ReceiveLBBSelection(Stats stats);
	void ReceiveGMTStats(Stats stats);

	void BounceGWSStats_partoftotalstats(wxCommandEvent& eventfromGWS);
	void BounceGESStats_partoftotalstats(wxCommandEvent& eventfromGES);
	void BounceGBSStats_partoftotalstats(wxCommandEvent& eventfromGBS);

	void OnCollChange(wxCollapsiblePaneEvent& event);
};

#endif
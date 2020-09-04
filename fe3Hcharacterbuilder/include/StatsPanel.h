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

	void OnCollChange(wxCollapsiblePaneEvent& event);
};

#endif
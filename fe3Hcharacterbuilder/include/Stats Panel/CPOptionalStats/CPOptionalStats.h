#ifndef CPOPTIONALSTATS_H
#define CPOPTIONALSTATS_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <constants.h>
#include <GridMain/GridWeaponStats.h>
#include <GridMain/GridEquipmentStats.h>
#include <GridMain/GridBattalionStats.h>
#include <GridCharInnateAbilityStats.h>
#include <GridClassInnateAbilityStats.h>
#include <GridSkillLevelAbilityStats.h>

class CPOptionalStats : public wxCollapsiblePane{	
private:
	wxBoxSizer* mainsizer;

	GridWeaponStats* gws;
	GridEquipmentStats* ges;
	GridBattalionStats* gbs;
	GridCharInnateAbilityStats* gchias;
	std::vector<GridClassInnateAbilityStats*> gcliasVector;
	std::vector<GridSkillLevelAbilityStats*> gslasVector;
public:
	CPOptionalStats(wxWindow* parent, wxWindowID id, const wxString& buffer);
	~CPOptionalStats() {}

	void ReceiveLBWSelection(Stats stats);
	void ReceiveLBESelection(Stats stats);
	void ReceiveLBBSelection(Stats stats);
};

#endif
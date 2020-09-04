#ifndef CPOPTIONALSTATS_H
#define CPOPTIONALSTATS_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <constants.h>
#include <Stat.h>
#include <Stats Panel/CPOptionalStats/WeaponStats/GridWeaponStats.h>
#include <Stats Panel/CPOptionalStats/EquipmentStats/GridEquipmentStats.h>
#include <Stats Panel/CPOptionalStats/BattalionStats/GridBattalionStats.h>
#include <Stats Panel/CPOptionalStats/CHIA/GridCharInnateAbilityStats.h>
#include <Stats Panel/CPOptionalStats/CLIA/GridClassInnateAbilityStats.h>
#include <Stats Panel/CPOptionalStats/SLA/GridSkillLevelAbilityStats.h>

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
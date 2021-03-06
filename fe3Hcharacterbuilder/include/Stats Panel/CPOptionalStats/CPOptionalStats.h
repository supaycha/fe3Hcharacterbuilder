#ifndef CPOPTIONALSTATS_H
#define CPOPTIONALSTATS_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <map>
#include <constants.h>
#include <Stat.h>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/CharacterInnateAbility.h>
#include <Unit/Ability/ClassInnateAbility/ClassInnateAbility.h>
#include <Unit/Ability/SkillLevelAbility/SkillLevelAbility.h>
#include <Stats Panel/CPOptionalStats/WeaponStats/GridWeaponStats.h>
#include <Stats Panel/CPOptionalStats/EquipmentStats/GridEquipmentStats.h>
#include <Stats Panel/CPOptionalStats/BattalionStats/GridBattalionStats.h>
#include <Stats Panel/CPOptionalStats/GambitStats/GridGambitStats.h>
#include <Stats Panel/CPOptionalStats/CHIA/GridCharInnateAbilityStats.h>
#include <Stats Panel/CPOptionalStats/CLIA/GridClassInnateAbilityStats.h>
#include <Stats Panel/CPOptionalStats/SLA/GridSkillLevelAbilityStats.h>

class CPOptionalStats : public wxCollapsiblePane{	
private:
	wxBoxSizer* mainsizer;

	GridWeaponStats* gws;
	GridEquipmentStats* ges;
	GridBattalionStats* gbs;
	GridGambitStats* ggs;
	GridCharInnateAbilityStats* gchias;
	std::vector<GridClassInnateAbilityStats*> gcliasVector;
	std::vector<GridSkillLevelAbilityStats*> gslasVector;
	std::map<wxString, wxClientData*> abilitymap;
public:
	CPOptionalStats(std::map<wxString, wxClientData*> uabilitymap, wxWindow* parent, wxWindowID id, const wxString& buffer);
	~CPOptionalStats() {}

	void ReceiveLBWSelection(Stats stats, WEAPONTYPE type);
	void ReceiveLBESelection(Stats stats);
	void ReceiveLBBSelection(Stats battalionstats, Stats gambitstats, bool battalionselectionmade);
	void ReceiveCHIASelection(wxString abilityname);
	void ReceiveCLIASelection(std::vector<wxString> abilityselections);
	void ReceiveSLASelection(std::vector<wxString> abilityselections);
};

#endif
#ifndef GRIDSKILLLEVELABILITYSTATS_H
#define GRIDSKILLLEVELABILITYSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <map>
#include <Stat.h>
#include <constants.h>
//#include <Unit/Unit.h>
//#include <Unit/Ability/Ability.h>
//#include <Unit/Ability/SkillLevelAbility.h>
#include <Stats Panel/CPOptionalStats/SLA/GTBSkillLevelAbilityStats.h>

wxDECLARE_EVENT(TRANSMIT_GSLAS_STATS, wxCommandEvent);

class GridSkillLevelAbilityStats : public wxGrid {
private:
	GTBSkillLevelAbilityStats* gtbslas;
public:
	GridSkillLevelAbilityStats(std::map<wxString, wxClientData*> skilllevelabilities, wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveSLASelection(wxString abilityname);
	void ReceiveLBWSelection_weapontypeifneeded(WEAPONTYPE type);
	void ReceiveLBBSelection(bool ubattalionselectionmade);
	void repopulate();
};

#endif
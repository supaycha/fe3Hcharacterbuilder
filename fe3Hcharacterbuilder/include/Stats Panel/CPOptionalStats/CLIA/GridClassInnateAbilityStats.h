#ifndef GRIDCLASSINNATEABILITYSTATS_H
#define GRIDCLASSINNATEABILITYSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <map>
#include <Stat.h>
#include <constants.h>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/ClassInnateAbility/ClassInnateAbility.h>
#include <Stats Panel/CPOptionalStats/CLIA/GTBClassInnateAbilityStats.h>

wxDECLARE_EVENT(TRANSMIT_GCLIAS_STATS, wxCommandEvent);

class GridClassInnateAbilityStats : public wxGrid {
private:
	GTBClassInnateAbilityStats* gtbclias;
public:
	GridClassInnateAbilityStats(std::map<wxString, wxClientData*> uclassinnateabilities, wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveCLIASelection(wxString abilityname);
	void ReceiveLBWSelection_weapontypeifneeded(WEAPONTYPE type);
	void repopulate();
};

#endif
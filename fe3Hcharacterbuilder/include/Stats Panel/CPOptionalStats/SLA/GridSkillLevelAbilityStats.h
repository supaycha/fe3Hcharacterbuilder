#ifndef GRIDSKILLLEVELABILITYSTATS_H
#define GRIDSKILLLEVELABILITYSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>
#include <constants.h>
#include <Stats Panel/CPOptionalStats/SLA/GTBSkillLevelAbilityStats.h>

wxDECLARE_EVENT(TRANSMIT_GBS_STATS, wxCommandEvent);

class GridSkillLevelAbilityStats : public wxGrid {
private:
	GTBSkillLevelAbilityStats* gtbcias;
public:
	GridSkillLevelAbilityStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBBSelection(Stats stats);
	void repopulate();
};

#endif
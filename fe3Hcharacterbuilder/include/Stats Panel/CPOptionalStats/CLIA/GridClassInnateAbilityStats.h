#ifndef GRIDCLASSINNATEABILITYSTATS_H
#define GRIDCLASSINNATEABILITYSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <map>
#include <Stat.h>
#include <constants.h>
#include <Stats Panel/CPOptionalStats/CLIA/GTBClassInnateAbilityStats.h>

wxDECLARE_EVENT(TRANSMIT_GBS_STATS, wxCommandEvent);

class GridClassInnateAbilityStats : public wxGrid {
private:
	GTBClassInnateAbilityStats* gtbcias;
	wxString currentCLIAselection;
	std::map<wxString, wxClientData*> classinnateabilities;
public:
	GridClassInnateAbilityStats(std::map<wxString, wxClientData*> uclassinnateabilities, wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBBSelection(Stats stats);
	void ReceiveCLIASelection(wxString abilityname);
	void repopulate();
};

#endif
#ifndef GRIDCLASSINNATEABILITYSTATS_H
#define GRIDCLASSINNATEABILITYSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>
#include <constants.h>
#include <Stats Panel/CPOptionalStats/CLIA/GTBClassInnateAbilityStats.h>

wxDECLARE_EVENT(TRANSMIT_GBS_STATS, wxCommandEvent);

class GridClassInnateAbilityStats : public wxGrid {
private:
	GTBClassInnateAbilityStats* gtbcias;
	//wxDECLARE_EVENT_TABLE();
public:
	GridClassInnateAbilityStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBBSelection(Stats stats);
	void repopulate();

	//void OnSize(wxSizeEvent& event);
};

#endif
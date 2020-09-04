#ifndef GRIDCHARINNATEABILITYSTATS_H
#define GRIDCHARINNATEABILITYSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>
#include <constants.h>
#include <Stats Panel/CPOptionalStats/CHIA/GTBCharInnateAbilityStats.h>

wxDECLARE_EVENT(TRANSMIT_GBS_STATS, wxCommandEvent);

class GridCharInnateAbilityStats : public wxGrid {
private:
	GTBCharInnateAbilityStats* gtbcias;
	//wxDECLARE_EVENT_TABLE();
public:
	GridCharInnateAbilityStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBBSelection(Stats stats);
	void repopulate();

	//void OnSize(wxSizeEvent& event);
};

#endif
#ifndef GRIDGAMBITSTATS_H
#define GRIDGAMBITSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>
#include <constants.h>
#include <Stats Panel/CPOptionalStats/GambitStats/GTBGambitStats.h>

wxDECLARE_EVENT(TRANSMIT_GGS_STATS, wxCommandEvent);

class GridGambitStats : public wxGrid {
private:
	GTBGambitStats* gtbgs;
public:
	GridGambitStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBBSelection(Stats stats);
	void repopulate();
};

#endif
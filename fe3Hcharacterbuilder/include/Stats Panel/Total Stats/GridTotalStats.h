#ifndef GRIDTOTALSTATS_H
#define GRIDTOTALSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>
#include <Stats Panel/Total Stats/GTBTotalStats.h>

class GridTotalStats : public wxGrid {
private:
	GTBTotalStats* gtbts;
public:
	GridTotalStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveGMTStats(Stats stats);
	void ReceiveGWSStats(Stats stats);
	void ReceiveGESStats(Stats stats);
	void ReceiveGBSStats(Stats stats);
	void ReceiveGCHIASStats(STATPACKAGEVECTOR spv);
	void ReceiveGCLIASStats(STATPACKAGEVECTOR spv);
	void ReceiveGSLASStats(STATPACKAGEVECTOR spv);

	void repopulate();
};

#endif
#ifndef GRIDTOTALSTATS_H
#define GRIDTOTALSTATS_H

#include <wx/wx.h>
#include <Stat.h>
#include <GTBmain.h>

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
	void repopulate();
};

#endif
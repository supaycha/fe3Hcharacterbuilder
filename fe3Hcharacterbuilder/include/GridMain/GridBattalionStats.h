#ifndef GRIDBATTALIONSTATS_H
#define GRIDBATTALIONSTATS_H

#include <wx/wx.h>
#include <Stat.h>
#include <constants.h>
#include <GTBMain/GTBBattalionStats.h>

wxDECLARE_EVENT(TRANSMIT_GBS_STATS, wxCommandEvent);

class GridBattalionStats : public wxGrid {
private:
	GTBBattalionStats* gtbbs;
	//wxDECLARE_EVENT_TABLE();
public:
	GridBattalionStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBBSelection(Stats stats);
	void repopulate();

	//void OnSize(wxSizeEvent& event);
};

#endif
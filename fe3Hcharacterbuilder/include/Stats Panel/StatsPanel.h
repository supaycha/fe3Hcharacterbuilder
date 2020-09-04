#ifndef STATSPANEL_H
#define STATSPANEL_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <constants.h>

#include <Stat.h>
#include <Stats Panel/CPOptionalStats/CPOptionalStats.h>
#include <Stats Panel/Total Stats/GridTotalStats.h>

class StatsPanel : public wxPanel {
private:
	wxBoxSizer* spSizer;

	CPOptionalStats* optionalstats;
	GridTotalStats* gts;

	wxDECLARE_EVENT_TABLE();
public:
	StatsPanel(wxWindow* parent, wxWindowID id);
	~StatsPanel() {}
	void ReceiveLBWSelection(Stats stats);
	void ReceiveLBESelection(Stats stats);
	void ReceiveLBBSelection(Stats stats);
	void ReceiveGMTStats(Stats stats);

	void BounceGWSStats_partoftotalstats(wxCommandEvent& eventfromGWS);
	void BounceGESStats_partoftotalstats(wxCommandEvent& eventfromGES);
	void BounceGBSStats_partoftotalstats(wxCommandEvent& eventfromGBS);

	void OnCollChange(wxCollapsiblePaneEvent& event);
};

#endif
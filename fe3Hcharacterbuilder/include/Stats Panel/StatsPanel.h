#ifndef STATSPANEL_H
#define STATSPANEL_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <map>
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
	StatsPanel(std::map<wxString, wxClientData*> abilitymap, wxWindow* parent, wxWindowID id);
	~StatsPanel() {}
	void ReceiveLBWSelection(Stats stats, WEAPONTYPE type);
	void ReceiveLBESelection(Stats stats);
	void ReceiveLBBSelection(Stats battalionstats, Stats gambitstats);
	void ReceiveCHIASelection(wxString abilityname);
	void ReceiveCLIASelection(std::vector<wxString> abilityselections);
	void ReceiveSLASelection(std::vector<wxString> abilityselections);
	void ReceiveGMTStats(Stats stats);
	void BounceGWSStats_partoftotalstats(wxCommandEvent& eventfromGWS);
	void BounceGESStats_partoftotalstats(wxCommandEvent& eventfromGES);
	void BounceGBSStats_partoftotalstats(wxCommandEvent& eventfromGBS);
	void BounceGCHIASStats_partoftotalstats(wxCommandEvent& event);
	void BounceGCLIASStats_partoftotalstats(wxCommandEvent& event);
	void BounceGSLASStats_partoftotalstats(wxCommandEvent& event);

	//void OnSize(wxSizeEvent& event);
	void OnCollChange(wxCollapsiblePaneEvent& event);
};

#endif
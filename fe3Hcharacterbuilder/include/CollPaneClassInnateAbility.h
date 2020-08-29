#ifndef COLLPANECLASSINNATEABILITY_H
#define COLLPANECLASSINNATEABILITY_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <GridClassInnateAbilityStats.h>

class CollPaneClassInnateAbility : public wxCollapsiblePane {
private:
	GridClassInnateAbilityStats* gcias;
	wxBoxSizer* mainsizer;
	wxDECLARE_EVENT_TABLE();
public:
	CollPaneClassInnateAbility(wxWindow* parent, wxWindowID id, const wxString& label);
	~CollPaneClassInnateAbility() {}
	void OnCollPaneChange(wxCollapsiblePaneEvent& event);
};

#endif
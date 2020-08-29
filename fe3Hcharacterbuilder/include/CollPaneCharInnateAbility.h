#ifndef COLLPANECHARINNATEABILITY_H
#define COLLPANECHARINNATEABILITY_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <GridCharInnateAbilityStats.h>

class CollPaneCharInnateAbility : public wxCollapsiblePane {
private:
	GridCharInnateAbilityStats* gcias;
	wxBoxSizer* mainsizer;
	wxDECLARE_EVENT_TABLE();
public:
	CollPaneCharInnateAbility(wxWindow* parent, wxWindowID id, const wxString& label);
	~CollPaneCharInnateAbility() {}
	void OnCollPaneChange(wxCollapsiblePaneEvent& event);
};

#endif
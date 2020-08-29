#ifndef COLLPANESKILLLEVELABILITY_H
#define COLLPANESKILLLEVELABILITY_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <GridSkillLevelAbilityStats.h>

class CollPaneSkillLevelAbility : public wxCollapsiblePane {
private:
	GridSkillLevelAbilityStats* gcias;
	wxBoxSizer* mainsizer;
	wxDECLARE_EVENT_TABLE();
public:
	CollPaneSkillLevelAbility(wxWindow* parent, wxWindowID id, const wxString& label);
	~CollPaneSkillLevelAbility() {}
	void OnCollPaneChange(wxCollapsiblePaneEvent& event);
};

#endif
#ifndef ABILITYPANEL_H
#define ABILITYPANEL_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <constants.h>
#include <CollPaneCharInnateAbility.h>
#include <CollPaneClassInnateAbility.h>
#include <CollPaneSkillLevelAbility.h>

class AbilityPanel : public wxPanel {
private:
	wxBoxSizer* panelsizer;
	CollPaneCharInnateAbility* cpchia;
	CollPaneClassInnateAbility* cpclia;
	CollPaneSkillLevelAbility* cpsla;
	wxDECLARE_EVENT_TABLE();
public:
	AbilityPanel(wxWindow* parent, wxWindowID id);
	~AbilityPanel() {}

	void OnCollChange(wxCollapsiblePaneEvent& event);
};

#endif
#ifndef ABILITYPANEL_H
#define ABILITYPANEL_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <map>
#include <constants.h>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/BlankAbility.h>
#include <Unit/Ability/CharacterInnateAbility.h>
#include <Unit/Ability/ClassInnateAbility.h>
#include <Unit/Ability/SkillLevelAbility.h>
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
	AbilityPanel(std::map<wxString, wxClientData*> abilitymap, wxWindow* parent, wxWindowID id);
	~AbilityPanel() {}

	void ReceiveCharacterInnateExclusivity(wxString charactername);
	void ReceiveClassInnateExclusivity(wxString classname);

	void FilterAbilitiesAndInitCollPanes(std::map<wxString, wxClientData*> abilitymap);

	void OnCollChange(wxCollapsiblePaneEvent& event);
};

#endif
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
#include <EquippedOptions/EquippedCharInnateAbility.h>
#include <EquippedOptions/EquippedClassInnateAbility.h>
#include <EquippedOptions/EquippedSkillLvlAbilities.h>

class AbilityPanel : public wxPanel {
private:
	wxBoxSizer* panelsizer;
	EquippedCharInnateAbility* echia;
	std::vector<EquippedClassInnateAbility*> ecliaVector;
	std::vector<EquippedSkillLvlAbilities*> eslaVector;

	std::map<wxString, wxClientData*> classinnateabilities;
	wxString currentLBCselection;
	std::vector<wxString> abilitynames;

	wxDECLARE_EVENT_TABLE();
public:
	AbilityPanel(std::map<wxString, wxClientData*> abilitymap, wxWindow* parent, wxWindowID id);
	~AbilityPanel() {}

	void ReceiveCharacterInnateExclusivity(wxString charactername);
	
	void ReceiveClassInnateExclusivity(wxString classname);	
	void CreateCLIAList();

	void PopulateECLIAVector();
	void FilterAbilitiesAndInitCollPanes(std::map<wxString, wxClientData*> abilitymap);

};

#endif
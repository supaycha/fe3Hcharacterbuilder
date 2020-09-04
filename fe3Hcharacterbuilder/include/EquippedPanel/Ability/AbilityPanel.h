#ifndef ABILITYPANEL_H
#define ABILITYPANEL_H

#include <wx/wx.h>
#include <map>
#include <sstream>
#include <constants.h>
#include <AbilitySelections.h>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
//#include <Unit/Ability/BlankAbility.h>
#include <Unit/Ability/CharacterInnateAbility.h>
#include <Unit/Ability/ClassInnateAbility.h>
#include <Unit/Ability/SkillLevelAbility.h>
#include <EquippedPanel/Ability/CHIA/EquippedCharInnateAbility.h>
#include <EquippedPanel/Ability/CLIA/EquippedClassInnateAbility.h>
#include <EquippedPanel/Ability/SLA/EquippedSkillLvlAbilities.h>

class AbilityPanel : public wxPanel {
private:
	wxBoxSizer* panelsizer;
	EquippedCharInnateAbility* echia;
	std::vector<EquippedClassInnateAbility*> ecliaVector;
	std::vector<EquippedSkillLvlAbilities*> eslaVector;

	std::map<wxString, wxClientData*> classinnateabilities;
	wxString currentLBCselection;
	std::vector<wxString> CLIAnames;
	std::vector<wxString> SLAnames;
public:
	AbilityPanel(std::map<wxString, wxClientData*> abilitymap, wxWindow* parent, wxWindowID id);
	~AbilityPanel() {}

	void ReceiveCharacterInnateExclusivity(wxString charactername);
	
	void ReceiveClassInnateExclusivity(wxString classname);	
	void CreateCLIAList();

	void PopulateECLIAVector();
	void FilterAbilitiesAndInitCollPanes(std::map<wxString, wxClientData*> abilitymap);

	void ReceiveSLASelections(AbilitySelections* selections);
	void CreateSLAList();

	void PopulateSLAVector();
};

#endif
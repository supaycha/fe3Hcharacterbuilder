#ifndef EQUIPPEDCHARINNATEABILITY_H
#define EQUIPPEDCHARINNATEABILITY_H

#include <wx/wx.h>
#include <map>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/CharacterInnateAbility.h>
#include <AbilityList.h>

class EquippedCharInnateAbility : public wxTextCtrl {
private:
	std::map<wxString, wxClientData*> abilitymap;
	wxString currentDDCselection;

	wxString currentchianame;
public:
	EquippedCharInnateAbility(std::map<wxString, wxClientData*> characterinnateabilities, wxWindow* parent, wxWindowID id);
	~EquippedCharInnateAbility() {}
	//void ReceiveExclusivity(wxString charactername);
	//void FilterAbilities();
	void ReceiveAbilityName(wxString abilityname);
	void repopulate();
	//void reselection();
	//wxArrayString ToArrayString(std::vector<wxString> names);
};

#endif
#ifndef EQUIPPEDCLASSINNATEABILITY_H
#define EQUIPPEDCLASSINNATEABILITY_H

#include <wx/wx.h>
#include <map>
#include <sstream>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/ClassInnateAbility.h>
#include <AbilityList.h>

class EquippedClassInnateAbility : public wxListBox {
private:
	wxString currentLBCselection;
	std::map<wxString, wxClientData*> abilitymap;

	std::vector<wxString> filteredAAnames;
	std::vector<wxString> selectedAAnames;
public:
	EquippedClassInnateAbility(wxWindow* parent, wxWindowID id, int x, int y);
	~EquippedClassInnateAbility() {}
	void ReceiveClassInnate(wxString classname);
	void FilterAbilities();
	void ReceiveAbilityFiltration(std::vector<wxString> dirtynames);
	//void ReceiveSelectionsfromBounceL(std::vector<wxString> uSelections);
	void repopulate();
	//void reselection();
	wxArrayString ToArrayString(std::vector<wxString> names);
};

#endif
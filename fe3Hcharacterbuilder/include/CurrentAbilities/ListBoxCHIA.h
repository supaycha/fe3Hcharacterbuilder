#ifndef LISTBOXCHIA_H
#define LISTBOXCHIA_H

#include <wx/wx.h>
#include <map>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/CharacterInnateAbility.h>
#include <AbilityList.h>

class ListBoxCHIA : public wxListBox {
private:
	std::map<wxString, wxClientData*> abilitymap;
	wxString currentDDCselection;

	std::vector<wxString> filteredAAnames;
	std::vector<wxString> selectedAAnames;
public:
	ListBoxCHIA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~ListBoxCHIA() {}
	void ReceiveExclusivity(wxString charactername);
	void FilterAbilities();
	void ReceiveAbilityFiltration(std::vector<wxString> dirtynames);
	void repopulate();
	void reselection();
	wxArrayString ToArrayString(std::vector<wxString> names);
};

#endif
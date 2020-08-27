#ifndef LISTBOXCLIA_H
#define LISTBOXCLIA_H

#include <wx/wx.h>
#include <map>
#include <sstream>
#include <AbilityList.h>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/ClassInnateAbility.h>

class ListBoxCLIA : public wxListBox {
private:
	wxString currentLBCselection;
	std::map<wxString, wxClientData*> abilitymap;

	std::vector<wxString> filteredAAnames;
	std::vector<wxString> selectedAAnames;
public:
	ListBoxCLIA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~ListBoxCLIA() {}
	void ReceiveClassInnate(wxString classname);
	void FilterAbilities();
	void ReceiveAbilityFiltration(std::vector<wxString> dirtynames);
	void ReceiveSelectionsfromBounceL(std::vector<wxString> uSelections);
	void repopulate();
	void reselection();
	wxArrayString ToArrayString(std::vector<wxString> names);

};

#endif
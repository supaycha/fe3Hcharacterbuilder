#ifndef LISTBOXASLA_H
#define LISTBOXASLA_H

#include <wx/wx.h>
#include <map>
#include <constants.h>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/SkillLevelAbility/SkillLevelAbility.h>
#include <AbilitySelections.h>
#include <Lists/AbilityList.h>

wxDECLARE_EVENT(TRANSMIT_LBASLA_SELECTION, wxCommandEvent);

class ListBoxASLA : public wxListBox {
private:
	std::map<wxString, wxClientData*> skilllevelabilitymap;	
	std::vector<SL> SLfilter{ 11, SL::E };

	std::vector<wxString> filteredAAnames;
	std::vector<wxString> selectedAAnames;

	wxString currentDDCHselection;

	wxDECLARE_EVENT_TABLE();
public:
	ListBoxASLA(std::map<wxString, wxClientData*> skilllevelabilitymap, wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~ListBoxASLA() {}

	void OnSelection(wxCommandEvent& event);
	void ReceiveSLInfo(SKILLLEVELPACKAGE* slpackage);
	void ReceiveforAbilityExclusivityCheck(wxString charactername);
	void FilterAbilities();

	void ReceiveAbilityFiltration(std::vector<wxString> dirtynames);
	void repopulate();
	void reselection();

	std::vector<wxString> UpdateSelections();
	std::vector<wxString> GetSelectionsAA() { return selectedAAnames; }

	wxArrayString ToArrayString(std::vector<wxString> names);
};

#endif
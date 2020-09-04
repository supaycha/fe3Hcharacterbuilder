#ifndef LISTBOXASLA_H
#define LISTBOXASLA_H

#include <wx/wx.h>
#include <map>
#include <sstream>
#include <constants.h>
#include <AbilitySelections.h>
#include <AbilityList.h>

wxDECLARE_EVENT(TRANSMIT_LBASLA_SELECTION, wxCommandEvent);

class ListBoxASLA : public wxListBox {
private:
	std::map<wxString, wxClientData*> abilitymap;
	std::vector<SL> SLfilter{ 11, SL::E };

	std::vector<wxString> filteredAAnames;
	std::vector<wxString> selectedAAnames;

	wxDECLARE_EVENT_TABLE();
public:
	ListBoxASLA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~ListBoxASLA() {}

	void OnSelection(wxCommandEvent& event);
	//void ReceiveExclusivity(wxString charactername);
	void ReceiveSLInfo(SLPACKAGE* slpackage);
	//void ReceiveClassInnate(wxString classname);
	void FilterAbilities();

	void ReceiveAbilityFiltration(std::vector<wxString> dirtynames);
	void ReceiveSelectionsfromBounceL(std::vector<wxString> uSelections);
	void repopulate();
	void reselection();

	std::vector<wxString> UpdateSelections();
	std::vector<wxString> GetSelectionsAA() { return selectedAAnames; }

	wxArrayString ToArrayString(std::vector<wxString> names);
};

#endif
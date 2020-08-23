#ifndef LISTBOXAA_H
#define LISTBOXAA_H

//#include <wx/wx.h>
//#include "constants.h"

class ListBoxAA : public wxListBox {
private:
	std::vector<wxString> filteredAAnames;
	std::vector<wxString> selectedAAnames;

	wxDECLARE_EVENT_TABLE();
public:
	ListBoxAA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~ListBoxAA() {}

	void OnSelection(wxCommandEvent& event);
	void ReceiveAbilityFiltration(std::vector<wxString> dirtynames);
	void ReceiveSelectionsfromBounceL(std::vector<wxString> uSelections);
	void repopulate();
	void reselection();

	std::vector<wxString> UpdateSelections();
	std::vector<wxString> GetSelectionsAA() { return selectedAAnames; }

	wxArrayString ToArrayString(std::vector<wxString> names);
};

#endif
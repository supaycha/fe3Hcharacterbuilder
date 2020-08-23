#ifndef LISTBOXSA_H
#define LISTBOXSA_H

#include <wx/wx.h>
#include "constants.h"

class ListBoxSA : public wxListBox {
private:
	std::vector<wxString> filteredSAnames;
	std::vector<wxString> selectedSAnames;

	wxDECLARE_EVENT_TABLE();
public:
	ListBoxSA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~ListBoxSA() {}

	void OnSelection(wxCommandEvent& event);
	void ReceiveAbilityFiltration(std::vector<wxString> dirtynames);
	void ReceiveSelectionsfromBounceR(std::vector<wxString> uSelections);
	void repopulate();
	void reselection();

	std::vector<wxString> UpdateSelections();
	std::vector<wxString> GetSelectionsSAAndClear();

	wxArrayString ToArrayString(std::vector<wxString> names);
};

#endif
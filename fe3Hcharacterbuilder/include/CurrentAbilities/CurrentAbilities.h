#ifndef CURRENTABILITIES_H
#define CURRENTABILITIES_H

#include <wx/wx.h>
#include <MyFrame.h>

class ListBoxCHIA;
class ListBoxCLIA;
class ListBoxSLA;
class MyFrame;

class CurrentAbilities : wxPanel {
private:
	ListBoxCHIA* lbchia;
	ListBoxCLIA* lbclia;
	ListBoxSLA* lbsla;

	std::vector<wxString> filteredSAnames;
	std::vector<wxString> selectedSAnames;

	wxDECLARE_EVENT_TABLE();
public:
	CurrentAbilities(MyFrame* parent, wxWindowID id);
	~CurrentAbilities() {}

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
#ifndef EQUIPPEDSKILLLVLABILITIES_H
#define EQUIPPEDSKILLLVLABILITIES_H

#include <wx/wx.h>
#include <constants.h>

class EquippedSkillLvlAbilities : public wxListBox {
private:
	std::vector<wxString> filteredSAnames;
	std::vector<wxString> selectedSAnames;

	wxDECLARE_EVENT_TABLE();
public:
	EquippedSkillLvlAbilities(wxWindow* parent, wxWindowID id, int x, int y);
	~EquippedSkillLvlAbilities() {}

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
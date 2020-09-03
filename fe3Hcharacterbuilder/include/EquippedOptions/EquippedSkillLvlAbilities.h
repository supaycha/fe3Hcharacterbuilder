#ifndef EQUIPPEDSKILLLVLABILITIES_H
#define EQUIPPEDSKILLLVLABILITIES_H

#include <wx/wx.h>
#include <map>
#include <constants.h>

class EquippedSkillLvlAbilities : public wxStaticText {
private:
	std::vector<wxString> filteredSAnames;
	std::vector<wxString> selectedSAnames;

	//wxDECLARE_EVENT_TABLE();
public:
	EquippedSkillLvlAbilities(std::map<wxString, wxClientData*> skilllevelabilities, wxWindow* parent, wxWindowID id, const wxString& label);
	~EquippedSkillLvlAbilities() {}

	//void OnSelection(wxCommandEvent& event);
	//void ReceiveAbilityFiltration(std::vector<wxString> dirtynames);
	//void ReceiveSelectionsfromBounceR(std::vector<wxString> uSelections);
	//void repopulate();
	//void reselection();

	//std::vector<wxString> UpdateSelections();
	//std::vector<wxString> GetSelectionsSAAndClear();

	//wxArrayString ToArrayString(std::vector<wxString> names);
};

#endif
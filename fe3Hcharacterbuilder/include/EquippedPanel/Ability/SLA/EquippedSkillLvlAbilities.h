#ifndef EQUIPPEDSKILLLVLABILITIES_H
#define EQUIPPEDSKILLLVLABILITIES_H

#include <wx/wx.h>
#include <map>
#include <constants.h>
#include <Unit/Ability/SkillLevelAbility/SkillLevelAbility.h>

wxDECLARE_EVENT(TRANSMIT_SLA_SELECTION, wxCommandEvent);

class EquippedSkillLvlAbilities : public wxStaticText {
private:
	std::vector<wxString> filteredSAnames;
	std::vector<wxString> selectedSAnames;

	wxString currentLBASLAselection;
	std::map<wxString, wxClientData*> skilllevelabilities;
public:
	EquippedSkillLvlAbilities(std::map<wxString, wxClientData*> uskilllevelabilities, wxWindow* parent, wxWindowID id, const wxString& label);
	~EquippedSkillLvlAbilities() {}

	void ReceiveSkillLevelAbility(wxString classname);
	void repopulate();
	wxString RetrieveDescription(wxString currentLBASLAselection);
};

#endif
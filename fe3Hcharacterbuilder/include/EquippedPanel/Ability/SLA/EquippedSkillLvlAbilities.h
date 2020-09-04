#ifndef EQUIPPEDSKILLLVLABILITIES_H
#define EQUIPPEDSKILLLVLABILITIES_H

#include <wx/wx.h>
#include <map>
#include <constants.h>

class EquippedSkillLvlAbilities : public wxStaticText {
private:
	std::vector<wxString> filteredSAnames;
	std::vector<wxString> selectedSAnames;

	wxString currentLBASLAselection;
public:
	EquippedSkillLvlAbilities(std::map<wxString, wxClientData*> skilllevelabilities, wxWindow* parent, wxWindowID id, const wxString& label);
	~EquippedSkillLvlAbilities() {}

	void ReceiveSkillLevelAbility(wxString classname);
	void repopulate();
};

#endif
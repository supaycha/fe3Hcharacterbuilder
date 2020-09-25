#ifndef SKILLLEVELMANAGER_H
#define SKILLLEVELMANAGER_H

#include <wx/wx.h>
#include <map>
#include <constants.h>
#include <AvailablePanel/SkillLevelManager/DropDownSkillLevel.h>
////#include <vld.h>

wxDECLARE_EVENT(TRANSMIT_SL_SELECTION, wxCommandEvent);

class SkillLevelManager : public wxPanel {
private:
	wxBoxSizer* mainsizer;
	std::vector<wxString> labels{ "Sword", "Axe", "Lance", "Bow", "Gauntlets", "Reason", "Faith", "Authority", "Heavy Armor", "Riding", "Flying" };
	std::vector<DropDownSkillLevel*> ddslVector;
	std::vector<wxStaticText*> stslVector;
	wxDECLARE_EVENT_TABLE();
public:
	SkillLevelManager(wxWindow* parent, wxWindowID id);
	~SkillLevelManager() {}

	void OnNewSelection(wxCommandEvent& selection);
};

#endif
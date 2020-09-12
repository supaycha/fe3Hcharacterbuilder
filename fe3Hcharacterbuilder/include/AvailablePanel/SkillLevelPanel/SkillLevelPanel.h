#ifndef SKILLLEVELPANEL_H
#define SKILLLEVELPANEL_H

#include <wx/wx.h>
#include <map>
#include <constants.h>
#include <AvailablePanel/SkillLevelPanel/ListBoxASLA.h>
#include <AvailablePanel/SkillLevelPanel/ListBoxBattalions.h>
#include <AvailablePanel/SkillLevelPanel/WeaponManager/WeaponManager.h>
#include <AvailablePanel/SkillLevelPanel/SkillLevelManager/SkillLevelManager.h>

wxDECLARE_EVENT(REPEAT_LBASLA_SELECTION, wxCommandEvent);

class SkillLevelPanel : public wxPanel {
private:
	wxBoxSizer* slpSizer;
	SkillLevelManager* slm;
	WeaponManager* wm;
	ListBoxASLA* lbasla;
	ListBoxBattalions* lbb;
public:
	SkillLevelPanel(std::map<wxString, wxClientData*> weaponmap, std::map<wxString, wxClientData*> battalionmap, std::map<wxString, wxClientData*> abilitymap, wxWindow* parent, wxWindowID id);
	~SkillLevelPanel() {}

	void ReceiveDDCHSelection(wxString charactername);
	void BounceSLInfo(wxCommandEvent& eventfromwho);
	void ForwardLBASLASelection(wxCommandEvent& forwarded);
};

#endif
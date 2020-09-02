#ifndef SKILLLEVELPANEL_H
#define SKILLLEVELPANEL_H

#include <wx/wx.h>
#include <constants.h>
#include <SkillLevelManager/SkillLevelManager.h>
#include <WeaponManager.h>
#include <ListBoxASLA.h>
#include <ListBox/ListBoxBattalions.h>

class SkillLevelManager;

class SkillLevelPanel : public wxPanel {
private:
	wxBoxSizer* slpSizer;
	SkillLevelManager* slm;
	WeaponManager* wm;
	ListBoxASLA* lbasla;
	ListBoxBattalions* lbb;
public:
	SkillLevelPanel(std::map<wxString, wxClientData*> weaponmap, std::map<wxString, wxClientData*> battalionmap, wxWindow* parent, wxWindowID id);
	~SkillLevelPanel() {}

	void ReceiveWeaponExclusivity(wxString charactername);
	void BounceSLInfo(wxCommandEvent& eventfromwho);
};

#endif
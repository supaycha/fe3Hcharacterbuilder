#ifndef WEAPONMANAGER_H
#define WEAPONMANAGER_H

#include <wx/wx.h>
#include <wx/tglbtn.h>
#include <map>
#include <constants.h>
#include <AvailablePanel/SkillLevelPanel/WeaponManager/ListBoxWeapons.h>

class WeaponManager : public wxPanel {
private:
	wxBoxSizer* mainsizer;
	ListBoxWeapons* lbw;
	std::vector<wxToggleButton*> weapontypes;
	wxDECLARE_EVENT_TABLE();
public:
	WeaponManager(std::map<wxString, wxClientData*> weaponmap, wxWindow* parent, wxWindowID id);
	~WeaponManager() {}

	void OnNewSelection(wxCommandEvent& eventfromwho);

	void ReceiveforWeaponExclusivityCheck(wxString charactername);
	void ReceiveSLInfo(SKILLLEVELPACKAGE* slpackage);
};

#endif
#ifndef WEAPONMANAGER_H
#define WEAPONMANAGER_H

#include <wx/wx.h>
#include <wx/tglbtn.h>
#include <map>
#include <constants.h>
#include <AvailablePanel/WeaponManager/ListBoxWeapons.h>

class WeaponManager : public wxPanel {
private:	
	ListBoxWeapons* lbw;
	wxBoxSizer* mainsizer;
	std::vector<wxToggleButton*> weapontypes;
	wxDECLARE_EVENT_TABLE();
public:
	WeaponManager(std::map<wxString, wxClientData*> weaponmap, 
		wxWindow* parent, wxWindowID id);
	~WeaponManager() {}

	void OnNewSelection(wxCommandEvent& selection);

	void ReceiveforWeaponExclusivityCheck(wxString charactername);
	void ReceiveSLInfo(SKILLLEVELPACKAGE* slpackage);
};

#endif
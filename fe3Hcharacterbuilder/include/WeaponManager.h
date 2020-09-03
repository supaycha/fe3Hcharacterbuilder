#ifndef WEAPONMANAGER_H
#define WEAPONMANAGER_H

#include <wx/wx.h>
#include <wx/tglbtn.h>
#include <constants.h>
#include <ListBox/ListBoxWeapons.h>

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

	void ReceiveWeaponExclusivity(wxString charactername);
	void ReceiveSLInfo(SLPACKAGE* slpackage);
};

#endif
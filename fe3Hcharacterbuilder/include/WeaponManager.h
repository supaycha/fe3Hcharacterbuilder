#ifndef WEAPONMANAGER_H
#define WEAPONMANAGER_H

#include <wx/wx.h>
#include <ListBox/ListBoxWeapons.h>

class WeaponManager : public wxPanel {
private:
	wxBoxSizer* mainsizer;
	ListBoxWeapons* lbw;
	std::vector<wxButton*> weapontypes;
public:
	WeaponManager(std::map<wxString, wxClientData*> weaponmap, wxWindow* parent, wxWindowID id);
	~WeaponManager() {}

	void ReceiveExclusivity(wxString charactername);
	void ReceiveSLInfo(SLPACKAGE* slpackage);
};

#endif
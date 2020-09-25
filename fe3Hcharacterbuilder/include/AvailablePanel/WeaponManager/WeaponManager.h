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

	std::vector<wxString> bitmapVector{ 
		"IDB_SWORD23", "IDB_AXE23", "IDB_LANCE23", 
		"IDB_BOW23", "IDB_GAUNTLETS23", "IDB_BLACKMAGIC23", 
		"IDB_DARKMAGIC23", "IDB_WHITEMAGIC23" };
	std::vector<wxToggleButton*> weapontypesVector;
	std::vector<wxBitmap> weaponbitmapVector;
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
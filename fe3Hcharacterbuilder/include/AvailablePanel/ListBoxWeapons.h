#ifndef LISTBOXWEAPONS_H
#define LISTBOXWEAPONS_H

#include <wx/wx.h>
#include <map>
#include <sstream>
#include <constants.h>
#include <Unit/Unit.h>
#include <Unit/Weapon/Weapon.h>

//wxDECLARE_EVENT(TRANSMIT_LBW_SELECTION, wxCommandEvent);

class ListBoxWeapons : public wxListBox {
private:
	std::map<wxString, wxClientData*> weaponmap;
	std::map<wxString, wxClientData*> allavailableweapons;

	wxString currentDDCselection;
	wxString mostrecentLBWselection;
	std::vector<SL> SLfilter{ 7, SL::E };
	std::vector<STINCPACKAGE> STfilter{8, { false, 0 } };
	//wxDECLARE_EVENT_TABLE();
public:
	ListBoxWeapons(std::map<wxString, wxClientData*> uweaponmap, 
		wxWindow* panel, wxWindowID id,
		int x, int y, 
		const wxArrayString& choices, long style);
	~ListBoxWeapons() {}

	//void OnNewSelection(wxCommandEvent& selection);
	void ReceiveWeaponExclusivity(wxString charactername);
	void ReceiveSLInfo(SKILLLEVELPACKAGE* slpackage);
	void ReceiveSTInfo(STINCPACKAGE package);

	void FactorInExternalChange();	
	
	std::map<wxString, wxClientData*> CreateListOfAvailableWeapons();
	void ReselectWeapons();

	void recalculate();
	void repopulate();
	bool CompareAllStrings();

	wxArrayString ToArrayString(std::vector<wxString> names);
	wxClientData** ToArrayData(std::vector<wxClientData*>& names);
};

#endif
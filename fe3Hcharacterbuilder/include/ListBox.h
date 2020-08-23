#ifndef LISTBOX_H
#define LISTBOX_H

#include <wx/wx.h>
#include <map>
#include <sstream>
#include <Unit/Unit.h>
#include <Unit/Weapon/Weapon.h>
#include <Unit/Equipment/Equipment.h>
#include <Unit/Battalion.h>
#include "constants.h"
//#include <vld.h>

wxDECLARE_EVENT(TRANSMIT_LBW_SELECTION, wxCommandEvent);
wxDECLARE_EVENT(TRANSMIT_LBE_SELECTION, wxCommandEvent);
wxDECLARE_EVENT(TRANSMIT_LBB_SELECTION, wxCommandEvent);

class ListBoxWeapons : public wxListBox {
private:
	std::map<wxString, wxClientData*> weaponmap;
	wxString currentDDCselection;
	wxString mostrecentLBWselection;
	std::vector<SL> SLfilter{ 7, SL::E };

	wxDECLARE_EVENT_TABLE();
public:
	ListBoxWeapons(std::map<wxString, wxClientData*> uweaponmap, wxWindow* panel, wxWindowID id, int x, int y, const wxArrayString& choices, long style);
	~ListBoxWeapons() {}

	void OnNewSelection(wxCommandEvent& selection);
	void ReceiveExclusivity(wxString charactername);
	void ReceiveSLInfo(SLPACKAGE* slpackage);

	void repopulate();
	void DetermineSelectionStatus();
	bool CompareAllStrings();

	wxArrayString ToArrayString(std::vector<wxString> names);
	wxClientData** ToArrayData(std::vector<wxClientData*>& names);
};

class ListBoxEquipment : public wxListBox {
private:
	std::map<wxString, wxClientData*> equipmentmap;
	wxString currentDDCSelection;
	wxString mostrecentLBEselection;
	wxDECLARE_EVENT_TABLE();
public:
	ListBoxEquipment(std::map<wxString, wxClientData*> uequipmentmap, wxWindow* panel, wxWindowID id, int x, int y, const wxArrayString& choices, long style);
	~ListBoxEquipment() {}

	void OnNewSelection(wxCommandEvent& selection);
	void ReceiveExclusivity(wxString charactername);

	void repopulate();
	void DetermineSelectionStatus();
	bool CompareAllStrings();

	wxArrayString ToArrayString(std::vector<wxString> names);
	wxClientData** ToArrayData(std::vector<wxClientData*>& names);
};

class ListBoxBattalions : public wxListBox {
	std::map<wxString, wxClientData*> battalionmap;
	SL sl;
	wxString mostrecentLBBselection;
	wxDECLARE_EVENT_TABLE();
public:
	ListBoxBattalions(std::map<wxString, wxClientData*> ubattalionmap, wxWindow* panel, wxWindowID id, int x, int y, const wxArrayString& choices, long style);
	~ListBoxBattalions() {}

	void OnNewSelection(wxCommandEvent& selection);
	void ReceiveSLInfo(SLPACKAGE* slpackage);

	void repopulate();
	void DetermineSelectionStatus();
	bool CompareAllStrings();

	wxArrayString ToArrayString(std::vector<wxString> names);
	wxClientData** ToArrayData(std::vector<wxClientData*>& names);
};

#endif
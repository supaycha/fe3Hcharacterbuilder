#ifndef LISTBOXEQUIPMENT_H
#define LISTBOXEQUIPMENT_H

#include <wx/wx.h>
#include <map>
#include <sstream>
#include <constants.h>
#include <Unit/Unit.h>
#include <Unit/Equipment/Equipment.h>

//wxDECLARE_EVENT(TRANSMIT_LBE_SELECTION, wxCommandEvent);

class ListBoxEquipment : public wxListBox {
private:
	std::map<wxString, wxClientData*> equipmentmap;
	std::map<wxString, wxClientData*> allavailableequipment;

	wxString currentDDCSelection;
	wxString mostrecentLBEselection;

	//wxDECLARE_EVENT_TABLE();
public:
	ListBoxEquipment(std::map<wxString, wxClientData*> uequipmentmap, 
		wxWindow* panel, wxWindowID id, 
		int x, int y, const 
		wxArrayString& choices, long style);
	~ListBoxEquipment() {}

	//void OnNewSelection(wxCommandEvent& selection);
	void ReceiveEquipmentExclusivity(wxString charactername);

	void FactorInExternalChange();

	std::map<wxString, wxClientData*> CreateListOfAvailableEquipment();
	void ReselectEquipment();

	void recalculate();
	void repopulate();
	//void DetermineSelectionStatus();
	bool CompareAllStrings();

	wxArrayString ToArrayString(std::vector<wxString> names);
	wxClientData** ToArrayData(std::vector<wxClientData*>& names);
};

#endif
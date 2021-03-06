#ifndef DROPDOWNCLASSES_H
#define DROPDOWNCLASSES_H

#include <wx/wx.h>
#include <map>
#include <sstream>
#include <constants.h>
#include <Unit/Unit.h>
#include <Unit/Class.h>

//wxDECLARE_EVENT(TRANSMIT_DDCL_SELECTION, wxCommandEvent);

class DropDownClasses : public wxComboBox {
private:
	std::map<wxString, wxClientData*> classmap;
	std::map<wxString, wxClientData*> allavailableclasses;

	wxString currentDDCSelection;
	wxString mostrecentDDCLselection;
	//wxDECLARE_EVENT_TABLE();
public:
	DropDownClasses(std::map<wxString, wxClientData*> classmap, wxWindow* panel, wxWindowID id, const wxArrayString& choices, long style);
	~DropDownClasses() {}

	//void OnNewSelection(wxCommandEvent& selection);
	void ReceiveExclusivity(wxString charactername);
	void FactorInExternalChange();
	std::map<wxString, wxClientData*> CreateListOfAvailableClasses();

	void recalculate();
	void repopulate();

	void ReselectClasses();
	bool CompareAllStrings();

	wxArrayString ToArrayString(std::vector<wxString> names);
	wxClientData** ToArrayData(std::vector<wxClientData*>& names);
};

#endif
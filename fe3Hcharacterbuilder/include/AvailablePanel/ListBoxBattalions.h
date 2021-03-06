#ifndef LISTBOXBATTALIONS_H
#define LISTBOXBATTALIONS_H

#include <wx/wx.h>
#include <map>
#include <constants.h>
#include <Unit/Unit.h>
#include <Unit/Battalion.h>

//wxDECLARE_EVENT(TRANSMIT_LBB_SELECTION, wxCommandEvent);

class ListBoxBattalions : public wxListBox {
	std::map<wxString, wxClientData*> battalionmap;
	std::map<wxString, wxClientData*> allavailablebattalions;

	SL sl;
	wxString mostrecentLBBselection;

	//wxDECLARE_EVENT_TABLE();
public:
	ListBoxBattalions(std::map<wxString, wxClientData*> ubattalionmap, 
		wxWindow* panel, wxWindowID id, 
		int x, int y, 
		const wxArrayString& choices, long style);
	~ListBoxBattalions() {}

	//void OnNewSelection(wxCommandEvent& selection);
	void ReceiveSLInfo(SKILLLEVELPACKAGE* slpackage);

	//void FactorInInternalChange();
	void FactorInExternalChange();

	std::map<wxString, wxClientData*> CreateListOfAvailableBattalions();
	void ReselectBattalion();

	void recalculate();
	void repopulate();
	bool CompareAllStrings();

	wxArrayString ToArrayString(std::vector<wxString> names);
	wxClientData** ToArrayData(std::vector<wxClientData*>& names);
};

#endif
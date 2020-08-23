#ifndef DROPDOWNCHARACTERS_H
#define DROPDOWNCHARACTERS_H

//#include <wx/wx.h>
//#include "constants.h"

wxDECLARE_EVENT(TRANSMIT_DDCH_SELECTION, wxCommandEvent);

class DropDownCharacters : public wxComboBox {
private:
	wxDECLARE_EVENT_TABLE();
public:
	DropDownCharacters(std::vector<wxString> characternames, std::vector<wxClientData*> characterdata, wxWindow* panel, wxWindowID id, const wxArrayString& choices, long style);
	~DropDownCharacters() {}

	void OnNewSelection(wxCommandEvent& selection);
	wxArrayString ToArrayString(std::vector<wxString> names);
	wxClientData** ToArrayData(std::vector<wxClientData*>& names);
};

#endif
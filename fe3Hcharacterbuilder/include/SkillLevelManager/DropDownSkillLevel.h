#ifndef DROPDOWNSKILLLEVEL_H
#define DROPDOWNSKILLLEVEL_H

//#include <wx/wx.h>
//#include "constants.h"

class DropDownSkillLevel : public wxComboBox {
private:
	wxString ddname;
public:
	DropDownSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, const wxString& value, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~DropDownSkillLevel() {}

	void initpopulate();

	wxArrayString ToArrayString(std::vector<wxString> names);
	wxClientData** ToArrayData(std::vector<wxClientData*>& names);
};

#endif
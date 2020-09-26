#ifndef DROPDOWNSKILLLEVEL_H
#define DROPDOWNSKILLLEVEL_H

#include <wx/wx.h>
#include "constants.h"

class DropDownSkillLevel : public wxComboBox {
private:
	wxString ddname;
	std::vector<wxString> skillLVLnames{ "E", "E+", "D", "D+", "C", "C+", "B", "B+", "A", "A+", "S", "S+" };
	std::vector<wxClientData*> skillLVLdata{ new SKILLLEVELPACKAGE{SL::E}, new SKILLLEVELPACKAGE(SL::EPLUS), new SKILLLEVELPACKAGE(SL::D), new SKILLLEVELPACKAGE(SL::DPLUS), new SKILLLEVELPACKAGE(SL::C), new SKILLLEVELPACKAGE(SL::CPLUS),
									  new SKILLLEVELPACKAGE(SL::B), new SKILLLEVELPACKAGE(SL::BPLUS), new SKILLLEVELPACKAGE(SL::A), new SKILLLEVELPACKAGE(SL::APLUS), new SKILLLEVELPACKAGE(SL::S), new SKILLLEVELPACKAGE(SL::SPLUS) };
public:
	DropDownSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, const wxString& value, int x, int y, const wxArrayString& choices, long style);
	~DropDownSkillLevel() {}

	void initpopulate();

	wxArrayString ToArrayString(std::vector<wxString> names);
	wxClientData** ToArrayData(std::vector<wxClientData*>& names);
};

#endif
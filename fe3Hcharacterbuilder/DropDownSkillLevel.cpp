#include "DropDownSkillLevel.h"

DropDownSkillLevel::DropDownSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, const wxString& value, int x, int y, int x2, int y2, const wxArrayString& choices, long style) :
	wxComboBox(parent, id, value, wxPoint(x, y), wxSize(x2, y2), choices, style)
{
	ddname = label;
	initpopulate();
}

void DropDownSkillLevel::initpopulate() {
	std::vector<wxString> skillLVLnames{ "E", "E+", "D", "D+", "C", "C+", "B", "B+", "A", "A+", "S", "S+" };
	std::vector<wxClientData*> skillLVLdata{ new SLPACKAGE{SL::E}, new SLPACKAGE(SL::EPLUS), new SLPACKAGE(SL::D), new SLPACKAGE(SL::DPLUS), new SLPACKAGE(SL::C), new SLPACKAGE(SL::CPLUS),
										  new SLPACKAGE(SL::B), new SLPACKAGE(SL::BPLUS), new SLPACKAGE(SL::A), new SLPACKAGE(SL::APLUS), new SLPACKAGE(SL::S), new SLPACKAGE(SL::SPLUS) };
	int offset = 50;

	for (int i = 0; i < (int)VARIOUS_SIZE::SL_DATA_SIZE; ++i) {
		SLPACKAGE* temp = dynamic_cast<SLPACKAGE*>(skillLVLdata[i]);
		temp->index = (GetId() - 50);
	}

	this->Append(ToArrayString(skillLVLnames), ToArrayData(skillLVLdata));
	this->SetSelection(0);
}

wxArrayString DropDownSkillLevel::ToArrayString(std::vector<wxString> names) {
	wxArrayString temparraystring;
	for (auto name : names) {
		temparraystring.Add(name);
	}

	return temparraystring;
}

wxClientData** DropDownSkillLevel::ToArrayData(std::vector<wxClientData*>& ptrs) {
	int size = ptrs.size();
	wxClientData** temparraydata = new wxClientData * [size];
	for (int i = 0; i < size; ++i) {
		temparraydata[i] = ptrs[i];
	}

	return temparraydata;
}
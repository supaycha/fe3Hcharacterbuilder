#include <AvailablePanel/SkillLevelPanel/SkillLevelManager/DropDownSkillLevel.h>

DropDownSkillLevel::DropDownSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, const wxString& value, int x, int y, int x2, int y2, const wxArrayString& choices, long style) :
	wxComboBox(parent, id, value, wxPoint(x, y), wxSize(x2, y2), choices, style)
{
	ddname = label;
	initpopulate();
}

void DropDownSkillLevel::initpopulate() {
	std::vector<wxString> skillLVLnames{ "E", "E+", "D", "D+", "C", "C+", "B", "B+", "A", "A+", "S", "S+" };
	std::vector<wxClientData*> skillLVLdata{ new SKILLLEVELPACKAGE{SL::E}, new SKILLLEVELPACKAGE(SL::EPLUS), new SKILLLEVELPACKAGE(SL::D), new SKILLLEVELPACKAGE(SL::DPLUS), new SKILLLEVELPACKAGE(SL::C), new SKILLLEVELPACKAGE(SL::CPLUS),
										  new SKILLLEVELPACKAGE(SL::B), new SKILLLEVELPACKAGE(SL::BPLUS), new SKILLLEVELPACKAGE(SL::A), new SKILLLEVELPACKAGE(SL::APLUS), new SKILLLEVELPACKAGE(SL::S), new SKILLLEVELPACKAGE(SL::SPLUS) };
	int offset = 70;

	for (int i = 0; i < (int)VARIOUS_SIZE::SL_DATA_SIZE; ++i) {
		SKILLLEVELPACKAGE* temp = dynamic_cast<SKILLLEVELPACKAGE*>(skillLVLdata[i]);
		temp->index = (GetId() - offset);
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
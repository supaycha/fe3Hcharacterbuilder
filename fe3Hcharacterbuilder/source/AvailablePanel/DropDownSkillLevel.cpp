#include <AvailablePanel/DropDownSkillLevel.h>

DropDownSkillLevel::DropDownSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, const wxString& value, int x, int y, const wxArrayString& choices, long style) :
	wxComboBox(parent, id, value, wxDefaultPosition, wxSize(x, y), choices, style)
{
	ddname = label;
	initpopulate();
}

void DropDownSkillLevel::initpopulate() {
	std::vector<wxString> skillLVLnames{ "E", "E+", "D", "D+", "C", "C+", "B", "B+", "A", "A+", "S", "S+" };
	std::vector<wxClientData*> skillLVLdata{ new SKILLLEVELPACKAGE{SL::E}, new SKILLLEVELPACKAGE(SL::EPLUS), new SKILLLEVELPACKAGE(SL::D), new SKILLLEVELPACKAGE(SL::DPLUS), new SKILLLEVELPACKAGE(SL::C), new SKILLLEVELPACKAGE(SL::CPLUS),
										  new SKILLLEVELPACKAGE(SL::B), new SKILLLEVELPACKAGE(SL::BPLUS), new SKILLLEVELPACKAGE(SL::A), new SKILLLEVELPACKAGE(SL::APLUS), new SKILLLEVELPACKAGE(SL::S), new SKILLLEVELPACKAGE(SL::SPLUS) };
	int offset = 70;

	for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_SKILL_LEVELS_PER_DDSL; ++i) {
		SKILLLEVELPACKAGE* temp = dynamic_cast<SKILLLEVELPACKAGE*>(skillLVLdata[i]);
		int test = GetId();
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
	int sizeofvector = ptrs.size();
	wxClientData** temparraydata = new wxClientData * [sizeofvector];
	for (int i = 0; i < sizeofvector; ++i) {
		temparraydata[i] = ptrs[i];
	}

	return temparraydata;
}
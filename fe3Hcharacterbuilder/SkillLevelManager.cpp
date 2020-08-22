#include "SkillLevelManager.h"

SkillLevelManager::SkillLevelManager(MyFrame* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	std::vector<wxString> labels{ "Sword", "Lance", "Axe", "Bow", "Gauntlets", "Reason", "Faith", "Authority", "Heavy Armor", "Riding", "Flying" };
	wxString value{};
	wxArrayString choices{};
	int ddslIDoffset = 0;
	int ddslPOINToffset = 0;
	int stslIDoffset = 0;
	int stslPOINToffset = 0;
	manager = new std::map<StaticTextSkillLevel*, DropDownSkillLevel*>();

	for (int i = 0; i < SL_DATA_SIZE; ++i) {
		StaticTextSkillLevel* stsl = new StaticTextSkillLevel(this, (ID_STSWORD + stslIDoffset), labels.at(i), 50, stslPOINToffset, 75, 25);
		DropDownSkillLevel* ddsl = new DropDownSkillLevel(this, (ID_DDSWORD + ddslIDoffset), labels.at(i), value, 0, ddslPOINToffset, 50, 25, choices, wxCB_DROPDOWN | wxCB_READONLY);

		manager->emplace(std::make_pair(stsl, ddsl));
		ddslIDoffset++;
		ddslPOINToffset += 25;
		stslIDoffset++;
		stslPOINToffset += 25;
	}
}

void SkillLevelManager::OnNewSelection(wxCommandEvent& uevent) {
	SLPACKAGE* temp = dynamic_cast<SLPACKAGE*>(uevent.GetClientObject());
	DropDownSkillLevel* tempwindow = dynamic_cast<DropDownSkillLevel*>(uevent.GetEventObject());

	temp->slstring = tempwindow->GetLabel();
	wxCommandEvent eventforlbw(TRANSMIT_SL_SELECTION, uevent.GetId());
	eventforlbw.SetClientObject(dynamic_cast<wxClientData*>(temp));
	eventforlbw.SetInt(ID_LBW);
	ProcessEvent(eventforlbw);

	wxCommandEvent eventforam(TRANSMIT_SL_SELECTION, uevent.GetId());
	eventforam.SetClientObject(dynamic_cast<wxClientData*>(temp));
	eventforam.SetInt(ID_AM);
	ProcessEvent(eventforam);

	wxCommandEvent eventforlbb(TRANSMIT_SL_SELECTION, uevent.GetId());
	eventforlbb.SetClientObject(dynamic_cast<wxClientData*>(temp));
	eventforlbb.SetInt(ID_LBB);
	ProcessEvent(eventforlbb);
}

StaticTextSkillLevel::StaticTextSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, int x, int y, int x2, int y2) :
	wxStaticText(parent, id, label, wxPoint(x, y), wxSize(x2, y2))
{
	stname = label;
}

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

	for (int i = 0; i < SL_DATA_SIZE; ++i) {
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

wxBEGIN_EVENT_TABLE(SkillLevelManager, wxPanel)
	EVT_COMBOBOX(ID_DDSWORD, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX(ID_DDLANCE, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX(ID_DDAXE, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX(ID_DDBOW, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX(ID_DDGAUNTLETS, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX(ID_DDREASON, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX(ID_DDFAITH, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX(ID_DDAUTHORITY, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX(ID_DDHEAVYARMOR, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX(ID_DDRIDING, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX(ID_DDFLYING, SkillLevelManager::OnNewSelection)
wxEND_EVENT_TABLE()

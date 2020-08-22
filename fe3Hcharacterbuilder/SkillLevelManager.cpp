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

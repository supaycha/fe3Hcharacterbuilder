#include <AvailablePanel/SkillLevelPanel/SkillLevelManager/SkillLevelManager.h>

SkillLevelManager::SkillLevelManager(wxWindow* parent, wxWindowID id) :
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

	for (int i = 0; i < (int)VARIOUS_SIZE::SL_DATA_SIZE; ++i) {
		StaticTextSkillLevel* stsl = new StaticTextSkillLevel(this, ((int)ST_CONTROL::ID_STSWORD + stslIDoffset), labels.at(i), 50, stslPOINToffset, 75, 25);
		DropDownSkillLevel* ddsl = new DropDownSkillLevel(this, ((int)DD_CONTROL::ID_DDSWORD + ddslIDoffset), labels.at(i), value, 0, ddslPOINToffset, 50, 25, choices, wxCB_DROPDOWN | wxCB_READONLY);

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
	eventforlbw.SetInt((int)ID_SINGLE_CONTROL::ID_LBW);
	ProcessEvent(eventforlbw);

	wxCommandEvent eventforlbasla(TRANSMIT_SL_SELECTION, uevent.GetId());
	eventforlbasla.SetClientObject(dynamic_cast<wxClientData*>(temp));
	eventforlbasla.SetInt((int)ID_SINGLE_CONTROL::ID_LBASLA);
	ProcessEvent(eventforlbasla);

	wxCommandEvent eventforlbb(TRANSMIT_SL_SELECTION, uevent.GetId());
	eventforlbb.SetClientObject(dynamic_cast<wxClientData*>(temp));
	eventforlbb.SetInt((int)ID_SINGLE_CONTROL::ID_LBB);
	ProcessEvent(eventforlbb);
}

wxBEGIN_EVENT_TABLE(SkillLevelManager, wxPanel)
	EVT_COMBOBOX((int)DD_CONTROL::ID_DDSWORD, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX((int)DD_CONTROL::ID_DDLANCE, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX((int)DD_CONTROL::ID_DDAXE, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX((int)DD_CONTROL::ID_DDBOW, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX((int)DD_CONTROL::ID_DDGAUNTLETS, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX((int)DD_CONTROL::ID_DDREASON, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX((int)DD_CONTROL::ID_DDFAITH, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX((int)DD_CONTROL::ID_DDAUTHORITY, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX((int)DD_CONTROL::ID_DDHEAVYARMOR, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX((int)DD_CONTROL::ID_DDRIDING, SkillLevelManager::OnNewSelection)
	EVT_COMBOBOX((int)DD_CONTROL::ID_DDFLYING, SkillLevelManager::OnNewSelection)
wxEND_EVENT_TABLE()

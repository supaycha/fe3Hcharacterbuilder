#include "WeaponManager.h"

WeaponManager::WeaponManager(std::map<wxString, wxClientData*> weaponmap, wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id)
{
	mainsizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* buttonsizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* lbwsizer = new wxBoxSizer(wxVERTICAL);
	const wxString buffer;
	wxArrayString emptybuffer;
	lbw = new ListBoxWeapons(weaponmap, this, (int)ID_SINGLE_CONTROL::ID_LBW, 150, 260, emptybuffer, wxLB_SINGLE | wxLB_SORT | wxLB_ALWAYS_SB);

	for (int i = 0; i < (int)VARIOUS_SIZE::WEAPON_TYPE_SIZE; ++i) {
		weapontypes.push_back(new wxToggleButton(this, ((int)WT_CONTROL::ID_BSWORD) + i, buffer));
	}

	wxBitmap swordICON23("IDB_SWORD23", wxBITMAP_TYPE_PNG_RESOURCE);
	weapontypes[0]->SetBitmap(swordICON23, wxRIGHT);

	wxBitmap axeICON23("IDB_AXE23", wxBITMAP_TYPE_PNG_RESOURCE);	
	weapontypes[1]->SetBitmap(axeICON23, wxRIGHT);
	
	wxBitmap lanceICON23("IDB_LANCE23", wxBITMAP_TYPE_PNG_RESOURCE);
	weapontypes[2]->SetBitmap(lanceICON23, wxRIGHT);

	wxBitmap bowICON23("IDB_BOW23", wxBITMAP_TYPE_PNG_RESOURCE);
	weapontypes[3]->SetBitmap(bowICON23, wxRIGHT);

	wxBitmap gauntletsICON23("IDB_GAUNTLETS23", wxBITMAP_TYPE_PNG_RESOURCE);
	weapontypes[4]->SetBitmap(gauntletsICON23, wxRIGHT);

	wxBitmap blackmagicICON23("IDB_BLACKMAGIC23", wxBITMAP_TYPE_PNG_RESOURCE);
	weapontypes[5]->SetBitmap(blackmagicICON23, wxRIGHT);

	wxBitmap darkmagicICON23("IDB_DARKMAGIC23", wxBITMAP_TYPE_PNG_RESOURCE);
	weapontypes[6]->SetBitmap(darkmagicICON23, wxRIGHT);

	wxBitmap whitemagicICON23("IDB_WHITEMAGIC23", wxBITMAP_TYPE_PNG_RESOURCE);
	weapontypes[7]->SetBitmap(whitemagicICON23, wxRIGHT);

	
	wxStaticText* lbwLABEL = new wxStaticText(this, wxID_ANY, "Available Weapons");

	for (auto button : weapontypes) {
		buttonsizer->Add(button);
	}

	lbwsizer->Add(lbwLABEL);
	lbwsizer->Add(lbw);

	mainsizer->Add(buttonsizer);
	mainsizer->Add(lbwsizer);

	this->SetSizer(mainsizer);

	this->Layout();
}

void WeaponManager::OnNewSelection(wxCommandEvent& eventfromwho) {
	int offset = 1;
	int id = eventfromwho.GetId();

	int trueid = id - offset;
	bool isNotIncluded = weapontypes[trueid]->GetValue();

	WTPACKAGE package{ isNotIncluded, trueid };
	lbw->ReceiveWTInfo(package);
	//switch (id) {
	//	case (int)WT_CONTROL::ID_BSWORD: {
	//		bool isPressed = weapontypes[id - offset]->GetValue();
	//		int templevel = transmission.GetInt();
	//		gmt->UpdateSCLSelection(templevel, (int)ID_MISC::ID_SPIN1);

	//		break;
	//	}

	//	case (int)WT_CONTROL::ID_BLANCE: {
	//		int templevel = transmission.GetInt();
	//		gmt->UpdateSCLSelection(templevel, (int)ID_MISC::ID_SPIN2);

	//		break;
	//	}

	//	case (int)WT_CONTROL::ID_BAXE: {
	//		int templevel = transmission.GetInt();
	//		gmt->UpdateSCLSelection(templevel, (int)ID_MISC::ID_SPIN2);

	//		break;
	//	}

	//	case (int)WT_CONTROL::ID_BBOW: {
	//		int templevel = transmission.GetInt();
	//		gmt->UpdateSCLSelection(templevel, (int)ID_MISC::ID_SPIN2);

	//		break;
	//	}

	//	case (int)WT_CONTROL::ID_BGAUNTLETS: {
	//		int templevel = transmission.GetInt();
	//		gmt->UpdateSCLSelection(templevel, (int)ID_MISC::ID_SPIN2);

	//		break;
	//	}

	//	case (int)WT_CONTROL::ID_BBLACKMAGIC: {
	//		int templevel = transmission.GetInt();
	//		gmt->UpdateSCLSelection(templevel, (int)ID_MISC::ID_SPIN2);

	//		break;
	//	}

	//	case (int)WT_CONTROL::ID_BDARKMAGIC: {
	//		int templevel = transmission.GetInt();
	//		gmt->UpdateSCLSelection(templevel, (int)ID_MISC::ID_SPIN2);

	//		break;
	//	}

	//	case (int)WT_CONTROL::ID_BWHITEMAGIC: {
	//		int templevel = transmission.GetInt();
	//		gmt->UpdateSCLSelection(templevel, (int)ID_MISC::ID_SPIN2);

	//		break;
	//	}

	//}

}

void WeaponManager::ReceiveWeaponExclusivity(wxString charactername) {	//forwarded from MyFrame::BounceDDCInfo()
	lbw->ReceiveExclusivity(charactername);
}

void WeaponManager::ReceiveSLInfo(SLPACKAGE* slpackage) {
	lbw->ReceiveSLInfo(slpackage);
}

wxBEGIN_EVENT_TABLE(WeaponManager, wxPanel)
	EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BSWORD, WeaponManager::OnNewSelection)
	EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BLANCE, WeaponManager::OnNewSelection)
	EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BAXE, WeaponManager::OnNewSelection)
	EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BBOW, WeaponManager::OnNewSelection)
	EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BGAUNTLETS, WeaponManager::OnNewSelection)
	EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BBLACKMAGIC, WeaponManager::OnNewSelection)
	EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BDARKMAGIC, WeaponManager::OnNewSelection)
	EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BWHITEMAGIC, WeaponManager::OnNewSelection)
wxEND_EVENT_TABLE()

#include <AvailablePanel/AvailablePanel.h>

//wxDEFINE_EVENT(TRANSMIT_SL_SELECTION, wxCommandEvent);

AvailablePanel::AvailablePanel(std::map<wxString, wxClientData*> weaponmap, std::map<wxString, wxClientData*> battalionmap, std::map<wxString, wxClientData*> equipmap, std::map<wxString, wxClientData*> skilllevelabilitymap, std::map<wxString, wxClientData*> classmasteryabilitymap, wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id)
{
	const wxString buffer;
	const wxArrayString emptybuffer;
	for (int i = 0; i < (int)CONSTANT_SIZE::SL_DATA_SIZE; ++i) {
		ddslVector.push_back(new DropDownSkillLevel(this, ((int)DD_CONTROL::ID_DDSWORD) + i, labels[i], buffer, 50, 25, emptybuffer, wxCB_DROPDOWN | wxCB_READONLY));
		stslVector.push_back(new wxStaticText(this, wxID_ANY, labels[i], wxDefaultPosition, wxSize(75, 25)));
	}

	wxStaticText* lbwLABEL = new wxStaticText(this, wxID_ANY, "Available Weapons");
	lbw = new ListBoxWeapons(weaponmap, this, (int)ID_SINGLE_CONTROL::ID_LBW, 150, 260, emptybuffer, wxLB_SINGLE | wxLB_SORT | wxLB_ALWAYS_SB);
	for (int i = 0; i < (int)CONSTANT_SIZE::WEAPON_TYPE_SIZE; ++i) {
		weapontypesVector.push_back(new wxToggleButton(this, ((int)WT_CONTROL::ID_BSWORD + i), buffer));
		weaponbitmapVector.push_back(wxBitmap(bitmapVector[i], wxBITMAP_TYPE_PNG_RESOURCE));
	}
	for (int i = 0; i < (int)CONSTANT_SIZE::WEAPON_TYPE_SIZE; ++i) {
		weapontypesVector[i]->SetBitmap(weaponbitmapVector[i], wxRIGHT);
	}

	wxStaticText* lbaslaLABEL = new wxStaticText(this, wxID_ANY, "Available Abilities");
	lbasla = new ListBoxASLA(skilllevelabilitymap, classmasteryabilitymap, this, (int)ID_SINGLE_CONTROL::ID_LBASLA, 0, 0, 150, 260, emptybuffer, wxLB_MULTIPLE);
	includeClassMasteries = new wxToggleButton(this, ((int)ID_MISC::ID_BCLASSMASTERY), "");
	wxStaticText* lbbLABEL = new wxStaticText(this, wxID_ANY, "Available Battalions");
	lbb = new ListBoxBattalions(battalionmap, this, (int)ID_SINGLE_CONTROL::ID_LBB, 150, 260, emptybuffer, wxLB_SINGLE | wxLB_SORT);
	wxStaticText* lbeLABEL = new wxStaticText(this, wxID_ANY, "Available Equipment");
	lbe = new ListBoxEquipment(equipmap, this, (int)ID_SINGLE_CONTROL::ID_LBE, 150, 400, emptybuffer, wxLB_SINGLE | wxLB_SORT);

	mainsizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* skilllevelpanel = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* skilllevelpanel_dropdowncol = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* skilllevelpanel_statictextcol = new wxBoxSizer(wxVERTICAL);
	for (int i = 0; i < (int)CONSTANT_SIZE::SL_DATA_SIZE; ++i) {
		skilllevelpanel_dropdowncol->Add(ddslVector[i]);
		skilllevelpanel_statictextcol->Add(stslVector[i]);
	}
	skilllevelpanel->Add(skilllevelpanel_dropdowncol);
	skilllevelpanel->Add(skilllevelpanel_statictextcol);
	mainsizer->Add(skilllevelpanel);

	wxBoxSizer* weaponpanelsizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* weaponpanel_buttonscol = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* weaponpanel_lbwcol = new wxBoxSizer(wxVERTICAL);
	for (auto button : weapontypesVector) {
		weaponpanel_buttonscol->Add(button);
	}
	weaponpanel_lbwcol->Add(lbwLABEL);
	weaponpanel_lbwcol->Add(lbw);
	weaponpanelsizer->Add(weaponpanel_buttonscol);
	weaponpanelsizer->Add(weaponpanel_lbwcol);
	mainsizer->Add(weaponpanelsizer);

	wxBoxSizer* column2 = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* column3 = new wxBoxSizer(wxVERTICAL);
	column2->Add(lbaslaLABEL);
	column2->Add(lbasla);
	column2->Add(includeClassMasteries);
	mainsizer->Add(column2);

	column3->Add(lbbLABEL);
	column3->Add(lbb);
	column3->Add(lbeLABEL);
	column3->Add(lbe);
	mainsizer->Add(column3);

	SetSizerAndFit(mainsizer);

	Bind(wxEVT_COMBOBOX, &AvailablePanel::BounceSLInfo, this, (int)DD_CONTROL::ID_DDSWORD, (int)DD_CONTROL::ID_DDFLYING);
	Bind(wxEVT_TOGGLEBUTTON, &AvailablePanel::BounceSTInfo, this, (int)WT_CONTROL::ID_BSWORD, (int)WT_CONTROL::ID_BWHITEMAGIC);
}

void AvailablePanel::ReceiveDDCHSelection(wxString charactername) {
	lbw->ReceiveExclusivity(charactername);
	lbasla->ReceiveforAbilityExclusivityCheck(charactername);
}
void AvailablePanel::ReceiveClassMasteryExclusivity(wxString classmasterycheck) {
	lbasla->ReceiveClassMasteryExclusivity(classmasterycheck);
}

void AvailablePanel::ReceiveEquipmentExclusivity(wxString charactername) {
	lbe->ReceiveEquipmentExclusivity(charactername);
}

void AvailablePanel::BounceSLInfo(wxCommandEvent& ddsl) {
	SKILLLEVELPACKAGE* slpackage = dynamic_cast<SKILLLEVELPACKAGE*>(ddsl.GetClientObject());
	DropDownSkillLevel* tempwindow = dynamic_cast<DropDownSkillLevel*>(ddsl.GetEventObject());
	slpackage->slstring = tempwindow->GetLabel();

	lbw->ReceiveSLInfo(slpackage);
	lbasla->ReceiveSLInfo(slpackage);
	if (slpackage->index == 7) {
		lbb->ReceiveSLInfo(slpackage);
	}
}

void AvailablePanel::BounceSTInfo(wxCommandEvent& stsl) {
	int id = stsl.GetId();
	bool isNotIncluded = weapontypesVector[id]->GetValue();

	STINCPACKAGE package{ isNotIncluded, id };
	lbw->ReceiveSTInfo(package);
}

void AvailablePanel::OnToggle(wxCommandEvent& eventfromwho) {
	bool isPressed = includeClassMasteries->GetValue();
	lbasla->ReceiveClassMasteryButtonStatus(isPressed);
}

//void AvailablePanel::OnNewSelection(wxCommandEvent& uevent) {
//	//SKILLLEVELPACKAGE* temp = dynamic_cast<SKILLLEVELPACKAGE*>(uevent.GetClientObject());
//	//DropDownSkillLevel* tempwindow = dynamic_cast<DropDownSkillLevel*>(uevent.GetEventObject());
//
//	//temp->slstring = tempwindow->GetLabel();
//	//wxCommandEvent eventforlbw(TRANSMIT_SL_SELECTION, uevent.GetId());
//	//eventforlbw.SetClientObject(dynamic_cast<wxClientData*>(temp));
//	//eventforlbw.SetInt((int)ID_SINGLE_CONTROL::ID_LBW);
//	//ProcessEvent(eventforlbw);
//
//	//wxCommandEvent eventforlbasla(TRANSMIT_SL_SELECTION, uevent.GetId());
//	//eventforlbasla.SetClientObject(dynamic_cast<wxClientData*>(temp));
//	//eventforlbasla.SetInt((int)ID_SINGLE_CONTROL::ID_LBASLA);
//	//ProcessEvent(eventforlbasla);
//
//	//wxCommandEvent eventforlbb(TRANSMIT_SL_SELECTION, uevent.GetId());
//	//eventforlbb.SetClientObject(dynamic_cast<wxClientData*>(temp));
//	//eventforlbb.SetInt((int)ID_SINGLE_CONTROL::ID_LBB);
//	//ProcessEvent(eventforlbb);
//
//
//
//
//	int offset = 1;
//	int id = uevent.GetId();
//
//	int trueid = id - offset;
//	bool isNotIncluded = weapontypesVector[trueid]->GetValue();
//
//	STINCPACKAGE package{ isNotIncluded, trueid };
//	lbw->ReceiveSTInfo(package);
//}

wxBEGIN_EVENT_TABLE(AvailablePanel, wxPanel)
	EVT_TOGGLEBUTTON((int)ID_MISC::ID_BCLASSMASTERY, AvailablePanel::OnToggle)
	//EVT_COMBOBOX((int)DD_CONTROL::ID_DDSWORD, AvailablePanel::OnNewSelection)
	//EVT_COMBOBOX((int)DD_CONTROL::ID_DDLANCE, AvailablePanel::OnNewSelection)
	//EVT_COMBOBOX((int)DD_CONTROL::ID_DDAXE, AvailablePanel::OnNewSelection)
	//EVT_COMBOBOX((int)DD_CONTROL::ID_DDBOW, AvailablePanel::OnNewSelection)
	//EVT_COMBOBOX((int)DD_CONTROL::ID_DDGAUNTLETS, AvailablePanel::OnNewSelection)
	//EVT_COMBOBOX((int)DD_CONTROL::ID_DDREASON, AvailablePanel::OnNewSelection)
	//EVT_COMBOBOX((int)DD_CONTROL::ID_DDFAITH, AvailablePanel::OnNewSelection)
	//EVT_COMBOBOX((int)DD_CONTROL::ID_DDAUTHORITY, AvailablePanel::OnNewSelection)
	//EVT_COMBOBOX((int)DD_CONTROL::ID_DDHEAVYARMOR, AvailablePanel::OnNewSelection)
	//EVT_COMBOBOX((int)DD_CONTROL::ID_DDRIDING, AvailablePanel::OnNewSelection)
	//EVT_COMBOBOX((int)DD_CONTROL::ID_DDFLYING, AvailablePanel::OnNewSelection)
	//EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BSWORD, AvailablePanel::OnNewSelection)
	//EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BLANCE, AvailablePanel::OnNewSelection)
	//EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BAXE, AvailablePanel::OnNewSelection)
	//EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BBOW, AvailablePanel::OnNewSelection)
	//EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BGAUNTLETS, AvailablePanel::OnNewSelection)
	//EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BBLACKMAGIC, AvailablePanel::OnNewSelection)
	//EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BDARKMAGIC, AvailablePanel::OnNewSelection)
	//EVT_TOGGLEBUTTON((int)WT_CONTROL::ID_BWHITEMAGIC, AvailablePanel::OnNewSelection)
wxEND_EVENT_TABLE()
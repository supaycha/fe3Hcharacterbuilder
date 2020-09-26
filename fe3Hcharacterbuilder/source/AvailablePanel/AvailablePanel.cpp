#include <AvailablePanel/AvailablePanel.h>

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
		weapontypesVector.push_back(new wxToggleButton(this, ((int)WT_CONTROL::ID_BSWORD) + i, buffer));
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
	lbw->ReceiveWeaponExclusivity(charactername);
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
	slpackage->slstring = ddsl.GetString();

	lbw->ReceiveSLInfo(slpackage);
	lbasla->ReceiveSLInfo(slpackage);
	if (slpackage->index == 7) {
		lbb->ReceiveSLInfo(slpackage);
	}
}

void AvailablePanel::BounceSTInfo(wxCommandEvent& stsl) {
	int id = stsl.GetId();
	int offset = 11;
	int trueid = id - offset;
	bool isNotIncluded = weapontypesVector[trueid]->GetValue();

	STINCPACKAGE package{ isNotIncluded, trueid };
	lbw->ReceiveSTInfo(package);
}

void AvailablePanel::OnToggle(wxCommandEvent& eventfromwho) {
	bool isPressed = includeClassMasteries->GetValue();
	lbasla->ReceiveClassMasteryButtonStatus(isPressed);
}

wxBEGIN_EVENT_TABLE(AvailablePanel, wxPanel)
	EVT_TOGGLEBUTTON((int)ID_MISC::ID_BCLASSMASTERY, AvailablePanel::OnToggle)
wxEND_EVENT_TABLE()
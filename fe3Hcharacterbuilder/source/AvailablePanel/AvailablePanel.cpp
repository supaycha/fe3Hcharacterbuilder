#include <AvailablePanel/AvailablePanel.h>

wxDEFINE_EVENT(TRANSMIT_SL_SELECTION, wxCommandEvent);

AvailablePanel::AvailablePanel(std::map<wxString, wxClientData*> weaponmap, std::map<wxString, wxClientData*> battalionmap, std::map<wxString, wxClientData*> equipmap, std::map<wxString, wxClientData*> skilllevelabilitymap, std::map<wxString, wxClientData*> classmasteryabilitymap, wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id)
{
	const wxString buffer;
	wxArrayString emptybuffer;
	for (int i = 0; i < (int)CONSTANT_SIZE::SL_DATA_SIZE; ++i) {
		stslVector.push_back(new wxStaticText(this, wxID_ANY, labels.at(i), wxDefaultPosition, wxSize(75, 25)));
		ddslVector.push_back(new DropDownSkillLevel(this, ((int)DD_CONTROL::ID_DDSWORD + i), labels.at(i), buffer, 50, 25, emptybuffer, wxCB_DROPDOWN | wxCB_READONLY));
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

	Bind(TRANSMIT_SL_SELECTION, &AvailablePanel::BounceSLInfo, this, (int)DD_CONTROL::ID_DDSWORD, (int)DD_CONTROL::ID_DDFLYING);
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

void AvailablePanel::BounceSLInfo(wxCommandEvent& info) {
	int idofreceiver = info.GetInt();
	switch (idofreceiver)
	{
		case (int)ID_SINGLE_CONTROL::ID_LBW: {
			SKILLLEVELPACKAGE* slpackage = dynamic_cast<SKILLLEVELPACKAGE*>(info.GetClientObject());
			lbw->ReceiveSLInfo(slpackage);
			break;
		}
		case (int)ID_SINGLE_CONTROL::ID_LBASLA: {
			SKILLLEVELPACKAGE* slpackage = dynamic_cast<SKILLLEVELPACKAGE*>(info.GetClientObject());
			lbasla->ReceiveSLInfo(slpackage);
			break;
		}
		case (int)ID_SINGLE_CONTROL::ID_LBB: {
			SKILLLEVELPACKAGE* slpackage = dynamic_cast<SKILLLEVELPACKAGE*>(info.GetClientObject());
			if (slpackage->index == 7) {
				lbb->ReceiveSLInfo(slpackage);
			}

			break;
		}
	}
}

void AvailablePanel::OnToggle(wxCommandEvent& eventfromwho) {
	bool isPressed = includeClassMasteries->GetValue();
	lbasla->ReceiveClassMasteryButtonStatus(isPressed);
}

wxBEGIN_EVENT_TABLE(AvailablePanel, wxPanel)
	EVT_TOGGLEBUTTON((int)ID_MISC::ID_BCLASSMASTERY, AvailablePanel::OnToggle)
wxEND_EVENT_TABLE()
#include <AvailablePanel/AvailablePanel.h>

wxDEFINE_EVENT(TRANSMIT_SL_SELECTION, wxCommandEvent);

AvailablePanel::AvailablePanel(std::map<wxString, wxClientData*> weaponmap, std::map<wxString, wxClientData*> battalionmap, std::map<wxString, wxClientData*> equipmap, std::map<wxString, wxClientData*> skilllevelabilitymap, std::map<wxString, wxClientData*> classmasteryabilitymap, wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id)
{
	const wxArrayString emptybuffer{};

	slm = new SkillLevelManager(this, (int)ID_SINGLE_CONTROL::ID_SLM);
	wm = new WeaponManager(weaponmap, this, (int)ID_MISC::ID_WM);
	includeClassMasteries = new wxToggleButton(this, ((int)ID_MISC::ID_BCLASSMASTERY), "");

	wxStaticText* lbaslaLABEL = new wxStaticText(this, wxID_ANY, "Available Abilities");
	lbasla = new ListBoxASLA(skilllevelabilitymap, classmasteryabilitymap, this, (int)ID_SINGLE_CONTROL::ID_LBASLA, 0, 0, 150, 260, emptybuffer, wxLB_MULTIPLE);
	wxStaticText* lbbLABEL = new wxStaticText(this, wxID_ANY, "Available Battalions");
	lbb = new ListBoxBattalions(battalionmap, this, (int)ID_SINGLE_CONTROL::ID_LBB, 150, 260, emptybuffer, wxLB_SINGLE | wxLB_SORT);
	wxStaticText* lbeLABEL = new wxStaticText(this, wxID_ANY, "Available Equipment");
	lbe = new ListBoxEquipment(equipmap, this, (int)ID_SINGLE_CONTROL::ID_LBE, 150, 400, emptybuffer, wxLB_SINGLE | wxLB_SORT);
	slpSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* column1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* column2 = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* column3 = new wxBoxSizer(wxVERTICAL);

	column1->Add(slm);
	column1->Add(wm);
	slpSizer->Add(column1);
	column2->Add(lbaslaLABEL);
	column2->Add(lbasla);
	column2->Add(includeClassMasteries);
	slpSizer->Add(column2);
	column3->Add(lbbLABEL);
	column3->Add(lbb);
	column3->Add(lbeLABEL);
	column3->Add(lbe);
	slpSizer->Add(column3);
	SetSizerAndFit(slpSizer);

	Bind(TRANSMIT_SL_SELECTION, &AvailablePanel::BounceSLInfo, this, (int)DD_CONTROL::ID_DDSWORD, (int)DD_CONTROL::ID_DDFLYING);
}

void AvailablePanel::ReceiveDDCHSelection(wxString charactername) {
	wm->ReceiveforWeaponExclusivityCheck(charactername);
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
			wm->ReceiveSLInfo(slpackage);
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
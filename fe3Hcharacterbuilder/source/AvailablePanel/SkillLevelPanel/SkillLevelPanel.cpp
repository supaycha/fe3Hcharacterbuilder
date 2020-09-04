#include <AvailablePanel/SkillLevelPanel/SkillLevelPanel.h>

wxDEFINE_EVENT(TRANSMIT_SL_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_LBASLA_SELECTION, wxCommandEvent);

SkillLevelPanel::SkillLevelPanel(std::map<wxString, wxClientData*> weaponmap, std::map<wxString, wxClientData*> battalionmap, wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id)
{
	const wxArrayString emptybuffer{};

	slm = new SkillLevelManager(this, (int)ID_SINGLE_CONTROL::ID_SLM);
	wm = new WeaponManager(weaponmap, this, (int)ID_MISC::ID_WM);	
	wxStaticText* lbaslaLABEL = new wxStaticText(this, wxID_ANY, "Available Abilities");
	lbasla = new ListBoxASLA(this, (int)ID_SINGLE_CONTROL::ID_LBASLA, 0, 0, 150, 260, emptybuffer, wxLB_MULTIPLE);
	wxStaticText* lbbLABEL = new wxStaticText(this, wxID_ANY, "Available Battalions");
	lbb = new ListBoxBattalions(battalionmap, this, (int)ID_SINGLE_CONTROL::ID_LBB, 150, 260, emptybuffer, wxLB_SINGLE | wxLB_SORT);

	slpSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* column1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* column2 = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* column3 = new wxBoxSizer(wxVERTICAL);

	column1->Add(slm);
	column1->Add(wm);
	slpSizer->Add(column1);
	column2->Add(lbaslaLABEL);
	column2->Add(lbasla);
	slpSizer->Add(column2);
	column3->Add(lbbLABEL);
	column3->Add(lbb);
	slpSizer->Add(column3);
	SetSizerAndFit(slpSizer);
	//this->Layout();

	Bind(TRANSMIT_SL_SELECTION, &SkillLevelPanel::BounceSLInfo, this, (int)DD_CONTROL::ID_DDSWORD, (int)DD_CONTROL::ID_DDFLYING);
	Bind(TRANSMIT_LBASLA_SELECTION, &SkillLevelPanel::ForwardLBASLASelection, this, (int)ID_SINGLE_CONTROL::ID_LBASLA);
}

void SkillLevelPanel::ReceiveWeaponExclusivity(wxString charactername) {	//forwarded from MyFrame::BounceDDCInfo()
	wm->ReceiveWeaponExclusivity(charactername);
}
//move entire bouncing of slpackage into skilllevelpanel.h from myframe.h
//it would bounce from skilllevelmanager to this function, renamed bounce slinfo
void SkillLevelPanel::BounceSLInfo(wxCommandEvent& eventfromwho) {
	int idofreceiver = eventfromwho.GetInt();
	switch (idofreceiver)
	{
		case (int)ID_SINGLE_CONTROL::ID_LBW: {
			SLPACKAGE* slpackage = dynamic_cast<SLPACKAGE*>(eventfromwho.GetClientObject());
			wm->ReceiveSLInfo(slpackage);
			break;
		}
		case (int)ID_SINGLE_CONTROL::ID_LBASLA: {
			SLPACKAGE* slpackage = dynamic_cast<SLPACKAGE*>(eventfromwho.GetClientObject());
			lbasla->ReceiveSLInfo(slpackage);
			break;
		}
		case (int)ID_SINGLE_CONTROL::ID_LBB: {
			SLPACKAGE* slpackage = dynamic_cast<SLPACKAGE*>(eventfromwho.GetClientObject());
			lbb->ReceiveSLInfo(slpackage);
			break;
		}
	}
}

void SkillLevelPanel::ForwardLBASLASelection(wxCommandEvent& forwarded) {
	wxCommandEvent event(REPEAT_LBASLA_SELECTION, (int)ID_SINGLE_CONTROL::ID_SLP);
	event.SetClientObject(forwarded.GetClientObject());
	ProcessEvent(event);
}
#include <MyFrame.h>

wxDEFINE_EVENT(REPEAT_DDCH_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(REPEAT_DDCL_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(REPEAT_GMT_STATS, wxCommandEvent);
wxDEFINE_EVENT(REPEAT_LBASLA_SELECTION, wxCommandEvent);

wxDEFINE_EVENT(SELECTION_HAS_CHANGED, wxCommandEvent);

wxDEFINE_EVENT(TRANSMIT_LBW_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_LBE_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_LBB_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_DDCH_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_SCL_SELECTION, wxSpinEvent);
wxDEFINE_EVENT(TRANSMIT_DDCL_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_GMT_STATS, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_CHIA_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_CLIA_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_SLA_SELECTION, wxCommandEvent);

MyFrame::MyFrame(wxWindowID id, const wxString& title) : wxFrame(NULL, id, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE | wxMAXIMIZE) {
	
	wxMenu* fileMenu = new wxMenu;
	fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-x"), wxT("Quit this program"));

	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, wxT("&File"));
	SetMenuBar(menuBar);

	wxArrayString emptybuffer;

	std::vector<wxString> battalionnames;
	std::vector<wxString> characternames;
	std::vector<wxString> weaponnames;
	std::vector<wxString> classnames;
	std::vector<wxString> equipnames;
	std::vector<wxString> abilitynames;

	std::vector<wxClientData*> battaliondata;
	std::vector<wxClientData*> characterdata;
	std::vector<wxClientData*> weapondata;
	std::vector<wxClientData*> classdata;
	std::vector<wxClientData*> equipdata;
	std::vector<wxClientData*> abilitydata;

	std::map<wxString, wxClientData*> weaponmap;
	std::map<wxString, wxClientData*> classmap;
	std::map<wxString, wxClientData*> equipmap;
	std::map<wxString, wxClientData*> battalionmap;
	std::map<wxString, wxClientData*> abilitymap;

	UnitList ulist;
	AbilityList alist;

	for (unsigned int i = 0; i < ulist.getSize(); ++i) {
		if (Battalion* temp = dynamic_cast<Battalion*>(ulist[i])) {
			battalionnames.push_back(temp->getName());
			battaliondata.push_back(temp->clone());
		}
	}

	for (unsigned int i = 0; i < ulist.getSize(); ++i) {
		if (Character* temp = dynamic_cast<Character*>(ulist[i])) {
			characternames.push_back(temp->getName());
			characterdata.push_back(temp->clone());
		}
	}

	for (unsigned int i = 0; i < ulist.getSize(); ++i) {
		if (dynamic_cast<Weapon*>(ulist[i])) {
			weaponnames.push_back(ulist[i]->getName());
			DetermineWeaponType(ulist[i], weapondata);
		}
	}

	for (unsigned int i = 0; i < ulist.getSize(); ++i) {
		if (Class* temp = dynamic_cast<Class*>(ulist[i])) {
			classnames.push_back(temp->getName());
			classdata.push_back(temp->clone());
		}
	}

	for (unsigned int i = 0; i < ulist.getSize(); ++i) {
		if (Equipment* temp = dynamic_cast<Equipment*>(ulist[i])) {
			equipnames.push_back(temp->getName());
			equipdata.push_back(temp->clone());
		}
	}

	for (unsigned int i = 0; i < alist.getSize(); ++i) {
		abilitynames.push_back(alist[i]->getName());
		abilitydata.push_back(alist[i]->clone());
	}

	for (int i = 0; i < (int)VARIOUS_SIZE::BATTALION_DATA_SIZE; ++i) {
		battalionmap.emplace(battalionnames[i], battaliondata[i]);
	}

	for (int i = 0; i < (int)VARIOUS_SIZE::WEAPON_DATA_SIZE; ++i) {
		weaponmap.emplace(weaponnames[i], weapondata[i]);
	}

	for (int i = 0; i < (int)VARIOUS_SIZE::CLASS_DATA_SIZE; ++i) {
		classmap.emplace(classnames[i], classdata[i]);
	}

	for (int i = 0; i < (int)VARIOUS_SIZE::EQUIPMENT_DATA_SIZE; ++i) {
		equipmap.emplace(equipnames[i], equipdata[i]);
	}

	for (unsigned int i = 0; i < alist.getSize(); ++i) {
		abilitymap.emplace(abilitynames[i], abilitydata[i]);
	}

	framesizer = new wxBoxSizer(wxHORIZONTAL);
	column1 = new wxBoxSizer(wxVERTICAL);		
	column2 = new wxBoxSizer(wxVERTICAL);
	column3 = new wxBoxSizer(wxHORIZONTAL);	
	column4 = new wxBoxSizer(wxVERTICAL);
	column5 = new wxBoxSizer(wxVERTICAL);

	mt = new MysteriousTeacher(characternames, characterdata, classmap, this, (int)ID_MISC::ID_MT);
	ep = new EquippedPanel(abilitymap, this, (int)ID_SINGLE_CONTROL::ID_EP);	
	slp = new SkillLevelPanel(weaponmap, battalionmap, this, (int)ID_SINGLE_CONTROL::ID_SLP);
	wxStaticText* lbeLABEL = new wxStaticText(this, wxID_ANY, "Available Equipment");
	lbe = new ListBoxEquipment(equipmap, this, (int)ID_SINGLE_CONTROL::ID_LBE, 150, 400, emptybuffer, wxLB_SINGLE | wxLB_SORT);
	sp = new StatsPanel(abilitymap, this, (int)ID_SINGLE_CONTROL::ID_SP);
	column1->Add(mt);	
	column1->Add(sp);
	column2->Add(ep);	
	column3->AddStretchSpacer();
	column4->Add(slp);
	column5->Add(lbeLABEL);
	column5->Add(lbe);
	framesizer->Add(column1);
	framesizer->Add(column2);
	framesizer->Add(column3, 1, wxEXPAND, 0);
	framesizer->Add(column4);
	framesizer->Add(column5);
	this->SetSizer(framesizer);
	this->Layout();

	Bind(REPEAT_DDCH_SELECTION, &MyFrame::BounceRepeatedDDCHSelection_exclusivitycheck, this, (int)ID_MISC::ID_MT);
	Bind(REPEAT_DDCL_SELECTION, &MyFrame::BounceRepeatedDDCLSelection_classinnatecheck, this, (int)ID_MISC::ID_MT);
	Bind(REPEAT_LBASLA_SELECTION, &MyFrame::BounceRepeatedLBASLASelection_updateselabiliities, this, (int)ID_SINGLE_CONTROL::ID_SLP);
	Bind(REPEAT_GMT_STATS, &MyFrame::BounceRepeatedGMTStats_partoftotalstats, this, (int)ID_MISC::ID_MT);
	Bind(TRANSMIT_LBW_SELECTION, &MyFrame::BounceLBWSelection, this, (int)ID_SINGLE_CONTROL::ID_LBW);
	Bind(TRANSMIT_LBE_SELECTION, &MyFrame::BounceLBESelection, this, (int)ID_SINGLE_CONTROL::ID_LBE);
	Bind(TRANSMIT_LBB_SELECTION, &MyFrame::BounceLBBSelection, this, (int)ID_SINGLE_CONTROL::ID_LBB);
	Bind(TRANSMIT_CHIA_SELECTION, &MyFrame::BounceCHIASelection, this, (int)ID_SINGLE_CONTROL::ID_ECHIA);
	Bind(TRANSMIT_CLIA_SELECTION, &MyFrame::BounceCLIASelection, this, (int)ID_SINGLE_CONTROL::ID_AP);
	Bind(TRANSMIT_SLA_SELECTION, &MyFrame::BounceSLASelection, this, (int)ID_SINGLE_CONTROL::ID_AP);
}

void MyFrame::BounceRepeatedDDCHSelection_exclusivitycheck(wxCommandEvent& repititionfromMT) {
	Character* tempcharacter = dynamic_cast<Character*>(repititionfromMT.GetClientObject());
	wxString charactername = tempcharacter->getName();

	slp->ReceiveWeaponExclusivity(charactername);
	ep->ReceiveCharacterInnateExclusivity(charactername);
	lbe->ReceiveEquipmentExclusivity(charactername);
}

void MyFrame::BounceRepeatedDDCLSelection_classinnatecheck(wxCommandEvent& repititionfromMT) {
	Class* tempclass = dynamic_cast<Class*>(repititionfromMT.GetClientObject());
	wxString classinnatecheck = tempclass->getName();
	ep->ReceiveClassInnateExclusivity(classinnatecheck);
}
void MyFrame::BounceRepeatedLBASLASelection_updateselabiliities(wxCommandEvent& repititionfromSLP) {
	AbilitySelections* tempselections = dynamic_cast<AbilitySelections*>(repititionfromSLP.GetClientObject());
	ep->ReceiveSLASelections(tempselections);
}

void MyFrame::BounceRepeatedGMTStats_partoftotalstats(wxCommandEvent& repititionfromMT) {
	Stats* tempGMTstats = dynamic_cast<Stats*>(repititionfromMT.GetClientObject());
	sp->ReceiveGMTStats(*tempGMTstats);
}

void MyFrame::BounceLBWSelection(wxCommandEvent& selection) {
	Weapon* tempweapon = dynamic_cast<Weapon*>(selection.GetClientObject());
	Stats tempstats = tempweapon->getStats();
	wxString tempname = tempweapon->getName();
	WEAPONTYPE tempweapontype = tempweapon->getWeaponType();
	sp->ReceiveLBWSelection(tempstats, tempweapontype);
	ep->ReceiveLBWSelection(tempname);
}

void MyFrame::BounceLBESelection(wxCommandEvent& selection) {
	Equipment* tempequipment = dynamic_cast<Equipment*>(selection.GetClientObject());
	Stats tempstats = tempequipment->getStats();
	wxString tempname = tempequipment->getName();
	wxString description = tempequipment->getDescription();
	sp->ReceiveLBESelection(tempstats);
	ep->ReceiveLBESelection(tempname, description);
}

void MyFrame::BounceLBBSelection(wxCommandEvent& selection) {
	Battalion* tempbattalion = dynamic_cast<Battalion*>(selection.GetClientObject());
	Stats tempstats = tempbattalion->getStats();
	wxString tempname = tempbattalion->getName();
	sp->ReceiveLBBSelection(tempstats);
	ep->ReceiveLBBSelection(tempname);
}
void MyFrame::BounceCHIASelection(wxCommandEvent& selection) {
	wxString tempstring = selection.GetString();
	sp->ReceiveCHIASelection(tempstring);
}

void MyFrame::BounceCLIASelection(wxCommandEvent& selection) {
	AbilitySelections* testing = dynamic_cast<AbilitySelections*>(selection.GetClientObject());
	std::vector<wxString> testing2 = testing->GetSelections();
	sp->ReceiveCLIASelection(testing2);
}

void MyFrame::BounceSLASelection(wxCommandEvent& selection) {
	AbilitySelections* testing = dynamic_cast<AbilitySelections*>(selection.GetClientObject());
	std::vector<wxString> testing2 = testing->GetSelections();
	sp->ReceiveSLASelection(testing2);
}

void MyFrame::DetermineWeaponType(Unit* unit, std::vector<wxClientData*>& weapondata) {
	if (BlankWeapon* temp = dynamic_cast<BlankWeapon*>(unit)) {
		weapondata.push_back(temp->clone());
	}
	if (Axe* temp = dynamic_cast<Axe*>(unit)) {
		weapondata.push_back(temp->clone());
	}
	if (BlackMagic* temp = dynamic_cast<BlackMagic*>(unit)) {
		weapondata.push_back(temp->clone());
	}
	if (Bow* temp = dynamic_cast<Bow*>(unit)) {
		weapondata.push_back(temp->clone());
	}
	if (DarkMagic* temp = dynamic_cast<DarkMagic*>(unit)) {
		weapondata.push_back(temp->clone());
	}
	if (Gauntlets* temp = dynamic_cast<Gauntlets*>(unit)) {
		weapondata.push_back(temp->clone());
	}
	if (Lance* temp = dynamic_cast<Lance*>(unit)) {
		weapondata.push_back(temp->clone());
	}
	if (Sword* temp = dynamic_cast<Sword*>(unit)) {
		weapondata.push_back(temp->clone());
	}
	if (WhiteMagic* temp = dynamic_cast<WhiteMagic*>(unit)) {
		weapondata.push_back(temp->clone());
	}
}

void MyFrame::OnQuit(wxCommandEvent& event) {
	Close();
}

void MyFrame::OnSize(wxSizeEvent& event) {
	if (ep) {
		ep->Fit();
	}
	if (sp) {
		sp->Fit();
	}

	wxSize test = this->GetMinSize();
	event.Skip();
}

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_SIZE(MyFrame::OnSize)
wxEND_EVENT_TABLE()
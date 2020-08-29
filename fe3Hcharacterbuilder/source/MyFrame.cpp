#include <MyFrame.h>

wxAuiManager* MyFrame::wxam;

wxDEFINE_EVENT(REPEAT_DDCH_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(REPEAT_DDCL_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(REPEAT_GMT_STATS, wxCommandEvent);

wxDEFINE_EVENT(SELECTION_HAS_CHANGED, wxCommandEvent);

wxDEFINE_EVENT(TRANSMIT_GWS_STATS, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_GES_STATS, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_GBS_STATS, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_LBW_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_LBE_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_LBB_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_SL_SELECTION, wxCommandEvent);

wxDEFINE_EVENT(TRANSMIT_DDCH_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_SCL_SELECTION, wxSpinEvent);
wxDEFINE_EVENT(TRANSMIT_DDCL_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_GMT_STATS, wxCommandEvent);

MyFrame::MyFrame(wxWindowID id, const wxString& title) : wxFrame(NULL, id, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE | wxMAXIMIZE) {
	
	wxMenu* fileMenu = new wxMenu;
	fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-x"), wxT("Quit this program"));

	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, wxT("&File"));
	SetMenuBar(menuBar);

	wxArrayString emptybuffer;
	const wxArrayString buffer{};

	std::vector<wxString> battalionnames;
	std::vector<wxString> characternames;
	std::vector<wxString> weaponnames;
	std::vector<wxString> classnames;
	std::vector<wxString> equipnames;
	std::vector<wxClientData*> battaliondata;
	std::vector<wxClientData*> characterdata;
	std::vector<wxClientData*> weapondata;
	std::vector<wxClientData*> classdata;
	std::vector<wxClientData*> equipdata;
	std::map<wxString, wxClientData*> weaponmap;
	std::map<wxString, wxClientData*> classmap;
	std::map<wxString, wxClientData*> equipmap;
	std::map<wxString, wxClientData*> battalionmap;
	UnitList ulist;

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

	for (int i = 0; i < (int)VARIOUS_SIZE::BATTALION_DATA_SIZE; ++i) {
		battalionmap.emplace(battalionnames[i], battaliondata[i]);
	}

	for (int i = 0; i < (int)VARIOUS_SIZE::WEAPON_DATA_SIZE; ++i) {
		auto happened = weaponmap.emplace(weaponnames[i], weapondata[i]);
		int k = 9;
	}

	for (int i = 0; i < (int)VARIOUS_SIZE::CLASS_DATA_SIZE; ++i) {
		classmap.emplace(classnames[i], classdata[i]);
	}

	for (int i = 0; i < (int)VARIOUS_SIZE::EQUIPMENT_DATA_SIZE; ++i) {
		equipmap.emplace(equipnames[i], equipdata[i]);
	}

	framesizer = new wxBoxSizer(wxHORIZONTAL);
	column1 = new wxBoxSizer(wxVERTICAL);	
	mt = new MysteriousTeacher(characternames, characterdata, classmap, this, (int)ID_MISC::ID_MT);
	ep = new EquippedPanel(this, (int)ID_SINGLE_CONTROL::ID_EP);
	column1->Add(mt);	
	column1->Add(ep);
	framesizer->Add(column1);
	this->SetSizer(framesizer);

	//column1->Add(gbs);
	//column1->Add(sizerforbcp);
	//sizerforbcp->Add(ptrforaddingsizer);
	//column2 = new wxBoxSizer(wxVERTICAL);
	//column3 = new wxBoxSizer(wxHORIZONTAL);
	//column4 = new wxBoxSizer(wxHORIZONTAL);
	//mainrow->Add(column2);
	//mainrow->Add(column3);
	//mainrow->Add(column4);

	//gws = new GridWeaponStats(this, (int)ID_SINGLE_CONTROL::ID_GWS);
	//ges = new GridEquipmentStats(this, (int)ID_SINGLE_CONTROL::ID_GES);
	//gts = new GridTotalStats(this, (int)ID_SINGLE_CONTROL::ID_GTS);
	lbw = new ListBoxWeapons(weaponmap, this, (int)ID_SINGLE_CONTROL::ID_LBW, 150, 400, emptybuffer, wxLB_SINGLE | wxLB_SORT | wxLB_ALWAYS_SB);
	lbe = new ListBoxEquipment(equipmap, this, (int)ID_SINGLE_CONTROL::ID_LBE, 150, 400, emptybuffer, wxLB_SINGLE | wxLB_SORT);
	lbb = new ListBoxBattalions(battalionmap, this, (int)ID_SINGLE_CONTROL::ID_LBB, 150, 400, emptybuffer, wxLB_SINGLE | wxLB_SORT);
	lbasla = new ListBoxASLA(this, (int)ID_SINGLE_CONTROL::ID_LBASLA, 0, 0, 150, 400, buffer, wxLB_MULTIPLE);
	//echia = new EquippedCharInnateAbility(this, (int)ID_SINGLE_CONTROL::ID_ECHIA, 150, 50);
	//eclia = new EquippedClassInnateAbility(this, (int)ID_SINGLE_CONTROL::ID_ECLIA, 150, 50);
	//esla = new EquippedSkillLvlAbilities(this, (int)ID_SINGLE_CONTROL::ID_ESLA, 150, 150);
	//slm = new SkillLevelManager(this, (int)ID_SINGLE_CONTROL::ID_SLM);
	//column1->Add(gws);
	//column1->Add(ges);
	//column1->Add(gbs);
	//column1->Add(gts);	
	//column2->Add(echia);
	//column2->Add(eclia);
	//column2->Add(esla);
	//column4->Add(slm);
	this->Layout();

	wxam = new wxAuiManager(this);
	wxam->AddPane(lbasla, wxRIGHT, wxT("Available Abilities"));
	wxam->AddPane(lbw, wxRIGHT, wxT("Available Weapons"));
	wxam->AddPane(lbe, wxRIGHT, wxT("Available Equipment"));
	wxam->AddPane(lbb, wxRIGHT, wxT("Available Battalions"));

	wxam->Update();
	Bind(REPEAT_DDCH_SELECTION, &MyFrame::BounceRepeatedDDCHSelection_exclusivitycheck, this, (int)ID_MISC::ID_MT);
	Bind(REPEAT_DDCL_SELECTION, &MyFrame::BounceRepeatedDDCLSelection_classinnatecheck, this, (int)ID_MISC::ID_MT);
	Bind(REPEAT_GMT_STATS, &MyFrame::BounceRepeatedGMTStats_partoftotalstats, this, (int)ID_MISC::ID_MT);

	Bind(TRANSMIT_LBW_SELECTION, &MyFrame::BounceLBWSelection, this, (int)ID_SINGLE_CONTROL::ID_LBW);
	Bind(TRANSMIT_LBE_SELECTION, &MyFrame::BounceLBESelection, this, (int)ID_SINGLE_CONTROL::ID_LBE);
	Bind(TRANSMIT_LBB_SELECTION, &MyFrame::BounceLBBSelection, this, (int)ID_SINGLE_CONTROL::ID_LBB);
	Bind(TRANSMIT_GWS_STATS, &MyFrame::BounceGWSStats_partoftotalstats, this, (int)ID_SINGLE_CONTROL::ID_GWS);
	Bind(TRANSMIT_GES_STATS, &MyFrame::BounceGESStats_partoftotalstats, this, (int)ID_SINGLE_CONTROL::ID_GES);
	Bind(TRANSMIT_GBS_STATS, &MyFrame::BounceGBSStats_partoftotalstats, this, (int)ID_SINGLE_CONTROL::ID_GBS);
	Bind(TRANSMIT_SL_SELECTION, &MyFrame::BounceSLInfo, this, (int)DD_CONTROL::ID_DDSWORD, (int)DD_CONTROL::ID_DDFLYING);
}

void MyFrame::BounceRepeatedDDCHSelection_exclusivitycheck(wxCommandEvent& repititionfromMT) {
	Character* tempcharacter = dynamic_cast<Character*>(repititionfromMT.GetClientObject());
	wxString exclusivitycheck = tempcharacter->getName();

	lbw->ReceiveExclusivity(exclusivitycheck);
	lbe->ReceiveExclusivity(exclusivitycheck);
	echia->ReceiveExclusivity(exclusivitycheck);
}

void MyFrame::BounceRepeatedDDCLSelection_classinnatecheck(wxCommandEvent& repititionfromMT) {
	Class* tempclass = dynamic_cast<Class*>(repititionfromMT.GetClientObject());
	wxString classinnatecheck = tempclass->getName();
	eclia->ReceiveClassInnate(classinnatecheck);
}

void MyFrame::BounceRepeatedGMTStats_partoftotalstats(wxCommandEvent& repititionfromMT) {
	Stats* tempGMTstats = dynamic_cast<Stats*>(repititionfromMT.GetClientObject());
	gts->ReceiveGMTStats(*tempGMTstats);
}

void MyFrame::BounceLBWSelection(wxCommandEvent& selection) {
	Weapon* tempweapon = dynamic_cast<Weapon*>(selection.GetClientObject());
	Stats tempstats = tempweapon->getStats();
	//gws->ReceiveLBWSelection(tempstats);
}

void MyFrame::BounceLBESelection(wxCommandEvent& selection) {
	Equipment* tempequipment = dynamic_cast<Equipment*>(selection.GetClientObject());
	//std::vector<Stat> tempstats((int)VARIOUS_SIZE::TOTAL_STATS_SIZE, Stat(L"0"));
	Stats tempstats = tempequipment->getStats();
	//tempstats[6] = selectionstats[0].getText();
	//tempstats[7] = selectionstats[1].getText();
	//Stats transferthis{ tempstats };

	ges->ReceiveLBESelection(tempstats);
}

void MyFrame::BounceLBBSelection(wxCommandEvent& selection) {
	Battalion* tempbattalion = dynamic_cast<Battalion*>(selection.GetClientObject());
	Stats tempstats = tempbattalion->getStats();
	//gbs->ReceiveLBBSelection(tempstats);
}

void MyFrame::BounceGWSStats_partoftotalstats(wxCommandEvent& eventfromGWS) {
	Stats* temp = dynamic_cast<Stats*>(eventfromGWS.GetClientObject());
	gts->ReceiveGWSStats(*temp);
}

void MyFrame::BounceGESStats_partoftotalstats(wxCommandEvent& eventfromGES) {
	Stats* temp = dynamic_cast<Stats*>(eventfromGES.GetClientObject());
	gts->ReceiveGESStats(*temp);
}

void MyFrame::BounceGBSStats_partoftotalstats(wxCommandEvent& eventfromGBS) {
	Stats* temp = dynamic_cast<Stats*>(eventfromGBS.GetClientObject());
	gts->ReceiveGBSStats(*temp);
}

void MyFrame::BounceSLInfo(wxCommandEvent& eventfromwho) {
	int idofreceiver = eventfromwho.GetInt();
	switch (idofreceiver)
	{
		case (int)ID_SINGLE_CONTROL::ID_LBW: {
			SLPACKAGE* slpackage = dynamic_cast<SLPACKAGE*>(eventfromwho.GetClientObject());
			lbw->ReceiveSLInfo(slpackage);
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
	wxSize test = this->GetMinSize();
	event.Skip();
}

void MyFrame::OnCollPaneChange(wxCollapsiblePaneEvent& event) {
	wxSize test = this->GetMinSize();
	//bcp->SetMinSize(test);
	//mainrow->Fit(this);
	event.Skip();
}

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_COMBOBOX((int)ID_MISC::ID_DDCH, DropDownCharacters::OnNewSelection)
	EVT_SIZE(MyFrame::OnSize)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_BCP, MyFrame::OnCollPaneChange)
	EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_WCP, MyFrame::OnCollPaneChange)
wxEND_EVENT_TABLE()

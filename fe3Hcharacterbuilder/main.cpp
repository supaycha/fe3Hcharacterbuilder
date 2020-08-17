#include "main.h"
#include <vld.h>

wxDEFINE_EVENT(TRANSMIT_DDCH_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_SCL_SELECTION, wxSpinEvent);
wxDEFINE_EVENT(TRANSMIT_DDCL_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_GMT_STATS, wxCommandEvent);

wxDEFINE_EVENT(REPEAT_DDCH_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(REPEAT_DDCL_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(REPEAT_GMT_STATS, wxCommandEvent);

wxDEFINE_EVENT(TRANSMIT_LBW_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_LBE_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_LBB_SELECTION, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_GWS_STATS, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_GES_STATS, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_GBS_STATS, wxCommandEvent);
wxDEFINE_EVENT(TRANSMIT_SL_SELECTION, wxCommandEvent);

wxDEFINE_EVENT(SELECTION_HAS_CHANGED, wxCommandEvent);

void DetermineWeaponType(Unit* unit, std::vector<wxClientData*>& weapondata);
wxArrayString ToArrayString(std::vector<wxString> names);
wxClientData** ToArrayData(std::vector<wxClientData*>& names);
std::map<wxString, int> ToMapString(std::vector<wxString> names);
void** ToVoidData(std::vector<wxClientData*> ptrs);
std::map<wxString, wxClientData*> ToMapBoth(std::vector<wxString> names, std::vector<wxClientData*> data);

void DetermineWeaponType(Unit* unit, std::vector<wxClientData*>& weapondata) {
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
wxArrayString ToArrayString(std::vector<wxString> names) {
	wxArrayString temparraystring;
	for (auto name : names) {
		temparraystring.Add(name);
	}

	return temparraystring;
}
wxClientData** ToArrayData(std::vector<wxClientData*>& ptrs) {
	int size = ptrs.size();
	wxClientData** temparraydata = new wxClientData * [size];
	for (int i = 0; i < size; ++i) {
		temparraydata[i] = ptrs[i];
	}

	return temparraydata;
}
std::map<wxString, int> ToMapString(std::vector<wxString> names) {
	std::map<wxString, int> tempmap;
	for (auto name : names) {
		tempmap.emplace(name, 0);
	}

	return tempmap;
}
void** ToVoidData(std::vector<wxClientData*> ptrs) {
	int size = ptrs.size();
	void** temparraydata = new void* [size];
	for (int i = 0; i < size; ++i) {
		temparraydata[i] = ptrs[i];
	}

	return temparraydata;
}
std::map<wxString, wxClientData*> ToMapBoth(std::vector<wxString> names, std::vector<wxClientData*> data) {
	std::map<wxString, wxClientData*> temp;

	for (unsigned int i = 0; i < names.size(); ++i) {
		temp.emplace(names[i], data[i]);
	}

	return temp;
}

bool MyApp::OnInit() {
	MyFrame* frame = new MyFrame(ID_FRAME, wxT("feBuilder"));

	frame->InitDialog();
	frame->Show(true);
	return true;
}

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
	
	for (int i = 0; i < BATTALION_DATA_SIZE; ++i) {
		battalionmap.emplace(battalionnames[i], battaliondata[i]);
	}

	for (int i = 0; i < WEAPON_DATA_SIZE; ++i) {
		weaponmap.emplace(weaponnames[i], weapondata[i]);
	}

	for (int i = 0; i < CLASS_DATA_SIZE; ++i) {
		classmap.emplace(classnames[i], classdata[i]);
	}

	for (int i = 0; i < EQUIPMENT_DATA_SIZE; ++i) {
		equipmap.emplace(equipnames[i], equipdata[i]);
	}

	Buildersizer = new wxBoxSizer(wxHORIZONTAL);
	MTandGridStats_col = new wxBoxSizer(wxVERTICAL);
	lbsizer = new wxBoxSizer(wxHORIZONTAL);
	slablsizer = new wxBoxSizer(wxHORIZONTAL);

	gws = new GridWeaponStats(this, ID_GWS);
	ges = new GridEquipmentStats(this, ID_GES);
	gbs = new GridBattalionStats(this, ID_GBS);
	gts = new GridTotalStats(this, ID_GTS);		
	mt = new MysteriousTeacher(characternames, characterdata, classmap, this, ID_MT);

	am = new AbilityManager(this, ID_AM);
	slm = new SkillLevelManager(this, ID_SLM);

	wxBoxSizer* lbesizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* lbwsizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* lbbsizer = new wxBoxSizer(wxVERTICAL);

	lbw = new ListBoxWeapons(weaponmap, this, ID_LBW, 150, 400, emptybuffer, wxLB_SINGLE | wxLB_SORT);
	lbe = new ListBoxEquipment(equipmap, this, ID_LBE, 150, 400, emptybuffer, wxLB_SINGLE | wxLB_SORT);	
	lbb = new ListBoxBattalions(battalionmap, this, ID_LBB, 150, 400, emptybuffer, wxLB_SINGLE | wxLB_SORT);

	lbwsizer->Add(lbw);
	lbesizer->Add(lbe);
	lbbsizer->Add(lbb);

	gridstatssizer = new wxBoxSizer(wxVERTICAL);

	gridstatssizer->Add(gws);
	gridstatssizer->Add(ges);
	gridstatssizer->Add(gbs);
	gridstatssizer->Add(gts);
	MTandGridStats_col->Add(mt);
	MTandGridStats_col->Add(gridstatssizer);

	lbsizer->Add(lbesizer);
	lbsizer->Add(lbwsizer);
	lbsizer->Add(lbbsizer);

	slablsizer->Add(am);
	slablsizer->Add(slm);

	Buildersizer->Add(MTandGridStats_col);
	Buildersizer->Add(lbsizer);
	Buildersizer->Add(slablsizer);

	this->SetSizerAndFit(Buildersizer);
	Bind(REPEAT_DDCH_SELECTION, &MyFrame::BounceRepeatedDDCHSelection_exclusivitycheck, this, ID_MT);
	Bind(REPEAT_DDCL_SELECTION, &MyFrame::BounceRepeatedDDCLSelection_classinnatecheck, this, ID_MT);
	Bind(REPEAT_GMT_STATS,		&MyFrame::BounceRepeatedGMTStats_partoftotalstats,		 this, ID_MT);

	Bind(TRANSMIT_LBW_SELECTION, &MyFrame::BounceLBWSelection, this, ID_LBW);
	Bind(TRANSMIT_LBE_SELECTION, &MyFrame::BounceLBESelection, this, ID_LBE);
	Bind(TRANSMIT_LBB_SELECTION, &MyFrame::BounceLBBSelection, this, ID_LBB);
	Bind(TRANSMIT_GWS_STATS, &MyFrame::BounceGWSStats_partoftotalstats, this, ID_GWS);
	Bind(TRANSMIT_GES_STATS, &MyFrame::BounceGESStats_partoftotalstats, this, ID_GES);
	Bind(TRANSMIT_GBS_STATS, &MyFrame::BounceGBSStats_partoftotalstats, this, ID_GBS);
	Bind(TRANSMIT_SL_SELECTION, &MyFrame::BounceSLInfo, this, ID_DDSWORD, ID_DDFLYING);
}

void MyFrame::BounceRepeatedDDCHSelection_exclusivitycheck(wxCommandEvent& repititionfromMT) {
	Character* tempcharacter = dynamic_cast<Character*>(repititionfromMT.GetClientObject());
	wxString exclusivitycheck = tempcharacter->getName();
	lbw->ReceiveExclusivity(exclusivitycheck);
	lbe->ReceiveExclusivity(exclusivitycheck);
	am->ReceiveExclusivity(exclusivitycheck);
}

void MyFrame::BounceRepeatedDDCLSelection_classinnatecheck(wxCommandEvent& repititionfromMT) {
	Class* tempclass = dynamic_cast<Class*>(repititionfromMT.GetClientObject());
	wxString classinnatecheck = tempclass->getName();
	am->ReceiveClassInnate(classinnatecheck);
}

void MyFrame::BounceRepeatedGMTStats_partoftotalstats(wxCommandEvent& repititionfromMT) {
	Stats* tempGMTstats = dynamic_cast<Stats*>(repititionfromMT.GetClientObject());
	gts->ReceiveGMTStats(*tempGMTstats);
}

void MyFrame::BounceLBWSelection(wxCommandEvent& selection) {
	Weapon* tempweapon = dynamic_cast<Weapon*>(selection.GetClientObject());
	Stats tempstats = tempweapon->getStats();
	gws->ReceiveLBWSelection(tempstats);
}

void MyFrame::BounceLBESelection(wxCommandEvent& selection) {
	Equipment* tempequipment = dynamic_cast<Equipment*>(selection.GetClientObject());
	std::vector<Stat> tempstats(TOTAL_STATS_SIZE, Stat(L"0"));
	Stats selectionstats = tempequipment->getStats();
	tempstats[6] = selectionstats[0].getText();
	tempstats[7] = selectionstats[1].getText();
	Stats transferthis{ tempstats };

	ges->ReceiveLBESelection(tempstats);
}

void MyFrame::BounceLBBSelection(wxCommandEvent& selection) {
	Battalion* tempbattalion = dynamic_cast<Battalion*>(selection.GetClientObject());
	Stats tempstats = tempbattalion->getStats();
	gbs->ReceiveLBBSelection(tempstats);
}

void MyFrame::BounceGWSStats_partoftotalstats(wxCommandEvent& eventfromGWS){
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
		case ID_LBW: {
			SLPACKAGE* slpackage = dynamic_cast<SLPACKAGE*>(eventfromwho.GetClientObject());
			lbw->ReceiveSLInfo(slpackage);
			break;
		}
		case ID_AM: {
			SLPACKAGE* slpackage = dynamic_cast<SLPACKAGE*>(eventfromwho.GetClientObject());
			am->ReceiveSLInfo(slpackage);
			break;
		}
		case ID_LBB: {
			SLPACKAGE* slpackage = dynamic_cast<SLPACKAGE*>(eventfromwho.GetClientObject());
			lbb->ReceiveSLInfo(slpackage);
			break;
		}
	}
}

void MyFrame::OnQuit(wxCommandEvent& event) {
	Close();
}

MysteriousTeacher::MysteriousTeacher(std::vector<wxString> characternames, std::vector<wxClientData*> characterdata, std::map<wxString, wxClientData*> classmap, MyFrame* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	gmt = new GridMysteriousTeacher(this, ID_GMT, 0);
	gmt->SetMargins(0, 0);

	wxArrayString emptybuffer;
	ddc = new DropDownCharacters(characternames, characterdata, this, ID_DDCH, emptybuffer, wxCB_DROPDOWN | wxCB_READONLY);
	
	wxString test = "1";
	for (int i = 0; i < 2; ++i) {
		sclVector.push_back(new SpinCtrlLevel(this, ID_SPIN1 + i, test, 1));
	}

	for (int i = 0; i < 3; ++i) {
		ddclVector.push_back(new DropDownClasses(classmap, this, ID_DDCL1 + i, emptybuffer, wxCB_DROPDOWN | wxCB_READONLY | wxCB_SORT));
	}

	total = new wxBoxSizer(wxHORIZONTAL);
	for (int i = 0; i < 3; ++i) {
		columns.push_back(new wxBoxSizer(wxVERTICAL));
	}

	int offset = 3;

	columns[0]->AddSpacer(gmt->GetRowHeight(0));
	columns[0]->AddSpacer(gmt->GetRowHeight(0));
	columns[0]->AddSpacer(gmt->GetRowHeight(0));
	columns[0]->AddSpacer(gmt->GetRowHeight(0));
	columns[0]->Add(sclVector[0]);
	columns[0]->AddSpacer(gmt->GetRowHeight(0));
	columns[0]->Add(sclVector[1]);
	columns[0]->AddSpacer(gmt->GetRowHeight(0));
	columns[0]->AddSpacer(gmt->GetRowHeight(0));

	columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->Add(ddc);
	columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->Add(ddclVector[0], 0, wxEXPAND, 0);
	columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->Add(ddclVector[1], 0, wxEXPAND, 0);
	columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->Add(ddclVector[2], 0, wxEXPAND, 0);

	columns[2]->Add(gmt);

	for (unsigned int i = 0; i < columns.size(); ++i) {
		total->Add(columns[i]);
	}

	SetSizerAndFit(total);
	Bind(TRANSMIT_DDCH_SELECTION, &MysteriousTeacher::BounceDDCHSelection, this, ID_DDCH);
	Bind(TRANSMIT_SCL_SELECTION, &MysteriousTeacher::BounceSCLSelection, this, ID_SPIN1, ID_SPIN2);
	Bind(TRANSMIT_DDCL_SELECTION, &MysteriousTeacher::BounceDDCLSelection, this, ID_DDCL1, ID_DDCL3);
	Bind(TRANSMIT_GMT_STATS, &MysteriousTeacher::ForwardGMTStats, this, ID_GMT);
}

void MysteriousTeacher::BounceDDCHSelection(wxCommandEvent& transmission) {
	wxCommandEvent repetition (REPEAT_DDCH_SELECTION, ID_MT);
	repetition.SetClientObject(transmission.GetClientObject());
	ProcessEvent(repetition);

	Character* tempcharacter = dynamic_cast<Character*>(transmission.GetClientObject());
	gmt->UpdateDDCHSelection(*tempcharacter);

	wxString exclusivitycheck = tempcharacter->getName();
	for (unsigned int i = 0; i < ddclVector.size(); ++i) {
		ddclVector[i]->ReceiveExclusivity(exclusivitycheck);
	}
}

void MysteriousTeacher::BounceSCLSelection(wxSpinEvent& transmission) {
	switch (transmission.GetId()) {
		case ID_SPIN1: {
			int templevel = transmission.GetInt();
			gmt->UpdateSCLSelection(templevel, ID_SPIN1);

			break;
		}

		case ID_SPIN2: {
			int templevel = transmission.GetInt();
			gmt->UpdateSCLSelection(templevel, ID_SPIN2);

			break;
		}
	}
}

void MysteriousTeacher::BounceDDCLSelection(wxCommandEvent& transmission) {
	wxCommandEvent repetition(REPEAT_DDCL_SELECTION, ID_MT);
	repetition.SetClientObject(transmission.GetClientObject());
	ProcessEvent(repetition);

	Class* tempclass = dynamic_cast<Class*>(transmission.GetClientObject());
	switch (transmission.GetId()) {
		case ID_DDCL1: {
			//Class* tempclass = dynamic_cast<Class*>(transmission.GetClientObject());
			gmt->UpdateDDCLSelection(*tempclass, ID_DDCL1);
			break;
		}

		case ID_DDCL2: {
			//Class* tempclass = dynamic_cast<Class*>(transmission.GetClientObject());
			gmt->UpdateDDCLSelection(*tempclass, ID_DDCL2);
			break;
		}

		case ID_DDCL3: {
			//Class* tempclass = dynamic_cast<Class*>(transmission.GetClientObject());
			gmt->UpdateDDCLSelection(*tempclass, ID_DDCL3);
			break;
		}
	}
}

void MysteriousTeacher::ForwardGMTStats(wxCommandEvent& forwarded) {
	wxCommandEvent event(REPEAT_GMT_STATS, ID_MT);
	event.SetClientObject(forwarded.GetClientObject());
	ProcessEvent(event);
}

DropDownCharacters::DropDownCharacters(std::vector<wxString> characternames, std::vector<wxClientData*> characterdata, wxWindow* panel,
	wxWindowID id, const wxArrayString& choices, long style) :
	wxComboBox(panel, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, choices, style)
{
	this->Append(ToArrayString(characternames), ToArrayData(characterdata));
	this->SetSelection(0);

	wxCommandEvent eventtoself(wxEVT_COMBOBOX, ID_DDCH);
	eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	ProcessEvent(eventtoself);
}

void DropDownCharacters::OnNewSelection(wxCommandEvent& selection) {
	wxCommandEvent event(TRANSMIT_DDCH_SELECTION, ID_DDCH);
	event.SetClientObject(selection.GetClientObject());
	ProcessEvent(event);
}

SpinCtrlLevel::SpinCtrlLevel(wxWindow* parent, wxWindowID id, const wxString& value, int min) :
	wxSpinCtrl(parent, id, value, wxDefaultPosition, wxDefaultSize, min)
{
	Bind(wxEVT_SPINCTRL, &SpinCtrlLevel::OnNewSelection, this, ID_SPIN1, ID_SPIN2);
}

void SpinCtrlLevel::OnNewSelection(wxSpinEvent& selection) {
	wxSpinEvent event(TRANSMIT_SCL_SELECTION, selection.GetId());
	int selectedvalue = selection.GetValue();
	event.SetInt(selectedvalue);
	ProcessEvent(event);
}

DropDownClasses::DropDownClasses(std::map<wxString, wxClientData*> uclassmap, wxWindow* panel, wxWindowID id, const wxArrayString& choices, long style) :
	wxComboBox(panel, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, choices, style)
{
	classmap = uclassmap;
	auto iter = classmap.begin();

	std::vector<wxString> firstname;
	std::vector<wxClientData*> firstdata;

	firstname.push_back(iter->first);
	Class* temp = dynamic_cast<Class*>(iter->second)->clone();
	firstdata.push_back(dynamic_cast<wxClientData*>(temp));
	this->Set(ToArrayString(firstname), ToArrayData(firstdata));

	this->SetSelection(0);
	wxCommandEvent eventtoself(wxEVT_COMBOBOX, this->GetId());
	eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	ProcessEvent(eventtoself);
}

void DropDownClasses::OnNewSelection(wxCommandEvent& selection) {
	wxCommandEvent event(TRANSMIT_DDCL_SELECTION, selection.GetId());
	event.SetClientObject(selection.GetClientObject());
	ProcessEvent(event);
}

void DropDownClasses::ReceiveExclusivity(wxString charactername) {
	currentDDCSelection = charactername;
	repopulate();
}

void DropDownClasses::repopulate() {
	std::vector<Class*> exclusiveclasses;
	std::vector<Class*> generalclasses;
	std::vector<wxString> classnames;
	std::vector<wxClientData*> classdata;

	for (auto element : classmap) {
		Class* temp = dynamic_cast<Class*>(element.second)->clone();
		if (temp->getExclusivity()) {
			exclusiveclasses.push_back(temp);
		}
		else {
			generalclasses.push_back(temp);
		}
	}

	for (auto cLass : exclusiveclasses) {
		std::wstring characternames = cLass->getCharacterName(), buffer;
		std::wstringstream stream(characternames);
		std::vector<std::wstring> namesfromstream;

		while (std::getline(stream, buffer, L',')) {
			namesfromstream.push_back(buffer);
		}

		for (auto possiblematch : namesfromstream) {
			if (currentDDCSelection == possiblematch) {
				classnames.push_back(cLass->getName());
				classdata.push_back(dynamic_cast<wxClientData*>(cLass));
			}
		}
	}

	for (auto cLass : generalclasses) {
		classnames.push_back(cLass->getName());
		classdata.push_back(dynamic_cast<wxClientData*>(cLass));
	}

	mostrecentDDCLselection = GetStringSelection();
	this->Set(ToArrayString(classnames), ToArrayData(classdata));
	DetermineSelectionStatus();
}

void DropDownClasses::DetermineSelectionStatus() {
	if (CompareAllStrings()) {
		int index = this->FindString(mostrecentDDCLselection);
		this->SetSelection(index);
		wxCommandEvent eventtoself(wxEVT_COMBOBOX, this->GetId());
		eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
		ProcessEvent(eventtoself);
	}

	else if (!CompareAllStrings()) {
		int index = this->FindString("---");
		this->SetSelection(index);
		wxCommandEvent eventtoself(wxEVT_COMBOBOX, this->GetId());
		eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
		ProcessEvent(eventtoself);
	}
}

bool DropDownClasses::CompareAllStrings() {
	wxArrayString currentclassselections = this->GetStrings();

	for (auto classname : currentclassselections) {
		if (classname == mostrecentDDCLselection) {
			return true;
		}
	}

	return false;
}

GridMysteriousTeacher::GridMysteriousTeacher(wxWindow* parent, wxWindowID id, bool hidecolheaders) :
	wxGrid(parent, id)
{
	gtbmt = new GTBMysteriousTeacher;

	CreateGrid(8, 10);	
	SetDefaultRowSize(MIN_HEIGHT_OF_COMBOBOX);
	SetDefaultColSize(SET_LENGTH_OF_COLUMNS);
	SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
	EnableEditing(false);
	DisableDragGridSize();

	for (unsigned int i = 0; i < 10; ++i) {
		SetColLabelValue(i, gtbmt->GetHeader(i));

	}
	SetUseNativeColLabels(true);

	if (hidecolheaders) {
		SetColLabelSize(0);
	}

	SetRowLabelSize(0);
	initpopulate();
}

void GridMysteriousTeacher::initpopulate() {
	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		SetCellValue(0, i, L"0");
		int k = 0;
	}
}

void GridMysteriousTeacher::repopulate() {
	wxGridCellFloatRenderer* testerlulz = new wxGridCellFloatRenderer(3, 2);
	std::vector<Stat> tempvectforstats;
	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue(0, i);
		SetCellValue(0, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue2(0, i);
		SetCellValue(1, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue3(0, i);
		SetCellRenderer(2, i, testerlulz->Clone());
		SetCellAlignment(2, i, wxALIGN_CENTER, wxALIGN_CENTER);
		SetCellValue(2, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue4(0, i);
		SetCellValue(3, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue5(0, i);
		SetCellRenderer(4, i, testerlulz->Clone());
		SetCellAlignment(4, i, wxALIGN_CENTER, wxALIGN_CENTER);
		SetCellValue(4, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue6(0, i);
		SetCellValue(5, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue7(0, i);
		SetCellValue(6, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue8(0, i);
		SetCellValue(7, i, stattoset);
		tempvectforstats.push_back(Stat(stattoset));
	}

	Stats* ptrtostats = new Stats(tempvectforstats);
	wxCommandEvent event(TRANSMIT_GMT_STATS, ID_GMT);
	wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);

}

void GridMysteriousTeacher::UpdateDDCHSelection(Character character) {
	gtbmt->UpdateDDCHSelection(character);
	repopulate();
}

void GridMysteriousTeacher::UpdateSCLSelection(int level, int ID) {
	switch (ID) {
		case ID_SPIN1: {
			gtbmt->UpdateSCLSelection(level, ID_SPIN1);
			repopulate();
			break;
		}

		case ID_SPIN2: {
			gtbmt->UpdateSCLSelection(level, ID_SPIN2);
			repopulate();
			break;
		}
	}
}

void GridMysteriousTeacher::UpdateDDCLSelection(Class cLass, int ID) {
	switch (ID) {
		case ID_DDCL1: {
			gtbmt->UpdateDDCLSelection(cLass, ID_DDCL1);
			repopulate();

			break;
		}

		case ID_DDCL2: {
			gtbmt->UpdateDDCLSelection(cLass, ID_DDCL2);
			repopulate();

			break;
		}

		case ID_DDCL3: {
			gtbmt->UpdateDDCLSelection(cLass, ID_DDCL3);
			repopulate();

			break;
		}
	}
}

void GTBMysteriousTeacher::UpdateDDCHSelection(Character character) {
	currentDDCHstats = character.getStats();
	currentDDCHgrowths = character.getGrowths();

	recalculate();
}

void GTBMysteriousTeacher::UpdateSCLSelection(int level, int ID) {
	switch (ID) {
		case ID_SPIN1: {
			currentSCL1selection = level;
			break;
		}

		case ID_SPIN2: {
			currentSCL2selection = level;
			break;
		}
	}

	recalculate();
}

void GTBMysteriousTeacher::UpdateDDCLSelection(Class cLass, int ID) {
	switch (ID) {
		case ID_DDCL1: {
			currentDDCL1growths = cLass.getGrowths();
			break;
		}

		case ID_DDCL2: {
			currentDDCL2growths = cLass.getGrowths();
			break;
		}

		case ID_DDCL3: {
			currentDDCL3booststostats = cLass.getBoostedStats();
			currentDDCL3minstats = cLass.getStats();
			currentDDCL3mountvars = cLass.getMountedStats();
			break;
		}
	}

	recalculate();
}

void GTBMysteriousTeacher::recalculate() {
	for (int i = 0; i < 10; ++i) {
		totals1[i] = currentDDCHgrowths[i];
	}

	for (int i = 0; i < 10; ++i) {
		totals2[i] = currentDDCHstats[i];
	}

	for (int i = 0; i < 10; ++i) {
		float chargrowth = _wtof(currentDDCHgrowths[i].getText().c_str());
		float classgrowth = _wtof(currentDDCL1growths[i].getText().c_str());
		totals3[i] = std::to_wstring(chargrowth + classgrowth);
	}

	for (int i = 0; i < 10; ++i) {
		float chargrowth = _wtof(currentDDCHgrowths[i].getText().c_str());
		float classgrowth = _wtof(currentDDCL1growths[i].getText().c_str());
		float subtotal = chargrowth + classgrowth;
		int level = currentSCL1selection;
		int avgtotal = subtotal * level;
		totals4[i] = std::to_wstring(avgtotal);
	}

	for (int i = 0; i < 10; ++i) {
		float chargrowth = _wtof(currentDDCHgrowths[i].getText().c_str());
		float classgrowth2 = _wtof(currentDDCL2growths[i].getText().c_str());
		totals5[i] = std::to_wstring(chargrowth + classgrowth2);
	}

	for (int i = 0; i < 10; ++i) {
		float chargrowth = _wtof(currentDDCHgrowths[i].getText().c_str());
		float classgrowth2 = _wtof(currentDDCL2growths[i].getText().c_str());
		float subtotal2 = chargrowth + classgrowth2;
		int level2 = currentSCL2selection;
		int avgtotal2 = subtotal2 * level2;
		totals6[i] = std::to_wstring(avgtotal2);
	}

	for (int i = 0; i < 10; ++i) {
		int charstat = _wtoi(currentDDCHstats[i].getText().c_str());

		float chargrowth = _wtof(currentDDCHgrowths[i].getText().c_str());

		float classgrowth1 = _wtof(currentDDCL1growths[i].getText().c_str());
		float classgrowth2 = _wtof(currentDDCL2growths[i].getText().c_str());

		int level1 = currentSCL1selection;
		int level2 = currentSCL2selection;

		float subtotal = chargrowth + classgrowth1;
		float subtotal2 = chargrowth + classgrowth2;

		int avgtotal1 = subtotal * level1;
		int avgtotal2 = subtotal2 * level2;

		int grandtotal = charstat + avgtotal1 + avgtotal2;
		totals7[i] = std::to_wstring(grandtotal);
	}

	for (int i = 0; i < 10; ++i) {
		int charstat = _wtoi(currentDDCHstats[i].getText().c_str());

		float chargrowth = _wtof(currentDDCHgrowths[i].getText().c_str());

		float classgrowth1 = _wtof(currentDDCL1growths[i].getText().c_str());
		float classgrowth2 = _wtof(currentDDCL2growths[i].getText().c_str());

		int classboost = _wtoi(currentDDCL3booststostats[i].getText().c_str());

		int level1 = currentSCL1selection;
		int level2 = currentSCL2selection;

		float subtotal = chargrowth + classgrowth1;
		float subtotal2 = chargrowth + classgrowth2;

		int avgtotal1 = subtotal * level1;
		int avgtotal2 = subtotal2 * level2;

		int grandtotal = charstat + avgtotal1 + avgtotal2;
		int megagrandtotal = grandtotal + classboost;
		totals8[i] = std::to_wstring(megagrandtotal);
	}
}

ListBoxWeapons::ListBoxWeapons(std::map<wxString, wxClientData*> uweaponmap, wxWindow* panel,
	wxWindowID id, int x, int y, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxDefaultPosition, wxSize(x, y), choices, style)
{
	weaponmap = uweaponmap;
	auto iter = weaponmap.begin();

	std::vector<wxString> firstname;
	std::vector<wxClientData*> firstdata;

	firstname.push_back(iter->first);
	Weapon* temp = dynamic_cast<Weapon*>(iter->second)->clone();
	firstdata.push_back(dynamic_cast<wxClientData*>(temp));
	this->Set(ToArrayString(firstname), ToArrayData(firstdata));

	this->SetSelection(0);
	wxCommandEvent eventtoself(ID_LBW);
	eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	ProcessEvent(eventtoself);
}

void ListBoxWeapons::OnNewSelection(wxCommandEvent& selection) {	//triggers on mouse click from user and from DetermineSelectionStatus()
	wxCommandEvent event(TRANSMIT_LBW_SELECTION, ID_LBW);
	event.SetClientObject(selection.GetClientObject());
	ProcessEvent(event);
}

void ListBoxWeapons::ReceiveExclusivity(wxString charactername) {	//forwarded from MyFrame::BounceDDCInfo()
	currentDDCselection = charactername;
	repopulate();
}

void ListBoxWeapons::ReceiveSLInfo(SLPACKAGE* slpackage) {
	if (slpackage->index < 7) {
		SLfilter[slpackage->index] = slpackage->sl;
	}

	repopulate();
}

void ListBoxWeapons::repopulate() {				
	std::vector<Weapon*> exclusiveweapons;		
	std::vector<Weapon*> generalweapons;
	std::vector<wxString> weaponnames;
	std::vector<wxClientData*> weapondata;

	for (auto element : weaponmap) {
		Weapon* temp = dynamic_cast<Weapon*>(element.second)->clone();
		if (temp->getExclusivity()) {
			exclusiveweapons.push_back(temp);
		}
		else {
			generalweapons.push_back(temp);
		}
	}

	for (auto weapon : exclusiveweapons) {
		std::wstring characternames = weapon->getCharacterName(), buffer;
		std::wstringstream stream(characternames);
		std::vector<std::wstring> namesfromstream;

		while (std::getline(stream, buffer, L',')) {
			namesfromstream.push_back(buffer);
		}

		for (auto possiblematch : namesfromstream) {
			if (currentDDCselection == possiblematch) {
				weaponnames.push_back(weapon->getName());
				weapondata.push_back(dynamic_cast<wxClientData*>(weapon));
			}
		}
	}

	for (auto weapon : generalweapons) {
		SL weaponSL = weapon->getSL();
		if ((int)weaponSL == -1) {
			weaponnames.push_back(weapon->getName());
			weapondata.push_back(dynamic_cast<wxClientData*>(weapon));
		}

		else {
			if (weaponSL <= SLfilter[(int)weapon->getType()]) {
				weaponnames.push_back(weapon->getName());
				weapondata.push_back(dynamic_cast<wxClientData*>(weapon));
			}
		}
	}
	mostrecentLBWselection = GetStringSelection();
	this->Set(ToArrayString(weaponnames), ToArrayData(weapondata));

	DetermineSelectionStatus();
}

void ListBoxWeapons::DetermineSelectionStatus() {
	if (CompareAllStrings()) {
		int index = this->FindString(mostrecentLBWselection);
		this->SetSelection(index);

		wxCommandEvent eventtoself(wxEVT_LISTBOX, ID_LBW);
		eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
		ProcessEvent(eventtoself);
	}

	else if (!CompareAllStrings()) {
		int index = this->FindString("---");
		this->SetSelection(index);

		wxCommandEvent eventtoself(wxEVT_LISTBOX, ID_LBW);
		eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
		ProcessEvent(eventtoself);
	}
}

bool ListBoxWeapons::CompareAllStrings() {
	wxArrayString currentweaponselections = this->GetStrings();

	for (auto weaponname : currentweaponselections) {
		if (weaponname == mostrecentLBWselection) {
			return true;
		}
	}

	return false;
}

ListBoxEquipment::ListBoxEquipment(std::map<wxString, wxClientData*> uequipmentmap, wxWindow* panel,
	wxWindowID id, int x, int y, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxDefaultPosition, wxSize(x, y), choices, style)
{
	equipmentmap = uequipmentmap;
	auto iter = uequipmentmap.begin();

	std::vector<wxString> firstname;
	std::vector<wxClientData*> firstdata;

	firstname.push_back(iter->first);
	Equipment* temp = dynamic_cast<Equipment*>(iter->second)->clone();
	firstdata.push_back(dynamic_cast<wxClientData*>(temp));
	this->Set(ToArrayString(firstname), ToArrayData(firstdata));

	this->SetSelection(0);
	wxCommandEvent eventtoself(ID_LBE);
	eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	ProcessEvent(eventtoself);
}

void ListBoxEquipment::OnNewSelection(wxCommandEvent& selection) {
	wxCommandEvent event(TRANSMIT_LBE_SELECTION, ID_LBE);
	event.SetClientObject(selection.GetClientObject());
	ProcessEvent(event);
}

void ListBoxEquipment::ReceiveExclusivity(wxString charactername) {
	currentDDCSelection = charactername;
	repopulate();
}

void ListBoxEquipment::repopulate() {
	std::vector<Equipment*> exclusiveequipment;
	std::vector<Equipment*> generalequipment;
	std::vector<wxString> equipmentnames;
	std::vector<wxClientData*> equipmentdata;

	for (auto element : equipmentmap) {
		Equipment* temp = dynamic_cast<Equipment*>(element.second)->clone();
		if (temp->getExclusivity()) {
			exclusiveequipment.push_back(temp);
		}
		else {
			generalequipment.push_back(temp);
		}
	}

	for (auto cLass : exclusiveequipment) {
		std::wstring characternames = cLass->getCharacterName(), buffer;
		std::wstringstream stream(characternames);
		std::vector<std::wstring> namesfromstream;

		while (std::getline(stream, buffer, L',')) {
			namesfromstream.push_back(buffer);
		}

		for (auto possiblematch : namesfromstream) {
			if (currentDDCSelection == possiblematch) {
				equipmentnames.push_back(cLass->getName());
				equipmentdata.push_back(dynamic_cast<wxClientData*>(cLass));
			}
		}
	}

	for (auto equipment : generalequipment) {
		equipmentnames.push_back(equipment->getName());
		equipmentdata.push_back(dynamic_cast<wxClientData*>(equipment));
	}

	mostrecentLBEselection = GetStringSelection();
	this->Set(ToArrayString(equipmentnames), ToArrayData(equipmentdata));
	DetermineSelectionStatus();
}

void ListBoxEquipment::DetermineSelectionStatus() {
	if (CompareAllStrings()) {
		int index = this->FindString(mostrecentLBEselection);
		this->SetSelection(index);
		wxCommandEvent eventtoself(wxEVT_LISTBOX, ID_LBE);
		eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
		ProcessEvent(eventtoself);
	}

	else if (!CompareAllStrings()) {
		int index = this->FindString("---");
		this->SetSelection(index);
		wxCommandEvent eventtoself(wxEVT_LISTBOX, ID_LBE);
		eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
		ProcessEvent(eventtoself);
	}
}

bool ListBoxEquipment::CompareAllStrings() {
	wxArrayString currentequipmentselections = this->GetStrings();

	for (auto equipmentname : currentequipmentselections) {
		if (equipmentname == mostrecentLBEselection) {
			return true;
		}
	}

	return false;
}

ListBoxBattalions::ListBoxBattalions(std::map<wxString, wxClientData*> ubattalionmap, wxWindow* panel, 
	wxWindowID id, int x, int y, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxDefaultPosition, wxSize(x, y), choices, style)
{
	battalionmap = ubattalionmap;
	auto iter = ubattalionmap.begin();

	std::vector<wxString> firstname;
	std::vector<wxClientData*> firstdata;

	firstname.push_back(iter->first);
	Battalion* temp = dynamic_cast<Battalion*>(iter->second)->clone();
	firstdata.push_back(dynamic_cast<wxClientData*>(temp));
	this->Set(ToArrayString(firstname), ToArrayData(firstdata));

	this->SetSelection(0);
	wxCommandEvent eventtoself(ID_LBB);
	eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	ProcessEvent(eventtoself);

}

void ListBoxBattalions::OnNewSelection(wxCommandEvent& selection) {
	wxCommandEvent event(TRANSMIT_LBB_SELECTION, ID_LBB);
	event.SetClientObject(selection.GetClientObject());
	ProcessEvent(event);
}

void ListBoxBattalions::ReceiveSLInfo(SLPACKAGE* slpackage) {
	if (slpackage->index == 7) {
		sl = slpackage->sl;
	}

	repopulate();
}

void ListBoxBattalions::repopulate() {
	std::vector<Battalion*> battalions;
	std::vector<wxString> battalionnames;
	std::vector<wxClientData*> battaliondata;

	for (auto element : battalionmap) {
		Battalion* temp = dynamic_cast<Battalion*>(element.second)->clone();
		battalions.push_back(temp);
	}

	for (auto battalion : battalions) {
		SL battalionSL = battalion->getSL();
		if ((int)battalionSL == -1) {
			battalionnames.push_back(battalion->getName());
			battaliondata.push_back(dynamic_cast<wxClientData*>(battalion));
		}

		else {
			if (battalionSL <= sl) {
				battalionnames.push_back(battalion->getName());
				battaliondata.push_back(dynamic_cast<wxClientData*>(battalion));
			}
		}
	}
	mostrecentLBBselection = GetStringSelection();
	this->Set(ToArrayString(battalionnames), ToArrayData(battaliondata));

	DetermineSelectionStatus();

}

void ListBoxBattalions::DetermineSelectionStatus() {
	if (CompareAllStrings()) {
		int index = this->FindString(mostrecentLBBselection);
		this->SetSelection(index);

		wxCommandEvent eventtoself(wxEVT_LISTBOX, ID_LBB);
		eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
		ProcessEvent(eventtoself);
	}

	else if (!CompareAllStrings()) {
		int index = this->FindString("---");
		this->SetSelection(index);

		wxCommandEvent eventtoself(wxEVT_LISTBOX, ID_LBB);
		eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
		ProcessEvent(eventtoself);
	}
}

bool ListBoxBattalions::CompareAllStrings() {
	wxArrayString currentbattalionselections = this->GetStrings();

	for (auto battalionname : currentbattalionselections) {
		if (battalionname == mostrecentLBBselection) {
			return true;
		}
	}

	return false;
}

GridWeaponStats::GridWeaponStats(wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	gtbws = new GTBWeaponStats;

	CreateGrid(1, gtbws->GetColsCount());
	for (int i = 0; i < gtbws->GetColsCount(); ++i) {
		SetColLabelValue(i, gtbws->GetHeader(i));
		AutoSizeColLabelSize(i);
	}
	SetUseNativeColLabels(true);

	SetRowLabelSize(0);
	initpopulate();
}

void GridWeaponStats::initpopulate() {
	for (int i = 0; i < gtbws->GetColsCount(); ++i) {
		SetCellValue(0, i, L"0");
		int k = 0;
	}
}

void GridWeaponStats::ReceiveLBWSelection(Stats stats) {
	gtbws->ReceiveLBWSelection(stats);
	repopulate();
}

void GridWeaponStats::repopulate() {
	std::vector<Stat> tempvectforstats;
	for (int i = 0; i < gtbws->GetColsCount(); ++i) {
		wxString colvalue = gtbws->GetValue(0, i);
		SetCellValue(0, i, colvalue);
		tempvectforstats.push_back(Stat(colvalue));
		int k = 0;
	}

	Stats* ptrtostats = new Stats(tempvectforstats);
	wxCommandEvent event(TRANSMIT_GWS_STATS, ID_GWS);
	wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);
}

void GTBWeaponStats::ReceiveLBWSelection(Stats stats) {
	weaponstats = stats;
}

GridEquipmentStats::GridEquipmentStats(wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	gtbes = new GTBEquipmentStats;

	CreateGrid(1, gtbes->GetColsCount());
	for (int i = 0; i < gtbes->GetColsCount(); ++i) {
		SetColLabelValue(i, gtbes->GetHeader(i));
		AutoSizeColLabelSize(i);
	}
	SetUseNativeColLabels(true);

	SetRowLabelSize(0);
	initpopulate();
}

void GridEquipmentStats::initpopulate() {
	for (int i = 0; i < gtbes->GetColsCount(); ++i) {
		SetCellValue(0, i, L"0");
		int k = 0;
	}
}

void GridEquipmentStats::ReceiveLBESelection(Stats stats) {
	gtbes->ReceiveLBESelection(stats);
	repopulate();
}

void GridEquipmentStats::repopulate() {
	std::vector<Stat> tempvectforstats;
	int col = 1;

	for (int i = 0; i < gtbes->GetColsCount(); ++i) {
		wxString colvalue = gtbes->GetValue(0, i);
		SetCellValue(0, i, colvalue);
		tempvectforstats.push_back(Stat(colvalue));
		int k = 0;
	}

	Stats* ptrtostats = new Stats(tempvectforstats);
	wxCommandEvent event(TRANSMIT_GES_STATS, ID_GES);
	wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);
}

void GTBEquipmentStats::ReceiveLBESelection(Stats stats) {
	equipmentstats = stats;
}

GridBattalionStats::GridBattalionStats(wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	gtbbs = new GTBBattalionStats;

	CreateGrid(1, gtbbs->GetColsCount());
	for (int i = 0; i < gtbbs->GetColsCount(); ++i) {
		SetColLabelValue(i, gtbbs->GetHeader(i));
		AutoSizeColLabelSize(i);
	}
	SetUseNativeColLabels(true);

	SetRowLabelSize(0);
	initpopulate();
}

void GridBattalionStats::initpopulate() {
	for (int i = 0; i < gtbbs->GetColsCount(); ++i) {
		SetCellValue(0, i, L"0");
		int k = 0;
	}
}

void GridBattalionStats::ReceiveLBBSelection(Stats stats) {
	gtbbs->ReceiveLBBSelection(stats);
	repopulate();
}

void GridBattalionStats::repopulate() {
	std::vector<Stat> tempvectforstats;
	int col = 1;

	for (int i = 0; i < gtbbs->GetColsCount(); ++i) {
		wxString colvalue = gtbbs->GetValue(0, i);
		SetCellValue(0, i, colvalue);
		tempvectforstats.push_back(Stat(colvalue));
		int k = 0;
	}

	Stats* ptrtostats = new Stats(tempvectforstats);
	wxCommandEvent event(TRANSMIT_GBS_STATS, ID_GBS);
	wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);
}

void GTBBattalionStats::ReceiveLBBSelection(Stats stats) {
	battalionstats = stats;
}

GridTotalStats::GridTotalStats(wxWindow* parent, wxWindowID id) :
	wxGrid(parent, id)
{
	gtbts = new GTBTotalStats;

	CreateGrid(1, gtbts->GetColsCount());
	for (int i = 0; i < gtbts->GetColsCount(); ++i) {
		SetColLabelValue(i, gtbts->GetHeader(i));
		AutoSizeColLabelSize(i);
	}
	SetUseNativeColLabels(true);

	SetRowLabelSize(0);
	initpopulate();
}

void GridTotalStats::initpopulate() {
	for (int i = 0; i < gtbts->GetColsCount(); ++i) {
		SetCellValue(0, i, L"0");
		int k = 0;
	}
}

void GridTotalStats::ReceiveGMTStats(Stats stats) {
	gtbts->ReceiveGMTStats(stats);
	gtbts->recalculate();
	repopulate();
}

void GridTotalStats::ReceiveGWSStats(Stats stats) {
	gtbts->ReceiveGWSStats(stats);
	gtbts->recalculate();
	repopulate();
}

void GridTotalStats::ReceiveGESStats(Stats stats) {
	gtbts->ReceiveGESStats(stats);
	gtbts->recalculate();
	repopulate();
}

void GridTotalStats::ReceiveGBSStats(Stats stats) {
	gtbts->ReceiveGBSStats(stats);
	gtbts->recalculate();
	repopulate();
}

void GridTotalStats::repopulate() {
	int col = 1;

	for (int i = 0; i < gtbts->GetColsCount(); ++i) {
		wxString colvalue = gtbts->GetValue(0, i);
		SetCellValue(0, i, colvalue);
		int k = 0;
	}
}

void GTBTotalStats::recalculate() {
	CalculateTotalPhysicalAttack();
	CalculateTotalMagicAttack();
	CalculateTotalPhysicalHit();
	CalculateTotalMagicHit();
	CalculateTotalCrit();
	CalculateAS();
	CalculateTotalProt();
	CalculateTotalResilience();
	CalculateTotalAvoid();
	CalculateTotalCritAvoid();
	CalculateTotalRange();
}

void GTBTotalStats::ReceiveGMTStats(Stats stats) {
	currentGMTstats = stats;
}

void GTBTotalStats::ReceiveGWSStats(Stats stats) {
	currentGWSstats = stats;
}

void GTBTotalStats::ReceiveGESStats(Stats stats) {
	currentGESstats = stats;
}

void GTBTotalStats::ReceiveGBSStats(Stats stats) {
	currentGBSstats = stats;
}

void GTBTotalStats::CalculateTotalPhysicalAttack() {
	std::wstring temp = currentGMTstats[2].getText();
	int lvcstat2 = _wtoi(temp.c_str());

	temp = currentGWSstats[0].getText();
	int lvwstat0 = _wtoi(temp.c_str());

	temp = currentGBSstats[0].getText();
	int lvbstat0 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat2 + lvwstat0 + lvbstat0);
	//	//+ ifEffective(Weapon Might x3)
	//	//+ Combat Art
	//	//+ Skills
	//	//+ Linked attacks
	//	//+/- Terrain Effects
	//	//- Enemies Protection);
	totalstats[0] = buffer;
}

void GTBTotalStats::CalculateTotalMagicAttack() {
	std::wstring temp = currentGMTstats[3].getText();
	int lvcstat3 = _wtoi(temp.c_str());

	temp = currentGWSstats[0].getText();
	int lvwstat0 = _wtoi(temp.c_str());

	temp = currentGBSstats[1].getText();
	int lvbstat1 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat3 + lvwstat0 + lvbstat1);
	//+ ifEffective(Weapon Might x3)
	//+ Combat Art
	//+ Skills
	//+/- Battalions
	//+ Staves
	//+ Linked attacks
	//+/- Terrain Effects
	//- Enemies Resilience);
	totalstats[1] = buffer;
}

void GTBTotalStats::CalculateTotalPhysicalHit() {
	std::wstring temp = currentGMTstats[4].getText();
	int lvcstat4 = _wtoi(temp.c_str());

	temp = currentGWSstats[1].getText();
	int lvwstat1 = _wtoi(temp.c_str());

	temp = currentGBSstats[2].getText();
	int lvbstat2 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat4 + lvwstat1 + lvbstat2);

	/*+ Combat Art
	+ Skills
	+/- Battalions
	+ Linked attacks
	+/- Terrain Effects
	- Enemies Avoid*/
	totalstats[2] = buffer;
}

void GTBTotalStats::CalculateTotalMagicHit() {
	std::wstring temp = currentGMTstats[4].getText();
	int lvcstat4 = _wtoi(temp.c_str());

	temp = currentGMTstats[6].getText();
	int lvcstat6 = _wtoi(temp.c_str());

	temp = currentGWSstats[1].getText();
	int lvwstat1 = _wtoi(temp.c_str());

	temp = currentGBSstats[2].getText();
	int lvbstat2 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring((lvcstat4 / 2) + (lvcstat6 / 2) + lvwstat1 + lvbstat2);

		/*+ Skills
		+ Linked attacks
		- Enemies Magic Avoid*/
	totalstats[3] = buffer;
}

void GTBTotalStats::CalculateTotalCrit() {
	std::wstring temp = currentGMTstats[4].getText();
	int lvcstat4 = _wtoi(temp.c_str());

	temp = currentGMTstats[6].getText();
	int lvcstat6 = _wtoi(temp.c_str());

	temp = currentGWSstats[2].getText();
	int lvwstat2 = _wtoi(temp.c_str());

	temp = currentGBSstats[3].getText();
	int lvbstat3 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat4 + (lvcstat6 / 2) + lvwstat2 + lvbstat3);

	totalstats[4] = buffer;
	/////*+Skills*/);
}

void GTBTotalStats::CalculateAS() {
	std::wstring temp = currentGMTstats[5].getText();
	int lvcstat5 = _wtoi(temp.c_str());

	temp = currentGWSstats[4].getText();
	int lvwstat4 = _wtoi(temp.c_str());

	temp = currentGWSstats[2].getText();
	int lvwstat2 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat5 + lvwstat4 - (lvwstat2 / 5));

	totalstats[5] = buffer;
}

void GTBTotalStats::CalculateTotalProt() {
	std::wstring temp = currentGMTstats[7].getText();
	int lvcstat7 = _wtoi(temp.c_str());

	temp = currentGESstats[6].getText();
	int lvestat6 = _wtoi(temp.c_str());

	temp = currentGBSstats[5].getText();
	int lvbstat5 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat7 + lvestat6 + lvbstat5);

	totalstats[6] = buffer;
}

void GTBTotalStats::CalculateTotalResilience() {
	std::wstring temp = currentGMTstats[8].getText();
	int lvcstat8 = _wtoi(temp.c_str());

	temp = currentGESstats[7].getText();
	int lvestat7 = _wtoi(temp.c_str());

	temp = currentGBSstats[6].getText();
	int lvbstat6 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat8 + lvestat7 + lvbstat6);

	totalstats[7] = buffer;
}

void GTBTotalStats::CalculateTotalAvoid() {
	std::wstring temp = totalstats[5].getText();
	int totalstats5 = _wtoi(temp.c_str());

	temp = currentGBSstats[4].getText();
	int lvbstat4 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(totalstats5 + lvbstat4);

	totalstats[8] = buffer;

	//	/*+ Skills
	//	+/- Terrain Effects*//*)*/;
}

void GTBTotalStats::CalculateTotalCritAvoid() {
	std::wstring temp = currentGWSstats[2].getText();
	int lvwstat2 = _wtoi(temp.c_str());

	temp = currentGMTstats[6].getText();
	int lvcstat6 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvwstat2 - lvcstat6);

	totalstats[9] = buffer;
}

void GTBTotalStats::CalculateTotalRange() {
	std::wstring temp = currentGWSstats[3].getText();
	int lvwstat3 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvwstat3);
	totalstats[10] = buffer;
}

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

StaticTextSkillLevel::StaticTextSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, int x, int y, int x2, int y2) :
	wxStaticText(parent, id, label, wxPoint(x, y), wxSize(x2, y2))
{
	stname = label;
}

DropDownSkillLevel::DropDownSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, const wxString& value, int x, int y, int x2, int y2, const wxArrayString& choices, long style) :
	wxComboBox(parent, id, value, wxPoint(x, y), wxSize(x2, y2), choices, style)
{
	ddname = label;
	initpopulate();
}

void DropDownSkillLevel::initpopulate() {
	std::vector<wxString> skillLVLnames{ "E", "E+", "D", "D+", "C", "C+", "B", "B+", "A", "A+", "S", "S+" };
	std::vector<wxClientData*> skillLVLdata{ new SLPACKAGE{SL::E}, new SLPACKAGE(SL::EPLUS), new SLPACKAGE(SL::D), new SLPACKAGE(SL::DPLUS), new SLPACKAGE(SL::C), new SLPACKAGE(SL::CPLUS),
										  new SLPACKAGE(SL::B), new SLPACKAGE(SL::BPLUS), new SLPACKAGE(SL::A), new SLPACKAGE(SL::APLUS), new SLPACKAGE(SL::S), new SLPACKAGE(SL::SPLUS) };
	int offset = 50;

	for (int i = 0; i < SL_DATA_SIZE; ++i) {
		SLPACKAGE* temp = dynamic_cast<SLPACKAGE*>(skillLVLdata[i]);
		temp->index = (GetId() - 50);
	}

	this->Append(ToArrayString(skillLVLnames), ToArrayData(skillLVLdata));
	this->SetSelection(0);
}

AbilityManager::AbilityManager(MyFrame* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	std::vector<wxString> abilitynames;
	std::vector<wxClientData*> abilitydata;
	AbilityList alist;

	for (unsigned int i = 0; i < alist.getSize(); ++i) {
		abilitynames.push_back(alist[i]->getName());
		abilitydata.push_back(alist[i]->clone());
	}

	for (unsigned int i = 0; i < alist.getSize(); ++i) {
		abilitymap.emplace(abilitynames[i], abilitydata[i]);
	}

	const wxArrayString buffer{};

	lbaa = new ListBoxAA(this, ID_LBAA, 0, 0, 150, 400, buffer, wxLB_MULTIPLE);
	lbsa = new ListBoxSA(this, ID_LBSA, 200, 0, 150, 400, buffer, wxLB_MULTIPLE);
	bmr = new ButtonMoveRight(this, ID_BMR, "->", 150, 50, 50, 50);
	bml = new ButtonMoveLeft(this, ID_BML, "<-", 150, 100, 50, 50);

	Bind(SELECTION_HAS_CHANGED, &AbilityManager::BounceSelectionstoRight, this, ID_BMR);
	Bind(SELECTION_HAS_CHANGED, &AbilityManager::BounceSelectionstoLeft, this, ID_BML);
}

void AbilityManager::ReceiveExclusivity(wxString charactername) {
	currentDDCselection = charactername;
	FilterAbilities();
}

void AbilityManager::ReceiveClassInnate(wxString classname) {
	currentLBCselection = classname;
	FilterAbilities();
}

void AbilityManager::ReceiveSLInfo(SLPACKAGE* slpackage) {
	SLfilter[slpackage->index] = slpackage->sl;
	FilterAbilities();
}

void AbilityManager::FilterAbilities() {
	std::vector<CharacterInnateAbility*> characterinnateabilities;
	std::vector<ClassInnateAbility*> classinnateabilities;
	std::vector<SkillLevelAbility*> skilllevelabilities;
	//std::vector<ClassMasteryAbility*> exclusiveweapons;

	std::vector<wxString> abilitynames;

	for (auto element : abilitymap) {
		Ability* tempability = dynamic_cast<Ability*>(element.second)->clone();
		if (CharacterInnateAbility* tempchia = dynamic_cast<CharacterInnateAbility*>(tempability)) {
			characterinnateabilities.push_back(tempchia);
		}
		if (ClassInnateAbility* tempclia = dynamic_cast<ClassInnateAbility*>(tempability)) {
			classinnateabilities.push_back(tempclia);
		}
		if (SkillLevelAbility* tempsla = dynamic_cast<SkillLevelAbility*>(tempability)) {
			skilllevelabilities.push_back(tempsla);
		}
	}

	for (auto ability : characterinnateabilities) {
		if (ability->getSource() == currentDDCselection) {
			abilitynames.push_back(ability->getName());
		}
	}

	for (auto ability : classinnateabilities) {
		std::wstring abilityns = ability->getSource(), buffer;
		std::wstringstream stream(abilityns);
		std::vector<std::wstring> namesfromstream;

		while (std::getline(stream, buffer, L',')) {
			namesfromstream.push_back(buffer);
		}

		for (auto possiblematch : namesfromstream) {
			if (possiblematch == currentLBCselection) {
				abilitynames.push_back(ability->getName());
			}
		}
	}

	for (auto ability : skilllevelabilities) {
		SL abilitySL = ability->getSL();

		if (abilitySL <= SLfilter[(int)ability->getWeaponType()]) {
			abilitynames.push_back(ability->getName());
		}
	}

	lbaa->ReceiveAbilityFiltration(abilitynames);
	lbsa->ReceiveAbilityFiltration(abilitynames);
}

void AbilityManager::BounceSelectionstoRight(wxCommandEvent& eventfromOnClick) {
	lbsa->ReceiveSelectionsfromBounceR(lbaa->GetSelectionsAA());
}

void AbilityManager::BounceSelectionstoLeft(wxCommandEvent& eventfromOnClick) {
	lbaa->ReceiveSelectionsfromBounceL(lbsa->GetSelectionsSAAndClear());
}

ListBoxAA::ListBoxAA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxPoint(x, y), wxSize(x2, y2), choices, style)
{
}

void ListBoxAA::OnSelection(wxCommandEvent& event) {
	selectedAAnames = UpdateSelections();
}

std::vector<wxString> ListBoxAA::UpdateSelections() {
	wxArrayInt selections;
	std::vector<wxString> tempvector;
	this->GetSelections(selections);

	for (auto selection : selections) {
		tempvector.push_back(this->GetString(selection));
	}

	return tempvector;
}

void ListBoxAA::ReceiveAbilityFiltration(std::vector<wxString> dirtynames) {
	filteredAAnames = dirtynames;

	std::vector<wxString> tempselected;

	for (auto newname : dirtynames) {
		for (auto oldname : selectedAAnames) {
			if (newname == oldname) {
				tempselected.push_back(newname);
				break;
			}
		}
	}
	selectedAAnames = tempselected;

	repopulate();
}

void ListBoxAA::ReceiveSelectionsfromBounceL(std::vector<wxString> uSelections) {
	for (auto newselect : uSelections) {
		std::erase(selectedAAnames, newselect);
	}

	repopulate();
}

void ListBoxAA::repopulate() {
	this->Set(ToArrayString(filteredAAnames));

	reselection();
}

void ListBoxAA::reselection() {
	for (auto selection : selectedAAnames) {
		int index = this->FindString(selection);
		if (!(this->IsSelected(index))) {
			this->SetSelection(index);
		}
	}
}

ListBoxSA::ListBoxSA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxPoint(x, y), wxSize(x2, y2), choices, style)
{
}

void ListBoxSA::OnSelection(wxCommandEvent& event) {
	selectedSAnames = UpdateSelections();
}

std::vector<wxString> ListBoxSA::UpdateSelections() {
	wxArrayInt selections;
	std::vector<wxString> tempvector;
	this->GetSelections(selections);

	for (auto selection : selections) {
		tempvector.push_back(this->GetString(selection));
	}

	return tempvector;
}

void ListBoxSA::ReceiveAbilityFiltration(std::vector<wxString> dirtynames) {
	std::vector<wxString> tempfiltered;
	std::vector<wxString> tempselected;

	for (auto newname : dirtynames) {
		for (auto oldname : filteredSAnames) {
			if (newname == oldname) {
				tempfiltered.push_back(newname);
				break;
			}
		}
	}

	for (auto newname : tempfiltered) {
		for (auto oldname : selectedSAnames) {
			if (newname == oldname) {
				tempselected.push_back(newname);
				break;
			}
		}
	}

	filteredSAnames = tempfiltered;
	selectedSAnames = tempselected;

	repopulate();
}

void ListBoxSA::ReceiveSelectionsfromBounceR(std::vector<wxString> uSelections) {
	filteredSAnames = uSelections;
	repopulate();
}

void ListBoxSA::repopulate() {
	this->Set(ToArrayString(filteredSAnames));

	reselection();
}

void ListBoxSA::reselection() {
	for (auto selection : selectedSAnames) {
		int index = this->FindString(selection);
		if (!(this->IsSelected(index))) {
			this->SetSelection(index);
		}
	}
}

std::vector<wxString> ListBoxSA::GetSelectionsSAAndClear() {
	std::vector<wxString> temp;

	for (auto element : selectedSAnames) {
		std::erase(filteredSAnames, element);
	}

	temp = selectedSAnames;
	selectedSAnames.clear();
	repopulate();
	return temp;
}

ButtonMoveRight::ButtonMoveRight(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2) :
	wxButton(panel, id, label, wxPoint(x, y), wxSize(x2, y2))
{
}

void ButtonMoveRight::OnClick(wxCommandEvent& uevent) {
	wxCommandEvent event(SELECTION_HAS_CHANGED, ID_BMR);
	ProcessEvent(event);
}

ButtonMoveLeft::ButtonMoveLeft(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2) :
	wxButton(panel, id, label, wxPoint(x, y), wxSize(x2, y2))
{
}

void ButtonMoveLeft::OnClick(wxCommandEvent& uevent) {
	wxCommandEvent event(SELECTION_HAS_CHANGED, ID_BML);
	ProcessEvent(event);
}

DECLARE_APP(MyApp);
IMPLEMENT_APP(MyApp);

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_COMBOBOX(ID_DDCH, DropDownCharacters::OnNewSelection)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(DropDownCharacters, wxComboBox)
	EVT_COMBOBOX(ID_DDCH, DropDownCharacters::OnNewSelection)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(DropDownClasses, wxComboBox)
	EVT_COMBOBOX(ID_DDCL1, DropDownClasses::OnNewSelection)
	EVT_COMBOBOX(ID_DDCL2, DropDownClasses::OnNewSelection)
	EVT_COMBOBOX(ID_DDCL3, DropDownClasses::OnNewSelection)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(ListBoxWeapons, wxListBox)
	EVT_LISTBOX(ID_LBW, ListBoxWeapons::OnNewSelection)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(ListBoxEquipment, wxListBox)
	EVT_LISTBOX(ID_LBE, ListBoxEquipment::OnNewSelection)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(ListBoxBattalions, wxListBox)
	EVT_LISTBOX(ID_LBB, ListBoxBattalions::OnNewSelection)
wxEND_EVENT_TABLE()

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

wxBEGIN_EVENT_TABLE(AbilityManager, wxPanel)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(ListBoxAA, wxListBox)
	EVT_LISTBOX(ID_LBAA, ListBoxAA::OnSelection)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(ListBoxSA, wxListBox)
	EVT_LISTBOX(ID_LBSA, ListBoxSA::OnSelection)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(ButtonMoveRight, wxButton)
	EVT_BUTTON(ID_BMR, ButtonMoveRight::OnClick)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(ButtonMoveLeft, wxButton)
	EVT_BUTTON(ID_BML, ButtonMoveLeft::OnClick)
wxEND_EVENT_TABLE()
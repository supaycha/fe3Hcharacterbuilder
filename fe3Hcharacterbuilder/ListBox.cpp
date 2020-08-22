#include "ListBox.h"

ListBoxWeapons::ListBoxWeapons(std::map<wxString, wxClientData*> uweaponmap, wxWindow* panel,
	wxWindowID id, int x, int y, const wxArrayString& choices, long style) :
wxListBox(panel, id, wxDefaultPosition, wxSize(x, y), choices, style)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
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
	Freeze();
	repopulate();
	Thaw();
}

void ListBoxWeapons::ReceiveSLInfo(SLPACKAGE* slpackage) {
	if (slpackage->index < 7) {
		SLfilter[slpackage->index] = slpackage->sl;
	}
	Freeze();
	repopulate();
	Thaw();
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

wxArrayString ListBoxWeapons::ToArrayString(std::vector<wxString> names) {
	wxArrayString temparraystring;
	for (auto name : names) {
		temparraystring.Add(name);
	}

	return temparraystring;
}

wxClientData** ListBoxWeapons::ToArrayData(std::vector<wxClientData*>& ptrs) {
	int size = ptrs.size();
	wxClientData** temparraydata = new wxClientData * [size];
	for (int i = 0; i < size; ++i) {
		temparraydata[i] = ptrs[i];
	}

	return temparraydata;
}


ListBoxEquipment::ListBoxEquipment(std::map<wxString, wxClientData*> uequipmentmap, wxWindow* panel,
	wxWindowID id, int x, int y, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxDefaultPosition, wxSize(x, y), choices, style)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
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
	Freeze();
	repopulate();
	Thaw();
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

wxArrayString ListBoxEquipment::ToArrayString(std::vector<wxString> names) {
	wxArrayString temparraystring;
	for (auto name : names) {
		temparraystring.Add(name);
	}

	return temparraystring;
}

wxClientData** ListBoxEquipment::ToArrayData(std::vector<wxClientData*>& ptrs) {
	int size = ptrs.size();
	wxClientData** temparraydata = new wxClientData * [size];
	for (int i = 0; i < size; ++i) {
		temparraydata[i] = ptrs[i];
	}

	return temparraydata;
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

	Freeze();
	repopulate();
	Thaw();
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

wxArrayString ListBoxBattalions::ToArrayString(std::vector<wxString> names) {
	wxArrayString temparraystring;
	for (auto name : names) {
		temparraystring.Add(name);
	}

	return temparraystring;
}

wxClientData** ListBoxBattalions::ToArrayData(std::vector<wxClientData*>& ptrs) {
	int size = ptrs.size();
	wxClientData** temparraydata = new wxClientData * [size];
	for (int i = 0; i < size; ++i) {
		temparraydata[i] = ptrs[i];
	}

	return temparraydata;
}

wxBEGIN_EVENT_TABLE(ListBoxWeapons, wxListBox)
	EVT_LISTBOX(ID_LBW, ListBoxWeapons::OnNewSelection)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(ListBoxEquipment, wxListBox)
	EVT_LISTBOX(ID_LBE, ListBoxEquipment::OnNewSelection)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(ListBoxBattalions, wxListBox)
	EVT_LISTBOX(ID_LBB, ListBoxBattalions::OnNewSelection)
wxEND_EVENT_TABLE()

#include <AvailablePanel/SkillLevelPanel/WeaponManager/ListBoxWeapons.h>

ListBoxWeapons::ListBoxWeapons(std::map<wxString, wxClientData*> uweaponmap, wxWindow* panel,
	wxWindowID id, int x, int y, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxDefaultPosition, wxSize(x, y), choices, style)
{
	for (int i = 0; i < 8; ++i) {
		WTPACKAGE transfer{ false, i };
		WTfilter.push_back(transfer);
	}

	//SetBackgroundStyle(wxBG_STYLE_PAINT);
	weaponmap = uweaponmap;
	auto iter = weaponmap.begin();

	std::vector<wxString> firstname;
	std::vector<wxClientData*> firstdata;

	firstname.push_back(iter->first);
	Weapon* temp = dynamic_cast<Weapon*>(iter->second)->clone();
	firstdata.push_back(dynamic_cast<wxClientData*>(temp));
	this->Set(ToArrayString(firstname), ToArrayData(firstdata));

	this->SetSelection(0);
	wxCommandEvent eventtoself((int)ID_SINGLE_CONTROL::ID_LBW);
	eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	ProcessEvent(eventtoself);
}

void ListBoxWeapons::OnNewSelection(wxCommandEvent& selection) {	//triggers on mouse click from user and from DetermineSelectionStatus()
	wxCommandEvent event(TRANSMIT_LBW_SELECTION, (int)ID_SINGLE_CONTROL::ID_LBW);
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

void ListBoxWeapons::ReceiveWTInfo(WTPACKAGE package) {
	WTfilter[package.index].isNotIncluded = package.isNotIncluded;
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

	for (unsigned int i = 0; i < generalweapons.size(); ++i) {
		SL weaponSL = generalweapons[i]->getSL();
		if ((int)weaponSL == -1) {
			weaponnames.push_back(generalweapons[i]->getName());
			weapondata.push_back(dynamic_cast<wxClientData*>(generalweapons[i]));
		}
		else if (WTfilter[(int)generalweapons[i]->getType()].isNotIncluded){
			continue;
		}
		else {
			if (weaponSL <= SLfilter[(int)generalweapons[i]->getType()]) {
				weaponnames.push_back(generalweapons[i]->getName());
				weapondata.push_back(dynamic_cast<wxClientData*>(generalweapons[i]));
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

		wxCommandEvent eventtoself(wxEVT_LISTBOX, (int)ID_SINGLE_CONTROL::ID_LBW);
		eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
		ProcessEvent(eventtoself);
	}

	else if (!CompareAllStrings()) {
		int index = this->FindString("---");
		this->SetSelection(index);

		wxCommandEvent eventtoself(wxEVT_LISTBOX, (int)ID_SINGLE_CONTROL::ID_LBW);
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

wxBEGIN_EVENT_TABLE(ListBoxWeapons, wxListBox)
	EVT_LISTBOX((int)ID_SINGLE_CONTROL::ID_LBW, ListBoxWeapons::OnNewSelection)
wxEND_EVENT_TABLE()

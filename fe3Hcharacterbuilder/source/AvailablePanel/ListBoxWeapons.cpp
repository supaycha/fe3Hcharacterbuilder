#include <AvailablePanel/ListBoxWeapons.h>

ListBoxWeapons::ListBoxWeapons(std::map<wxString, wxClientData*> uweaponmap, wxWindow* panel,
	wxWindowID id, int x, int y, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxDefaultPosition, wxSize(x, y), choices, style)
{
	//for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_WEAPON_RELATED_SKILL_LEVELS; ++i) {
	//	STINCPACKAGE transfer{ false, i };
	//	STfilter.push_back(transfer);
	//}

	weaponmap = uweaponmap;
	//auto iter = weaponmap.begin();

	//std::vector<wxString> firstname;
	//std::vector<wxClientData*> firstdata;

	//firstname.push_back(iter->first);
	//Weapon* temp = dynamic_cast<Weapon*>(iter->second)->clone();
	//firstdata.push_back(dynamic_cast<wxClientData*>(temp));
	//this->Set(ToArrayString(firstname), ToArrayData(firstdata));

	//this->SetSelection(0);
	//wxCommandEvent eventtoself((int)ID_SINGLE_CONTROL::ID_LBW);
	//eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	//ProcessEvent(eventtoself);
}

//void ListBoxWeapons::OnNewSelection(wxCommandEvent& selection) {	//triggers on mouse click from user and from DetermineSelectionStatus()
//	wxCommandEvent event(TRANSMIT_LBW_SELECTION, (int)ID_SINGLE_CONTROL::ID_LBW);
//	event.SetClientObject(selection.GetClientObject());
//	ProcessEvent(event);
//}

void ListBoxWeapons::ReceiveWeaponExclusivity(wxString charactername) {	//forwarded from MyFrame::BounceDDCInfo()
	currentDDCselection = charactername;
	FactorInExternalChange();
	//Freeze();
	//repopulate();
	//Thaw();
}

void ListBoxWeapons::ReceiveSLInfo(SKILLLEVELPACKAGE* slpackage) {
	if (slpackage->index < 7) {
		SLfilter[slpackage->index] = slpackage->sl;
	}
	FactorInExternalChange();
	//Freeze();
	//repopulate();
	//Thaw();
}

void ListBoxWeapons::ReceiveSTInfo(STINCPACKAGE package) {
	if (package.index < 8) {
		STfilter[package.index].isNotIncluded = package.isNotIncluded;
	}
	FactorInExternalChange();
	//Freeze();
	//repopulate();
	//Thaw();
}

void ListBoxWeapons::FactorInExternalChange() {
	allavailableweapons = CreateListOfAvailableWeapons();
	recalculate();
}

std::map<wxString, wxClientData*> ListBoxWeapons::CreateListOfAvailableWeapons() {
	std::map<wxString, wxClientData*> tempallavailableweapons;

	//std::vector<Weapon*> exclusiveweapons;
	//std::vector<Weapon*> generalweapons;
	//std::vector<wxString> weaponnames;
	//std::vector<wxClientData*> weapondata;

	for (auto element : weaponmap) {
		Weapon* tempweapon = dynamic_cast<Weapon*>(element.second)->clone();
		if (tempweapon->getExclusivity()) {
			std::wstring characternames = tempweapon->getCharacterName(), buffer;
			std::wstringstream stream(characternames);
			std::vector<std::wstring> namesfromstream;

			while (std::getline(stream, buffer, L',')) {
				namesfromstream.push_back(buffer);
			}

			for (auto possiblematch : namesfromstream) {
				if (currentDDCselection == possiblematch) {
					wxClientData* tempdata = dynamic_cast<wxClientData*>(tempweapon);
					tempallavailableweapons.emplace(std::make_pair(element.first, tempdata));
				}
			}
		}
		else {	
			for (unsigned int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_GENERAL_WEAPONS; ++i) {
				SL weaponSL = tempweapon->getSL();
				if ((int)weaponSL == -1) {
					wxClientData* tempdata = dynamic_cast<wxClientData*>(tempweapon);
					tempallavailableweapons.emplace(std::make_pair(element.first, tempdata));
				}
				else if (STfilter[(int)tempweapon->getWeaponType()].isNotIncluded) {
					continue;
				}
				else {
					if (weaponSL <= SLfilter[(int)tempweapon->getSkillType()]) {
						wxClientData* tempdata = dynamic_cast<wxClientData*>(tempweapon);
						tempallavailableweapons.emplace(std::make_pair(element.first, tempdata));
					}
				}
			}
		}
	}

	return tempallavailableweapons;
}

void ListBoxWeapons::recalculate() {
	mostrecentLBWselection = GetStringSelection();
	
	Freeze();
	repopulate();
	Thaw();

	ReselectWeapons();
	wxCommandEvent eventtoself(wxEVT_LISTBOX, (int)ID_SINGLE_CONTROL::ID_LBW);
	eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	ProcessEvent(eventtoself);
}

void ListBoxWeapons::repopulate() {
	std::vector<wxString> tempweaponnames;
	std::vector<wxClientData*> tempweapondata;
	for (auto element : allavailableweapons) {
		tempweaponnames.push_back(element.first);
		tempweapondata.push_back(element.second);
	}


	this->Set(ToArrayString(tempweaponnames), ToArrayData(tempweapondata));
}

void ListBoxWeapons::ReselectWeapons() {
	if (CompareAllStrings()) {
		int index = this->FindString(mostrecentLBWselection);
		this->SetSelection(index);
	}

	else if (!CompareAllStrings()) {
		int index = this->FindString("---");
		this->SetSelection(index);
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
	int sizeofvector = ptrs.size();
	wxClientData** temparraydata = new wxClientData * [sizeofvector];
	for (int i = 0; i < sizeofvector; ++i) {
		temparraydata[i] = ptrs[i];
	}

	return temparraydata;
}

//wxBEGIN_EVENT_TABLE(ListBoxWeapons, wxListBox)
//	//EVT_LISTBOX((int)ID_SINGLE_CONTROL::ID_LBW, ListBoxWeapons::OnNewSelection)
//wxEND_EVENT_TABLE()
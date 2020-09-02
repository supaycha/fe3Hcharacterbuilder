#include <ListBox/ListBoxEquipment.h>

ListBoxEquipment::ListBoxEquipment(std::map<wxString, wxClientData*> uequipmentmap, wxWindow* panel,
	wxWindowID id, int x, int y, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxDefaultPosition, wxSize(x, y), choices, style)
{
	//SetBackgroundStyle(wxBG_STYLE_PAINT);
	equipmentmap = uequipmentmap;
	auto iter = uequipmentmap.begin();

	std::vector<wxString> firstname;
	std::vector<wxClientData*> firstdata;

	firstname.push_back(iter->first);
	Equipment* temp = dynamic_cast<Equipment*>(iter->second)->clone();
	firstdata.push_back(dynamic_cast<wxClientData*>(temp));
	this->Set(ToArrayString(firstname), ToArrayData(firstdata));

	this->SetSelection(0);
	wxCommandEvent eventtoself((int)ID_SINGLE_CONTROL::ID_LBE);
	eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	ProcessEvent(eventtoself);
}

void ListBoxEquipment::OnNewSelection(wxCommandEvent& selection) {
	wxCommandEvent event(TRANSMIT_LBE_SELECTION, (int)ID_SINGLE_CONTROL::ID_LBE);
	event.SetClientObject(selection.GetClientObject());
	ProcessEvent(event);
}

void ListBoxEquipment::ReceiveEquipmentExclusivity(wxString charactername) {
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
	wxArrayString blehbl = this->GetStrings();
	DetermineSelectionStatus();
}

void ListBoxEquipment::DetermineSelectionStatus() {
	if (CompareAllStrings()) {
		int index = this->FindString(mostrecentLBEselection);
		this->SetSelection(index);
		wxCommandEvent eventtoself(wxEVT_LISTBOX, (int)ID_SINGLE_CONTROL::ID_LBE);
		eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
		ProcessEvent(eventtoself);
	}

	else if (!CompareAllStrings()) {
		int index = this->FindString("---");
		this->SetSelection(index);
		wxCommandEvent eventtoself(wxEVT_LISTBOX, (int)ID_SINGLE_CONTROL::ID_LBE);
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

wxBEGIN_EVENT_TABLE(ListBoxEquipment, wxListBox)
	EVT_LISTBOX((int)ID_SINGLE_CONTROL::ID_LBE, ListBoxEquipment::OnNewSelection)
wxEND_EVENT_TABLE()

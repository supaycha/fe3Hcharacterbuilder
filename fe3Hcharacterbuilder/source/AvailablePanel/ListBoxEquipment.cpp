#include <AvailablePanel/ListBoxEquipment.h>

ListBoxEquipment::ListBoxEquipment(std::map<wxString, wxClientData*> uequipmentmap, wxWindow* panel,
	wxWindowID id, int x, int y, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxDefaultPosition, wxSize(x, y), choices, style)
{
	equipmentmap = uequipmentmap;
	//auto iter = uequipmentmap.begin();

	//std::vector<wxString> firstname;
	//std::vector<wxClientData*> firstdata;

	//firstname.push_back(iter->first);
	//Equipment* temp = dynamic_cast<Equipment*>(iter->second)->clone();
	//firstdata.push_back(dynamic_cast<wxClientData*>(temp));
	//this->Set(ToArrayString(firstname), ToArrayData(firstdata));

	//this->SetSelection(0);
	//wxCommandEvent eventtoself((int)ID_SINGLE_CONTROL::ID_LBE);
	//eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	//ProcessEvent(eventtoself);
}

//void ListBoxEquipment::OnNewSelection(wxCommandEvent& selection) {
//	wxCommandEvent event(TRANSMIT_LBE_SELECTION, (int)ID_SINGLE_CONTROL::ID_LBE);
//	event.SetClientObject(selection.GetClientObject());
//	ProcessEvent(event);
//}

void ListBoxEquipment::ReceiveEquipmentExclusivity(wxString charactername) {
	currentDDCSelection = charactername;
	FactorInExternalChange();
}

void ListBoxEquipment::FactorInExternalChange() {
	allavailableequipment = CreateListOfAvailableEquipment();
	recalculate();
}

std::map<wxString, wxClientData*> ListBoxEquipment::CreateListOfAvailableEquipment() {
	std::map<wxString, wxClientData*> tempallavailableequipment;

	//std::vector<Equipment*> exclusiveequipment;
	//std::vector<Equipment*> generalequipment;
	//std::vector<wxString> equipmentnames;
	//std::vector<wxClientData*> equipmentdata;

	for (auto element : equipmentmap) {
		Equipment* tempequipment = dynamic_cast<Equipment*>(element.second)->clone();
		if (!(tempequipment->getExclusivity())) {
			wxClientData* tempdata = dynamic_cast<wxClientData*>(tempequipment);
			tempallavailableequipment.emplace(std::make_pair(element.first, tempdata));
		}
		else {
			std::wstring characternames = tempequipment->getCharacterName(), buffer;
			std::wstringstream stream(characternames);
			std::vector<std::wstring> namesfromstream;

			while (std::getline(stream, buffer, L',')) {
				namesfromstream.push_back(buffer);
			}

			for (auto possiblematch : namesfromstream) {
				if (currentDDCSelection == possiblematch) {
					wxClientData* tempdata = dynamic_cast<wxClientData*>(tempequipment);
					tempallavailableequipment.emplace(std::make_pair(element.first, tempdata));
				}
			}
		}
	}

	return tempallavailableequipment;
}

void ListBoxEquipment::recalculate() {
	mostrecentLBEselection = GetStringSelection();

	Freeze();
	repopulate();
	Thaw();

	ReselectEquipment();
	wxCommandEvent eventtoself(wxEVT_LISTBOX, (int)ID_SINGLE_CONTROL::ID_LBE);
	eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	ProcessEvent(eventtoself);
}

void ListBoxEquipment::repopulate() {
	std::vector<wxString> tempequipmentnames;
	std::vector<wxClientData*> tempequipmentdata;
	for (auto element : allavailableequipment) {
		tempequipmentnames.push_back(element.first);
		tempequipmentdata.push_back(element.second);
	}

	this->Set(ToArrayString(tempequipmentnames), ToArrayData(tempequipmentdata));
}

void ListBoxEquipment::ReselectEquipment() {
	if (CompareAllStrings()) {
		int index = this->FindString(mostrecentLBEselection);
		this->SetSelection(index);
	}

	else if (!CompareAllStrings()) {
		int index = this->FindString("---");
		this->SetSelection(index);
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
	int sizeofvector = ptrs.size();
	wxClientData** temparraydata = new wxClientData * [sizeofvector];
	for (int i = 0; i < sizeofvector; ++i) {
		temparraydata[i] = ptrs[i];
	}

	return temparraydata;
}
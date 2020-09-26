#include <MysteriousTeacher\DropDownClasses.h>

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

//void DropDownClasses::OnNewSelection(wxCommandEvent& selection) {
//	wxCommandEvent event(TRANSMIT_DDCL_SELECTION, selection.GetId());
//	event.SetClientObject(selection.GetClientObject());
//	ProcessEvent(event);
//}

void DropDownClasses::ReceiveExclusivity(wxString charactername) {
	currentDDCSelection = charactername;
	FactorInExternalChange();
	//Freeze();
	//repopulate();
	//Thaw();
}

void DropDownClasses::FactorInExternalChange() {
	allavailableclasses = CreateListOfAvailableClasses();
	recalculate();
}

std::map<wxString, wxClientData*> DropDownClasses::CreateListOfAvailableClasses() {
	std::map<wxString, wxClientData*> tempallavailableclasses;
	//std::vector<Class*> exclusiveclasses;
	//std::vector<Class*> generalclasses;
	//std::vector<wxString> classnames;
	//std::vector<wxClientData*> classdata;

	for (auto element : classmap) {
		Class* tempclass = dynamic_cast<Class*>(element.second)->clone();
		if (tempclass->getExclusivity()) {
			std::wstring characternames = tempclass->getCharacterName(), buffer;
			std::wstringstream stream(characternames);
			std::vector<std::wstring> namesfromstream;

			while (std::getline(stream, buffer, L',')) {
				namesfromstream.push_back(buffer);
			}

			for (auto possiblematch : namesfromstream) {
				if (currentDDCSelection == possiblematch) {
					wxClientData* tempdata = dynamic_cast<wxClientData*>(tempclass);
					tempallavailableclasses.emplace(std::make_pair(element.first, tempdata));
				}
			}
		}
		else {
			wxClientData* tempdata = dynamic_cast<wxClientData*>(tempclass);
			tempallavailableclasses.emplace(std::make_pair(element.first, tempdata));
		}
	}

	return tempallavailableclasses;
}

void DropDownClasses::recalculate() {
	mostrecentDDCLselection = GetStringSelection();

	Freeze();
	repopulate();
	Thaw();

	ReselectClasses();
	wxCommandEvent eventtoself(wxEVT_LISTBOX, GetId());
	eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	ProcessEvent(eventtoself);
}

void DropDownClasses::repopulate() {
	std::vector<wxString> tempweaponnames;
	std::vector<wxClientData*> tempweapondata;
	for (auto element : allavailableclasses) {
		tempweaponnames.push_back(element.first);
		tempweapondata.push_back(element.second);
	}

	this->Set(ToArrayString(tempweaponnames), ToArrayData(tempweapondata));
}

void DropDownClasses::ReselectClasses() {
	if (CompareAllStrings()) {
		int index = this->FindString(mostrecentDDCLselection);
		this->SetSelection(index);
	}

	else if (!CompareAllStrings()) {
		int index = this->FindString("---");
		this->SetSelection(index);
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

wxArrayString DropDownClasses::ToArrayString(std::vector<wxString> names) {
	wxArrayString temparraystring;
	for (auto name : names) {
		temparraystring.Add(name);
	}

	return temparraystring;
}

wxClientData** DropDownClasses::ToArrayData(std::vector<wxClientData*>& ptrs) {
	int sizeofvector = ptrs.size();
	wxClientData** temparraydata = new wxClientData * [sizeofvector];
	for (int i = 0; i < sizeofvector; ++i) {
		temparraydata[i] = ptrs[i];
	}

	return temparraydata;
}
//
//wxBEGIN_EVENT_TABLE(DropDownClasses, wxComboBox)
//	EVT_COMBOBOX((int)ID_MISC::ID_DDCL1, DropDownClasses::OnNewSelection)
//	EVT_COMBOBOX((int)ID_MISC::ID_DDCL2, DropDownClasses::OnNewSelection)
//	EVT_COMBOBOX((int)ID_MISC::ID_DDCL3, DropDownClasses::OnNewSelection)
//wxEND_EVENT_TABLE()
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

void DropDownClasses::OnNewSelection(wxCommandEvent& selection) {
	wxCommandEvent event(TRANSMIT_DDCL_SELECTION, selection.GetId());
	event.SetClientObject(selection.GetClientObject());
	ProcessEvent(event);
}

void DropDownClasses::ReceiveExclusivity(wxString charactername) {
	currentDDCSelection = charactername;
	Freeze();
	repopulate();
	Thaw();
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

wxBEGIN_EVENT_TABLE(DropDownClasses, wxComboBox)
	EVT_COMBOBOX((int)ID_MISC::ID_DDCL1, DropDownClasses::OnNewSelection)
	EVT_COMBOBOX((int)ID_MISC::ID_DDCL2, DropDownClasses::OnNewSelection)
	EVT_COMBOBOX((int)ID_MISC::ID_DDCL3, DropDownClasses::OnNewSelection)
wxEND_EVENT_TABLE()
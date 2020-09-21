#include <MysteriousTeacher\DropDownCharacters.h>

DropDownCharacters::DropDownCharacters(std::vector<wxString> characternames, std::vector<wxClientData*> characterdata, wxWindow* panel,
	wxWindowID id, const wxArrayString& choices, long style) :
	wxComboBox(panel, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, choices, style)
{
	this->Append(ToArrayString(characternames), ToArrayData(characterdata));
	this->SetSelection(0);

	wxCommandEvent eventtoself(wxEVT_COMBOBOX, (int)ID_MISC::ID_DDCH);
	eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	ProcessEvent(eventtoself);
}

void DropDownCharacters::OnNewSelection(wxCommandEvent& selection) {
	wxCommandEvent event(TRANSMIT_DDCH_SELECTION, (int)ID_MISC::ID_DDCH);
	event.SetClientObject(selection.GetClientObject());
	ProcessEvent(event);
}

wxArrayString DropDownCharacters::ToArrayString(std::vector<wxString> names) {
	wxArrayString temparraystring;
	for (auto name : names) {
		temparraystring.Add(name);
	}

	return temparraystring;
}

wxClientData** DropDownCharacters::ToArrayData(std::vector<wxClientData*>& ptrs) {
	int sizeofvector = ptrs.size();
	wxClientData** temparraydata = new wxClientData * [sizeofvector];
	for (int i = 0; i < sizeofvector; ++i) {
		temparraydata[i] = ptrs[i];
	}

	return temparraydata;
}

wxBEGIN_EVENT_TABLE(DropDownCharacters, wxComboBox)
	EVT_COMBOBOX((int)ID_MISC::ID_DDCH, DropDownCharacters::OnNewSelection)
wxEND_EVENT_TABLE()
#include <ListBox/ListBoxBattalions.h>

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
	wxCommandEvent eventtoself((int)ID_SINGLE_CONTROL::ID_LBB);
	eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	ProcessEvent(eventtoself);

}

void ListBoxBattalions::OnNewSelection(wxCommandEvent& selection) {
	wxCommandEvent event(TRANSMIT_LBB_SELECTION, (int)ID_SINGLE_CONTROL::ID_LBB);
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

		wxCommandEvent eventtoself(wxEVT_LISTBOX, (int)ID_SINGLE_CONTROL::ID_LBB);
		eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
		ProcessEvent(eventtoself);
	}

	else if (!CompareAllStrings()) {
		int index = this->FindString("---");
		this->SetSelection(index);

		wxCommandEvent eventtoself(wxEVT_LISTBOX, (int)ID_SINGLE_CONTROL::ID_LBB);
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

wxBEGIN_EVENT_TABLE(ListBoxBattalions, wxListBox)
	EVT_LISTBOX((int)ID_SINGLE_CONTROL::ID_LBB, ListBoxBattalions::OnNewSelection)
wxEND_EVENT_TABLE()
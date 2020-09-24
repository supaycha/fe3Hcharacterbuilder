#include <AvailablePanel/ListBoxBattalions.h>

ListBoxBattalions::ListBoxBattalions(std::map<wxString, wxClientData*> ubattalionmap,
	wxWindow* panel, wxWindowID id, int x, int y, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxDefaultPosition, wxSize(x, y), choices, style)
{
	battalionmap = ubattalionmap;
	//auto iter = ubattalionmap.begin();

	//std::vector<wxString> firstname;
	//std::vector<wxClientData*> firstdata;

	//firstname.push_back(iter->first);
	//Battalion* temp = dynamic_cast<Battalion*>(iter->second)->clone();
	//firstdata.push_back(dynamic_cast<wxClientData*>(temp));
	//this->Set(ToArrayString(firstname), ToArrayData(firstdata));

	//this->SetSelection(0);
	//wxCommandEvent eventtoself((int)ID_SINGLE_CONTROL::ID_LBB);
	//eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	//ProcessEvent(eventtoself);
}

//void ListBoxBattalions::OnNewSelection(wxCommandEvent& selection) {
//	wxCommandEvent event(TRANSMIT_LBB_SELECTION, (int)ID_SINGLE_CONTROL::ID_LBB);
//	event.SetClientObject(selection.GetClientObject());
//	ProcessEvent(event);
//	FactorInInternalChange();
//}

void ListBoxBattalions::ReceiveSLInfo(SKILLLEVELPACKAGE* slpackage) {
	sl = slpackage->sl;
	FactorInExternalChange();
}

//void ListBoxBattalions::FactorInInternalChange() {
//	recalculate();
//}

void ListBoxBattalions::FactorInExternalChange() {
	allavailableabilities = CreateListOfAvailableAbilities();
	recalculate();
}

std::map<wxString, wxClientData*> ListBoxBattalions::CreateListOfAvailableAbilities() {
	std::map<wxString, wxClientData*> tempallavailableabilities;
	for (auto element : battalionmap) {
		Battalion* tempbattalion = dynamic_cast<Battalion*>(element.second)->clone();
		SL battalionSL = tempbattalion->getSL();
		if ((int)battalionSL == -1) {
			wxClientData* tempdata = dynamic_cast<wxClientData*>(tempbattalion);
			tempallavailableabilities.emplace(std::make_pair(element.first, tempdata));
		}

		else {
			if (battalionSL <= sl) {
				wxClientData* tempdata = dynamic_cast<wxClientData*>(tempbattalion);
				tempallavailableabilities.emplace(std::make_pair(element.first, tempdata));
			}
		}
	}
	return tempallavailableabilities;
}

void ListBoxBattalions::ReselectAbility() {
	if (CompareAllStrings()) {
		int index = this->FindString(mostrecentLBBselection);
		this->SetSelection(index);
	}

	else if (!CompareAllStrings()) {
		int index = this->FindString("---");
		this->SetSelection(index);
	}
}

void ListBoxBattalions::recalculate() {	
	mostrecentLBBselection = GetStringSelection();

	Freeze();
	repopulate();
	Thaw();

	ReselectAbility();
	wxCommandEvent eventtoself(wxEVT_LISTBOX, (int)ID_SINGLE_CONTROL::ID_LBB);
	eventtoself.SetClientObject(this->GetClientObject(this->GetSelection()));
	ProcessEvent(eventtoself);
}

void ListBoxBattalions::repopulate() {
	std::vector<wxString> tempbattalionnames;
	std::vector<wxClientData*> tempbattaliondata;
	for (auto element : allavailableabilities) {
		tempbattalionnames.push_back(element.first);
		tempbattaliondata.push_back(element.second);
	}

	this->Set(ToArrayString(tempbattalionnames), ToArrayData(tempbattaliondata));
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
	int sizeofvector = ptrs.size();
	wxClientData** temparraydata = new wxClientData * [sizeofvector];
	for (int i = 0; i < sizeofvector; ++i) {
		temparraydata[i] = ptrs[i];
	}

	return temparraydata;
}

wxBEGIN_EVENT_TABLE(ListBoxBattalions, wxListBox)
	//EVT_LISTBOX((int)ID_SINGLE_CONTROL::ID_LBB, ListBoxBattalions::OnNewSelection)
wxEND_EVENT_TABLE()
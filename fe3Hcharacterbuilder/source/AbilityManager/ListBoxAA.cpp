#include <AbilityManager\ListBoxAA.h>

ListBoxAA::ListBoxAA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxPoint(x, y), wxSize(x2, y2), choices, style)
{
	//SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void ListBoxAA::OnSelection(wxCommandEvent& event) {
	selectedAAnames = UpdateSelections();
}

std::vector<wxString> ListBoxAA::UpdateSelections() {
	wxArrayInt selections;
	std::vector<wxString> tempvector;
	this->GetSelections(selections);

	for (auto selection : selections) {
		tempvector.push_back(this->GetString(selection));
	}

	return tempvector;
}

void ListBoxAA::ReceiveAbilityFiltration(std::vector<wxString> dirtynames) {
	filteredAAnames = dirtynames;

	std::vector<wxString> tempselected;

	for (auto newname : dirtynames) {
		for (auto oldname : selectedAAnames) {
			if (newname == oldname) {
				tempselected.push_back(newname);
				break;
			}
		}
	}
	selectedAAnames = tempselected;

	Freeze();
	repopulate();
	Thaw();
}

void ListBoxAA::ReceiveSelectionsfromBounceL(std::vector<wxString> uSelections) {
	for (auto newselect : uSelections) {
		std::erase(selectedAAnames, newselect);
	}

	Freeze();
	repopulate();
	Thaw();
}

void ListBoxAA::repopulate() {
	this->Set(ToArrayString(filteredAAnames));

	reselection();
}

void ListBoxAA::reselection() {
	for (auto selection : selectedAAnames) {
		int index = this->FindString(selection);
		if (!(this->IsSelected(index))) {
			this->SetSelection(index);
		}
	}
}

wxArrayString ListBoxAA::ToArrayString(std::vector<wxString> names) {
	wxArrayString temparraystring;
	for (auto name : names) {
		temparraystring.Add(name);
	}

	return temparraystring;
}

wxBEGIN_EVENT_TABLE(ListBoxAA, wxListBox)
	EVT_LISTBOX((int)ID_SINGLE_CONTROL::ID_LBAA, ListBoxAA::OnSelection)
wxEND_EVENT_TABLE()

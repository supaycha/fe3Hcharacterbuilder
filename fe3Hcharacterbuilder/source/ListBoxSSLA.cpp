//#include <ListBoxSSLA.h>
//
//ListBoxSSLA::ListBoxSSLA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style) :
//	wxListBox(panel, id, wxPoint(x, y), wxSize(x2, y2), choices, style)
//{
//	//SetBackgroundStyle(wxBG_STYLE_PAINT);
//}
//
//void ListBoxSSLA::OnSelection(wxCommandEvent& event) {
//	selectedSAnames = UpdateSelections();
//}
//
//std::vector<wxString> ListBoxSSLA::UpdateSelections() {
//	wxArrayInt selections;
//	std::vector<wxString> tempvector;
//	this->GetSelections(selections);
//
//	for (auto selection : selections) {
//		tempvector.push_back(this->GetString(selection));
//	}
//
//	return tempvector;
//}
//
//void ListBoxSSLA::ReceiveAbilityFiltration(std::vector<wxString> dirtynames) {
//	std::vector<wxString> tempfiltered;
//	std::vector<wxString> tempselected;
//
//	for (auto newname : dirtynames) {
//		for (auto oldname : filteredSAnames) {
//			if (newname == oldname) {
//				tempfiltered.push_back(newname);
//				break;
//			}
//		}
//	}
//
//	for (auto newname : tempfiltered) {
//		for (auto oldname : selectedSAnames) {
//			if (newname == oldname) {
//				tempselected.push_back(newname);
//				break;
//			}
//		}
//	}
//
//	filteredSAnames = tempfiltered;
//	selectedSAnames = tempselected;
//
//	Freeze();
//	repopulate();
//	Thaw();
//}
//
//void ListBoxSSLA::ReceiveSelectionsfromBounceR(std::vector<wxString> uSelections) {
//	filteredSAnames = uSelections;
//	Freeze();
//	repopulate();
//	Thaw();
//}
//
//void ListBoxSSLA::repopulate() {
//	this->Set(ToArrayString(filteredSAnames));
//
//	reselection();
//}
//
//void ListBoxSSLA::reselection() {
//	for (auto selection : selectedSAnames) {
//		int index = this->FindString(selection);
//		if (!(this->IsSelected(index))) {
//			this->SetSelection(index);
//		}
//	}
//}
//
//std::vector<wxString> ListBoxSSLA::GetSelectionsSAAndClear() {
//	std::vector<wxString> temp;
//
//	for (auto element : selectedSAnames) {
//		std::erase(filteredSAnames, element);
//	}
//
//	temp = selectedSAnames;
//	selectedSAnames.clear();
//	Freeze();
//	repopulate();
//	Thaw();
//	return temp;
//}
//
//wxArrayString ListBoxSSLA::ToArrayString(std::vector<wxString> names) {
//	wxArrayString temparraystring;
//	for (auto name : names) {
//		temparraystring.Add(name);
//	}
//
//	return temparraystring;
//}
//
//wxBEGIN_EVENT_TABLE(ListBoxSSLA, wxListBox)
//	EVT_LISTBOX((int)ID_SINGLE_CONTROL::ID_LBSSLA, ListBoxSSLA::OnSelection)
//wxEND_EVENT_TABLE()
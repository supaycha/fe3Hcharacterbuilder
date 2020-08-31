#include <MyApp.h>
bool MyApp::OnInit() {
	::wxInitAllImageHandlers();
	MyFrame* frame = new MyFrame((int)ID_MISC::ID_FRAME, wxT("feBuilder"));

	frame->InitDialog();
	frame->Show(true);
	return true;
}

IMPLEMENT_APP(MyApp);

//wxDEFINE_EVENT(SELECTION_HAS_CHANGED, wxCommandEvent);


//wxArrayString ToArrayString(std::vector<wxString> names) {
//	wxArrayString temparraystring;
//	for (auto name : names) {
//		temparraystring.Add(name);
//	}
//
//	return temparraystring;
//}
//wxClientData** ToArrayData(std::vector<wxClientData*>& ptrs) {
//	int size = ptrs.size();
//	wxClientData** temparraydata = new wxClientData * [size];
//	for (int i = 0; i < size; ++i) {
//		temparraydata[i] = ptrs[i];
//	}
//
//	return temparraydata;
//}
//std::map<wxString, int> ToMapString(std::vector<wxString> names) {
//	std::map<wxString, int> tempmap;
//	for (auto name : names) {
//		tempmap.emplace(name, 0);
//	}
//
//	return tempmap;
//}
//void** ToVoidData(std::vector<wxClientData*> ptrs) {
//	int size = ptrs.size();
//	void** temparraydata = new void* [size];
//	for (int i = 0; i < size; ++i) {
//		temparraydata[i] = ptrs[i];
//	}
//
//	return temparraydata;
//}
//std::map<wxString, wxClientData*> ToMapBoth(std::vector<wxString> names, std::vector<wxClientData*> data) {
//	std::map<wxString, wxClientData*> temp;
//
//	for (unsigned int i = 0; i < names.size(); ++i) {
//		temp.emplace(names[i], data[i]);
//	}
//
//	return temp;
//}
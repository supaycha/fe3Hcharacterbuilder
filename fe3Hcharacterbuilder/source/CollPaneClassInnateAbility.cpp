//#include "CollPaneClassInnateAbility.h"
//
//CollPaneClassInnateAbility::CollPaneClassInnateAbility(std::map<wxString, wxClientData*> classinnateabilities, wxWindow* parent, wxWindowID id, const wxString& label) :
//	wxCollapsiblePane(parent, id, label, wxDefaultPosition, wxSize(-1, -1))
//{
//	/*mainsizer = new wxBoxSizer(wxVERTICAL);*/
//	wxWindow* ciawindow = this->GetPane();
//	gcias = new GridClassInnateAbilityStats(ciawindow, (int)ID_SINGLE_CONTROL::ID_GCLIAS);
//
//	wxBoxSizer* ciasizer = new wxBoxSizer(wxVERTICAL);
//	ciasizer->Add(gcias, 0, wxEXPAND, 0);
//
//	ciawindow->SetSizer(ciasizer);
//	ciasizer->SetSizeHints(ciawindow);
//	//this->SetSizer(mainsizer);
//}
//
//void CollPaneClassInnateAbility::ReceiveClassInnateExclusivity(wxString classname) {
//	currentLBCselection = classname;
//	repopulate();
//}
//
//void CollPaneClassInnateAbility::repopulate() {
//	std::wstring abilityname;
//	for (auto element : classinnateabilities) {
//		ClassInnateAbility* tempability = dynamic_cast<ClassInnateAbility*>(element.second)->clone();
//		std::wstring abilityns = tempability->getSource(), buffer;
//		std::wstringstream stream(abilityns);
//		std::vector<std::wstring> namesfromstream;
//	
//		while (std::getline(stream, buffer, L',')) {
//			namesfromstream.push_back(buffer);
//		}
//	
//		for (auto possiblematch : namesfromstream) {
//			if (possiblematch == currentLBCselection) {
//				abilitynames.push_back(tempability->getName());
//			}
//		}
//	}
//
//	this->SetLabelText(abilityname);
//	this->Refresh();
//}
//
//void CollPaneClassInnateAbility::OnCollPaneChange(wxCollapsiblePaneEvent& event) {
//
//	//this->GetParent()->Layout();
//	event.Skip();
//}
//
//wxBEGIN_EVENT_TABLE(CollPaneClassInnateAbility, wxCollapsiblePane)
//	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPCLIA, CollPaneClassInnateAbility::OnCollPaneChange)
//wxEND_EVENT_TABLE()
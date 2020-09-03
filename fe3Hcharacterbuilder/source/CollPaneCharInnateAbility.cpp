//#include "CollPaneCharInnateAbility.h"
//
//CollPaneCharInnateAbility::CollPaneCharInnateAbility(std::map<wxString, wxClientData*> characterinnateabilitymap, wxWindow* parent, wxWindowID id, const wxString& label) :
//	wxCollapsiblePane(parent, id, label, wxDefaultPosition, wxSize(-1, -1))
//{
//	characterinnateabilities = characterinnateabilitymap;
//	/*mainsizer = new wxBoxSizer(wxVERTICAL);*/
//	wxWindow* ciawindow = this->GetPane();
//	gchias = new GridCharInnateAbilityStats(ciawindow, (int)ID_SINGLE_CONTROL::ID_GCHIAS);
//
//	wxBoxSizer* ciasizer = new wxBoxSizer(wxVERTICAL);
//	ciasizer->Add(gchias, 0, wxEXPAND, 0);
//
//	ciawindow->SetSizer(ciasizer);
//	ciasizer->SetSizeHints(ciawindow);
//	//this->SetSizer(mainsizer);
//}
//
//void CollPaneCharInnateAbility::ReceiveCharacterInnateExclusivity(wxString charactername) {
//	currentDDCselection = charactername;
//	repopulate();
//}
//
//void CollPaneCharInnateAbility::repopulate() {
//	//for (auto element : characterinnateabilities) {
//	//	Ability* tempability = dynamic_cast<Ability*>(element.second)->clone();
//	//	if (CharacterInnateAbility* tempchia = dynamic_cast<CharacterInnateAbility*>(tempability)) {
//	//		characterinnateabilities.push_back(tempchia);
//	//	}
//	//}
//	std::wstring abilityname;
//	for (auto element : characterinnateabilities) {
//		CharacterInnateAbility* tempability = dynamic_cast<CharacterInnateAbility*>(element.second)->clone();
//		if (tempability->getSource() == currentDDCselection) {
//			abilityname = tempability->getName();
//		}
//	}
//
//	this->SetLabelText(abilityname);
//	this->Refresh();
//	//gchias->ReceiveAbilityStats(abilitystats);
//	//Freeze();
//	//Thaw();
//}
//
//void CollPaneCharInnateAbility::OnCollPaneChange(wxCollapsiblePaneEvent& event) {
//
//	//this->GetParent()->Layout();
//	event.Skip();
//}
//
//wxBEGIN_EVENT_TABLE(CollPaneCharInnateAbility, wxCollapsiblePane)
//	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPCHIA, CollPaneCharInnateAbility::OnCollPaneChange)
//wxEND_EVENT_TABLE()
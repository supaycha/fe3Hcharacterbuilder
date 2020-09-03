//#include "CollPaneSkillLevelAbility.h"
//
//CollPaneSkillLevelAbility::CollPaneSkillLevelAbility(std::map<wxString, wxClientData*> skilllevelabilities, wxWindow* parent, wxWindowID id, const wxString& label) :
//	wxCollapsiblePane(parent, id, label, wxDefaultPosition, wxSize(-1, -1))
//{
//	/*mainsizer = new wxBoxSizer(wxVERTICAL);*/
//	wxWindow* ciawindow = this->GetPane();
//	gcias = new GridSkillLevelAbilityStats(ciawindow, (int)ID_SINGLE_CONTROL::ID_GSLAS);
//
//	wxBoxSizer* ciasizer = new wxBoxSizer(wxVERTICAL);
//	ciasizer->Add(gcias, 0, wxEXPAND, 0);
//
//	ciawindow->SetSizer(ciasizer);
//	ciasizer->SetSizeHints(ciawindow);
//	//this->SetSizer(mainsizer);
//}
//
//void CollPaneSkillLevelAbility::OnCollPaneChange(wxCollapsiblePaneEvent& event) {
//
//	//this->GetParent()->Layout();
//	event.Skip();
//}
//
//wxBEGIN_EVENT_TABLE(CollPaneSkillLevelAbility, wxCollapsiblePane)
//	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPSLA, CollPaneSkillLevelAbility::OnCollPaneChange)
//wxEND_EVENT_TABLE()
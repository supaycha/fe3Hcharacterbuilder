//#ifndef COLLPANECHARINNATEABILITY_H
//#define COLLPANECHARINNATEABILITY_H
//
//#include <wx/wx.h>
//#include <wx/collpane.h>
//#include <map>
//#include <GridCharInnateAbilityStats.h>
//#include <Unit/Ability/Ability.h>
//#include <Unit/Ability/CharacterInnateAbility.h>
//
//class CollPaneCharInnateAbility : public wxCollapsiblePane {
//private:
//	GridCharInnateAbilityStats* gchias;
//	wxBoxSizer* mainsizer;
//
//	wxString currentDDCselection;
//	std::map<wxString, wxClientData*> characterinnateabilities;
//	wxDECLARE_EVENT_TABLE();
//public:
//	CollPaneCharInnateAbility(std::map<wxString, wxClientData*> characterinnateabilities, wxWindow* parent, wxWindowID id, const wxString& label);
//	~CollPaneCharInnateAbility() {}
//
//	void ReceiveCharacterInnateExclusivity(wxString charactername);
//	void repopulate();
//
//	void OnCollPaneChange(wxCollapsiblePaneEvent& event);
//};
//
//#endif
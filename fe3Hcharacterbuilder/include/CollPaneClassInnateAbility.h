//#ifndef COLLPANECLASSINNATEABILITY_H
//#define COLLPANECLASSINNATEABILITY_H
//
//#include <wx/wx.h>
//#include <wx/collpane.h>
//#include <map>
//#include <sstream>
//#include <GridClassInnateAbilityStats.h>
//#include <Unit/Ability/Ability.h>
//#include <Unit/Ability/ClassInnateAbility.h>
//
//
//class CollPaneClassInnateAbility : public wxCollapsiblePane {
//private:
//	GridClassInnateAbilityStats* gcias;
//	wxBoxSizer* mainsizer;
//
//	wxString currentLBCselection;
//	std::map<wxString, wxClientData*> classinnateabilities;
//	std::vector<wxString> abilitynames;
//
//	wxDECLARE_EVENT_TABLE();
//public:
//	CollPaneClassInnateAbility(std::map<wxString, wxClientData*> classinnateabilities, wxWindow* parent, wxWindowID id, const wxString& label);
//	~CollPaneClassInnateAbility() {}
//
//	void ReceiveClassInnateExclusivity(wxString classname);
//	void repopulate();
//
//	void OnCollPaneChange(wxCollapsiblePaneEvent& event);
//};
//
//#endif
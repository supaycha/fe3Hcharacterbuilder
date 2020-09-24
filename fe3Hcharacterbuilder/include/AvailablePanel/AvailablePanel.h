#ifndef AVAILABLEPANEL__H
#define AVAILABLEPANEL__H
#include <wx/wx.h>
#include <wx/tglbtn.h>
#include <map>
#include <constants.h>
#include <AvailablePanel/ListBoxASLA.h>
#include <AvailablePanel/ListBoxBattalions.h>
#include <AvailablePanel/ListBoxEquipment.h>
#include <AvailablePanel/WeaponManager/WeaponManager.h>
#include <AvailablePanel/SkillLevelManager/SkillLevelManager.h>

class AvailablePanel : public wxPanel {
private:
	wxBoxSizer* slpSizer;
	SkillLevelManager* slm;
	WeaponManager* wm;
	ListBoxASLA* lbasla;
	ListBoxBattalions* lbb;
	ListBoxEquipment* lbe;
	wxToggleButton* includeClassMasteries;
	wxDECLARE_EVENT_TABLE();
public:
	AvailablePanel(std::map<wxString, wxClientData*> weaponmap, std::map<wxString, wxClientData*> battalionmap, std::map<wxString, wxClientData*> equipmap, std::map<wxString, wxClientData*> skilllevelabilitymap, std::map<wxString, wxClientData*> classmasteryabilitymap, wxWindow* parent, wxWindowID id);
	~AvailablePanel() {}

	void ReceiveDDCHSelection(wxString charactername);
	void ReceiveClassMasteryExclusivity(wxString classmasterycheck);
	void ReceiveEquipmentExclusivity(wxString charactername);
	void BounceSLInfo(wxCommandEvent& info);
	void OnToggle(wxCommandEvent& eventfromwho);
};


#endif
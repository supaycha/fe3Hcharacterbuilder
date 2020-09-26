#ifndef AVAILABLEPANEL__H
#define AVAILABLEPANEL__H
#include <wx/wx.h>
#include <wx/tglbtn.h>
#include <map>
#include <constants.h>
#include <AvailablePanel/ListBoxASLA.h>
#include <AvailablePanel/ListBoxBattalions.h>
#include <AvailablePanel/ListBoxEquipment.h>
#include <AvailablePanel/DropDownSkillLevel.h>
#include <AvailablePanel/ListBoxWeapons.h>

class AvailablePanel : public wxPanel {
private:
	wxBoxSizer* mainsizer;
	std::vector<wxString> labels{ 
		"Sword", "Axe", "Lance",
		"Bow", "Gauntlets", "Reason", 
		"Faith", "Authority", "Heavy Armor", 
		"Riding", "Flying" };
	std::vector<DropDownSkillLevel*> ddslVector;
	std::vector<wxStaticText*> stslVector;

	ListBoxWeapons* lbw;
	std::vector<wxString> bitmapVector{
		"IDB_SWORD23", "IDB_AXE23", "IDB_LANCE23",
		"IDB_BOW23", "IDB_GAUNTLETS23", "IDB_BLACKMAGIC23",
		"IDB_DARKMAGIC23", "IDB_WHITEMAGIC23" };
	std::vector<wxToggleButton*> weapontypesVector;
	std::vector<wxBitmap> weaponbitmapVector;

	ListBoxASLA* lbasla;	
	wxToggleButton* includeClassMasteries;
	ListBoxBattalions* lbb;
	ListBoxEquipment* lbe;
	wxDECLARE_EVENT_TABLE();
public:
	AvailablePanel(std::map<wxString, wxClientData*> weaponmap, std::map<wxString, wxClientData*> battalionmap, std::map<wxString, wxClientData*> equipmap, std::map<wxString, wxClientData*> skilllevelabilitymap, std::map<wxString, wxClientData*> classmasteryabilitymap, wxWindow* parent, wxWindowID id);
	~AvailablePanel() {}

	void ReceiveDDCHSelection(wxString charactername);
	void ReceiveClassMasteryExclusivity(wxString classmasterycheck);
	void ReceiveEquipmentExclusivity(wxString charactername);
	void BounceSLInfo(wxCommandEvent& ddsl);
	void BounceSTInfo(wxCommandEvent& info);
	void OnToggle(wxCommandEvent& eventfromwho);
	//void OnNewSelection(wxCommandEvent& uevent);
};


#endif
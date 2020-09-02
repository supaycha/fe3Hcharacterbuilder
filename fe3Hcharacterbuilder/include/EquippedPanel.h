#ifndef EQUIPPEDPANEL_H
#define EQUIPPEDPANEL_H

#include <wx/wx.h>
#include <map>
#include <EquippedOptions/EquippedBattalion.h>
#include <EquippedOptions/EquippedWeapon.h>
#include <EquippedOptions/EquippedEquipment.h>
#include <AbilityPanel.h>

class EquippedPanel : public wxPanel {
private:
	wxBoxSizer* panelsizer;
	EquippedBattalion* eb;
	EquippedWeapon* ew;
	EquippedEquipment* ee;
	AbilityPanel* ap;
	wxDECLARE_EVENT_TABLE();
public:
	EquippedPanel(std::map<wxString, wxClientData*> abilitymap, wxWindow* parent, wxWindowID id);
	~EquippedPanel() {}

	void ReceiveLBWSelection(Stats stats);
	void ReceiveLBESelection(Stats stats);
	void ReceiveLBBSelection(Stats stats);
	void ReceiveCharacterInnateExclusivity(wxString charactername);
	void ReceiveClassInnateExclusivity(wxString classname);
	void OnSize(wxSizeEvent& event);
	void OnCollChange(wxCollapsiblePaneEvent& event);
};

#endif
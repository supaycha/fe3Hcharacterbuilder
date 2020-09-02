#ifndef EQUIPPEDPANEL_H
#define EQUIPPEDPANEL_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <map>
#include <CollPaneWeapon.h>
#include <CollPaneBattalion.h>
#include <CollPaneEquipment.h>
#include <GridMain/GridBattalionStats.h>
#include <AbilityPanel.h>

class EquippedPanel : public wxPanel {
private:
	wxBoxSizer* panelsizer;
	CollPaneBattalion* cpb;
	CollPaneWeapon* cpw;
	CollPaneEquipment* cpe;
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
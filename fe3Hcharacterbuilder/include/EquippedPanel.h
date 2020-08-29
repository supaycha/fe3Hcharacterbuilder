#ifndef EQUIPPEDPANEL_H
#define EQUIPPEDPANEL_H

#include <wx/wx.h>
#include <wx/collpane.h>
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
	EquippedPanel(wxWindow* parent, wxWindowID id);
	~EquippedPanel() {}

	void OnSize(wxSizeEvent& event);
	void OnCollChange(wxCollapsiblePaneEvent& event);
};

#endif
#ifndef EQUIPPEDPANEL_H
#define EQUIPPEDPANEL_H

#include <wx/wx.h>
#include <WeaponCollPane.h>
#include <BattalionCollPane.h>
#include <GridMain/GridBattalionStats.h>

class EquippedPanel : public wxPanel {
private:
	wxBoxSizer* panelsizer;
	BattalionCollPane* bcp;
	WeaponCollPane* wcp;

	wxDECLARE_EVENT_TABLE();
public:
	EquippedPanel(wxWindow* parent, wxWindowID id);
	~EquippedPanel() {}

	void OnCollChange(wxCollapsiblePaneEvent& event);
};

#endif
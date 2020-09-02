#ifndef COLLPANEWEAPON_H
#define COLLPANEWEAPON_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <GridMain/GridWeaponStats.h>

class CollPaneWeapon : public wxCollapsiblePane {
private:
	GridWeaponStats* gws;
	wxBoxSizer* mainsizer;
	wxDECLARE_EVENT_TABLE();
public:
	CollPaneWeapon(wxWindow* parent, wxWindowID id, const wxString& label);
	~CollPaneWeapon() {}

	void ReceiveLBWSelection(Stats stats);

	void OnCollPaneChange(wxCollapsiblePaneEvent& event);
};

#endif
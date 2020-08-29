#ifndef WEAPONCOLLPANE_H
#define WEAPONCOLLPANE_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <GridMain/GridWeaponStats.h>

class WeaponCollPane : public wxCollapsiblePane {
private:
	GridWeaponStats* gws;
	wxBoxSizer* mainsizer;
	wxDECLARE_EVENT_TABLE();
public:
	WeaponCollPane(wxWindow* parent, wxWindowID id, const wxString& label);
	~WeaponCollPane() {}
	void OnCollPaneChange(wxCollapsiblePaneEvent& event);

};

#endif
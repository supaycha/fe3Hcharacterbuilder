#ifndef BATTALIONCOLLPANE_H
#define BATTALIONCOLLPANE_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <GridMain/GridBattalionStats.h>

class BattalionCollPane : public wxCollapsiblePane {
private:
	GridBattalionStats* gbs;
	wxBoxSizer* mainsizer;
	wxDECLARE_EVENT_TABLE();
public:
	BattalionCollPane(wxWindow* parent, wxWindowID id, const wxString& label);
	~BattalionCollPane() {}

	void OnCollPaneChange(wxCollapsiblePaneEvent& event);
};

#endif
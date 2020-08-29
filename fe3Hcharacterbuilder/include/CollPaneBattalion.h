#ifndef COLLPANEBATTALION_H
#define COLLPANEBATTALION_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <GridMain/GridBattalionStats.h>

class CollPaneBattalion : public wxCollapsiblePane {
private:
	GridBattalionStats* gbs;
	wxBoxSizer* mainsizer;
	wxDECLARE_EVENT_TABLE();
public:
	CollPaneBattalion(wxWindow* parent, wxWindowID id, const wxString& label);
	~CollPaneBattalion() {}

	void OnCollPaneChange(wxCollapsiblePaneEvent& event);
};

#endif
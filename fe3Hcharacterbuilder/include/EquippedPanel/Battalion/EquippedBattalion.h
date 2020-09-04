#ifndef EQUIPPEDBATTALION_H
#define EQUIPPEDBATTALION_H

#include <wx/wx.h>

class EquippedBattalion : public wxStaticText {
private:
public:
	EquippedBattalion(wxWindow* parent, wxWindowID id, const wxString& label);
	~EquippedBattalion() {}

	void ReceiveLBBSelection(wxString battalionname);
};

#endif
#ifndef BUTTONADDABILITY_H
#define BUTTONADDABILITY_H

#include <wx/wx.h>
#include <constants.h>

wxDECLARE_EVENT(SELECTION_HAS_CHANGED, wxCommandEvent);

class ButtonAddAbility : public wxButton {
private:
	wxDECLARE_EVENT_TABLE();
public:
	ButtonAddAbility(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2);
	~ButtonAddAbility() {}

	void OnClick(wxCommandEvent& uevent);
};

#endif
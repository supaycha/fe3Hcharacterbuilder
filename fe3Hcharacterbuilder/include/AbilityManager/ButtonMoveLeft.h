#ifndef BUTTONMOVELEFT_H
#define BUTTONMOVELEFT_H

#include <wx/wx.h>
#include <constants.h>

wxDECLARE_EVENT(SELECTION_HAS_CHANGED, wxCommandEvent);

class ButtonMoveLeft : public wxButton {
private:
	wxDECLARE_EVENT_TABLE();
public:
	ButtonMoveLeft(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2);
	~ButtonMoveLeft() {}

	void OnClick(wxCommandEvent& uevent);
};

#endif
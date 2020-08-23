#ifndef BUTTONMOVERIGHT_H
#define BUTTONMOVERIGHT_H

//#include <wx/wx.h>
//#include "constants.h"

wxDECLARE_EVENT(SELECTION_HAS_CHANGED, wxCommandEvent);

class ButtonMoveRight : public wxButton {
private:
	wxDECLARE_EVENT_TABLE();
public:
	ButtonMoveRight(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2);
	~ButtonMoveRight() {}

	void OnClick(wxCommandEvent& event);
};

#endif
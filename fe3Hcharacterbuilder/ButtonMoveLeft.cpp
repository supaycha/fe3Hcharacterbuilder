#include "ButtonMoveLeft.h"

ButtonMoveLeft::ButtonMoveLeft(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2) :
	wxButton(panel, id, label, wxPoint(x, y), wxSize(x2, y2))
{
}

void ButtonMoveLeft::OnClick(wxCommandEvent& uevent) {
	wxCommandEvent event(SELECTION_HAS_CHANGED, ID_BML);
	ProcessEvent(event);
}

wxBEGIN_EVENT_TABLE(ButtonMoveLeft, wxButton)
	EVT_BUTTON(ID_BML, ButtonMoveLeft::OnClick)
wxEND_EVENT_TABLE()
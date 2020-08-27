#include <ButtonAddAbility.h>

ButtonAddAbility::ButtonAddAbility(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2) :
	wxButton(panel, id, label, wxPoint(x, y), wxSize(x2, y2))
{
}

void ButtonAddAbility::OnClick(wxCommandEvent& uevent) {
	wxCommandEvent event(SELECTION_HAS_CHANGED, (int)ID_SINGLE_CONTROL::ID_BAA);
	ProcessEvent(event);
}

wxBEGIN_EVENT_TABLE(ButtonAddAbility, wxButton)
	EVT_BUTTON((int)ID_SINGLE_CONTROL::ID_BAA, ButtonAddAbility::OnClick)
wxEND_EVENT_TABLE()
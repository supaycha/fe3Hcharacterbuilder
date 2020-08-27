#include <ButtonRemoveAbility.h>

ButtonRemoveAbility::ButtonRemoveAbility(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2) :
	wxButton(panel, id, label, wxPoint(x, y), wxSize(x2, y2))
{
}

void ButtonRemoveAbility::OnClick(wxCommandEvent& uevent) {
	wxCommandEvent event(SELECTION_HAS_CHANGED, (int)ID_SINGLE_CONTROL::ID_BRA);
	ProcessEvent(event);
}

wxBEGIN_EVENT_TABLE(ButtonRemoveAbility, wxButton)
	EVT_BUTTON((int)ID_SINGLE_CONTROL::ID_BRA, ButtonRemoveAbility::OnClick)
wxEND_EVENT_TABLE()
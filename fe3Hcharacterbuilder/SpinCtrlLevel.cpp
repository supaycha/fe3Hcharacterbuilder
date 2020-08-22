#include "SpinCtrlLevel.h"

SpinCtrlLevel::SpinCtrlLevel(wxWindow* parent, wxWindowID id, const wxString& value, int min) :
	wxSpinCtrl(parent, id, value, wxDefaultPosition, wxDefaultSize, min)
{
	Bind(wxEVT_SPINCTRL, &SpinCtrlLevel::OnNewSelection, this, ID_SPIN1, ID_SPIN2);
}

void SpinCtrlLevel::OnNewSelection(wxSpinEvent& selection) {
	wxSpinEvent event(TRANSMIT_SCL_SELECTION, selection.GetId());
	int selectedvalue = selection.GetValue();
	event.SetInt(selectedvalue);
	ProcessEvent(event);
}
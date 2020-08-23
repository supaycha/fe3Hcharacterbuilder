#include <MysteriousTeacher\SpinCtrlLevel.h>

SpinCtrlLevel::SpinCtrlLevel(wxWindow* parent, wxWindowID id, const wxString& value, int min) :
	wxSpinCtrl(parent, id, value, wxDefaultPosition, wxDefaultSize, min)
{
	Bind(wxEVT_SPINCTRL, &SpinCtrlLevel::OnNewSelection, this, (int)ID_MISC::ID_SPIN1, (int)ID_MISC::ID_SPIN2);
}

void SpinCtrlLevel::OnNewSelection(wxSpinEvent& selection) {
	wxSpinEvent event(TRANSMIT_SCL_SELECTION, selection.GetId());
	int selectedvalue = selection.GetValue();
	event.SetInt(selectedvalue);
	ProcessEvent(event);
}
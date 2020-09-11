#include <EquippedPanel/Gambit/EquippedGambit.h>

EquippedGambit::EquippedGambit(wxWindow* parent, wxWindowID id, const wxString& label) :
	wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize)
{
}

void EquippedGambit::ReceiveLBBSelection(wxString gambitname) {
	this->SetLabelText(gambitname);
}
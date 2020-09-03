#include <EquippedOptions/EquippedWeapon.h>

EquippedWeapon::EquippedWeapon(wxWindow* parent, wxWindowID id, const wxString& label) :
	wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize)
{
}

void EquippedWeapon::ReceiveLBWSelection(wxString weaponname) {
	this->SetLabelText(weaponname);
}

wxBEGIN_EVENT_TABLE(EquippedWeapon, wxStaticText)
wxEND_EVENT_TABLE()
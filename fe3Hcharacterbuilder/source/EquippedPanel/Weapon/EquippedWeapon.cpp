#include <EquippedPanel/Weapon/EquippedWeapon.h>

EquippedWeapon::EquippedWeapon(wxWindow* parent, wxWindowID id, const wxString& label) :
	wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize)
{
}

void EquippedWeapon::ReceiveLBWSelection(wxString weaponname) {
	this->SetLabelText(weaponname);
}
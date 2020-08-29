#ifndef EQUIPPEDWEAPON_H
#define EQUIPPEDWEAPON_H

#include <wx/wx.h>

class EquippedWeapon : wxTextCtrl {
private:
public:
	EquippedWeapon(wxWindow* parent, wxWindowID id);
	~EquippedWeapon() {}
};

#endif
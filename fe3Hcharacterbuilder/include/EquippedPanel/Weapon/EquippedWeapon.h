#ifndef EQUIPPEDWEAPON_H
#define EQUIPPEDWEAPON_H

#include <wx/wx.h>
#include <Stat.h>

class EquippedWeapon : public wxStaticText {
private:
public:
	EquippedWeapon(wxWindow* parent, wxWindowID id, const wxString& label);
	~EquippedWeapon() {}
	int id;

	void ReceiveLBWSelection(wxString weaponname);
};

#endif
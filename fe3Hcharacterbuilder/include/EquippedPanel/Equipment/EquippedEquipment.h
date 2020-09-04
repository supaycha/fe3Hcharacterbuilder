#ifndef EQUIPPEDEQUIPMENT_H
#define EQUIPPEDEQUIPMENT_H

#include <wx/wx.h>

class EquippedEquipment : public wxStaticText {
private:
public:
	EquippedEquipment(wxWindow* parent, wxWindowID id, const wxString& label);
	~EquippedEquipment() {}

	void ReceiveLBESelection(wxString equipmentname);
};

#endif
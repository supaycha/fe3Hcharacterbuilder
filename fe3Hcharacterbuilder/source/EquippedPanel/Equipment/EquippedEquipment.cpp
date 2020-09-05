#include <EquippedPanel/Equipment/EquippedEquipment.h>

EquippedEquipment::EquippedEquipment(wxWindow* parent, wxWindowID id, const wxString& label) :
	wxStaticText(parent, id, label)
{
}

void EquippedEquipment::ReceiveLBESelection(wxString equipmentname, wxString equipmentdescription) {	
	this->SetLabelText(equipmentname);
	SetToolTip(equipmentdescription);
}
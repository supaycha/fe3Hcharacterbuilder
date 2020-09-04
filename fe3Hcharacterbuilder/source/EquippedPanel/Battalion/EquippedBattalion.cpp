#include <EquippedPanel/Battalion/EquippedBattalion.h>

EquippedBattalion::EquippedBattalion(wxWindow* parent, wxWindowID id, const wxString& label) :
	wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize)
{

}

void EquippedBattalion::ReceiveLBBSelection(wxString battalionname) {
	this->SetLabelText(battalionname);
}
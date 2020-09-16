#ifndef EQUIPPEDGAMBIT_H
#define EQUIPPEDGAMBIT_H

#include <wx/wx.h>

class EquippedGambit : public wxStaticText {
private:
public:
	EquippedGambit(wxWindow* parent, wxWindowID id, const wxString& label);
	~EquippedGambit() {}

	void ReceiveLBBSelection(wxString gambitname);
};

#endif
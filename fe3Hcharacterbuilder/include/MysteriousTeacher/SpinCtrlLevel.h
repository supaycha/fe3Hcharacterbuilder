#ifndef SPINCTRLLEVEL_H
#define SPINCTRLLEVEL_H

#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <constants.h>

wxDECLARE_EVENT(TRANSMIT_SCL_SELECTION, wxSpinEvent);

class SpinCtrlLevel : public wxSpinCtrl {
private:
public:
	SpinCtrlLevel(wxWindow* parent, wxWindowID id, const wxString& value, int min);
	~SpinCtrlLevel() {}

	void OnNewSelection(wxSpinEvent& event);
};

#endif
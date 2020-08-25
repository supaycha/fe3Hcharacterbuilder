#ifndef BUTTONREMOVEABILITY_H
#define BUTTONREMOVEABILITY_H

#include <wx/wx.h>
#include "constants.h"

wxDECLARE_EVENT(SELECTION_HAS_CHANGED, wxCommandEvent);

class ButtonRemoveAbility : public wxButton {
private:
	wxDECLARE_EVENT_TABLE();
public:
	ButtonRemoveAbility(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2);
	~ButtonRemoveAbility() {}

	void OnClick(wxCommandEvent& event);
};

#endif
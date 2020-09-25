#ifndef STATICTEXTSKILLLEVEL_H
#define STATICTEXTSKILLLEVEL_H

#include <wx/wx.h>

class StaticTextSkillLevel : public wxStaticText {
private:
	//wxString stname;
public:
	StaticTextSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, int x, int y);
	~StaticTextSkillLevel() {}
};

#endif
#ifndef RIGHTTOOLBAR_H
#define RIGHTTOOLBAR_H

#include <wx/aui/auibar.h>

class RightToolBar : public wxAuiToolBar {
private:
public:
	RightToolBar(wxWindow* parent, wxWindowID id);
	~RightToolBar() {}
};

#endif
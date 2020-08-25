#ifndef LISTBOXSLA_H
#define LISTBOXSLA_H

#include <wx/wx.h>
 
class ListBoxSLA {
private:
public:
	ListBoxSLA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~ListBoxSLA() {}

};

#endif
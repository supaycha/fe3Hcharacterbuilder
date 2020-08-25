#ifndef LISTBOXCLIA_H
#define LISTBOXCLIA_H

#include <wx/wx.h>

class ListBoxCLIA {
private:
public:
	ListBoxCLIA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~ListBoxCLIA() {}

};

#endif
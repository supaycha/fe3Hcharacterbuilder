#ifndef LISTBOXCHIA_H
#define LISTBOXCHIA_H

#include <wx/wx.h>

class ListBoxCHIA {
private:
public:
	ListBoxCHIA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~ListBoxCHIA() {}

};

#endif
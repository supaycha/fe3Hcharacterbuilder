#ifndef MYAPP_H
#define MYAPP_H

#include <wx/wx.h>
#include <wx/imagpng.h>
#include <MyFrame.h>
#include <constants.h>
//#include <vld.h>

class MyApp : public wxApp {
public:
	virtual bool OnInit();
};

DECLARE_APP(MyApp);
//wxArrayString ToArrayString(std::vector<wxString> names);
//wxClientData** ToArrayData(std::vector<wxClientData*>& names);
//std::map<wxString, int> ToMapString(std::vector<wxString> names);
//void** ToVoidData(std::vector<wxClientData*> ptrs);
//std::map<wxString, wxClientData*> ToMapBoth(std::vector<wxString> names, std::vector<wxClientData*> data);


#endif
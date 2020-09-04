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

#endif
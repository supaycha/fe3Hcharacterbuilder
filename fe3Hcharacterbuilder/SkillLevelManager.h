#ifndef SKILLLEVELMANAGER_H
#define SKILLLEVELMANAGER_H
#include "MyFrame.h"
#include <wx/wx.h>
#include <map>

#include "constants.h"
//#include <vld.h>

wxDECLARE_EVENT(TRANSMIT_SL_SELECTION, wxCommandEvent);

class DropDownSkillLevel;
class StaticTextSkillLevel;
class MyFrame;
class SkillLevelManager : public wxPanel {
private:
	std::map<StaticTextSkillLevel*, DropDownSkillLevel*>* manager;
	wxDECLARE_EVENT_TABLE();
public:
	SkillLevelManager(MyFrame* parent, wxWindowID id);
	~SkillLevelManager() {}

	void OnNewSelection(wxCommandEvent& uevent);
};

class StaticTextSkillLevel : public wxStaticText {
private:
	wxString stname;
public:
	StaticTextSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, int x, int y, int x2, int y2);
	~StaticTextSkillLevel() {}
};

class DropDownSkillLevel : public wxComboBox {
private:
	wxString ddname;
public:
	DropDownSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, const wxString& value, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~DropDownSkillLevel() {}

	void initpopulate();

	wxArrayString ToArrayString(std::vector<wxString> names);
	wxClientData** ToArrayData(std::vector<wxClientData*>& names);
};

#endif
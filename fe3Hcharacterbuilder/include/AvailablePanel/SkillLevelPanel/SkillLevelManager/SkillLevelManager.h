#ifndef SKILLLEVELMANAGER_H
#define SKILLLEVELMANAGER_H

#include <wx/wx.h>
#include <map>
#include <constants.h>
#include <AvailablePanel/SkillLevelPanel/SkillLevelManager/StaticTextSkillLevel.h>
#include <AvailablePanel/SkillLevelPanel/SkillLevelManager/DropDownSkillLevel.h>
////#include <vld.h>

wxDECLARE_EVENT(TRANSMIT_SL_SELECTION, wxCommandEvent);

class SkillLevelManager : public wxPanel {
private:
	std::map<StaticTextSkillLevel*, DropDownSkillLevel*>* manager;
	wxDECLARE_EVENT_TABLE();
public:
	SkillLevelManager(wxWindow* parent, wxWindowID id);
	~SkillLevelManager() {}

	void OnNewSelection(wxCommandEvent& uevent);
};

#endif
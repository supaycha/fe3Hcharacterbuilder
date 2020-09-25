#include <AvailablePanel/SkillLevelManager/StaticTextSkillLevel.h>

StaticTextSkillLevel::StaticTextSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, int x, int y) :
	wxStaticText(parent, id, label, wxDefaultPosition, wxSize(x, y))
{
	//stname = label;
}
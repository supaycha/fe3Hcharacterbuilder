#include <SkillLevelManager\StaticTextSkillLevel.h>

StaticTextSkillLevel::StaticTextSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, int x, int y, int x2, int y2) :
	wxStaticText(parent, id, label, wxPoint(x, y), wxSize(x2, y2))
{
	stname = label;
}
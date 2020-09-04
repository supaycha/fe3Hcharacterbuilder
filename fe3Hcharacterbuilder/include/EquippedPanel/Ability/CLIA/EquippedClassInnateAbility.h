#ifndef EQUIPPEDCLASSINNATEABILITY_H
#define EQUIPPEDCLASSINNATEABILITY_H

#include <wx/wx.h>
#include <map>
//#include <vld.h>

class EquippedClassInnateAbility : public wxStaticText {
private:
	wxString currentLBCselection;
	std::vector<wxString> abilitynames;
public:
	EquippedClassInnateAbility(std::map<wxString, wxClientData*> classinnateabilities, wxWindow* parent, wxWindowID id, const wxString& label);
	~EquippedClassInnateAbility() {}

	void ReceiveClassInnateAbility(wxString classname);
	void repopulate();
};

#endif
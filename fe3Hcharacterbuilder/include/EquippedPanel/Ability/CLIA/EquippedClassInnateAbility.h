#ifndef EQUIPPEDCLASSINNATEABILITY_H
#define EQUIPPEDCLASSINNATEABILITY_H

#include <wx/wx.h>
#include <map>
//#include <sstream>
//#include <Unit/Unit.h>
//#include <Unit/Ability/Ability.h>
//#include <Unit/Ability/ClassInnateAbility.h>

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
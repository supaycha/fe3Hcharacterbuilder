#ifndef EQUIPPEDCLASSINNATEABILITY_H
#define EQUIPPEDCLASSINNATEABILITY_H

#include <wx/wx.h>
#include <map>
#include <Unit/Ability/ClassInnateAbility/ClassInnateAbility.h>
//#include <vld.h>

wxDECLARE_EVENT(TRANSMIT_CLIA_SELECTION, wxCommandEvent);

class EquippedClassInnateAbility : public wxStaticText {
private:
	wxString currentLBCselection;
	std::vector<wxString> abilitynames;
	std::map<wxString, wxClientData*> classinnateabilities;
public:
	EquippedClassInnateAbility(std::map<wxString, wxClientData*> classinnateabilities, wxWindow* parent, wxWindowID id, const wxString& label);
	~EquippedClassInnateAbility() {}

	void ReceiveClassInnateAbility(wxString classname);
	void repopulate();
	wxString RetrieveDescription(wxString currentLBCselection);
};

#endif
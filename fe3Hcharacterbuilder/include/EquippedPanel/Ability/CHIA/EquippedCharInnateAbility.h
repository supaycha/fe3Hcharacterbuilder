#ifndef EQUIPPEDCHARINNATEABILITY_H
#define EQUIPPEDCHARINNATEABILITY_H

#include <wx/wx.h>
#include <map>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/CharacterInnateAbility.h>

wxDECLARE_EVENT(TRANSMIT_CHIA_SELECTION, wxCommandEvent);

class EquippedCharInnateAbility : public wxStaticText {
private:
	wxString currentDDCselection;
	std::map<wxString, wxClientData*> characterinnateabilities;
public:
	EquippedCharInnateAbility(std::map<wxString, wxClientData*> characterinnateabilities, wxWindow* parent, wxWindowID id, const wxString& label);
	~EquippedCharInnateAbility() {}

	void ReceiveCharacterInnateExclusivity(wxString charactername);
	void repopulate();
	wxString RetrieveDescription(wxString abilityname);
};

#endif
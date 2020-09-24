#ifndef LISTBOXASLA_H
#define LISTBOXASLA_H

#include <wx/wx.h>
#include <map>
#include <sstream>
#include <constants.h>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/SkillLevelAbility/SkillLevelAbility.h>
#include <AbilitySelections.h>
#include <Lists/AbilityList.h>

wxDECLARE_EVENT(TRANSMIT_LBASLA_SELECTION, wxCommandEvent);

class ListBoxASLA : public wxListBox {
private:
	std::map<wxString, wxClientData*> skilllevelabilitymap;	
	std::map<wxString, wxClientData*> classmasteryabilitymap;
	std::vector<SL> SLfilter{ 11, SL::E };

	std::vector<wxString> allavailableabilities;
	std::vector<wxString> previouslyselectedabilities;
	std::vector<wxString> stillpresentabilities;
	std::vector<wxString> currentlyselectedabilities;

	wxString currentDDCHselection;
	wxString currentDDCLselection;
	bool isClassMasteryToggleButtonPressed = false;
	wxDECLARE_EVENT_TABLE();
public:
	ListBoxASLA(std::map<wxString, wxClientData*> skilllevelabilitymap, 
		std::map<wxString, wxClientData*> classmasteryabilitymap, 
		wxWindow* panel, wxWindowID id, 
		int x, int y, int x2, int y2, 
		const wxArrayString& choices, long style);
	~ListBoxASLA() {}

	void OnNewSelection(wxCommandEvent& selection);
	void ReceiveSLInfo(SKILLLEVELPACKAGE* slpackage);
	void ReceiveforAbilityExclusivityCheck(wxString charactername);
	void ReceiveClassMasteryExclusivity(wxString classmasterycheck);
	void ReceiveClassMasteryButtonStatus(bool isPressed);	

	void FactorInInternalChange();
	bool CheckForClearSignal();	
	std::vector<wxString> ClearSelections();
	std::vector<wxString> AccountforProwessRedudancies(std::vector<wxString> selectedAAnames);
	void FactorInExternalChange();

	std::vector<wxString> CreateListOfAvailableAbilities();
	std::vector<wxString> GetToBeErasedSelectedAbilities();
	std::vector<wxString> GetStillPresentAbilities(std::vector<wxString> allavailableabilities, std::vector<wxString> previouslyselectedabilities);
	void ReselectAbilities(std::vector<wxString> upreviouslyselectedabilities);

	void recalculate();
	void repopulate();

	wxArrayString ToArrayString(std::vector<wxString> names);	
};

#endif
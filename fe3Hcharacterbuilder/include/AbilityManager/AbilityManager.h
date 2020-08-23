#ifndef ABILITYMANAGER_H
#define ABILITYMANAGER_H

#include <wx/wx.h>
#include <map>
#include <sstream>
#include "../Unit.h"
#include "../AbilityList.h"
#include "../constants.h"
#include "../MyFrame.h"
#include "ListBoxAA.h"
#include "ListBoxSA.h"
#include "ButtonMoveRight.h"
#include "ButtonMoveLeft.h"
//#include <vld.h>

class MyFrame;

wxDECLARE_EVENT(SELECTION_HAS_CHANGED, wxCommandEvent);

class AbilityManager : public wxPanel {
private:
	std::map<wxString, wxClientData*> abilitymap;
	ListBoxAA* lbaa;
	ListBoxSA* lbsa;
	ButtonMoveRight* bmr;
	ButtonMoveLeft* bml;

	wxString currentDDCselection;
	wxString currentLBCselection;
	std::vector<SL> SLfilter{ 11, SL::E };

	std::vector<wxString> filterLtoR;
	std::vector<wxString> filterRtoL;
	wxDECLARE_EVENT_TABLE();
public:
	AbilityManager(MyFrame* parent, wxWindowID id);
	~AbilityManager() {}

	void ReceiveExclusivity(wxString charactername);
	void ReceiveSLInfo(SLPACKAGE* slpackage);
	void ReceiveClassInnate(wxString classname);
	void FilterAbilities();

	void BounceSelectionstoRight(wxCommandEvent& eventfromOnClick);
	void BounceSelectionstoLeft(wxCommandEvent& eventfromOnClick);
};

#endif
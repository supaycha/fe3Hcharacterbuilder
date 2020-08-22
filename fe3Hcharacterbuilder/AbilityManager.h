#ifndef ABILITYMANAGER_H
#define ABILITYMANAGER_H

#include <wx/wx.h>
#include <map>
#include <sstream>
#include "Unit.h"
#include "AbilityList.h"
#include "constants.h"
#include "MyFrame.h"
//#include <vld.h>

class ListBoxAA;
class ListBoxSA;
class ButtonMoveRight;
class ButtonMoveLeft;
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

class ListBoxAA : public wxListBox {
private:
	std::vector<wxString> filteredAAnames;
	std::vector<wxString> selectedAAnames;

	wxDECLARE_EVENT_TABLE();
public:
	ListBoxAA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~ListBoxAA() {}

	void OnSelection(wxCommandEvent& event);
	void ReceiveAbilityFiltration(std::vector<wxString> dirtynames);
	void ReceiveSelectionsfromBounceL(std::vector<wxString> uSelections);
	void repopulate();
	void reselection();

	std::vector<wxString> UpdateSelections();
	std::vector<wxString> GetSelectionsAA() { return selectedAAnames; }

	wxArrayString ToArrayString(std::vector<wxString> names);
};

class ListBoxSA : public wxListBox {
private:
	std::vector<wxString> filteredSAnames;
	std::vector<wxString> selectedSAnames;

	wxDECLARE_EVENT_TABLE();
public:
	ListBoxSA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~ListBoxSA() {}

	void OnSelection(wxCommandEvent& event);
	void ReceiveAbilityFiltration(std::vector<wxString> dirtynames);
	void ReceiveSelectionsfromBounceR(std::vector<wxString> uSelections);
	void repopulate();
	void reselection();

	std::vector<wxString> UpdateSelections();
	std::vector<wxString> GetSelectionsSAAndClear();

	wxArrayString ToArrayString(std::vector<wxString> names);
};

class ButtonMoveRight : public wxButton {
private:
	wxDECLARE_EVENT_TABLE();
public:
	ButtonMoveRight(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2);
	~ButtonMoveRight() {}

	void OnClick(wxCommandEvent& event);
};

class ButtonMoveLeft : public wxButton {
private:
	wxDECLARE_EVENT_TABLE();
public:
	ButtonMoveLeft(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2);
	~ButtonMoveLeft() {}

	void OnClick(wxCommandEvent& uevent);
};

#endif
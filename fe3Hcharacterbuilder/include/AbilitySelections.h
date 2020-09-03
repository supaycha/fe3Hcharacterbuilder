#ifndef ABILITYSELECTIONS_H
#define ABILITYSELECTIONS_H

#include <wx/wx.h>

class AbilitySelections : public wxClientData {
private:
	std::vector<wxString> selections;
public:
	AbilitySelections() {}
	AbilitySelections(std::vector<wxString> uselections) : selections{ uselections } {}

	std::vector<wxString> GetSelections() { return selections; }

	~AbilitySelections() {}

};

#endif
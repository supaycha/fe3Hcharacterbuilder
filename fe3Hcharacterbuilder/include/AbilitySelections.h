#ifndef ABILITYSELECTIONS_H
#define ABILITYSELECTIONS_H

#include <wx/wx.h>

class AbilitySelections : public wxClientData {
private:
	std::vector<wxString> selections;
public:
	AbilitySelections() {}
	AbilitySelections(std::vector<wxString> uselections) : selections{ uselections } {}
	~AbilitySelections() {}

	std::vector<wxString> GetSelections();
};

#endif
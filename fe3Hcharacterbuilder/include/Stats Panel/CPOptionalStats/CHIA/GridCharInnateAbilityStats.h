#ifndef GRIDCHARINNATEABILITYSTATS_H
#define GRIDCHARINNATEABILITYSTATS_H

#include <wx/wx.h>
#include <wx/collpane.h>
#include <wx/grid.h>
#include <map>
#include <Stat.h>
#include <constants.h>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/CharacterInnateAbility.h>
#include <Stats Panel/CPOptionalStats/CHIA/GTBCharInnateAbilityStats.h>

wxDECLARE_EVENT(TRANSMIT_GCHIAS_STATS, wxCommandEvent);

class GridCharInnateAbilityStats : public wxGrid {
private:
	GTBCharInnateAbilityStats* gtbchias;
public:
	GridCharInnateAbilityStats(std::map<wxString, wxClientData*> ucharacterinnateabilities, wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveCHIASelection(wxString abilityname);
	void ReceiveLBBSelection(bool battalionselectionmade);
	void repopulate();
};

#endif
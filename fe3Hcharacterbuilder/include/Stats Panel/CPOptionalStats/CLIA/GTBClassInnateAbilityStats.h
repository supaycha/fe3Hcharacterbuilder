#ifndef GTBCLASSINNATEABILITYSTATS_H
#define GTBCLASSINNATEABILITYSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <map>
#include <Stat.h>
#include <constants.h>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/ClassInnateAbility.h>

class GTBClassInnateAbilityStats : public wxGridTableBase {
private:
	std::vector<STATPACKAGE> headers{ { STATTYPE::PROT, "PROT" }, { STATTYPE::WEIGHT, "WGT" }, { STATTYPE::RES, "RES" }, { STATTYPE::HIT, "HIT" },
									{ STATTYPE::AVO, "AVO" }, { STATTYPE::TCRIT, "TCRIT" }, { STATTYPE::SPD, "SPD" }, { STATTYPE::MOV, "MOV" },
									{ STATTYPE::LCK, "LCK" }, { STATTYPE::MATK, "MATK" }, { STATTYPE::HEAL, "HEAL" }, { STATTYPE::RANGE, "RANGE" },
									{ STATTYPE::MIGHT, "MIGHT" } };
	std::vector<wxString> currentheaders{ };	
	std::map<wxString, wxClientData*> classinnateabilities;
	std::vector<STATPACKAGE> statpVector{ };
	wxString currentCLIAselection;
	bool hasStats = false;
public:
	GTBClassInnateAbilityStats(std::map<wxString, wxClientData*> ucharacterinnateabilities);
	~GTBClassInnateAbilityStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return 1; }
	wxString GetValue(int nothing, int index) override { return statpVector[index].value; }
	void SetValue(int nothin, int index, const wxString& value) override { statpVector[index].value = value; }
	
	void ReceiveCLIASSelection(wxString currentCLIAselection);	

	void recalculate();
	bool DetermineStatsPresence();

	std::vector<STATPACKAGE> RetrieveSTATPackage();
	wxString GetHeader(int index) { return currentheaders[index]; }
	std::vector<wxString> GetCurrentHeaders();
};

#endif
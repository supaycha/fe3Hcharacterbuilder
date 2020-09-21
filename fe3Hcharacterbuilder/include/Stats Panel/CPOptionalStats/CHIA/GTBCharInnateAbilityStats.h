#ifndef GTBCHARINNATEABILITYSTATS_H
#define GTBCHARINNATEABILITYSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <map>
#include <Stat.h>
#include <constants.h>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/CharacterInnateAbility.h>
//#include <Stats Panel/CPOptionalStats/CHIA/GTBCharInnateAbilityStats.h>

class GTBCharInnateAbilityStats : public wxGridTableBase {
private:
	std::vector<STATPACKAGE> headers{ { STATTYPE::PROT, "PROT" }, { STATTYPE::WEIGHT, "WGT" }, { STATTYPE::RES, "RES" }, { STATTYPE::HIT, "HIT" },
									{ STATTYPE::AVO, "AVO" }, /*{ STATTYPE::TCRIT, "TCRIT" },*/ { STATTYPE::SPD, "SPD" }, { STATTYPE::MOV, "MOV" },
									{ STATTYPE::LCK, "LCK" }, { STATTYPE::MATK, "MATK" }, { STATTYPE::HEAL, "HEAL" }, { STATTYPE::RANGE, "RANGE" },
									{ STATTYPE::MIGHT, "MIGHT" }, { STATTYPE::GMIGHT, "GMIGHT" }, { STATTYPE::GHIT, "GHIT" } };
	std::vector<wxString> currentheaders{ };
	std::map<wxString, wxClientData*> characterinnateabilities;
	std::vector<STATPACKAGE> statpVector {};
	bool hasStats = false;
	wxString currentCHIAselection;
	bool battalionselectionmade;
	bool battalionmustexist;
	wxString currentheader;
public:
	GTBCharInnateAbilityStats(std::map<wxString, wxClientData*> ucharacterinnateabilities);
	~GTBCharInnateAbilityStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return statpVector.size(); }
	wxString GetValue(int nothing, int index) override { return statpVector[index].value; }
	void SetValue(int nothing, int index, const wxString& value) override { statpVector[index].value = value; }
	std::vector<STATPACKAGE> getSTATP() { return statpVector; }

	void ReceiveCHIASSelection(wxString abilityname);
	void ReceiveLBBSelection(bool battalionselectionmade);
	void recalculate();
	bool DetermineStatsPresence();
	bool DetermineWhetherBattalionMustExist();
	std::vector<STATPACKAGE> RetrieveSTATPackage();
	wxString GetHeader(int index) { return currentheaders[index]; }
	std::vector<wxString> GetCurrentHeaders();
};

#endif
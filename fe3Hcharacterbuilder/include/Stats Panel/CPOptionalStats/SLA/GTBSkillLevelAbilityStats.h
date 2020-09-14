#ifndef GTBSKILLLEVELABILITYSTATS_H
#define GTBSKILLLEVELABILITYSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <map>
#include <Stat.h>
#include <constants.h>
#include <Unit/Unit.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/SkillLevelAbility/SkillLevelAbility.h>

class GTBSkillLevelAbilityStats : public wxGridTableBase {
private:
	std::vector<STATPACKAGE> headers{ { STATTYPE::PROT, "PROT" }, { STATTYPE::WEIGHT, "WGT" }, { STATTYPE::RES, "RES" }, { STATTYPE::HIT, "HIT" },
									{ STATTYPE::AVO, "AVO" }, { STATTYPE::TCRIT, "TCRIT" }, { STATTYPE::SPD, "SPD" }, { STATTYPE::MOV, "MOV" },
									{ STATTYPE::LCK, "LCK" }, { STATTYPE::MATK, "MATK" }, { STATTYPE::HEAL, "HEAL" }, { STATTYPE::RANGE, "RANGE" },
									{ STATTYPE::MIGHT, "MIGHT" }, { STATTYPE::CRITAVO, "CRITAVO" }, { STATTYPE::CRIT, "CRIT" } };
	std::vector<wxString> currentheaders{ };
	std::map<wxString, wxClientData*> skilllevelabilities;
	std::vector<STATPACKAGE> statpVector{ };
	wxString currentSLAselection;
	bool hasStats = false;
	WEAPONTYPE currentWeaponTypeofEquippedWeapon = WEAPONTYPE::BLANK;
	bool hasWeaponType;
	bool equivalentWTs;
	WEAPONTYPE type = WEAPONTYPE::BLANK;
public:
	GTBSkillLevelAbilityStats(std::map<wxString, wxClientData*> uskilllevelabilities);
	~GTBSkillLevelAbilityStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return statpVector.size(); }
	wxString GetValue(int nothing, int index) override { return statpVector[index].value; }
	void SetValue(int nothing, int index, const wxString& value) override { statpVector[index].value = value; }
	
	bool GetHasStats() { return hasStats; }
	void ReceiveSLASSelection(wxString abilityname);
	void ReceiveLBWSelection_weapontypeifneeded(WEAPONTYPE type);	
	
	void recalculate();
	bool DetermineStatsPresence();
	bool DetermineWTMatch();

	WEAPONTYPE RetrieveABILITYWEAPONTYPE();
	std::vector<STATPACKAGE> RetrieveSTATPackage();
	wxString GetHeader(int index) { return currentheaders[index]; }
	std::vector<wxString> GetCurrentHeaders();
};

#endif
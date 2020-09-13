#ifndef GTBTOTALSTATS_H
#define GTBTOTALSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>
#include <constants.h>

class GTBTotalStats : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "PATK", "MATK", "PHIT", "MHIT", "TCRIT", "AS", "TPROT", "TRSL", "AVO", "CRITAVO", "RNGE" };
	Stats currentGMTstats;
	Stats currentGWSstats;
	Stats currentGESstats;
	Stats currentGBSstats;
	STATPACKAGEVECTOR incomingGCHIASstats;
	std::vector<Stats> currentGCLIASstats;
	std::vector<Stats> currentGSLASstats;
	Stats totalstats;
	std::vector<STATPACKAGE> thisshouldreflectcurrent {STATPACKAGE{ STATTYPE::HP, "0" }, STATPACKAGE{ STATTYPE::MOV, "0" }, STATPACKAGE{ STATTYPE::STR, "0" },
									STATPACKAGE{ STATTYPE::MAG, "0" }, STATPACKAGE{ STATTYPE::DEX, "0" }, STATPACKAGE{ STATTYPE::SPD, "0" },
									STATPACKAGE{ STATTYPE::LCK, "0" }, STATPACKAGE{ STATTYPE::DEF, "0" }, STATPACKAGE{ STATTYPE::RES, "0" },
									STATPACKAGE{ STATTYPE::CHA, "0" }, STATPACKAGE{ STATTYPE::MIGHT, "0" }, STATPACKAGE{ STATTYPE::GMIGHT, "0" },
									STATPACKAGE{ STATTYPE::HIT, "0" }, STATPACKAGE{ STATTYPE::GHIT, "0" }, STATPACKAGE{ STATTYPE::CRIT, "0" },
									STATPACKAGE{ STATTYPE::RANGE, "0" }, STATPACKAGE{ STATTYPE::WEIGHT, "0" }, STATPACKAGE{ STATTYPE::USES, "0" },
									STATPACKAGE{ STATTYPE::PROT, "0" }, STATPACKAGE{ STATTYPE::TCRIT, "0" }, STATPACKAGE{ STATTYPE::AVO, "0" },
									STATPACKAGE{ STATTYPE::MATK, "0" }, STATPACKAGE{ STATTYPE::HEAL, "0" }, STATPACKAGE{ STATTYPE::PATK, "0" },
									STATPACKAGE{ STATTYPE::END, "0" }, STATPACKAGE{ STATTYPE::CRITAVO, "0" } };
public:
	GTBTotalStats() :
		currentGMTstats{ (int)VARIOUS_SIZE::CHARACTER_DATA_SIZE, L"0" },
		currentGWSstats{ (int)VARIOUS_SIZE::WEAPON_DATA_SIZE, L"0" },
		currentGESstats{ (int)VARIOUS_SIZE::EQUIPMENT_STATS_SIZE, L"0" },
		totalstats((int)VARIOUS_SIZE::TOTAL_STATS_SIZE, L"0") {}
	~GTBTotalStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { return totalstats[col].getText(); }
	wxString GetValueCharacterStats(int row, int col) { return currentGMTstats[col].getText(); }
	wxString GetValueWeaponStats(int row, int col) { return currentGWSstats[col].getText(); }
	wxString GetValueEquipmentStats(int row, int col) { return currentGESstats[col].getText(); }

	void SetValue(int row, int col, const wxString& value) override { totalstats[col] = Stat(value); }
	void SetValueCharacterStats(int row, int col, const wxString& value) { currentGMTstats[col] = Stat(value); }
	void SetValueWeaponStats(int row, int col, const wxString& value) { currentGWSstats[col] = Stat(value); }
	void SetValueEquipmentStats(int row, int col, const wxString& value) { currentGESstats[col] = Stat(value); }
	void ReceiveGMTStats(Stats stats);
	void ReceiveGWSStats(Stats stats);
	void ReceiveGESStats(Stats stats);
	void ReceiveGBSStats(Stats stats);
	void ReceiveGCHIASStats(STATPACKAGEVECTOR spv);
	void ReceiveGCLIASStats(Stats stats, int id);
	void ReceiveGSLASStats(Stats stats, int id);
	void recalculate();

	void CalculateAbilityStats();
	void CalculateTotalPhysicalAttack();
	void CalculateTotalMagicAttack();
	void CalculateTotalPhysicalHit();
	void CalculateTotalMagicHit();
	void CalculateTotalCrit();
	void CalculateAS();
	void CalculateTotalProt();
	void CalculateTotalResilience();
	void CalculateTotalAvoid();
	void CalculateTotalCritAvoid();
	void CalculateTotalRange();
	void ClearValues();

	wxString GetHeader(int index) { return headers[index]; }
};

#endif
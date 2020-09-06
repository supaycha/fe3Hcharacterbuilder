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
	Stats currentGCHIASstats;
	std::vector<Stats> currentGCLIASstats;
	std::vector<Stats> currentGSLASstats;
	Stats totalstats;
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
	void ReceiveGCHIASStats(Stats stats);
	void ReceiveGCLIASStats(Stats stats, int id);
	void ReceiveGSLASStats(Stats stats, int id);
	void recalculate();

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

	wxString GetHeader(int index) { return headers[index]; }
};

#endif
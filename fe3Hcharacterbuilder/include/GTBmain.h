#ifndef GTBMAIN_H
#define GTBMAIN_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>
#include <constants.h>
//#include <vld.h>

class GTBWeaponStats : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "MIGHT", "HIT", "CRIT", "RANGE", "WEIGHT", "SL", "USES" };
	Stats weaponstats;
public:
	GTBWeaponStats() {}
	~GTBWeaponStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { return weaponstats[col].getText(); }
	void SetValue(int row, int col, const wxString& value) override { weaponstats[col] = Stat(value); }

	void ReceiveLBWSelection(Stats stats);

	wxString GetHeader(int index) { return headers[index]; }
};

class GTBEquipmentStats : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "PATK", "MATK", "PHIT", "MHIT", "TCRIT", "AS", "TPROT", "TRSL", "AVO", "CRITAVO", "RNGE" };
	Stats equipmentstats;
public:
	GTBEquipmentStats() {}
	~GTBEquipmentStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { return equipmentstats[col].getText(); }
	void SetValue(int row, int col, const wxString& value) override { equipmentstats[col] = Stat(value); }

	void ReceiveLBESelection(Stats stats);

	wxString GetHeader(int index) { return headers[index]; }
};

class GTBBattalionStats : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "PATK", "MATK", "HIT", "CRIT", "AVO", "PROT", "RES", "CHA", "END" };
	Stats battalionstats;
public:
	GTBBattalionStats() {}
	~GTBBattalionStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { return battalionstats[col].getText(); }
	void SetValue(int row, int col, const wxString& value) override { battalionstats[col] = Stat(value); }

	void ReceiveLBBSelection(Stats stats);

	wxString GetHeader(int index) { return headers[index]; }
};

class GTBTotalStats : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "PATK", "MATK", "PHIT", "MHIT", "TCRIT", "AS", "TPROT", "TRSL", "AVO", "CRITAVO", "RNGE" };
	Stats currentGMTstats;
	Stats currentGWSstats;
	Stats currentGESstats;
	Stats currentGBSstats;
	Stats totalstats;
public:
	GTBTotalStats() :
		currentGMTstats{ (int)VARIOUS_SIZE::CHARACTER_DATA_SIZE, L"0" },
		currentGWSstats{ (int)VARIOUS_SIZE::WEAPON_DATA_SIZE, L"0" },
		currentGESstats{ (int)VARIOUS_SIZE::TOTAL_STATS_SIZE, L"0" },
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
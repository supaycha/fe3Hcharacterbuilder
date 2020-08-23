#ifndef GTBMYSTERIOUSTEACHER_H
#define GTBMYSTERIOUSTEACHER_H

#include <wx/wx.h>
#include <wx/grid.h>
#include "Stat.h"
#include "Growth.h"
#include "Unit.h"

class GTBMysteriousTeacher : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "HP", "MOV", "STR", "MAG", "DEX", "SPD", "LCK", "DEF", "RES", "CHA" };

	Stats currentDDCHstats;
	Growths currentDDCHgrowths;

	Growths currentDDCL1growths;
	int currentSCL1selection;

	Growths currentDDCL2growths;
	int currentSCL2selection;

	Stats currentDDCL3booststostats;
	Stats currentDDCL3minstats;
	Stats currentDDCL3mountvars;


public:
	GTBMysteriousTeacher() :
		currentDDCHstats{ 10, L"0" },
		currentDDCHgrowths{ 10, L"0.0" },

		currentDDCL1growths{ 10, L"0.0" },
		currentSCL1selection{ 1 },

		currentDDCL2growths{ 10, L"0.0" },
		currentSCL2selection{ 1 },

		currentDDCL3booststostats{ 10, L"0" },
		currentDDCL3minstats{ 10, L"0" },
		currentDDCL3mountvars{ 10, L"0" },

		totals1{ 10, L"0" } {}
	~GTBMysteriousTeacher() {}

	Growths totals1;
	Stats totals2;
	Growths totals3;
	Stats totals4;
	Growths totals5;
	Stats totals6;
	Stats totals7;
	Stats totals8;

	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { return totals1[col].getText(); }
	wxString GetValue2(int row, int col) { return totals2[col].getText(); }
	wxString GetValue3(int row, int col) { return totals3[col].getText(); }
	wxString GetValue4(int row, int col) { return totals4[col].getText(); }
	wxString GetValue5(int row, int col) { return totals5[col].getText(); }
	wxString GetValue6(int row, int col) { return totals6[col].getText(); }
	wxString GetValue7(int row, int col) { return totals7[col].getText(); }
	wxString GetValue8(int row, int col) { return totals8[col].getText(); }

	void SetValue(int row, int col, const wxString& value) override { currentDDCHstats[col] = Stat(value); }
	void SetValueClass(int row, int col, const wxString& value) { currentDDCHstats[col] = Stat(value); }

	wxString GetHeader(int index) { return headers[index]; }

	void UpdateDDCHSelection(Character character);
	void UpdateSCLSelection(int level, int ID);
	void UpdateDDCLSelection(Class cLass, int ID);

	void recalculate();
};

#endif
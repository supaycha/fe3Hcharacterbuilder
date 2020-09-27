#ifndef GTBMYSTERIOUSTEACHER_H
#define GTBMYSTERIOUSTEACHER_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>
#include <Growth.h>
#include <constants.h>
#include <Unit/Unit.h>
#include <Unit/Character.h>
#include <Unit/Class.h>

class GTBMysteriousTeacher : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "HP", "MOV", "STR", "MAG", "DEX", "SPD", "LCK", "DEF", "RES", "CHA" };
	
	//character stats(0)
	////firstclasstotalstats(1)
	////secondclasstotalstats(2) 
	////beforebooststats(3)
	////afterbooststats(4)
	//final class stat boosts(5)
	//final class minimum stats(6)
	//final class mounted variances(7)
	////finalclasstotalstats(8)
	
	std::vector<Stats> statsVector;

	//character growths(0)
	////firsttotalgrowths(1)
	////secondtotalgrowths(2)
	//class 1 growths(3)
	//class 2 growths(4)
	
	
	////finaltotalgrowths(5)
	std::vector<Growths> growthsVector;

	//Stats currentDDCHstats;
	//Growths currentDDCHgrowths;

	//Growths currentDDCL1growths;
	int currentSCL1selection;

	//Growths currentDDCL2growths;
	int currentSCL2selection;

	//Stats currentDDCL3booststostats;
	//Stats currentDDCL3minstats;
	//Stats currentDDCL3mountvars;


public:
	GTBMysteriousTeacher() :
		statsVector{ 9,  {10, L"0"} },
		growthsVector{ 6, {10, L"0.0"} },
		//currentDDCHgrowths{ 10, L"0.0" },

		//currentDDCL1growths{ 10, L"0.0" },
		currentSCL1selection{ 1 },

		//currentDDCL2growths{ 10, L"0.0" },
		currentSCL2selection{ 1 }

		//currentDDCL3booststostats{ 10, L"0" },
		//currentDDCL3minstats{ 10, L"0" },
		//currentDDCL3mountvars{ 10, L"0" },

		//totals1{ 10, L"0" } 
	{}
	~GTBMysteriousTeacher() {}

	//Growths totals1;
	//Stats totals2;
	//Growths totals3;
	//Stats totals4;
	//Growths totals5;
	//Stats totals6;
	//Stats totals7;
	//Stats totals8;

	int GetNumberRows() override { return 8; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { switch (row) { case 1:case 3:case 5: {return GetGrowth(row, col); } default: {return GetStat(row, col); } } }
	void SetValue(int row, int col, const wxString& value) override { switch (row) { case 1:case 3:case 5: { SetGrowth(row, col, value); break; } default: { SetStat(row, col, value); } } }
	wxString GetStat(int row, int col) {
		int placeinvector = 5 + row;
		return statsVector[placeinvector][col].getText();
	}

	void SetStat(int row, int col, const wxString& value) {
		int placeinvector = 5 + row;
		statsVector[placeinvector][col].setText(value);
	}

	wxString GetGrowth(int row, int col) {
		int placeinvector = 4 + row;
		return growthsVector[placeinvector][col].getText();
	}

	void SetGrowth(int row, int col, const wxString& value) {
		int placeinvector = 4 + row;
		growthsVector[placeinvector][col].setText(value);
	}

	wxString GetHeader(int index) { return headers[index]; }

	void UpdateDDCHSelection(Character character);
	void UpdateSCLSelection(int level, int ID);
	void UpdateDDCLSelection(Class cLass, int ID);

	void recalculate();
};

#endif
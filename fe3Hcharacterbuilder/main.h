#define ID_FRAME		7
#define ID_MT			8
#define ID_DDCH			9
#define ID_DDCL1		10
#define ID_DDCL2		11
#define ID_DDCL3		12
#define ID_SPIN1		15
#define ID_SPIN2		16
#define ID_GMT			20

#define ID_LBW			30
#define ID_LBE			31
#define ID_LBB			32
#define	ID_GWS			33
#define ID_GES			34
#define ID_GBS			35
#define ID_GTS			36
#define ID_SLM			37
#define ID_AM			38
#define ID_LBAA			39
#define ID_LBSA			40
#define ID_BML			41
#define ID_BMR			42
#define ID_DDSWORD		50
#define ID_DDLANCE		51
#define ID_DDAXE		52
#define ID_DDBOW		53
#define ID_DDGAUNTLETS	54
#define ID_DDREASON		55
#define ID_DDFAITH		56
#define ID_DDAUTHORITY	57
#define ID_DDHEAVYARMOR 58
#define ID_DDRIDING		59
#define ID_DDFLYING		60
#define ID_STSWORD		61
#define ID_STLANCE		62
#define ID_STAXE		63
#define ID_STBOW		64
#define ID_STGAUNTLETS	65
#define ID_STREASON		66
#define ID_STFAITH		67
#define ID_STAUTHORITY	68
#define ID_STHEAVYARMOR 69
#define ID_STRIDING		70
#define ID_STFLYING		71

const unsigned int CHARACTER_DATA_SIZE = 41;
const unsigned int WEAPON_DATA_SIZE = 134;
const unsigned int CLASS_DATA_SIZE = 53;
const unsigned int EQUIPMENT_DATA_SIZE = 28;
const unsigned int BATTALION_DATA_SIZE = 190;
const unsigned int SL_DATA_SIZE = 11;
const unsigned int CHAR_CLASS_STATS_SIZE = 10;
const unsigned int TOTAL_STATS_SIZE = 11;
const unsigned int MIN_HEIGHT_OF_COMBOBOX = 23;
const unsigned int SET_LENGTH_OF_COLUMNS = 34;

#ifndef MAIN_H
#define MAIN_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/listctrl.h>
#include <wx/grid.h>
#include <algorithm>
#include <vld.h>
#include "UnitList.h"

class MysteriousTeacher;
class DropDownCharacters;
class SpinCtrlLevel;
class DropDownClasses;
class GridMysteriousTeacher;
class GTBMysteriousTeacher;
class ListBoxWeapons;
class ListBoxEquipment;
class ListBoxBattalions;
class GridWeaponStats;
class GridEquipmentStats;
class GridBattalionStats;
class GridTotalStats;

class SkillLevelManager;
class DropDownSkillLevel;
class StaticTextSkillLevel;
class AbilityManager;
class ListBoxAA;
class ListBoxSA;
class ButtonMoveLeft;
class ButtonMoveRight;

class MyApp : public wxApp {
public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame {
private:
	wxBoxSizer* Buildersizer;
	wxBoxSizer* MTandGridStats_col;
	wxBoxSizer* gridstatssizer;
	wxBoxSizer* lbsizer;
	wxBoxSizer* slablsizer;

	MysteriousTeacher* mt;
	ListBoxWeapons* lbw;
	ListBoxEquipment* lbe;	
	ListBoxBattalions* lbb;
	GridWeaponStats* gws;
	GridEquipmentStats* ges;
	GridBattalionStats* gbs;
	GridTotalStats* gts;
	SkillLevelManager* slm;
	AbilityManager* am;

	wxDECLARE_EVENT_TABLE();
public:
	MyFrame(wxWindowID id, const wxString& title);
	~MyFrame() {}
	void BounceRepeatedDDCHSelection_exclusivitycheck(wxCommandEvent& repititionfromMT);	
	void BounceRepeatedDDCLSelection_classinnatecheck(wxCommandEvent& repititionfromMT);
	void BounceRepeatedGMTStats_partoftotalstats(wxCommandEvent& repititionfromMT);
	void BounceLBWSelection(wxCommandEvent& selection);
	void BounceLBESelection(wxCommandEvent& selection);
	void BounceLBBSelection(wxCommandEvent& selection);
	void BounceGWSStats_partoftotalstats(wxCommandEvent& eventfromGWS);
	void BounceGESStats_partoftotalstats(wxCommandEvent& eventfromGES);
	void BounceGBSStats_partoftotalstats(wxCommandEvent& eventfromGBS);
	void BounceSLInfo(wxCommandEvent& eventfromwho);

	void OnQuit(wxCommandEvent& event);
};

//////////////////////////////////////////////

class MysteriousTeacher : public wxPanel {
private:	
	GridMysteriousTeacher* gmt;

	DropDownCharacters* ddc;
	wxBoxSizer* total;
	std::wstring currentDDCselection;

	std::vector<SpinCtrlLevel*> sclVector;
	std::vector<DropDownClasses*> ddclVector;
	std::vector<wxBoxSizer*> columns;
public:
	MysteriousTeacher(std::vector<wxString> characternames, std::vector<wxClientData*> characterdata, std::map<wxString, wxClientData*> classmap, MyFrame* parent, wxWindowID id);
	~MysteriousTeacher() {}

	void BounceDDCHSelection(wxCommandEvent& transmission);
	void BounceSCLSelection(wxSpinEvent& transmission);
	void BounceDDCLSelection(wxCommandEvent& transmission);

	void ForwardGMTStats(wxCommandEvent& forwarded);
};

class DropDownCharacters : public wxComboBox {
private:
	wxDECLARE_EVENT_TABLE();
public:
	DropDownCharacters(std::vector<wxString> characternames, std::vector<wxClientData*> characterdata, wxWindow* panel, wxWindowID id, const wxArrayString& choices, long style);
	~DropDownCharacters() {}

	void OnNewSelection(wxCommandEvent& selection);
};

class SpinCtrlLevel : public wxSpinCtrl {
private:
public:
	SpinCtrlLevel(wxWindow* parent, wxWindowID id, const wxString& value, int min);
	~SpinCtrlLevel() {}

	void OnNewSelection(wxSpinEvent& event);
};

class DropDownClasses : public wxComboBox {
private:
	std::map<wxString, wxClientData*> classmap;
	wxString currentDDCSelection;
	wxString mostrecentDDCLselection;
	wxDECLARE_EVENT_TABLE();
public:
	DropDownClasses(std::map<wxString, wxClientData*> classmap, wxWindow* panel, wxWindowID id, const wxArrayString& choices, long style);
	~DropDownClasses() {}

	void OnNewSelection(wxCommandEvent& selection);
	void ReceiveExclusivity(wxString charactername);

	void repopulate();
	void DetermineSelectionStatus();
	bool CompareAllStrings();
};

class GridMysteriousTeacher : public wxGrid {
private:
	std::vector<wxString> headers{ "HP", "MOV", "STR", "MAG", "DEX", "SPD", "LCK", "DEF", "RES", "CHA" };
	GTBMysteriousTeacher* gtbmt;
public:
	GridMysteriousTeacher(wxWindow* parent, wxWindowID id, bool hidecolheaders);
	~GridMysteriousTeacher() {}

	void initpopulate();
	void repopulate();

	void UpdateDDCHSelection(Character character);
	void UpdateSCLSelection(int level, int ID);
	void UpdateDDCLSelection(Class cLass, int ID);
};

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
		currentDDCHstats{10, L"0"},
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

////////////////////////////////////////

class ListBoxWeapons : public wxListBox {
private:
	std::map<wxString, wxClientData*> weaponmap;
	wxString currentDDCselection;
	wxString mostrecentLBWselection;
	std::vector<SL> SLfilter{ 7, SL::E };

	wxDECLARE_EVENT_TABLE();
public:
	ListBoxWeapons(std::map<wxString, wxClientData*> uweaponmap, wxWindow* panel, wxWindowID id, int x, int y, const wxArrayString& choices, long style);
	~ListBoxWeapons() {}

	void OnNewSelection(wxCommandEvent& selection);
	void ReceiveExclusivity(wxString charactername);
	void ReceiveSLInfo(SLPACKAGE* slpackage);

	void repopulate();
	void DetermineSelectionStatus();
	bool CompareAllStrings();
};

class ListBoxEquipment : public wxListBox {
private:
	std::map<wxString, wxClientData*> equipmentmap;
	wxString currentDDCSelection;
	wxString mostrecentLBEselection;
	wxDECLARE_EVENT_TABLE();
public:
	ListBoxEquipment(std::map<wxString, wxClientData*> uequipmentmap, wxWindow* panel, wxWindowID id, int x, int y, const wxArrayString& choices, long style);
	~ListBoxEquipment() {}

	void OnNewSelection(wxCommandEvent& selection);
	void ReceiveExclusivity(wxString charactername);

	void repopulate();
	void DetermineSelectionStatus();	
	bool CompareAllStrings();
};

class ListBoxBattalions : public wxListBox {
	std::map<wxString, wxClientData*> battalionmap;
	SL sl;
	wxString mostrecentLBBselection;
	wxDECLARE_EVENT_TABLE();
public:
	ListBoxBattalions(std::map<wxString, wxClientData*> ubattalionmap, wxWindow* panel, wxWindowID id, int x, int y, const wxArrayString& choices, long style);
	~ListBoxBattalions() {}

	void OnNewSelection(wxCommandEvent& selection);
	void ReceiveSLInfo(SLPACKAGE* slpackage);

	void repopulate();
	void DetermineSelectionStatus();
	bool CompareAllStrings();
};

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

class GridWeaponStats : public wxGrid {
private:
	GTBWeaponStats* gtbws;
public:
	GridWeaponStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBWSelection(Stats stats);
	void repopulate();
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

class GridEquipmentStats : public wxGrid {
private:
	GTBEquipmentStats* gtbes;
public:
	GridEquipmentStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBESelection(Stats stats);
	void repopulate();
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

class GridBattalionStats : public wxGrid {
private:
	GTBBattalionStats* gtbbs;
public:
	GridBattalionStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBBSelection(Stats stats);
	void repopulate();
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
		currentGMTstats{ CHARACTER_DATA_SIZE, L"0" },
		currentGWSstats{ WEAPON_DATA_SIZE, L"0" },
		currentGESstats{ TOTAL_STATS_SIZE, L"0" },
		totalstats(TOTAL_STATS_SIZE, L"0") {}
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

class GridTotalStats : public wxGrid {
private:
	GTBTotalStats* gtbts;
public:
	GridTotalStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveGMTStats(Stats stats);
	void ReceiveGWSStats(Stats stats);
	void ReceiveGESStats(Stats stats);
	void ReceiveGBSStats(Stats stats);
	void repopulate();
};

//////////////////////////////////


class SkillLevelManager : public wxPanel {
private:
	std::map<StaticTextSkillLevel*, DropDownSkillLevel*>* manager;
	wxDECLARE_EVENT_TABLE();
public:
	SkillLevelManager(MyFrame* parent, wxWindowID id);
	~SkillLevelManager() {}

	void OnNewSelection(wxCommandEvent& uevent);
};

class StaticTextSkillLevel : public wxStaticText {
private:
	wxString stname;
public:
	StaticTextSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, int x, int y, int x2, int y2);
	~StaticTextSkillLevel() {}
};

class DropDownSkillLevel : public wxComboBox {
private:
	wxString ddname;
public:
	DropDownSkillLevel(wxWindow* parent, wxWindowID id, const wxString& label, const wxString& value, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~DropDownSkillLevel() {}

	void initpopulate();
};

/// //////////////////////////////////////


class AbilityManager : public wxPanel {
private:
	std::map<wxString, wxClientData*> abilitymap;
	ListBoxAA* lbaa;
	ListBoxSA* lbsa;
	ButtonMoveRight* bmr;
	ButtonMoveLeft* bml;

	wxString currentDDCselection;
	wxString currentLBCselection;
	std::vector<SL> SLfilter{ 11, SL::E };

	std::vector<wxString> filterLtoR;
	std::vector<wxString> filterRtoL;
	wxDECLARE_EVENT_TABLE();
public:
	AbilityManager(MyFrame* parent, wxWindowID id);
	~AbilityManager() {}

	void ReceiveExclusivity(wxString charactername);
	void ReceiveSLInfo(SLPACKAGE* slpackage);
	void ReceiveClassInnate(wxString classname);
	void FilterAbilities();

	void BounceSelectionstoRight(wxCommandEvent& eventfromOnClick);
	void BounceSelectionstoLeft(wxCommandEvent& eventfromOnClick);
};

class ListBoxAA : public wxListBox {
private:
	std::vector<wxString> filteredAAnames;
	std::vector<wxString> selectedAAnames;

	wxDECLARE_EVENT_TABLE();
public:
	ListBoxAA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~ListBoxAA() {}

	void OnSelection(wxCommandEvent& event);
	void ReceiveAbilityFiltration(std::vector<wxString> dirtynames);
	void ReceiveSelectionsfromBounceL(std::vector<wxString> uSelections);
	void repopulate();
	void reselection();

	std::vector<wxString> UpdateSelections();
	std::vector<wxString> GetSelectionsAA() { return selectedAAnames; }
};

class ListBoxSA : public wxListBox {
private:
	std::vector<wxString> filteredSAnames;
	std::vector<wxString> selectedSAnames;

	wxDECLARE_EVENT_TABLE();
public:
	ListBoxSA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style);
	~ListBoxSA() {}

	void OnSelection(wxCommandEvent& event);
	void ReceiveAbilityFiltration(std::vector<wxString> dirtynames);
	void ReceiveSelectionsfromBounceR(std::vector<wxString> uSelections);
	void repopulate();
	void reselection();

	std::vector<wxString> UpdateSelections();
	std::vector<wxString> GetSelectionsSAAndClear();
};

class ButtonMoveRight : public wxButton {
private:
	wxDECLARE_EVENT_TABLE();
public:
	ButtonMoveRight(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2);
	~ButtonMoveRight() {}

	void OnClick(wxCommandEvent& event);
};

class ButtonMoveLeft : public wxButton {
private:
	wxDECLARE_EVENT_TABLE();
public:
	ButtonMoveLeft(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2);
	~ButtonMoveLeft() {}

	void OnClick(wxCommandEvent& uevent);
};

#endif
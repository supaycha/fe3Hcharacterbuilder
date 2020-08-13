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
#define	ID_GWS			32
#define ID_GES			33
#define ID_GTS			34
#define ID_SLM			35
#define ID_AM			36
#define ID_LBAA			37
#define ID_LBSA			38
#define ID_BML			39
#define ID_BMR			40
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
//#define ID_HP			80
//#define ID_MOV			81
//#define ID_STR			82
//#define ID_MAG			83
//#define ID_DEX			84
//#define ID_SPD			85
//#define ID_LCK			86
//#define ID_DEF			87
//#define ID_RES			88
//#define ID_CHA			89
//#define ID_MIGHT		90
//#define ID_HIT			91
//#define ID_CRIT			92
//#define ID_RANGE		93
//#define ID_WEIGHT		94
//#define ID_SL			95
//#define ID_USES			96

const unsigned int CHARACTER_DATA_SIZE = 41;
const unsigned int WEAPON_DATA_SIZE = 133;
const unsigned int CLASS_DATA_SIZE = 52;
const unsigned int EQUIPMENT_DATA_SIZE = 27;
const unsigned int SL_DATA_SIZE = 11;
const unsigned int CHAR_CLASS_STATS_SIZE = 10;
const unsigned int TOTAL_STATS_SIZE = 11;

#ifndef MAIN_H
#define MAIN_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/listctrl.h>
#include <wx/grid.h>
#include <algorithm>
#include <vld.h>
#include "UnitList.h"
//class ListBoxClasses : public wxListBox {
//private:
//	std::map<wxString, wxClientData*> classmap;
//	wxString currentDDCSelection;
//	wxString mostrecentselection;
//	wxDECLARE_EVENT_TABLE();
//public:
//	ListBoxClasses(std::map<wxString, wxClientData*> classmap, wxWindow* panel, wxWindowID id, const wxPoint& pos, const wxSize& size, const wxArrayString& choices, long style);
//	~ListBoxClasses() {}
//
//	void OnNewSelection(wxCommandEvent& sentevent);
//	void ReceiveDDCInfo(wxString charactername);
//
//	void repopulate();
//	bool CompareAllStrings();
//	void DetermineSelectionStatus();
//};
//class ListBoxClasses : public wxListBox {
//private:
//	std::map<wxString, wxClientData*> classmap;
//	wxString currentDDCSelection;
//	wxString mostrecentselection;
//	wxDECLARE_EVENT_TABLE();
//public:
//	ListBoxClasses(std::map<wxString, wxClientData*> classmap, wxWindow* panel, wxWindowID id, const wxPoint& pos, const wxSize& size, const wxArrayString& choices, long style);
//	~ListBoxClasses() {}
//
//	void OnNewSelection(wxCommandEvent& sentevent);
//	void ReceiveDDCInfo(wxString charactername);
//	
//	void repopulate();
//	bool CompareAllStrings();
//	void DetermineSelectionStatus();
//};
//class GTBCharacterStats : public wxGridTableBase {
//private:
//	std::vector<wxString> headers{ "HP", "MOV", "STR", "MAG", "DEX", "SPD", "LCK", "DEF", "RES", "CHA" };
//	Stats currentcharacterstats;
//	Stats currentclassstats;
//public:
//	GTBCharacterStats() {}
//	~GTBCharacterStats() {}
//	int GetNumberRows() override { return 1; }
//	int GetNumberCols() override { return headers.size(); }
//	wxString GetValue(int row, int col) override { return currentcharacterstats[col].getText(); }
//	wxString GetValueClass(int row, int col) { return currentclassstats[col].getText(); }
//	void SetValue(int row, int col, const wxString& value) override { currentcharacterstats[col] = Stat(value); }
//	void SetValueClass(int row, int col, const wxString& value) { currentclassstats[col] = Stat(value); }
//
//	void ReceiveDDCInfo(Stats characterstats);
//	void ReceiveLBCInfo(Stats classstats);
//};
//
//class GridCharacterStats : public wxGrid {
//private:
//	GTBCharacterStats* gtbcs;
//public:
//	GridCharacterStats(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
//	void initpopulate();
//	void ReceiveDDCInfo(Stats characterstats);
//	void ReceiveLBCInfo(Stats classstats);
//	void repopulate();
//	std::wstring CompareStats(std::wstring characterstat, std::wstring classstats, int index);
//};

class MysteriousTeacher;
class DropDownCharacters;
class SpinCtrlLevel;
class DropDownClasses;
class GridMysteriousTeacher;
class GTBMysteriousTeacher;
class ListBoxWeapons;
class ListBoxEquipment;
class GridWeaponStats;
class GridEquipmentStats;
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
	MysteriousTeacher* mt;
	ListBoxWeapons* lbw;
	ListBoxEquipment* lbe;
	SkillLevelManager* slm;
	AbilityManager* am;
	GridWeaponStats* gws;
	GridEquipmentStats* ges;
	GridTotalStats* gts;

	wxDECLARE_EVENT_TABLE();
public:
	MyFrame(wxWindowID id, const wxString& title);
	~MyFrame() {}
	void ReceiveRepeatedDDCHSelection_exclusivitycheck(wxCommandEvent& repititionfromMT);	
	void ReceiveRepeatedDDCLSelection_classinnatecheck(wxCommandEvent& repititionfromMT);

	void BounceLVCSInfo(wxCommandEvent& eventfromwho);
	void BounceClassInfo(wxCommandEvent& eventfromwho);

	void BounceLVWSInfo(wxCommandEvent& eventfromwho);
	void BounceLVESInfo(wxCommandEvent& eventfromwho);
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
	MysteriousTeacher(std::vector<wxString> characternames, std::vector<wxClientData*> characterdata, std::map<wxString, wxClientData*> classmap, MyFrame* parent, wxWindowID id, int x, int y, int x2, int y2);
	~MysteriousTeacher() {}

	void BounceDDCHSelection(wxCommandEvent& transmission);
	void BounceSCLSelection(wxSpinEvent& transmission);
	void BounceDDCLSelection(wxCommandEvent& transmission);

	void ForwardLVCSInfo(wxCommandEvent& eventfromwho);

	void BounceSelectionStatusInfo(wxCommandEvent& eventfromwho);
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
	wxString mostrecentselection;
	wxDECLARE_EVENT_TABLE();
public:
	DropDownClasses(std::map<wxString, wxClientData*> classmap, wxWindow* panel, wxWindowID id, const wxArrayString& choices, long style);
	~DropDownClasses() {}

	void OnNewSelection(wxCommandEvent& selection);
	void ReceiveExclusivity(wxString charactername);

	void repopulate();
	bool CompareAllStrings();
	void DetermineSelectionStatus();
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
	std::wstring CompareStats(std::wstring characterstat, std::wstring classstat, int index);

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
	wxString mostrecentselection;
	std::vector<SL> SLfilter{ 7, SL::E };

	wxDECLARE_EVENT_TABLE();
public:
	ListBoxWeapons(std::map<wxString, wxClientData*> uweaponmap, wxWindow* panel, wxWindowID id, const wxPoint& pos, const wxSize& size, const wxArrayString& choices, long style);
	~ListBoxWeapons() {}

	void OnNewSelection(wxCommandEvent& sentevent);
	void ReceiveExclusivity(wxString charactername);
	void ReceiveSLInfo(SLPACKAGE* slpackage);

	void repopulate();
	bool CompareAllStrings();
	void DetermineSelectionStatus();
};

class ListBoxEquipment : public wxListBox {
private:
	std::map<wxString, wxClientData*> equipmentmap;
	wxString currentDDCSelection;
	wxString mostrecentselection;
	wxDECLARE_EVENT_TABLE();
public:
	ListBoxEquipment(std::map<wxString, wxClientData*> equipmentmap, wxWindow* panel, wxWindowID id, const wxPoint& pos, const wxSize& size, const wxArrayString& choices, long style);
	~ListBoxEquipment() {}

	void OnNewSelection(wxCommandEvent& sentevent);
	void ReceiveExclusivity(wxString charactername);

	void repopulate();
	bool CompareAllStrings();
	void DetermineSelectionStatus();
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

	void ReceiveLBWInfo(Stats stats);
};

class GridWeaponStats : public wxGrid {
private:
	GTBWeaponStats* gtbws;
public:
	GridWeaponStats(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
	void initpopulate();
	void ReceiveLBWInfo(Stats stats);
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

	void ReceiveLBEInfo(Stats stats);
};

class GridEquipmentStats : public wxGrid {
private:
	GTBEquipmentStats* gtbes;
public:
	GridEquipmentStats(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
	void initpopulate();
	void ReceiveLBEInfo(Stats stats);
	void repopulate();
};

class GTBTotalStats : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "PATK", "MATK", "PHIT", "MHIT", "TCRIT", "AS", "TPROT", "TRSL", "AVO", "CRITAVO", "RNGE" };
	Stats currentLVCSstats;
	Stats currentLVWSstats;
	Stats currentLVESstats;
	Stats totalstats;
public:
	GTBTotalStats() :
		currentLVCSstats{ CHARACTER_DATA_SIZE, L"0" },
		currentLVWSstats{ WEAPON_DATA_SIZE, L"0" },
		currentLVESstats{ TOTAL_STATS_SIZE, L"0" },
		totalstats(TOTAL_STATS_SIZE, L"0") {}
	~GTBTotalStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { return totalstats[col].getText(); }
	wxString GetValueCharacterStats(int row, int col) { return currentLVCSstats[col].getText(); }
	wxString GetValueWeaponStats(int row, int col) { return currentLVWSstats[col].getText(); }
	wxString GetValueEquipmentStats(int row, int col) { return currentLVESstats[col].getText(); }

	void SetValue(int row, int col, const wxString& value) override { totalstats[col] = Stat(value); }
	void SetValueCharacterStats(int row, int col, const wxString& value) { currentLVCSstats[col] = Stat(value); }
	void SetValueWeaponStats(int row, int col, const wxString& value) { currentLVWSstats[col] = Stat(value); }
	void SetValueEquipmentStats(int row, int col, const wxString& value) { currentLVESstats[col] = Stat(value); }
	void ReceiveLVCSInfo(Stats stats);
	void ReceiveLVWSInfo(Stats stats);
	void ReceiveLVESInfo(Stats stats);
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
};

class GridTotalStats : public wxGrid {
private:
	GTBTotalStats* gtbts;
public:
	GridTotalStats(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
	void initpopulate();
	void ReceiveLVCSInfo(Stats stats);
	void ReceiveLVWSInfo(Stats stats);
	void ReceiveLVESInfo(Stats stats);
	void repopulate();
};

//////////////////////////////////


class SkillLevelManager : public wxPanel {
private:
	std::map<StaticTextSkillLevel*, DropDownSkillLevel*>* manager;
	wxDECLARE_EVENT_TABLE();
public:
	SkillLevelManager(MyFrame* parent, wxWindowID id, int x, int y, int x2, int y2);
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
	AbilityManager(MyFrame* parent, wxWindowID id, int x, int y, int x2, int y2);
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
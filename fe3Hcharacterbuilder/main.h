#define ID_FRAME		9
#define ID_DDCH			10
#define ID_LBW			11
#define ID_LBE			13
#define ID_SLM			14
#define ID_AM			15
#define ID_LBAA			16
#define ID_LBSA			17
#define ID_BML			18
#define ID_BMR			19
#define	ID_GWS			21
#define ID_GES			22
#define ID_GTS			23
#define ID_MT			24
#define ID_DDCL			25
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
#define ID_HP			80
#define ID_MOV			81
#define ID_STR			82
#define ID_MAG			83
#define ID_DEX			84
#define ID_SPD			85
#define ID_LCK			86
#define ID_DEF			87
#define ID_RES			88
#define ID_CHA			89
#define ID_MIGHT		90
#define ID_HIT			91
#define ID_CRIT			92
#define ID_RANGE		93
#define ID_WEIGHT		94
#define ID_SL			95
#define ID_USES			96
#define ID_SPIN1		100
#define ID_DDCL1		110
#define ID_GS1			120

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
class GridStats;
class ListBoxWeapons;
class ListBoxClasses;
class ListBoxEquipment;
class SkillLevelManager;
class DropDownSkillLevel;
class StaticTextSkillLevel;
class AbilityManager;
class ListBoxAA;
class ListBoxSA;
class ButtonMoveLeft;
class ButtonMoveRight;
class GridCharacterStats;
class GridWeaponStats;
class GridEquipmentStats;
class GridTotalStats;

class MyApp : public wxApp {
public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame {
private:
	MysteriousTeacher* mt;
	ListBoxWeapons* lbw;
	ListBoxClasses* lbc;
	ListBoxEquipment* lbe;
	SkillLevelManager* slm;
	AbilityManager* am;
	GridCharacterStats* gcs;
	GridWeaponStats* gws;
	GridEquipmentStats* ges;
	GridTotalStats* gts;

	wxDECLARE_EVENT_TABLE();
public:
	MyFrame(wxWindowID id, const wxString& title);
	~MyFrame() {}
	void BounceExclusivity(wxCommandEvent& eventfromwho);
	void BounceLVCSInfo(wxCommandEvent& eventfromwho);
	void BounceClassInfo(wxCommandEvent& eventfromwho);
	void BounceSelectionStatusInfo(wxCommandEvent& eventfromwho);

	void BounceLVWSInfo(wxCommandEvent& eventfromwho);
	void BounceLVESInfo(wxCommandEvent& eventfromwho);
	void BounceSLInfo(wxCommandEvent& eventfromwho);

	void OnQuit(wxCommandEvent& event);
};

class MysteriousTeacher : public wxPanel {
private: //each row is index i of every vector
	DropDownCharacters* ddc;

	std::vector<SpinCtrlLevel*> sclVector;
	std::vector<DropDownClasses*> ddclVector;
	std::vector<GridStats*> gsVector;
	wxBoxSizer* total;
	wxBoxSizer* row1;
	wxBoxSizer* row2;

	std::wstring currentDDCselection;
	;
	//sd;//another stype of gtb that represents subsequent rows, these will hold total growth rates and results, and expose calculations upon a click
public:
	MysteriousTeacher(std::vector<wxString> characternames, std::vector<wxClientData*> characterdata, std::map<wxString, wxClientData*> classmap, MyFrame* parent, wxWindowID id, int x, int y, int x2, int y2);
	~MysteriousTeacher() {}

	void BounceDDCInfo(wxCommandEvent& eventfromwho);
	void ForwardLVCSInfo(wxCommandEvent& eventfromwho);
	void ForwardClassInfo(wxCommandEvent& eventfromwho);

	void BounceSelectionStatusInfo(wxCommandEvent& eventfromwho);

	void BounceExclusivity(wxCommandEvent& eventfromwho);
	void ForwardExclusivity(wxCommandEvent& eventfromwho);

	void BounceLevelSelection(wxSpinEvent& eventfromwho);
};

class DropDownCharacters : public wxComboBox {
private:
	wxDECLARE_EVENT_TABLE();
public:
	DropDownCharacters(std::vector<wxString> characternames, std::vector<wxClientData*> characterdata, wxWindow* panel, wxWindowID id, const wxArrayString& choices, long style);
	~DropDownCharacters() {}

	void OnNewSelection(wxCommandEvent& event);
};

class SpinCtrlLevel : public wxSpinCtrl {
private:
	wxDECLARE_EVENT_TABLE();
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

	void OnNewSelection(wxCommandEvent& sentevent);
	void ReceiveExclusivity(wxString charactername);

	void repopulate();
	bool CompareAllStrings();
	void DetermineSelectionStatus();
};

class GTBCharacterClassStats : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "HP", "MOV", "STR", "MAG", "DEX", "SPD", "LCK", "DEF", "RES", "CHA" };
	Character currentcharacterdata;
	Class currentclassdata;

	Stats currentcharacterstats;
	Growths currentcharactergrowths;

	Stats currentclassstats;
	Growths currentclassgrowths;
	Stats currentclassboosts;
	Stats currentmountedvariances;

	int currentSPINselection;

	Stats totals;
public:
	GTBCharacterClassStats() {}
	~GTBCharacterClassStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { return totals[col].getText(); }
	wxString GetValueClass(int row, int col) { return currentclassstats[col].getText(); }
	void SetValue(int row, int col, const wxString& value) override { currentcharacterstats[col] = Stat(value); }
	void SetValueClass(int row, int col, const wxString& value) { currentclassstats[col] = Stat(value); }

	wxString GetHeader(int index) { return headers[index]; }

	void ReceiveDDCInfo(Character character);
	void ReceiveLBCInfo(Class cLass);

	void ReceiveLevel(int level);

	void recalculate();
};

class GridStats : public wxGrid {
private:
	std::vector<wxString> headers{ "HP", "MOV", "STR", "MAG", "DEX", "SPD", "LCK", "DEF", "RES", "CHA" };
	GTBCharacterClassStats* gtbcs;
public:
	GridStats(wxWindow* parent, wxWindowID id);
	~GridStats() {}

	void initpopulate();
	void repopulate();
	std::wstring CompareStats(std::wstring characterstat, std::wstring classstat, int index);

	void ReceiveDDCInfo(Character character);
	void ReceiveLBCInfo(Class cLass);

	void ReceiveLevel(int level);
};

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
	void ReceiveClassInfo(wxString classname);
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
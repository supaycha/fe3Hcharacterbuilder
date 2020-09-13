#ifndef CONSTANTS_H
#define CONSTANTS_H
//#include <vld.h>
#include <string>

enum class ID_MISC {
	ID_FRAME = 7,
	ID_MT = 8,
	ID_DDCH = 9,
	ID_DDCL1 = 10,
	ID_DDCL2 = 11,
	ID_DDCL3 = 12,
	ID_SPIN1 = 15,
	ID_SPIN2 = 16,
	ID_GMT = 20,
	ID_WM = 21,
	ID_ECLIA = 22,
	ID_ECLIA2 = 23,
	ID_ECLIA3 = 24,
	ID_SLA = 25,
	ID_SLA2 = 26,
	ID_SLA3 = 27,
	ID_SLA4 = 28,
	ID_SLA5 = 29,
	ID_BCLASSMASTERY = 30
};

enum class ID_SINGLE_CONTROL {
	ID_LBW = 30, 
	ID_LBE = 31, 
	ID_LBB = 32,
	ID_GWS = 33,
	ID_GES = 34,
	ID_GBS = 35,
	ID_SLM = 36,
	ID_LBASLA = 37,
	ID_LBSSLA = 38,
	ID_LBSA = 39,
	ID_BAA = 40,
	ID_BRA = 41,
	ID_EB = 42,
	ID_EW = 43,
	ID_EE = 44,
	ID_EP = 45,
	ID_SP = 46,
	ID_GTBCHIAS = 50,
	ID_GTBCLIAS = 51,
	ID_ECHIA = 52,
	ID_ECLIA = 53,
	ID_ECLIA2 = 54,
	ID_ECLIA3 = 55,

	ID_AP = 56,
	ID_GTBSLAS = 57,
	ID_ESLA = 58,
	ID_SLP = 59,
	ID_GCHIAS = 60,
	ID_GCLIAS = 61,
	ID_GCLIAS2 = 62,
	ID_GCLIAS3 = 63,
	ID_GSLAS = 64,
	ID_GSLAS2 = 65,
	ID_GSLAS3 = 66,
	ID_GSLAS4 = 67,
	ID_GSLAS5 = 68,	
	ID_GTS = 69,
	ID_CPOS = 70,
	ID_EG = 71,
	ID_GGS = 72
	//ID_CHIATXT = 71,
	//ID_CLIATXT = 72,
	//ID_CLIATXT2 = 73,
	//ID_CLIATXT3 = 74,
	//ID_SLATXT = 75,
	//ID_SLATXT2 = 76,
	//ID_SLATXT3 = 77,
	//ID_SLATXT4 = 78,
	//ID_SLATXT5 = 79,
};

enum class DD_CONTROL {
	ID_DDSWORD = 70,
	ID_DDLANCE = 71,
	ID_DDAXE = 72,
	ID_DDBOW = 73,
	ID_DDGAUNTLETS = 74,
	ID_DDREASON = 75,
	ID_DDFAITH = 76,
	ID_DDAUTHORITY = 77,
	ID_DDHEAVYARMOR = 78,
	ID_DDRIDING = 79,
	ID_DDFLYING = 80
};

enum class ST_CONTROL {
	ID_STSWORD = 81,
	ID_STLANCE = 82,
	ID_STAXE = 83,
	ID_STBOW = 84,
	ID_STGAUNTLETS = 85,
	ID_STREASON = 86,
	ID_STFAITH = 87,
	ID_STAUTHORITY = 88,
	ID_STHEAVYARMOR = 89,
	ID_STRIDING = 90,
	ID_STFLYING = 91
};

enum class WT_CONTROL {
	ID_BSWORD = 1,
	ID_BAXE = 2,
	ID_BLANCE = 3,
	ID_BBOW = 4,
	ID_BGAUNTLETS = 5,
	ID_BBLACKMAGIC = 6,
	ID_BDARKMAGIC = 7,
	ID_BWHITEMAGIC = 8
};

enum class VARIOUS_SIZE {
	WEAPON_TYPE_SIZE = 8,
	CHARACTER_DATA_SIZE = 41,
	WEAPON_DATA_SIZE = 196,
	CLASS_DATA_SIZE = 53,
	EQUIPMENT_DATA_SIZE = 28,
	BATTALION_DATA_SIZE = 187,
	SL_DATA_SIZE = 11,

	CHAR_CLASS_STATS_SIZE = 10,
	TOTAL_STATS_SIZE = 11,
	EQUIPMENT_STATS_SIZE = 12,
	MIN_HEIGHT_OF_COMBOBOX = 23,
	SET_LENGTH_OF_COLUMNS = 34,
};

enum class SL : int {
	BLANK = -1, 
	E = 0, 
	EPLUS = 1, 
	D = 2, 
	DPLUS = 3, 
	C = 4, 
	CPLUS = 5, 
	B = 6, 
	BPLUS = 7, 
	A = 8, 
	APLUS = 9, 
	S = 10, 
	SPLUS = 11
};

enum class SKILLTYPE : int {
	BLANK = -1,
	SWORD = 0,
	AXE = 1,
	LANCE = 2,
	BOW = 3,
	GAUNTLETS = 4,
	REASON = 5,
	FAITH = 6,
	AUTHORITY = 7, 
	HEAVYARMOR = 8, 
	RIDING = 9, 
	FLYING = 10
};

enum class WEAPONTYPE : int {
	BLANK = -1,
	SWORD = 0,
	AXE = 1,
	LANCE = 2,
	BOW = 3,
	GAUNTLETS = 4,
	BLACKMAGIC = 5,
	DARKMAGIC = 6,
	WHITEMAGIC = 7,
	BOTH = 13


};

enum class EQUIPMENTTYPE : int {
	BLANK = -1, 
	SHIELD = 0, 
	RING = 1, 
	STAFF = 2, 
	GEM = 3
};

struct SKILLLEVELPACKAGE : public wxClientData {
	SL sl;
	wxString slstring;
	int index;

	SKILLLEVELPACKAGE(SL uSL) : sl(uSL), index{}, slstring{} {}
};

struct CHARSLPACKAGE : public wxClientData {
	SL sl;
	wxString charactername;

	CHARSLPACKAGE(SL usl, wxString ucharactername) : sl{ usl }, charactername{ ucharactername } {}
};

struct STINCPACKAGE : public wxClientData {
	bool isNotIncluded;
	int index;

	STINCPACKAGE(bool inclusion, int id) : isNotIncluded(inclusion), index{id} {}
};

enum class STATTYPE : int {
	BLANK = -1,
	HP,
	MOV,
	STR,
	MAG,
	DEX,
	SPD,
	LCK,
	DEF,
	RES,
	CHA,
	MIGHT,
	GMIGHT,
	HIT,
	GHIT,
	CRIT,
	RANGE,
	WEIGHT,
	USES,
	PROT,
	TCRIT,
	AVO,
	MATK,
	HEAL,
	PATK,
	END,
	CRITAVO
};

struct STATPACKAGE {
	STATTYPE stattype;
	wxString value;

	STATPACKAGE() {}
	STATPACKAGE(STATTYPE ust, wxString uvalue) : stattype {ust}, value {uvalue} {}
};

struct STATPACKAGEVECTOR : public wxClientData {
	std::vector<STATPACKAGE> statpVector;

	STATPACKAGEVECTOR() {}
	STATPACKAGEVECTOR(std::vector<STATPACKAGE> ustatpVector) : statpVector{ ustatpVector } {}
	auto begin() { return statpVector.begin(); }
	auto end() { return statpVector.end(); }
};

//struct AbilityStats {	
//	std::wstring hp = 0;
//	std::wstring mov = 0;
//	std::wstring str = 0;
//	std::wstring mag = 0;
//	std::wstring dex = 0;
//	std::wstring spd = 0;
//	std::wstring lck = 0;
//	std::wstring def = 0;
//	std::wstring res = 0;
//	std::wstring cha = 0;
//	std::wstring might = 0;
//	std::wstring gmight = 0;
//	std::wstring hit = 0;
//	std::wstring ghit = 0;
//	std::wstring crit = 0;
//	std::wstring range = 0;
//	std::wstring weight = 0;
//	std::wstring uses = 0;
//	std::wstring prot = 0;
//	std::wstring tcrit = 0;
//	std::wstring avo = 0;
//	std::wstring matk = 0;
//	std::wstring heal = 0;
//	std::wstring patk = 0;
//	std::wstring end = 0;
//	std::wstring critavo = 0;
//};

#endif
#ifndef CONSTANTS_H
#define CONSTANTS_H
//#include <vld.h>
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
	ID_AP = 54,
	ID_GTBSLAS = 55,
	ID_ESLA = 56,
	ID_SLP = 57,
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
	ID_CPOS = 70

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

enum class WEAPONTYPE : int {
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

enum class EQUIPMENTTYPE : int {
	BLANK = -1, 
	SHIELD = 0, 
	RING = 1, 
	STAFF = 2, 
	GEM = 3
};

struct SLPACKAGE : public wxClientData {
	SL sl;
	wxString slstring;
	int index;

	SLPACKAGE(SL uSL) : sl(uSL), index{}, slstring{} {}
};

struct WTPACKAGE : public wxClientData {
	bool isNotIncluded;
	int index;

	WTPACKAGE(bool inclusion, int id) : isNotIncluded(inclusion), index{id} {}
};

#endif

//#define ID_FRAME		7
//#define ID_MT			8
//#define ID_DDCH			9
//#define ID_DDCL1		10
//#define ID_DDCL2		11
//#define ID_DDCL3		12
//#define ID_SPIN1		15
//#define ID_SPIN2		16
//#define ID_GMT			20
//#define ID_LBW			30
//#define ID_LBE			31
//#define ID_LBB			32
//#define ID_GWS			33
//#define ID_GES			34
//#define ID_GBS			35
//#define ID_GTS			36
//#define ID_SLM			37
//#define ID_AM				38
//#define ID_LBAA			39
//#define ID_LBSA			40
//#define ID_BML			41
//#define ID_BMR			42
//#define ID_DDSWORD		50
//#define ID_DDLANCE		51
//#define ID_DDAXE		52
//#define ID_DDBOW		53
//#define ID_DDGAUNTLETS	54
//#define ID_DDREASON		55
//#define ID_DDFAITH		56
//#define ID_DDAUTHORITY	57
//#define ID_DDHEAVYARMOR 58
//#define ID_DDRIDING		59
//#define ID_DDFLYING		60
//#define ID_STSWORD		61
//#define ID_STLANCE		62
//#define ID_STAXE		63
//#define ID_STBOW		64
//#define ID_STGAUNTLETS	65
//#define ID_STREASON		66
//#define ID_STFAITH		67
//#define ID_STAUTHORITY	68
//#define ID_STHEAVYARMOR 69
//#define ID_STRIDING		70
//#define ID_STFLYING		71
//const unsigned int CHARACTER_DATA_SIZE = 41;
//const unsigned int WEAPON_DATA_SIZE = 196;
//const unsigned int CLASS_DATA_SIZE = 53;
//const unsigned int EQUIPMENT_DATA_SIZE = 28;
//const unsigned int BATTALION_DATA_SIZE = 187;
//const unsigned int SL_DATA_SIZE = 11;
//const unsigned int CHAR_CLASS_STATS_SIZE = 10;
//const unsigned int TOTAL_STATS_SIZE = 11;
//const unsigned int MIN_HEIGHT_OF_COMBOBOX = 23;
//const unsigned int SET_LENGTH_OF_COLUMNS = 34;

#ifndef CONSTANTS_H
#define CONSTANTS_H
//#include <vld.h>

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
const unsigned int WEAPON_DATA_SIZE = 196;
const unsigned int CLASS_DATA_SIZE = 53;
const unsigned int EQUIPMENT_DATA_SIZE = 28;
const unsigned int BATTALION_DATA_SIZE = 187;
const unsigned int SL_DATA_SIZE = 11;
const unsigned int CHAR_CLASS_STATS_SIZE = 10;
const unsigned int TOTAL_STATS_SIZE = 11;
const unsigned int MIN_HEIGHT_OF_COMBOBOX = 23;
const unsigned int SET_LENGTH_OF_COLUMNS = 34;

enum class SL : int {
	BLANK = -1, E = 0, EPLUS = 1, D = 2, DPLUS = 3, C = 4, CPLUS = 5, B = 6, BPLUS = 7, A = 8, APLUS = 9, S = 10, SPLUS = 11
};

enum class WEAPONTYPE : int {
	BLANK = -1, SWORD = 0, LANCE = 1, AXE = 2, BOW = 3, GAUNTLETS = 4, REASON = 5, FAITH = 6, AUTHORITY = 7, HEAVYARMOR = 8, RIDING = 9, FLYING = 10
};

enum class EQUIPMENTTYPE : int {
	BLANK = -1, SHIELD = 0, RING = 1, STAFF = 2, GEM = 3
};

struct SLPACKAGE : public wxClientData {
	SL sl;
	wxString slstring;
	int index;

	SLPACKAGE(SL uSL) : sl(uSL), index{}, slstring{} {}
};

#endif
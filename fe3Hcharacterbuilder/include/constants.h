#ifndef CONSTANTS_H
#define CONSTANTS_H
//#include <vld.h>
#include <string>

enum class ID_MISC {
	ID_FRAME,
	ID_MT,
	ID_DDCH,
	ID_DDCL1,
	ID_DDCL2,
	ID_DDCL3,
	ID_SPIN1,
	ID_SPIN2,
	ID_GMT,
	ID_WM,
	//ID_ECLIA,
	//ID_ECLIA2,
	//ID_ECLIA3,
	//ID_SLA,
	//ID_SLA2,
	//ID_SLA3,
	//ID_SLA4,
	//ID_SLA5,
	ID_BCLASSMASTERY
};

enum class ID_SINGLE_CONTROL {
	ID_LBW, 
	ID_LBE, 
	ID_LBB,
	ID_GWS,
	ID_GES,
	ID_GBS,
	ID_SLM,
	ID_LBASLA,
	//ID_LBSSLA,
	//ID_LBSA,
	//ID_BAA,
	//ID_BRA,
	ID_EB,
	ID_EW,
	ID_EE,
	ID_EP,
	ID_SP,
	ID_GTBCHIAS,
	//ID_GTBCLIAS,
	ID_ECHIA,
	ID_ECLIA,
	ID_ECLIA2,
	ID_ECLIA3,
	ID_AP,
	//ID_GTBSLAS,
	ID_ESLA,
	ID_SLP,
	ID_GCHIAS,
	ID_GCLIAS,
	ID_GCLIAS2,
	ID_GCLIAS3,
	ID_GSLAS,
	ID_GSLAS2,
	ID_GSLAS3,
	ID_GSLAS4,
	ID_GSLAS5,	
	ID_GTS,
	ID_CPOS,
	ID_EG,
	ID_GGS
};

enum class DD_CONTROL {
	ID_DDSWORD = 70,
	ID_DDLANCE,
	ID_DDAXE,
	ID_DDBOW,
	ID_DDGAUNTLETS,
	ID_DDREASON,
	ID_DDFAITH,
	ID_DDAUTHORITY,
	ID_DDHEAVYARMOR,
	ID_DDRIDING,
	ID_DDFLYING
};

enum class ST_CONTROL {
	ID_STSWORD = 81,
	ID_STLANCE,
	ID_STAXE,
	ID_STBOW,
	ID_STGAUNTLETS,
	ID_STREASON,
	ID_STFAITH,
	ID_STAUTHORITY,
	ID_STHEAVYARMOR,
	ID_STRIDING,
	ID_STFLYING
};

enum class WT_CONTROL {
	ID_BSWORD = 1,
	ID_BAXE,
	ID_BLANCE,
	ID_BBOW,
	ID_BGAUNTLETS,
	ID_BBLACKMAGIC,
	ID_BDARKMAGIC,
	ID_BWHITEMAGIC
};

enum class CONSTANT_SIZE {
	WEAPON_TYPE_SIZE = 8,
	CHARACTER_DATA_SIZE = 41,
	WEAPON_DATA_SIZE = 196,
	CLASS_DATA_SIZE = 53,
	EQUIPMENT_DATA_SIZE = 28,
	BATTALION_DATA_SIZE = 187,
	SL_DATA_SIZE = 11,

	//CHAR_CLASS_STATS_SIZE = 10,
	TOTAL_STATS_SIZE = 12,
	EQUIPMENT_STATS_SIZE = 12,
	NUM_OF_SKILL_LEVELS_PER_DDSL = 12,
	NUM_OF_WEAPON_RELATED_SKILL_LEVELS = 8,
	NUM_OF_GENERAL_WEAPONS = 178,
	NUM_OF_CLASS_INNATE_ABILITIES_MAX = 3,
	NUM_OF_SKILL_LEVEL_ABILITIES_MAX = 5,
	NUM_OF_GMT_COLS = 10,
	NUM_OF_SCL_IN_MT = 2,
	NUM_OF_DDCL_IN_MT = 3,
	NUM_OF_COLS_IN_MT_SIZER = 3,
	NUM_OF_COLS_IN_GCHIAS = 2,
	NUM_OF_COLS_IN_GCLIAS = 3,
	NUM_OF_COLS_IN_GSLAS = 3,
	NUM_OF_GCLIAS_IN_CPOPTIONALSTATS = 3,
	NUM_OF_GSLAS_IN_CPOPTIONALSTATS = 5,
	SIZE_OF_ULIST = 506,
	SIZE_OF_ALIST = 206,
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
	BOTH = 13,
	ALL = 14


};

enum class PROWESSTYPE : int {
	SWORD,
	AXE,
	LANCE,
	BOW,
	GAUNTLETS,
	REASON,
	FAITH,
	AUTHORITY
};

enum class EQUIPMENTTYPE : int {
	BLANK = -1, 
	SHIELD = 0, 
	RING = 1, 
	STAFF = 2, 
	GEM = 3
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
	PMIGHT,
	MMIGHT,
	GMIGHT,	
	PATK,
	MATK,
	HIT,
	GHIT,
	CRIT,	
	WCRIT,
	//TCRIT,
	AVO,
	CRITAVO,
	PROT,
	RANGE,
	WEIGHT,
	USES,
	HEAL,
	END
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

#endif
#ifndef CHARACTER_H
#define CHARACTER_H

#include <wx/wx.h>
#include <Stat.h>
#include <Growth.h>
#include <Unit/Unit.h>

class Character : public Unit {
private:
	std::wstring charname;
	Stats charstats;
	Growths basegrowths;
public:
	Character() {}
	Character(std::wstring uNAME,
		std::wstring uHP, std::wstring uMOV, std::wstring uSTR,
		std::wstring uMAG, std::wstring uDEX, std::wstring uSPD,
		std::wstring uLCK, std::wstring uDEF, std::wstring uRES, 
		std::wstring uCHA,
		std::wstring bHP, std::wstring bMOV, std::wstring bSTR, 
		std::wstring bMAG, std::wstring bDEX, std::wstring bSPD, 
		std::wstring bLCK, std::wstring bDEF, std::wstring bRES, 
		std::wstring bCHA)
		:
		charname{ uNAME },
		charstats{ uHP, uMOV, uSTR,
					uMAG, uDEX, uSPD,
					uLCK, uDEF, uRES,
					uCHA },
		basegrowths{ bHP, bMOV, bSTR,
						bMAG, bDEX, bSPD,
						bLCK, bDEF, bRES,
						bCHA }
	{}
	~Character() {}

	const std::wstring getName() override { return charname; }
	const Stats getStats() override { return charstats; }

	Character* new_expr() override { return new Character(); }
	Character* clone() override { return new Character(*this); }	
	
	const Growths getGrowths() { return basegrowths; }
};

#endif
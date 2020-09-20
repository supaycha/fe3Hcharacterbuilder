#ifndef CLASS_H
#define CLASS_H

#include <wx/wx.h>
#include <Stat.h>
#include <Growth.h>
#include <Unit/Unit.h>

class Class : public Unit {
private:
	std::wstring name;
	bool hasExclusivity;
	std::wstring charactername;
	Stats basestats;
	Stats classboosts;
	Growths classgrowths;
	Stats mountedvariances;
public:
	Class() {}
	Class(std::wstring uNAME, bool uHasExclusivity, std::wstring uCharacterName,
			std::wstring uHP, std::wstring uMOV, std::wstring uSTR,
			std::wstring uMAG, std::wstring uDEX, std::wstring uSPD,
			std::wstring uLCK, std::wstring uDEF, std::wstring uRES,
			std::wstring uCHA,
			std::wstring bHP, std::wstring bMOV, std::wstring bSTR, 
			std::wstring bMAG, std::wstring bDEX, std::wstring bSPD, 
			std::wstring bLCK, std::wstring bDEF, std::wstring bRES, 
			std::wstring bCHA,
			std::wstring cHP, std::wstring cMOV, std::wstring cSTR,
			std::wstring cMAG, std::wstring cDEX, std::wstring cSPD, 
			std::wstring cLCK, std::wstring cDEF, std::wstring cRES, 
			std::wstring cCHA,
			std::wstring dHP, std::wstring dMOV, std::wstring dSTR, 
			std::wstring dMAG, std::wstring dDEX, std::wstring dSPD, 
			std::wstring dLCK, std::wstring dDEF, std::wstring dRES, 
			std::wstring dCHA) :
		name{ uNAME },
		hasExclusivity{ uHasExclusivity },
		charactername{ uCharacterName },
		basestats{ uHP, uMOV, uSTR,
					uMAG, uDEX, uSPD,
					uLCK, uDEF, uRES,
					uCHA },
		classboosts{ bHP, bMOV, bSTR,
					bMAG, bDEX, bSPD,
					bLCK, bDEF, bRES,
					bCHA },
		classgrowths{ cHP, cMOV, cSTR,
					cMAG, cDEX, cSPD,
					cLCK, cDEF, cRES,
					cCHA },
		mountedvariances{ dHP, dMOV, dSTR,
						dMAG, dDEX, dSPD,
						dLCK, dDEF, dRES,
						dCHA }
	{}
	~Class() {}

	const std::wstring getName() override { return name; }
	const Stats getStats() override { return basestats; }

	Class* new_expr() override { return new Class(); }
	Class* clone() override { return new Class(*this); }

	const Stats getBoostedStats() { return classboosts; }
	const Growths getGrowths() { return classgrowths; }
	const Stats getMountedStats() { return mountedvariances; }
	bool getExclusivity() { return hasExclusivity; }
	std::wstring getCharacterName() { return charactername; }
};

#endif
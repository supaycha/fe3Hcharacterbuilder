#ifndef SKILLLEVELABILITY_H
#define SKILLLEVELABILITY_H

#include <string>
#include <constants.h>
#include <Unit/Ability/Ability.h>

class SkillLevelAbility : public Ability {
private:
	std::wstring slaType = L"SkillLevel";
	SL sl;
	WEAPONTYPE wt;
	bool hasStatUp;
	STPACKAGE stp;
	STPACKAGE stp2;
	STPACKAGE stp3;
public:
	SkillLevelAbility() {}
	SkillLevelAbility(std::wstring uName, std::wstring uSource, SL uLevel, WEAPONTYPE uWT, std::wstring uDescription, 
			bool uHasStatUp, STATTYPE ust, wxString uname) : 
		sl(uLevel), wt(uWT), hasStatUp{ uHasStatUp }, stp{ ust, uname }, Ability{ uName, uSource, uDescription } {}
	SkillLevelAbility(std::wstring uName, std::wstring uSource, SL uLevel, WEAPONTYPE uWT, std::wstring uDescription, 
			bool uHasStatUp, STATTYPE ust, wxString uname, STATTYPE ust2, wxString uname2) :
		sl(uLevel), wt(uWT), hasStatUp{ uHasStatUp }, stp{ ust, uname }, stp2{ ust2, uname2 }, Ability{ uName, uSource, uDescription } {}
	SkillLevelAbility(std::wstring uName, std::wstring uSource, SL uLevel, WEAPONTYPE uWT, std::wstring uDescription, 
			bool uHasStatUp, STATTYPE ust, wxString uname, STATTYPE ust2, wxString uname2, STATTYPE ust3, wxString uname3) :
		sl(uLevel), wt(uWT), hasStatUp{ uHasStatUp }, stp{ ust, uname }, stp2{ ust2, uname2 }, stp3{ ust3, uname3 }, Ability{ uName, uSource, uDescription } {}

	~SkillLevelAbility() {}
	std::wstring getType() { return slaType; }

	SL getSL() { return sl; }
	WEAPONTYPE getWeaponType() { return wt; }
	bool getHasStatUp() { return hasStatUp; }
	STPACKAGE getSTP() { return stp; }
	SkillLevelAbility* new_expr() override { return new SkillLevelAbility(); }
	SkillLevelAbility* clone() override { return new SkillLevelAbility(*this); }
};

#endif
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
	std::vector<STPACKAGE> stpVector;
public:
	SkillLevelAbility() {}
	SkillLevelAbility(std::wstring uName, std::wstring uSource, SL uLevel, WEAPONTYPE uWT, std::wstring uDescription, 
			bool uHasStatUp, STATTYPE ust, wxString uname) : 
		sl(uLevel), wt(uWT), hasStatUp{ uHasStatUp }, stpVector{ STPACKAGE(ust, uname) }, Ability{ uName, uSource, uDescription } {}
	SkillLevelAbility(std::wstring uName, std::wstring uSource, SL uLevel, WEAPONTYPE uWT, std::wstring uDescription, 
			bool uHasStatUp, STATTYPE ust, wxString uname, STATTYPE ust2, wxString uname2) :
		sl(uLevel), wt(uWT), hasStatUp{ uHasStatUp }, stpVector{ STPACKAGE(ust, uname), STPACKAGE(ust, uname) }, Ability{ uName, uSource, uDescription } {}
	SkillLevelAbility(std::wstring uName, std::wstring uSource, SL uLevel, WEAPONTYPE uWT, std::wstring uDescription, 
			bool uHasStatUp, STATTYPE ust, wxString uname, STATTYPE ust2, wxString uname2, STATTYPE ust3, wxString uname3) :
		sl(uLevel), wt(uWT), hasStatUp{ uHasStatUp }, stpVector{ STPACKAGE(ust, uname), STPACKAGE(ust2, uname2), STPACKAGE(ust3, uname3) }, Ability{ uName, uSource, uDescription } {}

	~SkillLevelAbility() {}
	std::wstring getType() { return slaType; }

	SL getSL() { return sl; }
	WEAPONTYPE getWeaponType() { return wt; }
	bool getHasStatUp() { return hasStatUp; }
	std::vector<STPACKAGE>  getSTP() { return stpVector; }
	SkillLevelAbility* new_expr() override { return new SkillLevelAbility(); }
	SkillLevelAbility* clone() override { return new SkillLevelAbility(*this); }
};

#endif
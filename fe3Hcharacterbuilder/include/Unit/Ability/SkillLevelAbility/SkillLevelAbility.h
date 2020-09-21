#ifndef SKILLLEVELABILITY_H
#define SKILLLEVELABILITY_H

#include <string>
#include <constants.h>
#include <Unit/Ability/Ability.h>

class SkillLevelAbility : public Ability {
private:
	std::wstring slaType = L"SkillLevel";
	SKILLTYPE st;
	WEAPONTYPE wt;
	bool hasStatUp;
	std::vector<STATPACKAGE> statpVector;
public:
	SkillLevelAbility() {}
	SkillLevelAbility(std::wstring uName, std::wstring uSource, SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription,
		bool uHasStatUp, std::vector<STATPACKAGE> ustatpVector) :
		st(uST),
		wt(uWT), 
		hasStatUp{ uHasStatUp }, 
		statpVector{ ustatpVector }, 
		Ability{ uName, uSource, uDescription } 
	{}
	SkillLevelAbility(const SkillLevelAbility&) = default;
	virtual ~SkillLevelAbility() {}

	virtual std::wstring getType() { return slaType; }

	virtual SkillLevelAbility* new_expr() = 0;
	virtual SkillLevelAbility* clone() = 0;

	bool getHasStatUp() { return hasStatUp; }
	std::vector<STATPACKAGE>  getSTATP() { return statpVector; }
	virtual SKILLTYPE getSkillType() { return st; }
	virtual WEAPONTYPE getWeaponType() { return wt; }
};

#endif
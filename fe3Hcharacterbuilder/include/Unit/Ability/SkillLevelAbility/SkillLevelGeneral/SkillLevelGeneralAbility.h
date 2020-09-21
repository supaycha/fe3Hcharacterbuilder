#ifndef SKILLLEVELGENERALABILITY_H
#define SKILLLEVELGENERALABILITY_H

#include <string>
#include <constants.h>
#include <Unit/Ability/SkillLevelAbility/SkillLevelAbility.h>

class SkillLevelGeneralAbility : public SkillLevelAbility {
private:	
	SL sl;
public:
	SkillLevelGeneralAbility() {}
	SkillLevelGeneralAbility(std::wstring uName, std::wstring uSource, SL usl, 
		SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription,
		bool uHasStatUp, std::vector<STATPACKAGE> ustatpVector) :
		sl{ usl }, 
		SkillLevelAbility(uName, uSource, uST, uWT, uDescription, uHasStatUp, ustatpVector)
	{}
	SkillLevelGeneralAbility(const SkillLevelGeneralAbility&) = default;
	~SkillLevelGeneralAbility() {}

	SkillLevelGeneralAbility* new_expr() override { return new SkillLevelGeneralAbility(); }
	SkillLevelGeneralAbility* clone() override { return new SkillLevelGeneralAbility(*this); }	
	
	virtual SL getSL() { return sl; }
};

#endif
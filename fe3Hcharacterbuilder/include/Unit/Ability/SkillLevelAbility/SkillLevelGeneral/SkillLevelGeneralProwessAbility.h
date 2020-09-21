#ifndef SKILLLEVELGENERALPROWESSABILITY_H
#define SKILLLEVELGENERALPROWESSABILITY_H

#include <string>
#include <constants.h>
#include <Unit/Ability/SkillLevelAbility/SkillLevelGeneral/SkillLevelGeneralAbility.h>

class SkillLevelGeneralProwessAbility : public SkillLevelGeneralAbility {
private:
	PROWESSTYPE pt;
public:
	SkillLevelGeneralProwessAbility() {}
	SkillLevelGeneralProwessAbility(std::wstring uName, std::wstring uSource, SL uSL, 
		SKILLTYPE uST, WEAPONTYPE uWT, PROWESSTYPE uPT, 
		std::wstring uDescription, bool uHasStatUp, std::vector<STATPACKAGE> ustatpVector) :
		pt { uPT },
		SkillLevelGeneralAbility(uName, uSource, uSL, uST, uWT, uDescription, uHasStatUp, ustatpVector)
	{}
	~SkillLevelGeneralProwessAbility() {}

	SkillLevelGeneralProwessAbility* new_expr() override { return new SkillLevelGeneralProwessAbility(); }
	SkillLevelGeneralProwessAbility* clone() override { return new SkillLevelGeneralProwessAbility(*this); }	
	
	PROWESSTYPE getProwessType() { return pt; }
};

#endif
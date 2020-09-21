#ifndef SKILLLEVELCHARACTERABILITY_H
#define SKILLLEVELCHARACTERABILITY_H

#include <string>
#include <constants.h>
#include <Unit/Ability/SkillLevelAbility/SkillLevelAbility.h>

class SkillLevelCharacterAbility : public SkillLevelAbility {
private:
	std::vector<CHARSLPACKAGE> charsl;
public:
	SkillLevelCharacterAbility() {}
	SkillLevelCharacterAbility(std::wstring uName, std::wstring uSource, std::vector<CHARSLPACKAGE> ucharsl, 
		SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription,
		bool uHasStatUp, std::vector<STATPACKAGE> ustatpVector) :
		charsl{ ucharsl },
		SkillLevelAbility(uName, uSource, uST, uWT, uDescription, uHasStatUp, ustatpVector)
	{}
	~SkillLevelCharacterAbility() {}

	SkillLevelCharacterAbility* new_expr() override { return new SkillLevelCharacterAbility(); }
	SkillLevelCharacterAbility* clone() override { return new SkillLevelCharacterAbility(*this); }	
	
	std::vector<CHARSLPACKAGE> getCharSL() { return charsl; }
};

#endif
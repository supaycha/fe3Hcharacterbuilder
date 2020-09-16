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
	SkillLevelCharacterAbility(std::wstring uName, std::wstring uSource, std::vector<CHARSLPACKAGE> ucharsl, SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription,
		bool uHasStatUp, std::vector<STATPACKAGE> ustatpVector) :
		charsl{ ucharsl },
		SkillLevelAbility(uName, uSource, uST, uWT, uDescription, uHasStatUp, ustatpVector)
	{}
	//SkillLevelCharacterAbility(std::wstring uName, std::wstring uSource, SL usl, SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription, bool uHasStatUp,
	//	STATTYPE ust, wxString uname, STATTYPE ust2, wxString uname2) :
	//	sl{ usl },
	//	SkillLevelAbility(uName, uSource, uST, uWT, uDescription, uHasStatUp, ust, uname, ust2, uname2)
	//{}
	//SkillLevelCharacterAbility(std::wstring uName, std::wstring uSource, SL usl, SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription, bool uHasStatUp,
	//	STATTYPE ust, wxString uname, STATTYPE ust2, wxString uname2, STATTYPE ust3, wxString uname3) :
	//	sl{ usl },
	//	SkillLevelAbility(uName, uSource, uST, uWT, uDescription, uHasStatUp, ust, uname, ust2, uname2, ust3, uname3)
	//{}
	~SkillLevelCharacterAbility() {}

	std::vector<CHARSLPACKAGE> getCharSL() { return charsl; }
	SkillLevelCharacterAbility* new_expr() override { return new SkillLevelCharacterAbility(); }
	SkillLevelCharacterAbility* clone() override { return new SkillLevelCharacterAbility(*this); }
};

#endif
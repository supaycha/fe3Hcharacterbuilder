#ifndef SKILLLEVELABILITY_H
#define SKILLLEVELABILITY_H

#include <string>
#include <constants.h>
#include <Unit/Ability/Ability.h>

class SkillLevelAbility : public Ability {
private:
	std::wstring slaType = L"SkillLevel";
	SL sl;
	SKILLTYPE st;
	WEAPONTYPE wt;
	bool hasStatUp;
	std::vector<STATPACKAGE> statpVector;
public:
	SkillLevelAbility() {}
	SkillLevelAbility(std::wstring uName, std::wstring uSource, SL uLevel, SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription,
			bool uHasStatUp, STATTYPE ust, wxString uname) : 
		sl(uLevel), st(uST), wt(uWT), hasStatUp{ uHasStatUp }, statpVector{ STATPACKAGE(ust, uname) }, Ability{ uName, uSource, uDescription } {}
	SkillLevelAbility(std::wstring uName, std::wstring uSource, SL uLevel, SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription,
			bool uHasStatUp, STATTYPE ust, wxString uname, STATTYPE ust2, wxString uname2) :
		sl(uLevel), st(uST), wt(uWT), hasStatUp{ uHasStatUp }, statpVector{ STATPACKAGE(ust, uname), STATPACKAGE(ust, uname) }, Ability{ uName, uSource, uDescription } {}
	SkillLevelAbility(std::wstring uName, std::wstring uSource, SL uLevel, SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription,
			bool uHasStatUp, STATTYPE ust, wxString uname, STATTYPE ust2, wxString uname2, STATTYPE ust3, wxString uname3) :
		sl(uLevel), st(uST), wt(uWT), hasStatUp{ uHasStatUp }, statpVector{ STATPACKAGE(ust, uname), STATPACKAGE(ust2, uname2), STATPACKAGE(ust3, uname3) }, Ability{ uName, uSource, uDescription } {}

	~SkillLevelAbility() {}
	std::wstring getType() { return slaType; }

	SL getSL() { return sl; }
	SKILLTYPE getSkillType() { return st; }
	WEAPONTYPE getWeaponType() { return wt; }
	bool getHasStatUp() { return hasStatUp; }
	std::vector<STATPACKAGE>  getWTP() { return statpVector; }
	SkillLevelAbility* new_expr() override { return new SkillLevelAbility(); }
	SkillLevelAbility* clone() override { return new SkillLevelAbility(*this); }
};

#endif
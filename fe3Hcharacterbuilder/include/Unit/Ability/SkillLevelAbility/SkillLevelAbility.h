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
		st(uST), wt(uWT), hasStatUp{ uHasStatUp }, statpVector{ ustatpVector }, Ability{ uName, uSource, uDescription } {}
	//SkillLevelAbility(std::wstring uName, std::wstring uSource, SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription,
	//		bool uHasStatUp, STATTYPE ust, wxString uname, STATTYPE ust2, wxString uname2) :
	//	st(uST), wt(uWT), hasStatUp{ uHasStatUp }, statpVector{ STATPACKAGE(ust, uname), STATPACKAGE(ust2, uname2) }, Ability{ uName, uSource, uDescription } {}
	//SkillLevelAbility(std::wstring uName, std::wstring uSource, SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription,
	//		bool uHasStatUp, STATTYPE ust, wxString uname, STATTYPE ust2, wxString uname2, STATTYPE ust3, wxString uname3) :
	//	st(uST), wt(uWT), hasStatUp{ uHasStatUp }, statpVector{ STATPACKAGE(ust, uname), STATPACKAGE(ust2, uname2), STATPACKAGE(ust3, uname3) }, Ability{ uName, uSource, uDescription } {}

	virtual ~SkillLevelAbility() {}
	SkillLevelAbility(const SkillLevelAbility&) = default;

	bool getHasStatUp() { return hasStatUp; }
	std::vector<STATPACKAGE>  getWTP() { return statpVector; }

	virtual std::wstring getType() { return slaType; }
	virtual SKILLTYPE getSkillType() { return st; }
	virtual WEAPONTYPE getWeaponType() { return wt; }
	virtual SkillLevelAbility* new_expr() = 0;
	virtual SkillLevelAbility* clone() = 0;
};

#endif
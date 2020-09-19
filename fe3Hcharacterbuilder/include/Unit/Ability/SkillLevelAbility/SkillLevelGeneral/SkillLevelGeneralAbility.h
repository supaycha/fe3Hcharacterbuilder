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
	SkillLevelGeneralAbility(std::wstring uName, std::wstring uSource, SL usl, SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription,
							bool uHasStatUp, std::vector<STATPACKAGE> ustatpVector) :
		sl{ usl }, 
		SkillLevelAbility(uName, uSource, uST, uWT, uDescription, uHasStatUp, ustatpVector)
	{}
	//SkillLevelGeneralAbility(std::wstring uName, std::wstring uSource, SL usl, SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription, bool uHasStatUp, 
	//	STATTYPE ust, wxString uname, STATTYPE ust2, wxString uname2) :
	//	sl{ usl },
	//	SkillLevelAbility(uName, uSource, uST, uWT, uDescription, uHasStatUp, ust, uname, ust2, uname2)
	//{}
	//SkillLevelGeneralAbility(std::wstring uName, std::wstring uSource, SL usl, SKILLTYPE uST, WEAPONTYPE uWT, std::wstring uDescription, bool uHasStatUp,
	//	STATTYPE ust, wxString uname, STATTYPE ust2, wxString uname2, STATTYPE ust3, wxString uname3) :
	//	sl{ usl },
	//	SkillLevelAbility(uName, uSource, uST, uWT, uDescription, uHasStatUp, ust, uname, ust2, uname2, ust3, uname3)
	//{}
	~SkillLevelGeneralAbility() {}

	virtual SL getSL() { return sl; }
	SkillLevelGeneralAbility* new_expr() override { return new SkillLevelGeneralAbility(); }
	SkillLevelGeneralAbility* clone() override { return new SkillLevelGeneralAbility(*this); }
};

#endif
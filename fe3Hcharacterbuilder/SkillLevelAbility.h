#ifndef SKILLLEVELABILITY_H
#define SKILLLEVELABILITY_H

class SkillLevelAbility : public Ability {
private:
	std::wstring slaType = L"SkillLevel";
	SL sl;
	WEAPONTYPE wt;
public:
	SkillLevelAbility() {}
	SkillLevelAbility(std::wstring uName, std::wstring uSource, SL uLevel, WEAPONTYPE uWT, std::wstring uDescription) : sl(uLevel), wt(uWT), Ability{ uName, uSource, uDescription } {}
	~SkillLevelAbility() {}
	std::wstring getType() { return slaType; }

	SL getSL() { return sl; }
	WEAPONTYPE getWeaponType() { return wt; }
	SkillLevelAbility* new_expr() override { return new SkillLevelAbility(); }
	SkillLevelAbility* clone() override { return new SkillLevelAbility(*this); }
};

#endif
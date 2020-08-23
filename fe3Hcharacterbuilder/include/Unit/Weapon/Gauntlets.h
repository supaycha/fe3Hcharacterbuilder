#ifndef GAUNTLETS_H
#define GAUNTLETS_H

class Gauntlets : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::GAUNTLETS;
public:
	Gauntlets() {}
	Gauntlets(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~Gauntlets() {}
	WEAPONTYPE getType() override { return wt; };
	Gauntlets* new_expr() override { return new Gauntlets(); }
	Gauntlets* clone() override { return new Gauntlets(*this); }
};

#endif
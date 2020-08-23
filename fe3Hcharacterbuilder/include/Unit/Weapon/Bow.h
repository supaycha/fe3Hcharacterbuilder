#ifndef BOW_H
#define BOW_H

#include <string>
#include <constants.h>
#include <Unit/Weapon/Weapon.h>

class Bow : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::BOW;
public:
	Bow() {}
	Bow(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~Bow() {}
	WEAPONTYPE getType() override { return wt; };
	Bow* new_expr() override { return new Bow(); }
	Bow* clone() override { return new Bow(*this); }
};

#endif
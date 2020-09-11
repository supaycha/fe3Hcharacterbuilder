#ifndef SWORD_H
#define SWORD_H

#include <string>
#include <constants.h>
#include <Unit/Weapon/Weapon.h>

class Sword : public Weapon {
private:
	SKILLTYPE st = SKILLTYPE::SWORD;
	WEAPONTYPE wt = WEAPONTYPE::SWORD;
public:
	Sword() {}
	Sword(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~Sword() {}
	SKILLTYPE getSkillType() override { return st; };
	WEAPONTYPE getWeaponType() override { return wt; };

	Sword* new_expr() override { return new Sword(); }
	Sword* clone() override { return new Sword(*this); }
};

#endif
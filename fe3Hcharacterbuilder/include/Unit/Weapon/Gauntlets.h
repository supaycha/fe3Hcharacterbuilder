#ifndef GAUNTLETS_H
#define GAUNTLETS_H

#include <string>
#include <constants.h>
#include <Unit/Weapon/Weapon.h>

class Gauntlets : public Weapon {
private:
	SKILLTYPE st = SKILLTYPE::GAUNTLETS;
	WEAPONTYPE wt = WEAPONTYPE::GAUNTLETS;
public:
	Gauntlets() {}
	Gauntlets(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, 
		std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) :
		Weapon{ uName, uExclusivity, uCharacterName, 
				uMight, uHit, uCrit, 
				uRange, uWeight, uSkillLVL,
				uUses, skillLVL } {}
	~Gauntlets() {}

	SKILLTYPE getSkillType() override { return st; };
	WEAPONTYPE getWeaponType() override { return wt; };

	Gauntlets* new_expr() override { return new Gauntlets(); }
	Gauntlets* clone() override { return new Gauntlets(*this); }
};

#endif
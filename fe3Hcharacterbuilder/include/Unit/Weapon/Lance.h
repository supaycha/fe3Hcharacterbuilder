#ifndef LANCE_H
#define LANCE_H

#include <string>
#include <constants.h>
#include <Unit/Weapon/Weapon.h>

class Lance : public Weapon {
private:
	SKILLTYPE st = SKILLTYPE::LANCE;
	WEAPONTYPE wt = WEAPONTYPE::LANCE;
public:
	Lance() {}
	Lance(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, 
		std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : 
		Weapon{ uName, uExclusivity, uCharacterName, 
				uMight, uHit, uCrit, 
				uRange, uWeight, uSkillLVL, 
				uUses, skillLVL } {}
	~Lance() {}

	SKILLTYPE getSkillType() override { return st; };
	WEAPONTYPE getWeaponType() override { return wt; };

	Lance* new_expr() override { return new Lance(); }
	Lance* clone() override { return new Lance(*this); }
};

#endif
#ifndef BLANKWEAPON_H
#define BLANKWEAPON_H

#include <string>
#include <constants.h>
#include <Unit/Weapon/Weapon.h>

class BlankWeapon : public Weapon {
private:
	SKILLTYPE st = SKILLTYPE::BLANK;
	WEAPONTYPE wt = WEAPONTYPE::BLANK;
public:
	BlankWeapon() {}
	BlankWeapon(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~BlankWeapon() {}
	SKILLTYPE getSkillType() override { return st; };
	WEAPONTYPE getWeaponType() override { return wt; };

	BlankWeapon* new_expr() override { return new BlankWeapon(); }
	BlankWeapon* clone() override { return new BlankWeapon(*this); }
};

#endif
#ifndef WHITEMAGIC_H
#define WHITEMAGIC_H

#include <string>
#include <constants.h>
#include <Unit/Weapon/Weapon.h>

class WhiteMagic : public Weapon {
private:
	SKILLTYPE st = SKILLTYPE::FAITH;
	WEAPONTYPE wt = WEAPONTYPE::WHITEMAGIC;
public:
	WhiteMagic() {}
	WhiteMagic(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~WhiteMagic() {}
	SKILLTYPE getSkillType() override { return st; };
	WEAPONTYPE getWeaponType() override { return wt; };

	WhiteMagic* new_expr() override { return new WhiteMagic(); }
	WhiteMagic* clone() override { return new WhiteMagic(*this); }
};

#endif
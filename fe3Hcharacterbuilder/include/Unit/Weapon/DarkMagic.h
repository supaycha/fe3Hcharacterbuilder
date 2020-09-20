#ifndef DARKMAGIC_H
#define DARKMAGIC_H

#include <string>
#include <constants.h>
#include <Unit/Weapon/Weapon.h>

class DarkMagic : public Weapon {
private:	
	SKILLTYPE st = SKILLTYPE::REASON;
	WEAPONTYPE wt = WEAPONTYPE::DARKMAGIC;
public:
	DarkMagic() {}
	DarkMagic(std::wstring uName, bool uExclusivity, std::wstring uCharacterName,
		std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) :
		Weapon{ uName, uExclusivity, uCharacterName, 
				uMight, uHit, uCrit, 
				uRange, uWeight, uSkillLVL, 
				uUses, skillLVL } {}
	~DarkMagic() {}

	SKILLTYPE getSkillType() override { return st; };
	WEAPONTYPE getWeaponType() override { return wt; };

	DarkMagic* new_expr() override { return new DarkMagic(); }
	DarkMagic* clone() override { return new DarkMagic(*this); }
};

#endif
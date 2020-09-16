#ifndef BLACKMAGIC_H
#define BLACKMAGIC_H

#include <string>
#include <constants.h>
#include <Unit/Weapon/Weapon.h>

class BlackMagic : public Weapon {
private:
	SKILLTYPE st = SKILLTYPE::REASON;
	WEAPONTYPE wt = WEAPONTYPE::BLACKMAGIC;
public:
	BlackMagic() {}
	BlackMagic(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~BlackMagic() {}
	SKILLTYPE getSkillType() override { return st; };
	WEAPONTYPE getWeaponType() override { return wt; };

	BlackMagic* new_expr() override { return new BlackMagic(); }
	BlackMagic* clone() override { return new BlackMagic(*this); }
};

#endif
#ifndef AXE_H
#define AXE_H

#include <string>
#include <constants.h>
#include <Unit/Weapon/Weapon.h>

class Axe : public Weapon {
private:
	SKILLTYPE st = SKILLTYPE::AXE;
	WEAPONTYPE wt = WEAPONTYPE::AXE;
public:
	Axe() {};
	Axe(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, 
		std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : 
		Weapon{ uName, uExclusivity, uCharacterName, 
				uMight, uHit, uCrit, 
				uRange, uWeight, uSkillLVL, 
				uUses, skillLVL } 
	{}
	~Axe() {}

	SKILLTYPE getSkillType() override { return st; };
	WEAPONTYPE getWeaponType() override { return wt; };

	Axe* new_expr() override { return new Axe(); }
	Axe* clone() override { return new Axe(*this); }
};

#endif
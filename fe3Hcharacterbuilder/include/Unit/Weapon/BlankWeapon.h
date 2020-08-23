#ifndef BLANKWEAPON_H
#define BLANKWEAPON_H

class BlankWeapon : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::BLANK;
public:
	BlankWeapon() {}
	BlankWeapon(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~BlankWeapon() {}
	WEAPONTYPE getType() override { return wt; };
	BlankWeapon* new_expr() override { return new BlankWeapon(); }
	BlankWeapon* clone() override { return new BlankWeapon(*this); }
};

#endif
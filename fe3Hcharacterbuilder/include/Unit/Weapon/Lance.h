#ifndef LANCE_H
#define LANCE_H

class Lance : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::LANCE;
public:
	Lance() {}
	Lance(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~Lance() {}
	WEAPONTYPE getType() override { return wt; };
	Lance* new_expr() override { return new Lance(); }
	Lance* clone() override { return new Lance(*this); }
};

#endif
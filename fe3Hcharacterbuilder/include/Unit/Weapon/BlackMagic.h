#ifndef BLACKMAGIC_H
#define BLACKMAGIC_H

class BlackMagic : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::REASON;
public:
	BlackMagic() {}
	BlackMagic(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~BlackMagic() {}
	WEAPONTYPE getType() override { return wt; };
	BlackMagic* new_expr() override { return new BlackMagic(); }
	BlackMagic* clone() override { return new BlackMagic(*this); }
};

#endif
#ifndef BLANKABILITY_H
#define BLANKABILITY_H


class BlankAbility : public Ability {
private:
	std::wstring slaType = L"---";
	SL sl;
	WEAPONTYPE wt;
public:
	BlankAbility() {}
	BlankAbility(std::wstring uName, std::wstring uSource, SL uLevel, WEAPONTYPE uWT, std::wstring uDescription) : sl(uLevel), wt(uWT), Ability{ uName, uSource, uDescription } {}
	~BlankAbility() {}
	std::wstring getType() { return slaType; }

	SL getSL() { return sl; }
	WEAPONTYPE getWeaponType() { return wt; }
	BlankAbility* new_expr() override { return new BlankAbility(); }
	BlankAbility* clone() override { return new BlankAbility(*this); }
};

#endif
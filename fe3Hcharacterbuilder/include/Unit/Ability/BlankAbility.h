#ifndef BLANKABILITY_H
#define BLANKABILITY_H

#include <string>
#include <constants.h>
#include <Unit/Ability/Ability.h>

class BlankAbility : public Ability {
private:
	std::wstring slaType = L"---";
	SL sl;
	SKILLTYPE st;
public:
	BlankAbility() {}
	BlankAbility(std::wstring uName, std::wstring uSource, 
		SL uLevel, SKILLTYPE uST, std::wstring uDescription) : 
		sl(uLevel), 
		st(uST), 
		Ability{ uName, uSource, uDescription } 
	{}
	~BlankAbility() {}

	std::wstring getType() { return slaType; }

	BlankAbility* new_expr() override { return new BlankAbility(); }
	BlankAbility* clone() override { return new BlankAbility(*this); }

	SL getSL() { return sl; }
	SKILLTYPE getWeaponType() { return st; }
};

#endif
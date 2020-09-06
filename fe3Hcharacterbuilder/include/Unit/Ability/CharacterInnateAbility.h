#ifndef CHARACTERINNATEABILITY_H
#define CHARACTERINNATEABILITY_H

#include <string>
#include <Unit/Ability/Ability.h>

class CharacterInnateAbility : public Ability {
private:
	std::wstring ciaType = L"CharacterInnate";
	bool hasStatUp;
public:
	CharacterInnateAbility() {}
	CharacterInnateAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription, bool uHasStatUp) : hasStatUp{ uHasStatUp }, Ability { uName, uSource, uDescription } {}
	~CharacterInnateAbility() {}
	std::wstring getType() { return ciaType; }
	CharacterInnateAbility* new_expr() override { return new CharacterInnateAbility(); }
	CharacterInnateAbility* clone() override { return new CharacterInnateAbility(*this); }
};

#endif
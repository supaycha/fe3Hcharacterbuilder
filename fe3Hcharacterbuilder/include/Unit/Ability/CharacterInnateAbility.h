#ifndef CHARACTERINNATEABILITY_H
#define CHARACTERINNATEABILITY_H

#include <string>
#include <constants.h>
#include <Unit/Ability/Ability.h>

class CharacterInnateAbility : public Ability {
private:
	std::wstring ciaType = L"CharacterInnate";
	bool hasStatUp;
	STPACKAGE stp;
public:
	CharacterInnateAbility() {}
	CharacterInnateAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription, bool uHasStatUp, STATTYPE ust, wxString uname) : hasStatUp{ uHasStatUp }, stp{ ust, uname }, Ability{ uName, uSource, uDescription } {}
	~CharacterInnateAbility() {}
	std::wstring getType() { return ciaType; }
	bool getHasStatUp() { return hasStatUp; }
	STPACKAGE getSTP() { return stp; }
	CharacterInnateAbility* new_expr() override { return new CharacterInnateAbility(); }
	CharacterInnateAbility* clone() override { return new CharacterInnateAbility(*this); }
};

#endif
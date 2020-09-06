#ifndef CLASSINNATEABILITY_H
#define CLASSINNATEABILITY_H

#include <string>
#include <Unit/Ability/Ability.h>
#include <constants.h>

class ClassInnateAbility : public Ability {
private:
	std::wstring ciaType = L"ClassInnate";
	bool hasStatUp;
	STPACKAGE stp;
public:
	ClassInnateAbility() {}
	ClassInnateAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription, bool uHasStatUp, STATTYPE ust, wxString uname) : hasStatUp{ uHasStatUp }, stp{ ust, uname }, Ability{ uName, uSource, uDescription } {}
	~ClassInnateAbility() {}
	std::wstring getType() { return ciaType; }
	bool getHasStatUp() { return hasStatUp; }
	STPACKAGE getSTP() { return stp; }

	ClassInnateAbility* new_expr() override { return new ClassInnateAbility(); }
	ClassInnateAbility* clone() override { return new ClassInnateAbility(*this); }
};

#endif
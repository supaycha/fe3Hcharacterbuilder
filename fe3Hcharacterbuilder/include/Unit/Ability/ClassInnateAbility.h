#ifndef CLASSINNATEABILITY_H
#define CLASSINNATEABILITY_H

#include <string>
#include <Unit/Ability/Ability.h>

class ClassInnateAbility : public Ability {
private:
	std::wstring ciaType = L"ClassInnate";
public:
	ClassInnateAbility() {}
	ClassInnateAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription) : Ability{ uName, uSource, uDescription } {}
	~ClassInnateAbility() {}
	std::wstring getType() { return ciaType; }
	ClassInnateAbility* new_expr() override { return new ClassInnateAbility(); }
	ClassInnateAbility* clone() override { return new ClassInnateAbility(*this); }
};

#endif
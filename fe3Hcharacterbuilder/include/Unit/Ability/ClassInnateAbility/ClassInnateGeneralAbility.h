#ifndef CLASSINNATEGENERALABILITY_H
#define CLASSINNATEGENERALABILITY_H

#include <string>
#include <constants.h>
#include <Unit/Ability/ClassInnateAbility/ClassInnateAbility.h>

class ClassInnateGeneralAbility : public ClassInnateAbility {
private:
public:
	ClassInnateGeneralAbility() {}
	ClassInnateGeneralAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription,
		bool uHasStatUp, std::vector<STATPACKAGE> ustatpVector) :
		ClassInnateAbility(uName, uSource, uDescription, uHasStatUp, ustatpVector)
	{}
	~ClassInnateGeneralAbility() {}
	ClassInnateGeneralAbility* new_expr() override { return new ClassInnateGeneralAbility(); }
	ClassInnateGeneralAbility* clone() override { return new ClassInnateGeneralAbility(*this); }
};

#endif
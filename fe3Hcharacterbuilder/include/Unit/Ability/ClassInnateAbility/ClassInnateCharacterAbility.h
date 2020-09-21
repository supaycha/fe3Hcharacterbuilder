#ifndef CLASSINNATECHARACTERABILITY_H
#define CLASSINNATECHARACTERABILITY_H

#include <string>
#include <constants.h>
#include <Unit/Ability/ClassInnateAbility/ClassInnateAbility.h>

class ClassInnateCharacterAbility : public ClassInnateAbility {
private:
	WEAPONTYPE wt;
public:
	ClassInnateCharacterAbility() {}
	ClassInnateCharacterAbility(std::wstring uName, std::wstring uSource, WEAPONTYPE uWT, std::wstring uDescription,
		bool uHasStatUp, std::vector<STATPACKAGE> ustatpVector) :
		wt {uWT},
		ClassInnateAbility(uName, uSource, uDescription, uHasStatUp, ustatpVector)
	{}
	~ClassInnateCharacterAbility() {}

	ClassInnateCharacterAbility* new_expr() override { return new ClassInnateCharacterAbility(); }
	ClassInnateCharacterAbility* clone() override { return new ClassInnateCharacterAbility(*this); }	
	
	WEAPONTYPE getWeaponType() { return wt; }
};

#endif
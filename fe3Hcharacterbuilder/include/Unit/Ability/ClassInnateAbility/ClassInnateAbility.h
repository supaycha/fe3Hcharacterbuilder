#ifndef CLASSINNATEABILITY_H
#define CLASSINNATEABILITY_H

#include <string>
#include <Unit/Ability/Ability.h>
#include <constants.h>

class ClassInnateAbility : public Ability {
private:
	std::wstring ciaType = L"ClassInnate";
	bool hasStatUp;
	std::vector<STATPACKAGE> statpVector;
public:
	ClassInnateAbility() {}
	ClassInnateAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription,
		bool uHasStatUp, std::vector<STATPACKAGE> ustatpVector) : 
		hasStatUp { uHasStatUp }, 
		statpVector{ ustatpVector }, 
		Ability{ uName, uSource, uDescription } 
	{}	
	ClassInnateAbility(const ClassInnateAbility&) = default;
	virtual ~ClassInnateAbility() {}

	virtual std::wstring getType() { return ciaType; }	
	
	virtual ClassInnateAbility* new_expr() = 0;
	virtual ClassInnateAbility* clone() = 0;

	bool getHasStatUp() { return hasStatUp; }
	std::vector<STATPACKAGE> getSTATP() { return statpVector; }
};

#endif
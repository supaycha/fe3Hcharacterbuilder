#ifndef CLASSMASTERYABILITY_H
#define CLASSMASTERYABILITY_H

#include <string>
#include <Unit/Ability/Ability.h>

class ClassMasteryAbility : public Ability {
private:
	std::wstring cmaType = L"ClassMastery";
	bool hasStatUp;
	std::vector<STATPACKAGE> statpVector;
public:
	ClassMasteryAbility() {}
	ClassMasteryAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription, bool uHasStatUp) :
		hasStatUp{ uHasStatUp },
		Ability{ uName, uSource, uDescription } 
	{}
	ClassMasteryAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription, 
		bool uHasStatUp, std::vector<STATPACKAGE> ustatpVector) : 
		hasStatUp{ uHasStatUp },
		statpVector{ ustatpVector },
		Ability{ uName, uSource, uDescription } 
	{}
	~ClassMasteryAbility() {}

	std::wstring getType() { return cmaType; }

	ClassMasteryAbility* new_expr() override { return new ClassMasteryAbility(); }
	ClassMasteryAbility* clone() override { return new ClassMasteryAbility(*this); }	
	
	std::vector<STATPACKAGE> getSTATP() { return statpVector; }
};

#endif
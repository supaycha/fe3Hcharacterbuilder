#ifndef CHARACTERINNATEABILITY_H
#define CHARACTERINNATEABILITY_H

#include <string>
#include <constants.h>
#include <Unit/Ability/Ability.h>

class CharacterInnateAbility : public Ability {
private:
	std::wstring ciaType = L"CharacterInnate";
	bool hasStatUp;
	bool battalioncheck = false;
	bool battalionmustexist;
	std::vector<STATPACKAGE> statpVector;
	
public:
	CharacterInnateAbility() {}
	CharacterInnateAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription, 
		bool uHasStatUp, std::vector<STATPACKAGE> ustatpVector) :
		hasStatUp{ uHasStatUp }, 
		statpVector{ ustatpVector },
		Ability{ uName, uSource, uDescription } 
	{}
	CharacterInnateAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription, 
		bool uHasStatUp, bool ubattalioncheck, bool ubattalionmustexist, std::vector<STATPACKAGE> ustatpVector) :
		hasStatUp{ uHasStatUp },
		battalioncheck{ ubattalioncheck },
		battalionmustexist{ ubattalionmustexist },
		statpVector{ ustatpVector },
		Ability{ uName, uSource, uDescription }
	{}
	~CharacterInnateAbility() {}
	
	std::wstring getType() { return ciaType; }	
	
	CharacterInnateAbility* new_expr() override { return new CharacterInnateAbility(); }
	CharacterInnateAbility* clone() override { return new CharacterInnateAbility(*this); }

	bool getHasStatUp() { return hasStatUp; }
	bool getBattalionMustExist() { return battalionmustexist; }
	std::vector<STATPACKAGE>  getSTATP() { return statpVector; }
};

#endif
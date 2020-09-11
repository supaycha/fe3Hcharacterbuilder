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
	CharacterInnateAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription, bool uHasStatUp, STATTYPE ust, wxString uname) : 
		hasStatUp{ uHasStatUp }, 
		statpVector{ STATPACKAGE(ust, uname) },
		Ability{ uName, uSource, uDescription } 
	{}
	CharacterInnateAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription, bool uHasStatUp, bool ubattalioncheck, bool ubattalionmustexist, STATTYPE ust, wxString uname) :
		hasStatUp{ uHasStatUp },
		battalioncheck{ ubattalioncheck },
		battalionmustexist{ ubattalionmustexist },
		statpVector{ STATPACKAGE(ust, uname) },
		Ability{ uName, uSource, uDescription }
	{}
	CharacterInnateAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription, bool uHasStatUp, bool ubattalioncheck, bool ubattalionmustexist, STATTYPE ust, wxString uname, STATTYPE ust2, wxString uname2) :
		hasStatUp{ uHasStatUp }, 
		battalioncheck { ubattalioncheck },
		battalionmustexist { ubattalionmustexist },
		statpVector{ STATPACKAGE(ust, uname), STATPACKAGE(ust2, uname2) },
		Ability{ uName, uSource, uDescription } 
	{}

	~CharacterInnateAbility() {}
	std::wstring getType() { return ciaType; }
	bool getHasStatUp() { return hasStatUp; }
	std::vector<STATPACKAGE>  getWTP() { return statpVector; }
	CharacterInnateAbility* new_expr() override { return new CharacterInnateAbility(); }
	CharacterInnateAbility* clone() override { return new CharacterInnateAbility(*this); }
};

#endif
#ifndef SHIELD_H
#define SHIELD_H

#include <string>
#include <constants.h>
#include <Unit/Equipment/Equipment.h>

class Shield : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::SHIELD;
public:
	Shield() {}
	Shield(std::wstring uName, bool uExclusivity, std::wstring uCharacterName,
		std::wstring uPROT, std::wstring uWGT, std::wstring uRES,
		std::wstring uHIT, std::wstring uTCRIT, std::wstring uAVO,
		std::wstring uSPD, std::wstring uMOV, std::wstring uLCK, 
		std::wstring uMATK, std::wstring uHEAL, std::wstring uRANGE, 
		std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterName, 
				uPROT, uWGT, uRES, 
				uHIT, uTCRIT, uAVO,
				uSPD, uMOV, uLCK, 
				uMATK, uHEAL, uRANGE,
				uDescription }
	{}
	~Shield() {}

	Shield* new_expr() override { return new Shield(); }
	Shield* clone() override { return new Shield(*this); }
};

#endif
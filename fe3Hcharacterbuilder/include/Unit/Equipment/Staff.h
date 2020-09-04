#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <constants.h>
#include <Unit/Equipment/Equipment.h>

class Staff : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::STAFF;
public:
	Staff() {}
	Staff(std::wstring uName, bool uExclusivity, std::wstring uCharacterNameorNames, 
		std::wstring uPROT, std::wstring uWGT, std::wstring uRES, std::wstring uHIT, std::wstring uTCRIT,
		std::wstring uAVO, std::wstring uSPD, std::wstring uMOV, std::wstring uLCK, std::wstring uMATK,
		std::wstring uHEAL, std::wstring uRANGE, 
		std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterNameorNames, uPROT, uWGT, uRES, uHIT, uTCRIT, uAVO, uSPD, uMOV, uLCK, uMATK, uHEAL, uRANGE, uDescription } {}
	~Staff() {}

	Staff* new_expr() override { return new Staff(); }
	Staff* clone() override { return new Staff(*this); }
};

#endif
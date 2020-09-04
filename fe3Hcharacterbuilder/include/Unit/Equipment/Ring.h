#ifndef RING_H
#define RING_H

#include <string>
#include <constants.h>
#include <Unit/Equipment/Equipment.h>

class Ring : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::RING;
public:
	Ring() {}
	Ring(std::wstring uName, bool uExclusivity, std::wstring uCharacterNameorNames, 
		std::wstring uPROT, std::wstring uWGT, std::wstring uRES, std::wstring uHIT, std::wstring uTCRIT,
		std::wstring uAVO, std::wstring uSPD, std::wstring uMOV, std::wstring uLCK, std::wstring uMATK,
		std::wstring uHEAL, std::wstring uRANGE, 
		std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterNameorNames, uPROT, uWGT, uRES, uHIT, uTCRIT, uAVO, uSPD, uMOV, uLCK, uMATK, uHEAL, uRANGE, uDescription } {}
	~Ring() {}

	Ring* new_expr() override { return new Ring(); }
	Ring* clone() override { return new Ring(*this); }
};

#endif
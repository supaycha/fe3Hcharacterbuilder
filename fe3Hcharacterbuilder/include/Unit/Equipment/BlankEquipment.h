#ifndef BLANKEQUIPMENT_H
#define BLANKEQUIPMENT_H

#include <string>
#include <constants.h>
#include <Unit/Equipment/Equipment.h>

class BlankEquipment : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::BLANK;
public:
	BlankEquipment() {}
	BlankEquipment(std::wstring uName, bool uExclusivity, std::wstring uCharacterNameorNames, 
		std::wstring uPROT, std::wstring uWGT, std::wstring uRES, std::wstring uHIT, std::wstring uTCRIT,
		std::wstring uAVO, std::wstring uSPD, std::wstring uMOV, std::wstring uLCK, std::wstring uMATK,
		std::wstring uHEAL, std::wstring uRANGE,
		std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterNameorNames, uPROT, uWGT, uRES, uHIT, uTCRIT, uAVO, uSPD, uMOV, uLCK, uMATK, uHEAL, uRANGE, uDescription } {}
	~BlankEquipment() {}

	BlankEquipment* new_expr() override { return new BlankEquipment(); }
	BlankEquipment* clone() override { return new BlankEquipment(*this); }
};

#endif
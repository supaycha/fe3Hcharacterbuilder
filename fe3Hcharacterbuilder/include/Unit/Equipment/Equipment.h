#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <Stat.h>
#include <constants.h>
#include <Unit/Unit.h>

class Equipment : public Unit {
private:
	std::wstring equipmentname;
	bool exclusivity = false;
	std::wstring charactername;
	Stats equipstats;
	std::wstring description;
public:
	Equipment() {};
	Equipment(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, 
		std::wstring uPROT, std::wstring uWGT, std::wstring uRES, std::wstring uHIT, std::wstring uTCRIT,
		std::wstring uAVO, std::wstring uSPD, std::wstring uMOV, std::wstring uLCK, std::wstring uMATK, 
		std::wstring uHEAL, std::wstring uRANGE, 
		std::wstring uDescription) :
		equipmentname{ uName },
		exclusivity{ uExclusivity },
		charactername{ uCharacterName },
		equipstats{ uPROT, uWGT, uRES, uHIT, uTCRIT, uAVO, uSPD, uMOV, uLCK, uMATK, uHEAL, uRANGE },
		description{ uDescription } {}
	~Equipment() {}
	Equipment(const Equipment&) = default;
	virtual const std::wstring getName() { return equipmentname; }
	virtual const Stats getStats() { return equipstats; }
	bool getExclusivity() { return exclusivity; }
	virtual const std::wstring getCharacterName() { return charactername; }
	wxString getDescription() { return description; }
	virtual Equipment* new_expr() = 0;
	virtual Equipment* clone() = 0;
};

#endif
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
	Equipment(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uProtection, std::wstring uResilience, std::wstring uDescription) :
		equipmentname{ uName },
		exclusivity{ uExclusivity },
		charactername{ uCharacterName },
		equipstats{ uProtection, uResilience },
		description{ uDescription } {}
	~Equipment() {}
	Equipment(const Equipment&) = default;
	virtual const std::wstring getName() { return equipmentname; }
	virtual const Stats getStats() { return equipstats; }
	bool getExclusivity() { return exclusivity; }
	virtual const std::wstring getCharacterName() { return charactername; }
	virtual EQUIPMENTTYPE getType() = 0;
	virtual Equipment* new_expr() = 0;
	virtual Equipment* clone() = 0;
};

#endif
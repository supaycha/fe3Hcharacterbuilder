#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <Stat.h>
#include <constants.h>
#include <Unit/Unit.h>

class Weapon : public Unit {
private:
	std::wstring weapname;
	bool exclusivity = false;
	std::wstring charactername;
	Stats weapstats;
	SL sl;
public:
	Weapon() {}
	Weapon(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring SkillLVL,
		std::wstring uUses, SL uSkillLVL) :
		weapname(uName),
		exclusivity{ uExclusivity },
		charactername{ uCharacterName },
		weapstats(uMight, uHit, uCrit, uRange, uWeight, SkillLVL, uUses),
		sl(uSkillLVL)
	{}
	virtual ~Weapon() {}
	Weapon(const Weapon&) = default;
	virtual const std::wstring getName() { return weapname; }
	virtual const Stats getStats() { return weapstats; }
	bool getExclusivity() { return exclusivity; }
	virtual const std::wstring getCharacterName() { return charactername; }
	SL getSL() { return sl; }
	virtual SKILLTYPE getSkillType() = 0;
	virtual WEAPONTYPE getWeaponType() = 0;

	virtual Weapon* new_expr() = 0;
	virtual Weapon* clone() = 0;
};

#endif
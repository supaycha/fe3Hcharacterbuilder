#ifndef UNIT_H
#define UNIT_H

#include "Stat.h"
#include "Growth.h"
#include "constants.h"
//#include <vld.h>

class Unit : public wxClientData {
public:
	virtual const std::wstring getName() = 0;
	virtual const Stats getStats() = 0;

	Unit() {};
	Unit(const Unit&) = default;
	virtual ~Unit() {}
	virtual Unit* new_expr() = 0;
	virtual Unit* clone() = 0;
};

//class Gambit : public Unit {
//private:
//	std::wstring name;
//	Stats gambitstats;
//public:
//	Gambit() {}
//	~Gambit() {}
//
//	const std::wstring getName() override { return name; }
//	const Stats getStats() override { return gambitstats; }
//
//	Gambit* new_expr() override { return new Gambit(); }
//	Gambit* clone() override { return new Gambit(*this); }
//};

class Character : public Unit {
private:
	std::wstring charname;
	Stats charstats;
	Growths basegrowths;
	//Crest crest;
	//BuddingTalent bt;
public:
	Character() {}
	Character(std::wstring uNAME,
		std::wstring uHP, std::wstring uMOV,
		std::wstring uSTR, std::wstring uMAG, std::wstring uDEX,
		std::wstring uSPD, std::wstring uLCK, std::wstring uDEF,
		std::wstring uRES, std::wstring uCHA,
		std::wstring bHP, std::wstring bMOV,
		std::wstring bSTR, std::wstring bMAG, std::wstring bDEX,
		std::wstring bSPD, std::wstring bLCK, std::wstring bDEF,
		std::wstring bRES, std::wstring bCHA)
		:
		charname{ uNAME },
		charstats{ uHP, uMOV, uSTR,
						uMAG, uDEX, uSPD,
						uLCK, uDEF, uRES,
						uCHA },
		basegrowths{ bHP, bMOV, bSTR,
						bMAG, bDEX, bSPD,
						bLCK, bDEF, bRES,
						bCHA }
	{}
	~Character() {}
	const std::wstring getName() override { return charname; }
	const Stats getStats() override { return charstats; }
	const Growths getGrowths() { return basegrowths; }
	Character* new_expr() override { return new Character(); }
	Character* clone() override { return new Character(*this); }
};

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
	virtual WEAPONTYPE getType() = 0;
	virtual Weapon* new_expr() = 0;
	virtual Weapon* clone() = 0;
};
class Axe : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::AXE;
public:
	Axe() {};
	Axe(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~Axe() {}

	WEAPONTYPE getType() override { return wt; };
	Axe* new_expr() override { return new Axe(); }
	Axe* clone() override { return new Axe(*this); }
};
class BlackMagic : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::REASON;
public:
	BlackMagic() {}
	BlackMagic(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~BlackMagic() {}
	WEAPONTYPE getType() override { return wt; };
	BlackMagic* new_expr() override { return new BlackMagic(); }
	BlackMagic* clone() override { return new BlackMagic(*this); }
};
class Bow : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::BOW;
public:
	Bow() {}
	Bow(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~Bow() {}
	WEAPONTYPE getType() override { return wt; };
	Bow* new_expr() override { return new Bow(); }
	Bow* clone() override { return new Bow(*this); }
};
class DarkMagic : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::REASON;
public:
	DarkMagic() {}
	DarkMagic(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~DarkMagic() {}
	WEAPONTYPE getType() override { return wt; };
	DarkMagic* new_expr() override { return new DarkMagic(); }
	DarkMagic* clone() override { return new DarkMagic(*this); }
};
class Gauntlets : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::GAUNTLETS;
public:
	Gauntlets() {}
	Gauntlets(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~Gauntlets() {}
	WEAPONTYPE getType() override { return wt; };
	Gauntlets* new_expr() override { return new Gauntlets(); }
	Gauntlets* clone() override { return new Gauntlets(*this); }
};
class Lance : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::LANCE;
public:
	Lance() {}
	Lance(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~Lance() {}
	WEAPONTYPE getType() override { return wt; };
	Lance* new_expr() override { return new Lance(); }
	Lance* clone() override { return new Lance(*this); }
};
class Sword : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::SWORD;
public:
	Sword() {}
	Sword(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~Sword() {}
	WEAPONTYPE getType() override { return wt; };
	Sword* new_expr() override { return new Sword(); }
	Sword* clone() override { return new Sword(*this); }
};
class WhiteMagic : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::FAITH;
public:
	WhiteMagic() {}
	WhiteMagic(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~WhiteMagic() {}
	WEAPONTYPE getType() override { return wt; };
	WhiteMagic* new_expr() override { return new WhiteMagic(); }
	WhiteMagic* clone() override { return new WhiteMagic(*this); }
};
class BlankWeapon : public Weapon {
private:
	WEAPONTYPE wt = WEAPONTYPE::BLANK;
public:
	BlankWeapon() {}
	BlankWeapon(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses, SL skillLVL) : Weapon{ uName, uExclusivity, uCharacterName, uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses, skillLVL } {}
	~BlankWeapon() {}
	WEAPONTYPE getType() override { return wt; };
	BlankWeapon* new_expr() override { return new BlankWeapon(); }
	BlankWeapon* clone() override { return new BlankWeapon(*this); }
};

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
class Shield : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::SHIELD;
public:
	Shield() {}
	Shield(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uProtection, std::wstring uResilience, std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterName, uProtection, uResilience, uDescription } {}
	~Shield() {}

	EQUIPMENTTYPE getType() override { return et; };
	Shield* new_expr() override { return new Shield(); }
	Shield* clone() override { return new Shield(*this); }
};
class Ring : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::RING;
public:
	Ring() {}
	Ring(std::wstring uName, bool uExclusivity, std::wstring uCharacterNameorNames, std::wstring uProtection, std::wstring uResilience, std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterNameorNames, uProtection, uResilience, uDescription } {}
	~Ring() {}

	EQUIPMENTTYPE getType() override { return et; };
	Ring* new_expr() override { return new Ring(); }
	Ring* clone() override { return new Ring(*this); }
};
class Staff : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::STAFF;
public:
	Staff() {}
	Staff(std::wstring uName, bool uExclusivity, std::wstring uCharacterNameorNames, std::wstring uProtection, std::wstring uResilience, std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterNameorNames, uProtection, uResilience, uDescription } {}
	~Staff() {}

	EQUIPMENTTYPE getType() override { return et; };
	Staff* new_expr() override { return new Staff(); }
	Staff* clone() override { return new Staff(*this); }
};
class Gem : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::STAFF;
public:
	Gem() {}
	Gem(std::wstring uName, bool uExclusivity, std::wstring uCharacterNameorNames, std::wstring uProtection, std::wstring uResilience, std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterNameorNames, uProtection, uResilience, uDescription } {}
	~Gem() {}

	EQUIPMENTTYPE getType() override { return et; };
	Gem* new_expr() override { return new Gem(); }
	Gem* clone() override { return new Gem(*this); }
};
class BlankEquipment : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::BLANK;
public:
	BlankEquipment() {}
	BlankEquipment(std::wstring uName, bool uExclusivity, std::wstring uCharacterNameorNames, std::wstring uProtection, std::wstring uResilience, std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterNameorNames, uProtection, uResilience, uDescription } {}
	~BlankEquipment() {}

	EQUIPMENTTYPE getType() override { return et; };
	BlankEquipment* new_expr() override { return new BlankEquipment(); }
	BlankEquipment* clone() override { return new BlankEquipment(*this); }
};

class Class : public Unit {
private:
	std::wstring name;
	bool hasExclusivity;
	std::wstring charactername;
	Stats basestats;
	Stats classboosts;
	Growths classgrowths;
	Stats mountedvariances;
public:
	Class() {}
	Class(std::wstring uNAME, bool uHasExclusivity, std::wstring uCharacterName,
		std::wstring uHP, std::wstring uMOV, std::wstring uSTR,
		std::wstring uMAG, std::wstring uDEX, std::wstring uSPD,
		std::wstring uLCK, std::wstring uDEF, std::wstring uRES,
		std::wstring uCHA,
		std::wstring bHP, std::wstring bMOV,
		std::wstring bSTR, std::wstring bMAG, std::wstring bDEX,
		std::wstring bSPD, std::wstring bLCK, std::wstring bDEF,
		std::wstring bRES, std::wstring bCHA,
		std::wstring cHP, std::wstring cMOV,
		std::wstring cSTR, std::wstring cMAG, std::wstring cDEX,
		std::wstring cSPD, std::wstring cLCK, std::wstring cDEF,
		std::wstring cRES, std::wstring cCHA,
		std::wstring dHP, std::wstring dMOV,
		std::wstring dSTR, std::wstring dMAG, std::wstring dDEX,
		std::wstring dSPD, std::wstring dLCK, std::wstring dDEF,
		std::wstring dRES, std::wstring dCHA) :
		name{ uNAME },
		hasExclusivity{ uHasExclusivity },
		charactername{ uCharacterName },
		basestats{ uHP, uMOV, uSTR,
						uMAG, uDEX, uSPD,
						uLCK, uDEF, uRES,
						uCHA },
		classboosts{ bHP, bMOV, bSTR,
						bMAG, bDEX, bSPD,
						bLCK, bDEF, bRES,
						bCHA },
		classgrowths{ cHP, cMOV, cSTR,
						cMAG, cDEX, cSPD,
						cLCK, cDEF, cRES,
						cCHA },
		mountedvariances{ dHP, dMOV, dSTR,
						dMAG, dDEX, dSPD,
						dLCK, dDEF, dRES,
						dCHA } {}
	~Class() {}

	const std::wstring getName() override { return name; }
	const Stats getStats() override { return basestats; }
	const Stats getBoostedStats() { return classboosts; }
	const Growths getGrowths() { return classgrowths; }
	const Stats getMountedStats() { return mountedvariances; }

	Class* new_expr() override { return new Class(); }
	Class* clone() override { return new Class(*this); }

	bool getExclusivity() { return hasExclusivity; }
	std::wstring getCharacterName() { return charactername; }
};

class Battalion : public Unit {
private:
	std::wstring name;
	Stats battstats;
	Stats levelincreases;
	std::wstring gambit;
	SL sl;
public:
	Battalion() {}
	Battalion(std::wstring uName,
		std::wstring uPA, std::wstring uMA, std::wstring uHIT, std::wstring uCRIT, std::wstring uAVO,
		std::wstring uPROT, std::wstring uRES, std::wstring uCHA, std::wstring uEND,
		std::wstring bPA, std::wstring bMA, std::wstring bHIT, std::wstring bCRIT, std::wstring bAVO,
		std::wstring bPROT, std::wstring bRES, std::wstring bCHA, std::wstring bEND, std::wstring uGambit, SL uSL) :
		name{ uName },
		battstats{ uPA, uMA, uHIT, uCRIT, uAVO, uPROT, uRES, uCHA, uEND },
		levelincreases{ bPA, bMA, bHIT, bCRIT, bAVO, bPROT, bRES, bCHA, bEND },
		gambit{ uGambit },
		sl{ uSL }
	{}
	~Battalion() {}

	const std::wstring getName() override { return name; }
	const Stats getStats() override { return battstats; }
	SL getSL() { return sl; }

	Battalion* new_expr() override { return new Battalion(); }
	Battalion* clone() override { return new Battalion(*this); }
};

class Ability : public Unit {
private:
	std::wstring abname;
	std::wstring source;
	std::wstring description;
public:
	Ability() {}
	Ability(std::wstring uName, std::wstring uSource, std::wstring uDescription) :
		abname(uName),
		source(uSource),
		description(uDescription) {}
	virtual ~Ability() {}

	const std::wstring getName() override { return abname; }
	const Stats getStats() { Stats nothing; return nothing; };  //does nothing
	virtual std::wstring getType() = 0;
	std::wstring getSource() { return source; }
	virtual Ability* new_expr() = 0;
	virtual Ability* clone() = 0;
};
class CharacterInnateAbility : public Ability {
private:
	std::wstring ciaType = L"CharacterInnate";
public:
	CharacterInnateAbility() {}
	CharacterInnateAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription) : Ability{ uName, uSource, uDescription } {}
	~CharacterInnateAbility() {}
	std::wstring getType() { return ciaType; }
	CharacterInnateAbility* new_expr() override { return new CharacterInnateAbility(); }
	CharacterInnateAbility* clone() override { return new CharacterInnateAbility(*this); }
};
class ClassInnateAbility : public Ability {
private:
	std::wstring ciaType = L"ClassInnate";
public:
	ClassInnateAbility() {}
	ClassInnateAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription) : Ability{ uName, uSource, uDescription } {}
	~ClassInnateAbility() {}
	std::wstring getType() { return ciaType; }
	ClassInnateAbility* new_expr() override { return new ClassInnateAbility(); }
	ClassInnateAbility* clone() override { return new ClassInnateAbility(*this); }
};
class ClassMasteryAbility : public Ability {
private:
	std::wstring cmaType = L"ClassMastery";
public:
	ClassMasteryAbility() {}
	ClassMasteryAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription) : Ability{ uName, uSource, uDescription } {}
	~ClassMasteryAbility() {}
	std::wstring getType() { return cmaType; }
	ClassMasteryAbility* new_expr() override { return new ClassMasteryAbility(); }
	ClassMasteryAbility* clone() override { return new ClassMasteryAbility(*this); }
};
class SkillLevelAbility : public Ability {
private:
	std::wstring slaType = L"SkillLevel";
	SL sl;
	WEAPONTYPE wt;
public:
	SkillLevelAbility() {}
	SkillLevelAbility(std::wstring uName, std::wstring uSource, SL uLevel, WEAPONTYPE uWT, std::wstring uDescription) : sl(uLevel), wt(uWT), Ability{ uName, uSource, uDescription } {}
	~SkillLevelAbility() {}
	std::wstring getType() { return slaType; }

	SL getSL() { return sl; }
	WEAPONTYPE getWeaponType() { return wt; }
	SkillLevelAbility* new_expr() override { return new SkillLevelAbility(); }
	SkillLevelAbility* clone() override { return new SkillLevelAbility(*this); }
};
class BlankAbility : public Ability {
private:
	std::wstring slaType = L"---";
	SL sl;
	WEAPONTYPE wt;
public:
	BlankAbility() {}
	BlankAbility(std::wstring uName, std::wstring uSource, SL uLevel, WEAPONTYPE uWT, std::wstring uDescription) : sl(uLevel), wt(uWT), Ability{ uName, uSource, uDescription } {}
	~BlankAbility() {}
	std::wstring getType() { return slaType; }

	SL getSL() { return sl; }
	WEAPONTYPE getWeaponType() { return wt; }
	BlankAbility* new_expr() override { return new BlankAbility(); }
	BlankAbility* clone() override { return new BlankAbility(*this); }
};

#endif
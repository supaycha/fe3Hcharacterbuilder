#ifndef UNITLIST_H
#define UNITLIST_H
#include <wx/wx.h>
#include <Windows.h>
#include <vector>
#include <list>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vld.h>

class Stat {
private:
	std::wstring stat;
public:
	Stat() : stat{} {}
	Stat(std::wstring change) : stat{ change } {}
	std::wstring getText() const { return stat; }
	Stat& operator=(const Stat& source) = default;  //in cpp
	Stat(const Stat&) = default;
};

class Stats : public wxClientData {
private:
	std::vector<Stat> stats;
public:
	Stats() : stats{ 10, Stat{} } {}
	Stats(int size, std::wstring value) : stats(size, value) {}
	Stats(std::vector<Stat> change) : stats(change) {}
	Stats(std::wstring uPROT, std::wstring uRES) : stats{ uPROT, uRES } {}
	Stats(std::wstring uHP, std::wstring uMOV, std::wstring uSTR,
		std::wstring uMAG, std::wstring uDEX, std::wstring uSPD,
		std::wstring uLCK, std::wstring uDEF, std::wstring uRES,
		std::wstring uCHA) :
		stats{ uHP, uMOV, uSTR, uMAG, uDEX, uSPD, uLCK, uDEF, uRES, uCHA }
	{}
	Stats(std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses) :
		stats{ uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses }
	{}
	Stats(std::wstring uPHYSATK, std::wstring uMGKATK, std::wstring uHIT,
		std::wstring uCRIT, std::wstring uAVO, std::wstring uPROT,
		std::wstring uRES, std::wstring uCHA, std::wstring uEND) :
		stats{ uPHYSATK, uMGKATK, uHIT, uCRIT, uAVO, uPROT, uRES, uCHA, uEND }
	{}
	Stats(std::wstring uPHYSATK, std::wstring uMGKATK, std::wstring uPHYSHIT,
		std::wstring uMGKHIT, std::wstring uTCRIT, std::wstring uAS,
		std::wstring TPROT, std::wstring TRSL, std::wstring uAVO, std::wstring uCRITAVO, std::wstring uRNGE) :
		stats{ uPHYSATK, uMGKATK, uPHYSHIT, uMGKHIT, uTCRIT, uAS, TPROT, TRSL, uAVO, uCRITAVO, uRNGE }
	{}

	int Size() const { return stats.size(); }
	Stat& operator[](UINT index) { return stats[index]; }
	Stats& operator=(const Stats& source) = default;
	Stats(const Stats&) = default;
	Stats* new_expr() { return new Stats(); }
	Stats* clone() { return new Stats(*this); }

	void push_back(std::wstring stringforstat) { stats.push_back(stringforstat); }
	//auto begin() { return stats.begin(); }
	//auto end() { return stats.end(); }
};

class Growth {
private:
	std::wstring growth;
public:
	Growth() : growth{} {}
	Growth(std::wstring change) : growth{ change } {}
	std::wstring getText() const { return growth; }
	Growth& operator=(const Growth& source) = default;  //in cpp
	Growth(const Growth&) = default;
};

class Growths : public wxClientData {
private:
	std::vector<Growth> growths;
public:
	Growths() : growths{ 10, Growth{} } {}
	Growths(int size, std::wstring value) : growths(size, value) {}
	Growths(std::vector<Growth> change) : growths(change) {}
	Growths(std::wstring uPROT, std::wstring uRES) : growths{ uPROT, uRES } {}
	Growths(std::wstring uHP, std::wstring uMOV, std::wstring uSTR,
		std::wstring uMAG, std::wstring uDEX, std::wstring uSPD,
		std::wstring uLCK, std::wstring uDEF, std::wstring uRES,
		std::wstring uCHA) :
		growths{ uHP, uMOV, uSTR, uMAG, uDEX, uSPD, uLCK, uDEF, uRES, uCHA }
	{}

	int Size() const { return growths.size(); }
	Growth& operator[](UINT index) { return growths[index]; }
	Growths& operator=(const Growths& source) = default;
	Growths(const Growths&) = default;
	Growths* new_expr() { return new Growths(); }
	Growths* clone() { return new Growths(*this); }

	void push_back(std::wstring stringforgrowth) { growths.push_back(stringforgrowth); }
	//auto begin() { return growths.begin(); }
	//auto end() { return growths.end(); }
};

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

enum class SL : int {
	BLANK = -1, E = 0, EPLUS = 1, D = 2, DPLUS = 3, C = 4, CPLUS = 5, B = 6, BPLUS = 7, A = 8, APLUS = 9, S = 10, SPLUS = 11
};

enum class WEAPONTYPE : int {
	BLANK = -1, SWORD = 0, LANCE = 1, AXE = 2, BOW = 3, GAUNTLETS = 4, REASON = 5, FAITH = 6, AUTHORITY = 7, HEAVYARMOR = 8, RIDING = 9, FLYING = 10
};

enum class EQUIPMENTTYPE : int {
	BLANK = -1, SHIELD = 0, RING = 1, STAFF = 2, GEM = 3
};

struct SLPACKAGE : public wxClientData {
	SL sl;
	wxString slstring;
	int index;

	SLPACKAGE(SL uSL) : sl(uSL), index{}, slstring{} {}
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
		std::wstring uPROT, std::wstring uRES, std::wstring uCHA, 
		std::wstring bPA, std::wstring bMA, std::wstring bHIT, std::wstring bCRIT, std::wstring bAVO,
		std::wstring bPROT, std::wstring bRES, std::wstring bCHA, std::wstring uEND, std::wstring uGambit, SL uSL) :
		name { uName },
		battstats{ uPA, uMA, uHIT, uCRIT, uAVO, uPROT, uRES, uCHA, uEND },
		levelincreases{ bPA, bMA, bHIT, bCRIT, bAVO, bPROT, bRES, bCHA, uEND },
		gambit { uGambit },
		sl{ uSL } 
	{}
	~Battalion() {}

	const std::wstring getName() override { return name; }
	const Stats getStats() override { return battstats; }
	SL getSL() { return sl; }

	Battalion* new_expr() override { return new Battalion(); }
	Battalion* clone() override { return new Battalion(*this); }
};

class UnitList {
private:
	std::vector<std::unique_ptr<Unit>> list;
public:
	UnitList() {
		list.emplace_back(std::make_unique<Battalion>(L"---", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"---", SL::BLANK));
		list.emplace_back(std::make_unique<Battalion>(L"Church of Seiros Soldiers", 
			L"0", L"0", L"0", L"0", L"0", L"1", L"1", L"1", L"30", 
			L"0", L"0", L"1.3", L"0", L"0", L"0.5", L"0.5", L"0", L"0", L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Mercenaries", 
			L"1", L"-2", L"5", L"0", L"0", L"1", L"1", L"1", L"30", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Onslaught", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Holy Monks", 
			L"-1", L"0", L"5", L"0", L"0", L"0", L"1", L"1", L"30", 
			L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", L"0", L"0", L"Stride", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Sacred Monks",
			L"-1", L"0", L"5", L"0", L"0", L"0", L"2", L"1", L"30",
			L"0", L"0", L"1.3", L"0", L"0", L"0", L"0.5", L"0", L"0", L"Resonant White Magic", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Brawlers", 
			L"2", L"-2", L"0", L"0", L"5", L"0", L"-1", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0.5", L"0", L"0", L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Magic Corps",
			L"-2", L"1", L"0", L"0", L"0", L"0", L"3", L"3", L"30",
			L"0", L"0.5", L"1.3", L"0", L"0", L"0", L"0.5", L"0", L"0", L"Group Flames", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Archers", 
			L"0", L"0", L"10", L"0", L"5", L"0", L"0", L"3", L"45",
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0", L"0", L"0", L"0", L"Fusillade", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Armored Co.", 
			L"2", L"0", L"0", L"0", L"-10", L"2", L"0", L"3", L"60", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Onslaught", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Pegasus Co.", 
			L"2", L"0", L"0", L"0", L"1", L"0", L"3", L"5", L"60",
			L"0.5", L"0", L"0", L"0", L"1", L"0.5", L"0.5", L"0", L"0", L"Assembly", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Knights of Seiros",
			L"2", L"-1", L"0", L"0", L"1", L"1", L"1", L"5", L"60", 
			L"0.5", L"0", L"0", L"0", L"1", L"0.5", L"0.5", L"0", L"0", L"Blaze", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Holy Knights of Seiros", 
			L"3", L"-2", L"0", L"0", L"0", L"1", L"3", L"7", L"75",
			L"1", L"0", L"0", L"0", L"0", L"1", L"1", L"0", L"0", L"Assault Troop", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Indech Sword Fighters", 
			L"4", L"-21", L"10", L"2", L"0", L"0", L"0", L"10", L"105", 
			L"1", L"0", L"2.5", L"2", L"0", L"1", L"0", L"0", L"0", L"Retribution", SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Macuil Evil Repelling Co.", 
			L"0", L"3", L"20", L"0", L"0", L"1", L"2", L"10", L"105",
			L"0", L"1", L"2.5", L"0", L"0", L"0", L"1", L"0", L"0", L"Resonant Lightning", SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Infantry", 
			L"0", L"-2", L"5", L"0", L"0", L"1", L"0", L"1", L"30", 
			L"0", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Lure", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Warriors", 
			L"2", L"-2", L"0", L"0", L"0", L"0", L"0", L"1", L"30",
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", L"Random Shot", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Brawlers", 
			L"2", L"-2", L"0", L"0", L"5", L"0", L"-1", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Magic Corps", 
			L"-2", L"2", L"0", L"0", L"0", L"0", L"2", L"3", L"20", 
			L"0", L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"Group Flames", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Archers", 
			L"1", L"-2", L"10", L"0", L"0", L"1", L"0", L"3", L"30", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Fusillade", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Cavalry",
			L"2", L"-2", L"0", L"0", L"0", L"2", L"0", L"3", L"45",
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0", L"Assault Troop", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Armored Co.", 
			L"1", L"-2", L"0", L"0", L"-10", L"3", L"0", L"3", L"60",
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Impregnable Wall", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Knights",
			L"3", L"-2", L"0", L"0", L"0", L"2", L"0", L"5", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Blaze", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Snipers", 
			L"3", L"-2", L"5", L"0", L"0", L"1", L"0", L"5", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Flash-Fire Arrows", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Magic Users",
			L"-2", L"3", L"0", L"5", L"0", L"0", L"2", L"5", L"45", 
			L"0", L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"Resonant Flames", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Pavise Co.",
			L"0", L"-2", L"0", L"0", L"-10", L"4", L"1", L"5", L"75",
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0.5", L"0", L"0", L"Blaze", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Pegasus Co.", 
			L"2", L"0", L"10", L"0", L"0", L"1", L"2", L"6", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0.5", L"0", L"0", L"Group Lance Attack", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Wyvern Co.",
			L"3", L"-2", L"5", L"5", L"0", L"2", L"0", L"5", L"60", 
			L"0.5", L"0", L"0", L"1.3", L"0", L"0.5", L"0", L"0", L"0", L"Reversal", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Heavy Soldiers", 
			L"2", L"-2", L"5", L"0", L"-10", L"5", L"1", L"7", L"75", 
			L"1", L"0", L"2.5", L"0", L"0", L"1", L"0", L"0", L"0", L"Line of Lances", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Holy Magic Users", 
			L"-2", L"2", L"0", L"0", L"0", L"0", L"3", L"8", L"60", 
			L"0", L"1", L"0", L"0", L"0", L"1", L"1", L"0", L"0", L"Blessing", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Raiders", 
			L"3", L"0", L"0", L"0", L"5", L"0", L"0", L"7", L"75",
			L"1", L"0", L"0", L"0", L"1.3", L"1", L"0", L"0", L"0", L"Absorption", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Imperial Guard", 
			L"3", L"-2", L"0", L"10", L"0", L"0", L"0", L"7", L"75", 
			L"1", L"0", L"0", L"0", L"0", L"1", L"0", L"0", L"0", L"Blaze", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Elite Wyvern Co.", 
			L"4", L"-2", L"0", L"5", L"0", L"2", L"0", L"7", L"75", 
			L"1", L"0", L"0", L"1.3", L"0", L"1", L"0", L"0", L"0", L"Assembly", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Black Eagle Heavy Axes",
			L"3", L"0", L"0", L"10", L"-10", L"4", L"2", L"10", L"105",
			L"1", L"0", L"0", L"0", L"0", L"1", L"0", L"0", L"0", L"Onslaught", SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Black Eagle Cavalry",
			L"3", L"0", L"10", L"0", L"5", L"1", L"0", L"10", L"105",
			L"1", L"0", L"2.5", L"0", L"0", L"1", L"0", L"0", L"0", L"Linked Horses", SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Black Eagle Pegasus Co.",
			L"3", L"0", L"0", L"10", L"5", L"1", L"3", L"10", L"105", 
			L"1", L"0", L"0", L"0", L"1.3", L"1", L"1", L"0", L"0", L"Retribution", SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Infantry",
			L"1", L"-2", L"0", L"0", L"0", L"1", L"0", L"1", L"30", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Lure", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Lance Co.", 
			L"1", L"-2", L"0", L"0", L"5", L"0", L"0", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", L"Group Lance Atack", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Brawlers", 
			L"2", L"-2", L"0", L"0", L"5", L"0", L"-1", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Magic Corps", 
			L"-2", L"1", L"0", L"0", L"0", L"1", L"2", L"3", L"30", 
			L"0", L"0.5", L"1.3", L"0", L"0", L"0", L"0.5", L"0", L"0", L"Group Ice", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Archers",
			L"2", L"-2", L"5", L"0", L"0", L"1", L"0", L"3", L"30",
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Retribution", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Cavalry", 
			L"2", L"-2", L"0", L"0", L"0", L"2", L"0", L"3", L"45",
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Stride", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Armored Co.", 
			L"1", L"-2", L"0", L"0", L"-10", L"3", L"0", L"3", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Impregnable Wall", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Knights", 
			L"3", L"-2", L"0", L"0", L"0", L"2", L"1", L"5", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Assault Troop", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Snipers	", 
			L"1", L"-2", L"5", L"0", L"0", L"1", L"1", L"5", L"60", 
			L"0.5", L"0", L"2.5", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Fusillade", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Magic Users", 
			L"-2", L"3", L"0", L"0", L"0", L"1", L"1", L"5", L"45", 
			L"0", L"0.5", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0", L"Resonant Ice", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Brave Lance Co.", 
			L"2", L"-2", L"10", L"0", L"5", L"1", L"0", L"5", L"60", 
			L"0.5", L"0", L"2.5", L"0", L"1.3", L"0.5", L"0", L"0", L"0", L"Onslaught", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Pegasus Co.", 
			L"2", L"0", L"0", L"0", L"0", L"1", L"2", L"6", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0.5", L"0", L"0", L"Assembly", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Wyvern Co.", 
			L"3", L"-2", L"10", L"0", L"0", L"2", L"0", L"5", L"60", 
			L"0.5", L"0", L"1.3", L"1.3", L"0", L"0.5", L"0", L"0", L"0", L"Recovery Roar", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Heavy Soldiers",
			L"0", L"-2", L"0", L"0", L"-10", L"3", L"0", L"7", L"90", 
			L"1", L"0", L"1.3", L"1.3", L"0", L"1", L"0", L"0", L"0", L"Group Lance Attack", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Holy Knights",
			L"3", L"-2", L"0", L"0", L"-10", L"1", L"3", L"7", L"75",
			L"1", L"0", L"1.3", L"1.3", L"0", L"1", L"0", L"0", L"0", L"Linked Horses", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Heavy Knights",
			L"0", L"-2", L"5", L"0", L"-15", L"3", L"0", L"7", L"90",
			L"1", L"0", L"2.5", L"0", L"0", L"1", L"0", L"0", L"0", L"Sacred Shield", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Royal Guard",
			L"2", L"0", L"10", L"10", L"-10", L"0", L"0", L"7", L"75",
			L"1", L"0", L"2.5", L"0", L"0", L"1", L"0", L"0", L"0", L"Line of Lances", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Priests", 
			L"0", L"2", L"0", L"0", L"-5", L"0", L"3", L"7", L"60",
			L"0", L"1", L"1.3", L"0", L"0", L"0", L"1", L"0", L"0", L"Blessing", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Blue Lion Knights", 
			L"3", L"-2", L"0", L"10", L"-10", L"1", L"0", L"10", 
			L"1", L"0", L"1.3", L"1.3", L"0", L"1", L"0", L"0", L"0", L"105", L"Linked Horses", SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Blue Lion Magic Corps",
			L"-2", L"3", L"0", L"0", L"-10", L"1", L"3", L"10", L"105", 
			L"0", L"1", L"1.3", L"0", L"0", L"1", L"1", L"0", L"0", L"Resonant Ice", SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Blue Lion Dancers", 
			L"-5", L"-5", L"0", L"0", L"15", L"1", L"1", L"10", L"105", 
			L"1", L"1", L"0", L"0", L"1.3", L"0.5", L"0.5", L"0", L"0", L"Dance of the Goddess", SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Infantry", 
			L"0", L"-2", L"5", L"0", L"5", L"0", L"0", L"1", L"30",
			L"0", L"0", L"1", L"0", L"1.3", L"0", L"0", L"0", L"0", L"Lure", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Duelists", 
			L"0", L"-2", L"0", L"5", L"5", L"0", L"0", L"1", L"30",
			L"0", L"0", L"0", L"1", L"1.3", L"0", L"0", L"0", L"0", L"Mad Melee	", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Brawlers", 
			L"2", L"-2", L"0", L"0", L"5", L"0", L"-1", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Magic Corps", 
			L"-2", L"1", L"0", L"0", L"5", L"0", L"2", L"3", L"30",
			L"0", L"0.5", L"0", L"0", L"1.3", L"0", L"0.5", L"0", L"0", L"Group Lightning", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Archers", 
			L"1", L"-2", L"10", L"0", L"5", L"0", L"0", L"3", L"30", 
			L"0.5", L"0", L"1", L"0", L"1.3", L"0", L"0", L"0", L"0", L"Poisoned Arrows", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Cavalry", 
			L"2", L"-2", L"0", L"0", L"5", L"0", L"0", L"3", L"45", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", L"Assault Troop", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Armored Co.",
			L"1", L"-2", L"0", L"0", L"-5", L"2", L"0", L"3", L"60",
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", L"Disturbance", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Knights",
			L"2", L"-2", L"0", L"0", L"5", L"1", L"1", L"5", L"60", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0", L"Blaze", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Snipers", 
			L"1", L"-2", L"10", L"0", L"5", L"0", L"0", L"5", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0", L"0", L"0", L"0", L"Fusillade", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Magic Users",
			L"-2", L"2", L"0", L"0", L"5", L"0", L"2", L"5", L"45", 
			L"0", L"0.5", L"0", L"0", L"1.3", L"0", L"0.5", L"0", L"0", L"Resonant Lightning	", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Veteran Duelists",
			L"2", L"-2", L"0", L"0", L"5", L"1", L"0", L"5", L"60", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0", L"Absorption", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Pegasus Co.",
			L"2", L"0", L"0", L"0", L"5", L"0", L"1", L"6", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0.5", L"0", L"0", L"Assembly", SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Wyvern Co.", 
			L"3", L"-2", L"0", L"0", L"5", L"1", L"0", L"5", L"60", 
			L"0.5", L"0", L"0", L"1.3", L"1.3", L"0.5", L"0", L"0", L"0", L"Impregnable Wall", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Pavise Co.",
			L"2", L"-2", L"0", L"0", L"-5", L"4", L"1", L"7", L"90", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"1", L"0", L"0", L"0", L"Group Lance Attack", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Physicians", 
			L"0", L"1", L"0", L"0", L"5", L"0", L"2", L"7", L"60", 
			L"0", L"0.5", L"0", L"0", L"1.3", L"0", L"0.5", L"0", L"0", L"Resonant White Magic", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Sages", 
			L"0", L"4", L"0", L"0", L"-10", L"0", L"2", L"7", L"60", 
			L"0", L"1", L"1.3", L"1.3", L"0", L"0", L"1", L"0", L"0", L"Blessing", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Master Archers", 
			L"2", L"-1", L"0", L"10", L"5", L"0", L"0", L"7", L"60", 
			L"0.5", L"0", L"0", L"1.3", L"1.3", L"1", L"0", L"0", L"0", L"Flash-Fire Arrows", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Guard", 
			L"3", L"0", L"0", L"5", L"1", L"0", L"0", L"7", L"75", 
			L"0.5", L"0", L"0", L"1.3", L"1", L"1", L"0", L"0", L"0", L"Poison Tactic", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Golden Deer Wyvern Co.",
			L"2", L"-2", L"0", L"0", L"5", L"1", L"0", L"10", L"105",
			L"1", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0", L"0", L"0", L"Assault Troop", SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Golden Deer Archers", 
			L"2", L"-2", L"15", L"0", L"10", L"0", L"1", L"10", L"105", 
			L"0", L"0", L"2.5", L"0", L"1.3", L"0.5", L"0.5", L"0", L"0", L"Poison Tactic", SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Golden Deer Cavalry", 
			L"4", L"-2", L"0", L"0", L"-5", L"3", L"2", L"10", L"105",
			L"1", L"0", L"1.3", L"0", L"0", L"1", L"0", L"0", L"0", L"Linked Horses", SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Supreme Armored Co.", 
			L"3", L"2", L"0", L"0", L"-10", L"2", L"1", L"10", L"120",
			L"1", L"1", L"1.3", L"0", L"0", L"1", L"1", L"0", L"0", L"Raging Flames", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"King of Lions Corps", 
			L"5", L"-2", L"0", L"10", L"-5", L"1", L"0", L"10", L"120",
			L"1.3", L"0", L"1.3", L"1.3", L"0", L"1", L"0", L"0", L"0", L"Wave Attack", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Immortal Corps",
			L"4", L"-2", L"0", L"0", L"10", L"0", L"0", L"10", L"120", 
			L"1", L"0", L"0", L"0", L"1.3", L"1", L"0", L"0", L"0", L"Ashes and Dust", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Vestra Sorcery Engineers", 
			L"-2", L"3", L"0", L"0", L"5", L"0", L"2", L"7", L"75", 
			L"0", L"1", L"0", L"0", L"1.3", L"1", L"1", L"0", L"0", L"Resonant Lightning", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Aegir Astral Knights",
			L"3", L"-2", L"0", L"0", L"15", L"0", L"0", L"7", L"105", 
			L"1", L"0", L"0", L"0", L"1.3", L"0.5", L"0.5", L"0", L"0", L"Assault Troop", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Hevring Prayer Troops", 
			L"0", L"3", L"0", L"0", L"-10", L"0", L"3", L"7", L"75", 
			L"0", L"1", L"1.3", L"0", L"0", L"1", L"1", L"0", L"0", L"Blessing", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Bergliez War Group", 
			L"4", L"0", L"0", L"0", L"-10", L"0", L"0", L"7", L"105", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"Onslaught", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Varley Archers", 
			L"0", L"0", L"20", L"0", L"-10", L"1", L"0", L"7", L"75", 
			L"0", L"0", L"2.5", L"0", L"0", L"1", L"0", L"0", L"0",
			L"Fusillade", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Opera Co. Volunteers", 
			L"0", L"0", L"10", L"0", L"10", L"0", L"0", L"10", L"75",
			L"0", L"0", L"2.5", L"0", L"1.3", L"1", L"0", L"0", L"0",
			L"Dance of the Goddess", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Brigid Hunters", 
			L"0", L"-2", L"0", L"5", L"15", L"0", L"0", L"7", L"105", 
			L"1", L"0", L"0", L"1.3", L"1.3", L"0", L"0", L"0", L"0",
			L"Poison Tactic", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Duscur Heavy Soldiers", 
			L"4", L"-2", L"0", L"0", L"-15", L"5", L"0", L"7", L"120",
			L"1", L"0", L"1.3", L"0", L"0", L"1.3", L"0", L"0", L"0",
			L"Line of Lances", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Fraldarius Soldiers", 
			L"3", L"0", L"0", L"10", L"0", L"2", L"0", L"7", L"105",
			L"1", L"0", L"0", L"2.5", L"0", L"1", L"0", L"0", L"0",
			L"Onslaught", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Gaspard Knights",
			L"1", L"0", L"0", L"0", L"-5", L"1", L"0", L"7", L"105", 
			L"1", L"0", L"1.3", L"0", L"0", L"1", L"0", L"0", L"0",
			L"Assault Troop", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Gautier Knights",
			L"3", L"-2", L"0", L"0", L"15", L"0", L"0", L"7", L"105", 
			L"1", L"0", L"0", L"0", L"1.3", L"1.3", L"0", L"0", L"0",
			L"Stride", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Church Soldiers", 
			L"0", L"1", L"0", L"0", L"0", L"0", L"2", L"5", L"75",
			L"0", L"0.5", L"1.3", L"0", L"0", L"0", L"1", L"0", L"0",
			L"Resonant White Magic", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"School of Sorcery Soldiers", 
			L"-2", L"2", L"10", L"0", L"0", L"0", L"2", L"5", L"75", 
			L"0", L"1", L"2.5", L"0", L"0", L"0", L"0.5", L"0", L"0",
			L"Resonant Flames", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Galatea Pegasus Co.", 
			L"3", L"0", L"0", L"0", L"5", L"1", L"2", L"8", L"105", 
			L"1", L"0", L"1.3", L"0", L"1.3", L"1", L"1", L"0", L"0",
			L"Lure", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Gloucester Knights", 
			L"2", L"2", L"10", L"0", L"0", L"1", L"1", L"7", L"105",
			L"1", L"1", L"1.3", L"0", L"0", L"1", L"1", L"0", L"0",
			L"Assault Troop", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Leicester Mercenaries", 
			L"3", L"-2", L"10", L"10", L"0", L"0", L"0", L"7", L"105", 
			L"1", L"0", L"2.5", L"1.3", L"0", L"1", L"0", L"0", L"0",
			L"Blaze", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Victor Private Military", 
			L"2", L"0", L"5", L"0", L"0", L"0", L"2", L"5", L"105", 
			L"1", L"0", L"2.5", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Assembly", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Ordelia Sorcery Co.", 
			L"-1", L"4", L"10", L"0", L"0", L"0", L"2", L"7", L"75", 
			L"0", L"1", L"2.5", L"0", L"0", L"0", L"1", L"0", L"0",
			L"Resonant Lightning", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Edmund Troops", 
			L"1", L"1", L"30", L"0", L"0", L"0", L"0", L"7", L"105", 
			L"1", L"1", L"2.5", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Flash-Fire Arrows", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Goneril Valkyries",
			L"4", L"-2", L"10", L"10", L"0", L"2", L"1", L"7", L"105", 
			L"1", L"0", L"2.5", L"1.3", L"0", L"1", L"0", L"0", L"0",
			L"Assault Troop", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Sauin Militia",
			L"1", L"0", L"10", L"0", L"5", L"0", L"0", L"5", L"75", 
			L"0", L"0", L"2.5", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Poisoned Arrows", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Cichol Wyvern Co.",
			L"3", L"0", L"10", L"10", L"0", L"2", L"1", L"10", L"105", 
			L"1", L"0", L"1.3", L"1.3", L"1.3", L"1", L"0", L"0", L"0",
			L"Assault Troop", SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Cethleann Monks", 
			L"0", L"2", L"10", L"0", L"0", L"1", L"3", L"10", L"105", 
			L"0", L"1", L"2.5", L"0", L"0", L"0", L"1", L"0", L"0",
			L"Resonant White Magic", SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Jeralt’s Mercenaries",
			L"1", L"0", L"0", L"5", L"5", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"1.3", L"2.5", L"0", L"0", L"0", L"0",
			L"Assault Troop", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Reaper Knights", 
			L"3", L"-2", L"0", L"5", L"10", L"0", L"0", L"1", L"105",
			L"1", L"0", L"0", L"1.3", L"1.3", L"1", L"0", L"0", L"0",
			L"Assault Troop", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Secret Transport Force",
			L"1", L"0", L"0", L"0", L"10", L"1", L"1", L"8", L"105",
			L"0.5", L"0", L"0", L"0", L"1.3", L"1", L"1", L"0", L"0",
			L"Stride", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Mockingbird’s Thieves", 
			L"1", L"1", L"5", L"5", L"5", L"1", L"1", L"5", L"105", 
			L"1", L"1", L"1.3", L"1.3", L"1.3", L"0.5", L"0.5", L"0", L"0",
			L"Absorption", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Leicester Dicers Corps", 
			L"3", L"3", L"0", L"0", L"0", L"1", L"1", L"5", L"0",
			L"1", L"1", L"1.3", L"0", L"0", L"1", L"1", L"0", L"0",
			L"Onslaught", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Nuvelle Fliers Corps", 
			L"0", L"3", L"0", L"0", L"5", L"0", L"3", L"8", L"105", 
			L"0", L"1", L"1.3", L"0", L"1.3", L"0", L"1", L"0", L"0",
			L"Resonant Lightning", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Timotheos Magi Corps", 
			L"0", L"3", L"5", L"5", L"0", L"0", L"1", L"7", L"105", 
			L"0", L"1.3", L"1.3", L"1.3", L"0", L"0.5", L"1", L"0", L"0",
			L"Resonant Flames", SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Remire Militia", 
			L"0", L"0", L"0", L"0", L"0", L"1", L"0", L"1", L"30",
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Youths", 
			L"0", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"30", 
			L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Youths", 
			L"0", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"30",
			L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Youths",
			L"0", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"30",
			L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", L"0", L"0",
			L"", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Duscur Infantry", 
			L"1", L"-2", L"0", L"0", L"5", L"1", L"-1", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Almyra Mercenaries", 
			L"3", L"0", L"0", L"0", L"5", L"0", L"-2", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0",
			L"Fusillade", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Brigid Mercenaries",
			L"1", L"0", L"5", L"5", L"0", L"0", L"0", L"1", L"30", 
			L"0.5", L"0", L"1.3", L"1.3", L"0", L"0", L"0", L"0", L"0",
			L"Onslaught", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Morfis Magic Corps",
			L"-2", L"3", L"0", L"0", L"0", L"0", L"3", L"5", L"45",
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Resonant Lightning", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Essar Research Group",
			L"1", L"1", L"20", L"0", L"0", L"0", L"0", L"1", L"60",
			L"1", L"1", L"2.5", L"0", L"0", L"0", L"0", L"0", L"0",
			L"Blessing", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Holst’s Chosen",
			L"3", L"0", L"0", L"0", L"0", L"3", L"0", L"3", L"0", 
			L"1", L"0", L"1.3", L"1.3", L"0", L"1", L"0", L"0", L"0",
			L"Assault Troop", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Nuvelle Chamberlain Co.",
			L"3", L"0", L"5", L"5", L"0", L"1", L"3", L"5", L"45",
			L"1.3", L"0", L"1.3", L"1.3", L"0", L"0", L"1", L"0", L"0",
			L"Battleground Cafe", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Nuvelle Attendants Co.",
			L"0", L"3", L"0", L"5", L"5", L"1", L"3", L"5", L"45", 
			L"0", L"1.3", L"0", L"1.3", L"1.3", L"0", L"1", L"0", L"0",
			L"Absolute Defense", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Nuvelle Stewards Co.", 
			L"1", L"1", L"5", L"5", L"1", L"1", L"3", L"10", L"45", 
			L"1", L"1", L"1.3", L"1.3", L"1", L"0", L"1", L"0", L"0",
			L"Battleground Clean Up", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Iron King’s Thieves", 
			L"-1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Gaspard Militia", 
			L"-1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"West Church Corps",
			L"0", L"1", L"0", L"0", L"0", L"0", L"1", L"1", L"75",
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Group Lightning", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"West Church Mercenaries", 
			L"1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Onslaught", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"West Church Sages", 
			L"0", L"2", L"0", L"0", L"-10", L"0", L"2", L"1", L"75", 
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Group Lightning", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"West Church Pegasus Co.", 
			L"1", L"0", L"0", L"0", L"0", L"0", L"1", L"3", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"West Church Knights", 
			L"2", L"-1", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Mysterious Infantry", 
			L"1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Mysterious Magic Corps", 
			L"0", L"1", L"0", L"0", L"0", L"0", L"1", L"1", L"75", 
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Group Flames", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Mysterious Magic Users",
			L"-5", L"2", L"0", L"0", L"-5", L"0", L"2", L"1", L"75",
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Resonant Flames", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Miklan Private Militia",
			L"1", L"-2", L"5", L"0", L"0", L"1", L"0", L"1", L"75", 
			L"0.5", L"0", L"2.5", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Reaper Infantry",
			L"0", L"0", L"0", L"0", L"10", L"0", L"0", L"1", L"75",
			L"0", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Onslaught", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Rampaging Villagers",
			L"1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Solon Subordinates", 
			L"-2", L"3", L"0", L"0", L"-5", L"0", L"2", L"1", L"75",
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Resonant Flames", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Kronya Subordinates	",
			L"0", L"0", L"0", L"0", L"20", L"0", L"0", L"1", L"75",
			L"0", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0",
			L"Onslaught", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Pallardó Bodyguards", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Poison Tactic", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Rowe Knights", 
			L"3", L"-1", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Linked Horses", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"House Rowe Archers", 
			L"2", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Flash-Fire Arrows", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Rowe Armored Co.",
			L"1", L"0", L"0", L"0", L"-10", L"1", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Group Lance Attack", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Rowe Cavalry",
			L"2", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Daphnel Duelists",
			L"3", L"-2", L"0", L"0", L"10", L"0", L"0", L"1", L"105",
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0",
			L"Onslaught", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Almyra Wyvern Co.", 
			L"4", L"-2", L"-5", L"0", L"10", L"2", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Assault Troop", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Almyra Cavalry", 
			L"2", L"-2", L"0", L"0", L"10", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Assault Troop", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dark Infantry", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Onslaught", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dark Magic Corps", 
			L"-1", L"2", L"0", L"0", L"0", L"0", L"2", L"1", L"75", 
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Resonant Lightning", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Einherjar", 
			L"4", L"0", L"0", L"0", L"-10", L"1", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Enhanced Infantry", 
			L"2", L"0", L"0", L"0", L"-5", L"0", L"1", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Enhanced Heavy Co.", 
			L"1", L"0", L"0", L"0", L"-10", L"2", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Group Lance Attack", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Enhanced Cavalry", 
			L"3", L"0", L"0", L"0", L"-10", L"1", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Linked Horses", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Enhanced Wyvern Co.",
			L"2", L"0", L"0", L"0", L"-10", L"0", L"2", L"3", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Poison Tactic", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Ancient Infantry", 
			L"2", L"0", L"0", L"0", L"-5", L"0", L"1", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Ancient Armored Co.", 
			L"1", L"0", L"0", L"0", L"-5", L"1", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Onslaught", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Ancient Cavalry", 
			L"3", L"0", L"0", L"0", L"-5", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Ancient Wyvern Co.",
			L"2", L"0", L"0", L"0", L"-5", L"0", L"1", L"3", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Lure", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Phantasmal Cavalry", 
			L"2", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Phantasmal Infantry", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Phantasmal Wyvern Co.", 
			L"2", L"0", L"0", L"0", L"0", L"0", L"2", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Duscur Cavalry",
			L"2", L"0", L"0", L"0", L"-10", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dominic Cavalry",
			L"1", L"0", L"10", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"2.5", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Merchant Military",
			L"-1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0", L"0.5", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Poison Tactic", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Thieves", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Rogues", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Bandits",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Pirates", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Arundel Magic Corps",
			L"0", L"2", L"0", L"0", L"0", L"1", L"2", L"1", L"75",
			L"0", L"1", L"0", L"0", L"0", L"1", L"1", L"0", L"0",
			L"Resonant Flames", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Mysterious Wyvern Co.",
			L"1", L"0", L"0", L"0", L"5", L"1", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"2.5", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dark Wyvern Co.", 
			L"1", L"0", L"0", L"0", L"5", L"1", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"2.5", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Ancient Sorcerers", 
			L"-5", L"2", L"0", L"0", L"-5", L"0", L"4", L"1", L"75",
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Resonant Flames", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Enhanced Sorcerers", 
			L"-5", L"4", L"0", L"0", L"-5", L"0", L"4", L"1", L"75", 
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Resonant Lightning", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Phantasmal Magic Corps",
			L"0", L"3", L"0", L"0", L"0", L"0", L"3", L"1", L"75",
			L"0", L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0",
			L"Resonant Flames", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Phantasmal Archers", 
			L"1", L"0", L"10", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"2.5", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Gaspard Archers",
			L"-1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Thief Marksmen",
			L"-1", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Cliff Bandit Marksmen",
			L"-1", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Pirate Marksmen", 
			L"-1", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"West Church Archers", 
			L"1", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Fusillade", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Flame Emperor Co.", 
			L"3", L"2", L"-5", L"0", L"-10", L"2", L"1", L"5", L"75", 
			L"0.5", L"0.5", L"0", L"1.3", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Raging Flames", SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Thief Pegasus Corps", 
			L"2", L"0", L"0", L"0", L"1", L"0", L"3", L"5", L"60", 
			L"0.5", L"0", L"0", L"0", L"1", L"0.5", L"0.5", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Pirate Pegasus Corps",
			L"2", L"0", L"0", L"0", L"1", L"0", L"3", L"5", L"60", 
			L"0.5", L"0", L"0", L"0", L"1", L"0.5", L"0.5", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Bandit Pegasus Corps",
			L"2", L"0", L"0", L"0", L"1", L"0", L"3", L"5", L"60",
			L"0.5", L"0", L"0", L"0", L"1", L"0.5", L"0.5", L"0", L"0",
			L"Disturbance", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dahlman Guard", 
			L"0", L"3", L"20", L"0", L"0", L"3", L"3", L"10", L"105", 
			L"0", L"1.3", L"1.3", L"0", L"0", L"1", L"1", L"0", L"0",
			L"Resonant Flames", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dahlman Magic Co.", 
			L"0", L"2", L"10", L"0", L"0", L"2", L"3", L"5", L"75",
			L"0", L"1", L"1.3", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Group Flames", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dahlman Armored Group", 
			L"3", L"0", L"10", L"0", L"0", L"3", L"0", L"5", L"75", 
			L"1", L"0", L"1.3", L"0", L"0", L"1.3", L"0", L"0", L"0",
			L"Assault Troop", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dahlman PMC",
			L"2", L"0", L"10", L"0", L"0", L"2", L"0", L"3", L"75", 
			L"1", L"0", L"1.3", L"0", L"0", L"1", L"0.5", L"0", L"0",
			L"Onslaught", SL::E));

		list.emplace_back(std::make_unique<Character>(L"---", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Character>(L"Byleth", L"27", L"4", L"13", L"6", L"9", L"8", L"8", L"6", L"6", L"7",
			L"0.45", L"0", L"0.45", L"0.35", L"0.45", L"0.45", L"0.45", L"0.35", L"0.3", L"0.45"));
		list.emplace_back(std::make_unique<Character>(L"Edelgard", L"29", L"4", L"13", L"6", L"5", L"8", L"5", L"6", L"4", L"10",
			L"0.4", L"0", L"0.55", L"0.45", L"0.45", L"0.4", L"0.3", L"0.35", L"0.35", L"0.6"));
		list.emplace_back(std::make_unique<Character>(L"Dorothea", L"24", L"4", L"5", L"11", L"6", L"7", L"6", L"4", L"7", L"8",
			L"0.4", L"0", L"0.2", L"0.4", L"0.45", L"0.4", L"0.35", L"0.15", L"0.35", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Ferdinand", L"28", L"4", L"8", L"5", L"6", L"8", L"6", L"6", L"2", L"7",
			L"0.5", L"0", L"0.45", L"0.2", L"0.4", L"0.5", L"0.4", L"0.35", L"0.2", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Hubert", L"22", L"4", L"6", L"12", L"6", L"7", L"6", L"4", L"7", L"8",
			L"0.35", L"0", L"0.3", L"0.55", L"0.45", L"0.45", L"0.35", L"0.25", L"0.4", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Linhardt", L"24", L"4", L"5", L"10", L"6", L"5", L"7", L"5", L"9", L"3",
			L"0.3", L"0", L"0.3", L"0.45", L"0.4", L"0.4", L"0.45", L"0.3", L"0.45", L"0.2"));
		list.emplace_back(std::make_unique<Character>(L"Caspar", L"26", L"4", L"9", L"3", L"5", L"6", L"8", L"6", L"2", L"4",
			L"0.55", L"0", L"0.45", L"0.25", L"0.45", L"0.45", L"0.4", L"0.3", L"0.2", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Bernadetta", L"25", L"4", L"8", L"5", L"7", L"7", L"5", L"4", L"2", L"6",
			L"0.35", L"0", L"0.35", L"0.2", L"0.55", L"0.5", L"0.25", L"0.2", L"0.3", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Petra", L"25", L"4", L"9", L"3", L"7", L"10", L"7", L"5", L"2", L"6",
			L"0.45", L"0", L"0.4", L"0.25", L"0.5", L"0.6", L"0.45", L"0.3", L"0.15", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Dimitri", L"28", L"4", L"12", L"4", L"7", L"7", L"5", L"7", L"4", L"9",
			L"0.55", L"0", L"0.6", L"0.2", L"0.5", L"0.5", L"0.25", L"0.4", L"0.2", L"0.55"));
		list.emplace_back(std::make_unique<Character>(L"Dedue", L"30", L"4", L"12", L"2", L"5", L"7", L"5", L"8", L"1", L"4",
			L"0.6", L"0", L"0.5", L"0.15", L"0.3", L"0.2", L"0.25", L"0.5", L"0.1", L"0.3"));
		list.emplace_back(std::make_unique<Character>(L"Felix", L"26", L"4", L"10", L"5", L"6", L"9", L"5", L"5", L"3", L"5",
			L"0.45", L"0", L"0.55", L"0.3", L"0.45", L"0.55", L"0.4", L"0.3", L"0.2", L"0.3"));
		list.emplace_back(std::make_unique<Character>(L"Ashe", L"23", L"4", L"8", L"5", L"8", L"9", L"6", L"5", L"6", L"5",
			L"0.35", L"0", L"0.35", L"0.25", L"0.55", L"0.5", L"0.4", L"0.2", L"0.35", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Sylvain", L"27", L"4", L"9", L"5", L"5", L"8", L"6", L"6", L"2", L"7",
			L"0.55", L"0", L"0.45", L"0.3", L"0.35", L"0.5", L"0.35", L"0.4", L"0.25", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Mercedes", L"25", L"4", L"6", L"10", L"6", L"8", L"5", L"5", L"9", L"8",
			L"0.3", L"0", L"0.25", L"0.5", L"0.45", L"0.4", L"0.3", L"0.25", L"0.45", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Annette", L"23", L"4", L"6", L"11", L"7", L"7", L"6", L"5", L"4", L"6",
			L"0.25", L"0", L"0.3", L"0.5", L"0.5", L"0.35", L"0.35", L"0.2", L"0.3", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Ingrid", L"27", L"4", L"8", L"6", L"6", L"8", L"6", L"5", L"8", L"8",
			L"0.4", L"0", L"0.35", L"0.35", L"0.4", L"0.6", L"0.45", L"0.3", L"0.4", L"0.45"));
		list.emplace_back(std::make_unique<Character>(L"Claude", L"26", L"4", L"11", L"5", L"8", L"8", L"7", L"6", L"4", L"8",
			L"0.35", L"0", L"0.4", L"0.25", L"0.6", L"0.55", L"0.45", L"0.3", L"0.25", L"0.55"));
		list.emplace_back(std::make_unique<Character>(L"Lorenz", L"28", L"4", L"8", L"7", L"6", L"7", L"5", L"6", L"6", L"3",
			L"0.55", L"0", L"0.4", L"0.4", L"0.45", L"0.4", L"0.25", L"0.3", L"0.4", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Raphael", L"30", L"4", L"11", L"3", L"5", L"6", L"6", L"7", L"1", L"4",
			L"0.65", L"0", L"0.5", L"0.15", L"0.35", L"0.15", L"0.35", L"0.45", L"0.1", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Ignatz", L"25", L"4", L"8", L"5", L"7", L"8", L"8", L"4", L"6", L"4",
			L"0.35", L"0", L"0.35", L"0.3", L"0.5", L"0.5", L"0.55", L"0.25", L"0.35", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Lysithea", L"22", L"4", L"4", L"11", L"7", L"7", L"4", L"3", L"4", L"5",
			L"0.2", L"0", L"0.15", L"0.6", L"0.6", L"0.5", L"0.15", L"0.1", L"0.25", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Marianne", L"23", L"4", L"5", L"11", L"6", L"7", L"6", L"4", L"8", L"7",
			L"0.35", L"0", L"0.2", L"0.5", L"0.4", L"0.4", L"0.35", L"0.15", L"0.45", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Hilda", L"29", L"4", L"10", L"5", L"5", L"8", L"6", L"6", L"3", L"7",
			L"0.5", L"0", L"0.45", L"0.25", L"0.3", L"0.5", L"0.35", L"0.35", L"0.2", L"0.5"));
		list.emplace_back(std::make_unique<Character>(L"Leonie", L"26", L"4", L"9", L"5", L"8", L"9", L"6", L"7", L"2", L"7",
			L"0.4", L"0", L"0.4", L"0.2", L"0.55", L"0.6", L"0.4", L"0.4", L"0.15", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Flayn", L"24", L"4", L"6", L"9", L"6", L"5", L"4", L"5", L"10", L"9",
			L"0.25", L"0", L"0.25", L"0.55", L"0.45", L"0.35", L"0.15", L"0.25", L"0.5", L"0.45"));
		list.emplace_back(std::make_unique<Character>(L"Hanneman", L"25", L"4", L"6", L"10", L"6", L"6", L"4", L"5", L"7", L"5",
			L"0.4", L"0", L"0.3", L"0.55", L"0.45", L"0.2", L"0.35", L"0.25", L"0.4", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Seteth", L"27", L"4", L"9", L"8", L"8", L"5", L"6", L"6", L"4", L"9",
			L"0.5", L"0", L"0.45", L"0.35", L"0.5", L"0.5", L"0.25", L"0.3", L"0.25", L"0.45"));
		list.emplace_back(std::make_unique<Character>(L"Manuela", L"26", L"4", L"10", L"8", L"6", L"8", L"6", L"5", L"4", L"7",
			L"0.5", L"0", L"0.35", L"0.35", L"0.4", L"0.6", L"0.35", L"0.3", L"0.25", L"0.5"));
		list.emplace_back(std::make_unique<Character>(L"Gilbert", L"30", L"4", L"9", L"4", L"6", L"5", L"4", L"5", L"2", L"6",
			L"0.55", L"0", L"0.45", L"0.2", L"0.45", L"0.3", L"0.15", L"0.45", L"0.1", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Alois", L"28", L"4", L"9", L"4", L"5", L"6", L"5", L"5", L"2", L"7",
			L"0.45", L"0", L"0.45", L"0.2", L"0.35", L"0.4", L"0.3", L"0.4", L"0.2", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Catherine", L"27", L"4", L"8", L"5", L"6", L"7", L"6", L"5", L"2", L"4",
			L"0.5", L"0", L"0.5", L"0.25", L"0.4", L"0.55", L"0.3", L"0.3", L"0.2", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Shamir", L"26", L"4", L"8", L"4", L"7", L"6", L"8", L"5", L"2", L"6",
			L"0.35", L"0", L"0.4", L"0.2", L"0.55", L"0.4", L"0.55", L"0.2", L"0.15", L"0.3"));
		list.emplace_back(std::make_unique<Character>(L"Cyril", L"24", L"4", L"7", L"4", L"6", L"6", L"6", L"5", L"2", L"4",
			L"0.35", L"0", L"0.2", L"0.15", L"0.4", L"0.4", L"0.3", L"0.1", L"0.1", L"0.15"));
		list.emplace_back(std::make_unique<Character>(L"Jeritza", L"30", L"4", L"8", L"6", L"6", L"8", L"4", L"7", L"5", L"3",
			L"0.5", L"0", L"0.5", L"0.35", L"0.35", L"0.6", L"0.3", L"0.4", L"0.25", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Anna", L"26", L"4", L"7", L"7", L"7", L"7", L"7", L"5", L"7", L"7",
			L"0.35", L"0", L"0.35", L"0.35", L"0.45", L"0.55", L"0.45", L"0.3", L"0.4", L"0.5"));
		list.emplace_back(std::make_unique<Character>(L"Yuri", L"24", L"4", L"10", L"6", L"7", L"9", L"7", L"5", L"7", L"8",
			L"0.3", L"0", L"0.4", L"0.35", L"0.4", L"0.65", L"0.45", L"0.3", L"0.35", L"0.5"));
		list.emplace_back(std::make_unique<Character>(L"Balthus", L"28", L"4", L"11", L"5", L"4", L"7", L"3", L"7", L"4", L"4",
			L"0.5", L"0", L"0.5", L"0.3", L"0.25", L"0.3", L"0.2", L"0.45", L"0.3", L"0.3"));
		list.emplace_back(std::make_unique<Character>(L"Constance", L"23", L"4", L"5", L"11", L"6", L"6", L"4", L"3", L"4", L"6",
			L"0.2", L"0", L"0.2", L"0.6", L"0.3", L"0.35", L"0.15", L"0.15", L"0.3", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Hapi", L"26", L"4", L"6", L"11", L"8", L"6", L"4", L"4", L"7", L"4",
			L"0.35", L"0", L"0.35", L"0.45", L"0.45", L"0.4", L"0.2", L"0.15", L"0.45", L"0.25"));

		list.emplace_back(std::make_unique<BlankWeapon>(L"---", false, L"NULL", L"0", L"0", L"0", L"0", L"0", L"0", L"0", SL::BLANK));
		list.emplace_back(std::make_unique<Sword>(L"Broken Sword", false, L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0", SL::E));
		list.emplace_back(std::make_unique<Sword>(L"Iron Sword", false, L"NULL", L"5", L"90", L"0", L"1", L"5", L"E", L"40", SL::E));
		list.emplace_back(std::make_unique<Sword>(L"Iron Sword+", false, L"NULL", L"6", L"100", L"0", L"1", L"5", L"E", L"45", SL::E));
		list.emplace_back(std::make_unique<Sword>(L"Steel Sword", false, L"NULL", L"8", L"85", L"0", L"1", L"10", L"D", L"50", SL::D));
		list.emplace_back(std::make_unique<Sword>(L"Steel Sword+", false, L"NULL", L"10", L"85", L"0", L"1", L"10", L"D", L"55", SL::D));
		list.emplace_back(std::make_unique<Sword>(L"Silver Sword", false, L"NULL", L"12", L"90", L"0", L"1", L"8", L"B", L"30", SL::B));
		list.emplace_back(std::make_unique<Sword>(L"Silver Sword+", false, L"NULL", L"13", L"90", L"0", L"1", L"8", L"B", L"40", SL::B));
		list.emplace_back(std::make_unique<Sword>(L"Brave Sword", false, L"NULL", L"9", L"75", L"0", L"1", L"12", L"B", L"30", SL::B));
		list.emplace_back(std::make_unique<Sword>(L"Brave Sword+", false, L"NULL", L"10", L"85", L"0", L"1", L"12", L"B", L"40", SL::B));
		list.emplace_back(std::make_unique<Sword>(L"Killing Edge", false, L"NULL", L"8", L"85", L"25", L"1", L"10", L"C", L"20", SL::C));
		list.emplace_back(std::make_unique<Sword>(L"Killing Edge+", false, L"NULL", L"9", L"85", L"35", L"1", L"10", L"C", L"25", SL::C));
		list.emplace_back(std::make_unique<Sword>(L"Training Sword", false, L"NULL", L"3", L"100", L"0", L"1", L"4", L"E", L"50", SL::E));
		list.emplace_back(std::make_unique<Sword>(L"Training Sword+", false, L"NULL", L"3", L"100", L"0", L"1", L"2", L"E", L"65", SL::E));

		list.emplace_back(std::make_unique<Sword>(L"Levin Sword", false, L"NULL", L"9", L"70", L"0", L"1-2", L"9", L"C", L"25", SL::C));
		list.emplace_back(std::make_unique<Sword>(L"Levin Sword+", false, L"NULL", L"9", L"70", L"0", L"1-3", L"9", L"C", L"30", SL::C));

		list.emplace_back(std::make_unique<Sword>(L"Armorslayer", false, L"NULL", L"8", L"80", L"0", L"1", L"11", L"D", L"20", SL::D));
		list.emplace_back(std::make_unique<Sword>(L"Armorslayer+", false, L"NULL", L"8", L"100", L"5", L"1", L"11", L"D", L"25", SL::D));

		list.emplace_back(std::make_unique<Sword>(L"Rapier", false, L"NULL", L"7", L"95", L"10", L"1", L"5", L"E", L"40", SL::E));
		list.emplace_back(std::make_unique<Sword>(L"Rapier+", false, L"NULL", L"9", L"95", L"20", L"1", L"5", L"E", L"45", SL::E));

		list.emplace_back(std::make_unique<Sword>(L"Devil Sword", false, L"NULL", L"13", L"65", L"0", L"1", L"10", L"D", L"30", SL::D));
		list.emplace_back(std::make_unique<Sword>(L"Devil Sword+", false, L"NULL", L"16", L"65", L"0", L"1", L"10", L"D", L"30", SL::D));

		list.emplace_back(std::make_unique<Sword>(L"Wo Dao", false, L"NULL", L"8", L"90", L"30", L"1", L"5", L"B", L"15", SL::B));
		list.emplace_back(std::make_unique<Sword>(L"Wo Dao+", false, L"NULL", L"9", L"90", L"40", L"1", L"5", L"B", L"25", SL::B));

		list.emplace_back(std::make_unique<Sword>(L"Sword of Seiros", false, L"NULL", L"11", L"80", L"10", L"1", L"6", L"A", L"30", SL::A));
		list.emplace_back(std::make_unique<Sword>(L"Sword of Begalta", true, L"Claude", L"12", L"100", L"0", L"1", L"5", L"A", L"30", SL::A));
		list.emplace_back(std::make_unique<Sword>(L"Sword of Moralta", false, L"NULL", L"13", L"75", L"25", L"1", L"9", L"A", L"30", SL::A));

		list.emplace_back(std::make_unique<Sword>(L"Cursed Ashiya Sword", true, L"Felix", L"13", L"70", L"40", L"1", L"8", L"B", L"15", SL::B));
		list.emplace_back(std::make_unique<Sword>(L"Cursed Ashiya Sword+", true, L"Felix", L"14", L"70", L"50", L"1", L"8", L"B", L"20", SL::B));

		list.emplace_back(std::make_unique<Sword>(L"Sword of Zoltan", false, L"NULL", L"13", L"90", L"0", L"1", L"9", L"A", L"25", SL::A));
		list.emplace_back(std::make_unique<Sword>(L"Sword of Zoltan+", false, L"NULL", L"16", L"90", L"5", L"1", L"9", L"A", L"30", SL::A));

		list.emplace_back(std::make_unique<Sword>(L"Thunderbrand", true, L"Catherine", L"13", L"70", L"10", L"1", L"7", L"E", L"30", SL::E));
		list.emplace_back(std::make_unique<Sword>(L"Blutgang", true, L"Marianne", L"13", L"80", L"0", L"1", L"7", L"E", L"20", SL::E));
		list.emplace_back(std::make_unique<Sword>(L"Sword of the Creator", true, L"Byleth", L"7", L"90", L"0", L"1-2", L"9", L"E", L"20", SL::E));

		list.emplace_back(std::make_unique<Sword>(L"Venin Edge", false, L"NULL", L"5", L"90", L"0", L"1", L"6", L"C", L"20", SL::C));
		list.emplace_back(std::make_unique<Sword>(L"Venin Edge+", false, L"NULL", L"6", L"100", L"0", L"1", L"6", L"C", L"25", SL::C));

		list.emplace_back(std::make_unique<Sword>(L"Mercurius", false, L"NULL", L"15", L"100", L"10", L"1", L"7", L"A", L"40", SL::A));
		list.emplace_back(std::make_unique<Sword>(L"Rusted Sword", false, L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0", SL::E));
		list.emplace_back(std::make_unique<Lance>(L"Broken Lance", false, L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0", SL::E));

		list.emplace_back(std::make_unique<Lance>(L"Iron Lance", false, L"NULL", L"6", L"80", L"0", L"1", L"6", L"E", L"30", SL::E));
		list.emplace_back(std::make_unique<Lance>(L"Iron Lance+", false, L"NULL", L"7", L"90", L"0", L"1", L"6", L"E", L"35", SL::E));

		list.emplace_back(std::make_unique<Lance>(L"Steel Lance", false, L"NULL", L"9", L"75", L"0", L"1", L"11", L"D", L"40", SL::D));
		list.emplace_back(std::make_unique<Lance>(L"Steel Lance+", false, L"NULL", L"11", L"75", L"0", L"1", L"11", L"D", L"45", SL::D));

		list.emplace_back(std::make_unique<Lance>(L"Silver Lance", false, L"NULL", L"13", L"80", L"0", L"1", L"9", L"B", L"25", SL::B));
		list.emplace_back(std::make_unique<Lance>(L"Silver Lance+", false, L"NULL", L"14", L"80", L"0", L"1", L"9", L"B", L"35", SL::B));

		list.emplace_back(std::make_unique<Lance>(L"Brave Lance", false, L"NULL", L"10", L"70", L"0", L"1", L"13", L"B", L"25", SL::B));
		list.emplace_back(std::make_unique<Lance>(L"Brave Lance+", false, L"NULL", L"11", L"80", L"0", L"1", L"13", L"B", L"35", SL::B));

		list.emplace_back(std::make_unique<Lance>(L"Killer Lance", false, L"NULL", L"9", L"80", L"25", L"1", L"11", L"C", L"20", SL::C));
		list.emplace_back(std::make_unique<Lance>(L"Killer Lance+", false, L"NULL", L"10", L"80", L"35", L"1", L"11", L"C", L"25", SL::C));

		list.emplace_back(std::make_unique<Lance>(L"Training Lance", false, L"NULL", L"4", L"90", L"0", L"1", L"5", L"E", L"50", SL::E));
		list.emplace_back(std::make_unique<Lance>(L"Training Lance+", false, L"NULL", L"4", L"90", L"0", L"1", L"3", L"E", L"65", SL::E));

		list.emplace_back(std::make_unique<Lance>(L"Javelin", false, L"NULL", L"2", L"80", L"0", L"1-2", L"8", L"D", L"30", SL::D));
		list.emplace_back(std::make_unique<Lance>(L"Javelin+", false, L"NULL", L"3", L"80", L"0", L"1-2", L"8", L"D", L"40", SL::D));

		list.emplace_back(std::make_unique<Lance>(L"Short Spear", false, L"NULL", L"5", L"75", L"0", L"1-2", L"10", L"C", L"25", SL::C));
		list.emplace_back(std::make_unique<Lance>(L"Short Spear+", false, L"NULL", L"6", L"75", L"0", L"1-2", L"10", L"C", L"35", SL::C));

		list.emplace_back(std::make_unique<Lance>(L"Spear", false, L"NULL", L"8", L"70", L"0", L"1-2", L"12", L"B", L"20", SL::B));
		list.emplace_back(std::make_unique<Lance>(L"Spear+", false, L"NULL", L"9", L"70", L"0", L"1-2", L"12", L"B", L"30", SL::B));

		list.emplace_back(std::make_unique<Lance>(L"Horseslayer", false, L"NULL", L"8", L"70", L"0", L"1", L"13", L"D", L"20", SL::D));
		list.emplace_back(std::make_unique<Lance>(L"Horseslayer+", false, L"NULL", L"8", L"90", L"5", L"1", L"13", L"D", L"25", SL::D));

		list.emplace_back(std::make_unique<Lance>(L"Blessed Lance", false, L"NULL", L"7", L"80", L"0", L"1", L"14", L"C", L"20", SL::C));
		list.emplace_back(std::make_unique<Lance>(L"Blessed Lance+", false, L"NULL", L"9", L"80", L"0", L"1", L"14", L"C", L"20", SL::C));

		list.emplace_back(std::make_unique<Lance>(L"Crescent Sickle", false, L"NULL", L"10", L"80", L"0", L"1", L"12", L"B", L"50", SL::B));
		list.emplace_back(std::make_unique<Lance>(L"Crescent Sickle+", false, L"NULL", L"11", L"80", L"10", L"1", L"12", L"B", L"55", SL::B));

		list.emplace_back(std::make_unique<Lance>(L"Lance of Zoltan", false, L"NULL", L"15", L"80", L"0", L"1", L"10", L"A", L"20", SL::A));
		list.emplace_back(std::make_unique<Lance>(L"Lance of Zoltan+", false, L"NULL", L"18", L"80", L"5", L"1", L"10", L"A", L"25", SL::A));

		list.emplace_back(std::make_unique<Lance>(L"Lance of Ruin", true, L"Sylvain", L"22", L"65", L"20", L"1", L"9", L"E", L"20", SL::E));
		list.emplace_back(std::make_unique<Lance>(L"Areadbhar", true, L"Dimitri", L"19", L"75", L"10", L"1", L"9", L"E", L"20", SL::E));
		list.emplace_back(std::make_unique<Lance>(L"Luin", true, L"Ingrid", L"17", L"90", L"10", L"1", L"9", L"E", L"20", SL::E));
		list.emplace_back(std::make_unique<Lance>(L"Spear of Assal", true, L"Seteth", L"14", L"85", L"10", L"1", L"9", L"A", L"30", SL::A));

		list.emplace_back(std::make_unique<Lance>(L"Arrow of Indra", false, L"NULL", L"12", L"75", L"0", L"1-2", L"14", L"C", L"30", SL::C));
		list.emplace_back(std::make_unique<Lance>(L"Arrow of Indra+", false, L"NULL", L"12", L"75", L"0", L"1-3", L"14", L"C", L"35", SL::C));

		list.emplace_back(std::make_unique<Lance>(L"Venin Lance", false, L"NULL", L"6", L"80", L"0", L"1", L"7", L"C", L"20", SL::C));
		list.emplace_back(std::make_unique<Lance>(L"Venin Lance+", false, L"NULL", L"7", L"90", L"0", L"1", L"7", L"C", L"25", SL::C));

		list.emplace_back(std::make_unique<Lance>(L"Gradivus", false, L"NULL", L"17", L"90", L"10", L"1-2", L"8", L"A", L"30", SL::A));
		list.emplace_back(std::make_unique<Lance>(L"Rusted Lance", false, L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0", SL::E));
		list.emplace_back(std::make_unique<Axe>(L"Broken Axe", false, L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0", SL::E));
		
		list.emplace_back(std::make_unique<Axe>(L"Iron Axe", false, L"NULL", L"8", L"70", L"0", L"1", L"7", L"E", L"45", SL::E));
		list.emplace_back(std::make_unique<Axe>(L"Iron Axe+", false, L"NULL", L"9", L"80", L"0", L"1", L"7", L"E", L"50", SL::E));

		list.emplace_back(std::make_unique<Axe>(L"Steel Axe", false, L"NULL", L"11", L"65", L"0", L"1", L"12", L"D", L"55", SL::D));
		list.emplace_back(std::make_unique<Axe>(L"Steel Axe+", false, L"NULL", L"13", L"65", L"0", L"1", L"12", L"D", L"60", SL::D));

		list.emplace_back(std::make_unique<Axe>(L"Silver Axe", false, L"NULL", L"16", L"70", L"0", L"1", L"10", L"B", L"30", SL::B));
		list.emplace_back(std::make_unique<Axe>(L"Silver Axe+", false, L"NULL", L"17", L"70", L"0", L"1", L"10", L"B", L"40", SL::B));

		list.emplace_back(std::make_unique<Axe>(L"Brave Axe", false, L"NULL", L"12", L"60", L"0", L"1", L"14", L"B", L"30", SL::B));
		list.emplace_back(std::make_unique<Axe>(L"Brave Axe+", false, L"NULL", L"13", L"70", L"0", L"1", L"14", L"B", L"40", SL::B));

		list.emplace_back(std::make_unique<Axe>(L"Killer Axe", false, L"NULL", L"11", L"70", L"25", L"1", L"12", L"C", L"20", SL::C));
		list.emplace_back(std::make_unique<Axe>(L"Killer Axe+", false, L"NULL", L"12", L"70", L"35", L"1", L"12", L"C", L"25", SL::C));

		list.emplace_back(std::make_unique<Axe>(L"Training Axe", false, L"NULL", L"6", L"80", L"0", L"1", L"6", L"E", L"50", SL::E));
		list.emplace_back(std::make_unique<Axe>(L"Training Axe+", false, L"NULL", L"6", L"80", L"0", L"1", L"4", L"E", L"65", SL::E));

		list.emplace_back(std::make_unique<Axe>(L"Bolt Axe", false, L"NULL", L"14", L"60", L"0", L"1-2", L"15", L"B", L"25", SL::B));
		list.emplace_back(std::make_unique<Axe>(L"Bolt Axe+", false, L"NULL", L"14", L"60", L"0", L"1-3", L"15", L"B", L"30", SL::B));

		list.emplace_back(std::make_unique<Axe>(L"Hand Axe", false, L"NULL", L"4", L"70", L"0", L"1-2", L"10", L"D", L"30", SL::D));
		list.emplace_back(std::make_unique<Axe>(L"Hand Axe+", false, L"NULL", L"5", L"70", L"0", L"1-2", L"10", L"D", L"40", SL::D));

		list.emplace_back(std::make_unique<Axe>(L"Short Axe", false, L"NULL", L"8", L"65", L"0", L"1-2", L"12", L"C", L"25", SL::C));
		list.emplace_back(std::make_unique<Axe>(L"Short Axe+", false, L"NULL", L"9", L"65", L"0", L"1-2", L"12", L"C", L"35", SL::C));

		list.emplace_back(std::make_unique<Axe>(L"Tomahawk", false, L"NULL", L"12", L"60", L"0", L"1-2", L"14", L"B", L"20", SL::B));
		list.emplace_back(std::make_unique<Axe>(L"Tomahawk+", false, L"NULL", L"13", L"60", L"0", L"1-2", L"14", L"B", L"30", SL::B));

		list.emplace_back(std::make_unique<Axe>(L"Hammer", false, L"NULL", L"10", L"60", L"0", L"1", L"15", L"D", L"20", SL::D));
		list.emplace_back(std::make_unique<Axe>(L"Hammer+", false, L"NULL", L"10", L"80", L"5", L"1", L"15", L"D", L"25", SL::D));

		list.emplace_back(std::make_unique<Axe>(L"Devil Axe", false, L"NULL", L"18", L"60", L"0", L"1", L"14", L"D", L"30", SL::D));
		list.emplace_back(std::make_unique<Axe>(L"Devil Axe+", false, L"NULL", L"21", L"60", L"0", L"1", L"14", L"D", L"30", SL::D));

		list.emplace_back(std::make_unique<Axe>(L"Freikugel", true, L"Hilda", L"23", L"65", L"10", L"1", L"11", L"E", L"20", SL::E));
		list.emplace_back(std::make_unique<Axe>(L"Crusher", true, L"Annette", L"18", L"60", L"0", L"1", L"11", L"E", L"20", SL::E));
		list.emplace_back(std::make_unique<Axe>(L"Axe of Ukonvasara", true, L"Lorenz", L"19", L"65", L"20", L"1", L"15", L"A", L"30", SL::A));

		list.emplace_back(std::make_unique<Axe>(L"Axe of Zoltan", false, L"NULL", L"17", L"70", L"0", L"1", L"14", L"A", L"20", SL::A));
		list.emplace_back(std::make_unique<Axe>(L"Axe of Zoltan+", false, L"NULL", L"20", L"70", L"5", L"1", L"14", L"A", L"25", SL::A));

		list.emplace_back(std::make_unique<Axe>(L"Mace", false, L"NULL", L"6", L"70", L"0", L"1", L"6", L"E", L"20", SL::E));
		list.emplace_back(std::make_unique<Axe>(L"Mace+", false, L"NULL", L"6", L"90", L"5", L"1", L"6", L"E", L"25", SL::E));

		list.emplace_back(std::make_unique<Axe>(L"Amyr", true, L"Edelgard,Rhea", L"24", L"60", L"20", L"1", L"11", L"E", L"20", SL::E));

		list.emplace_back(std::make_unique<Axe>(L"Venin Axe", false, L"NULL", L"8", L"70", L"0", L"1", L"8", L"C", L"20", SL::C));
		list.emplace_back(std::make_unique<Axe>(L"Venin Axe+", false, L"NULL", L"9", L"80", L"0", L"1", L"8", L"C", L"25", SL::C));

		list.emplace_back(std::make_unique<Axe>(L"Hauteclere", false, L"NULL", L"19", L"80", L"10", L"1", L"12", L"A", L"40", SL::A));
		list.emplace_back(std::make_unique<Axe>(L"Rusted Axe", false, L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0", SL::E));
		list.emplace_back(std::make_unique<Bow>(L"Broken Bow", false, L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0", SL::E));

		list.emplace_back(std::make_unique<Bow>(L"Iron Bow", false, L"NULL", L"6", L"85", L"0", L"2", L"6", L"E", L"40", SL::E));
		list.emplace_back(std::make_unique<Bow>(L"Iron Bow+", false, L"NULL", L"7", L"95", L"0", L"2", L"5", L"E", L"45", SL::E));

		list.emplace_back(std::make_unique<Bow>(L"Steel Bow", false, L"NULL", L"9", L"80", L"0", L"2", L"11", L"D", L"50", SL::D));
		list.emplace_back(std::make_unique<Bow>(L"Steel Bow+", false, L"NULL", L"11", L"80", L"0", L"2", L"10", L"D", L"55", SL::D));

		list.emplace_back(std::make_unique<Bow>(L"Silver Bow", false, L"NULL", L"12", L"75", L"0", L"2", L"9", L"B", L"30", SL::B));
		list.emplace_back(std::make_unique<Bow>(L"Silver Bow+", false, L"NULL", L"13", L"75", L"0", L"2", L"8", L"B", L"40", SL::B));

		list.emplace_back(std::make_unique<Bow>(L"Brave Bow", false, L"NULL", L"10", L"70", L"0", L"2", L"13", L"B", L"30", SL::B));
		list.emplace_back(std::make_unique<Bow>(L"Brave Bow+", false, L"NULL", L"11", L"80", L"0", L"2", L"12", L"B", L"40", SL::B));

		list.emplace_back(std::make_unique<Bow>(L"Killer Bow", false, L"NULL", L"9", L"80", L"25", L"2", L"11", L"C", L"20", SL::C));
		list.emplace_back(std::make_unique<Bow>(L"Killer Bow+", false, L"NULL", L"10", L"80", L"35", L"2", L"11", L"C", L"25", SL::C));

		list.emplace_back(std::make_unique<Bow>(L"Training Bow", false, L"NULL", L"3", L"90", L"0", L"2", L"5", L"E", L"50", SL::E));
		list.emplace_back(std::make_unique<Bow>(L"Training Bow+", false, L"NULL", L"3", L"90", L"0", L"2", L"3", L"E", L"65", SL::E));

		list.emplace_back(std::make_unique<Bow>(L"Magic Bow", false, L"NULL", L"8", L"75", L"0", L"2", L"9", L"B", L"25", SL::B));
		list.emplace_back(std::make_unique<Bow>(L"Magic Bow+", false, L"NULL", L"8", L"75", L"0", L"2-3", L"9", L"B", L"30", SL::B));

		list.emplace_back(std::make_unique<Bow>(L"Longbow", false, L"NULL", L"9", L"70", L"0", L"2-3", L"13", L"C", L"20", SL::C));
		list.emplace_back(std::make_unique<Bow>(L"Longbow+", false, L"NULL", L"11", L"70", L"0", L"2-3", L"13", L"C", L"25", SL::C));

		list.emplace_back(std::make_unique<Bow>(L"Mini Bow", false, L"NULL", L"4", L"90", L"0", L"1-2", L"3", L"D", L"50", SL::D));
		list.emplace_back(std::make_unique<Bow>(L"Mini Bow+", false, L"NULL", L"6", L"90", L"10", L"1-2", L"3", L"D", L"55", SL::D));

		list.emplace_back(std::make_unique<Bow>(L"Blessed Bow", false, L"NULL", L"6", L"70", L"0", L"2", L"14", L"C", L"20", SL::C));
		list.emplace_back(std::make_unique<Bow>(L"Blessed Bow+", false, L"NULL", L"8", L"70", L"0", L"2", L"14", L"C", L"20", SL::C));

		list.emplace_back(std::make_unique<Bow>(L"Tathlum Bow", true, L"Mercedes,Jeritza", L"13", L"80", L"10", L"2", L"11", L"A", L"30", SL::A));
		list.emplace_back(std::make_unique<Bow>(L"The Inexhaustible", true, L"Seteth", L"11", L"80", L"0", L"2", L"11", L"A", L"30", SL::A));

		list.emplace_back(std::make_unique<Bow>(L"Bow of Zoltan", false, L"NULL", L"13", L"75", L"0", L"2", L"8", L"A", L"20", SL::A));
		list.emplace_back(std::make_unique<Bow>(L"Bow of Zoltan+", false, L"NULL", L"16", L"75", L"5", L"2", L"8", L"A", L"25", SL::A));

		list.emplace_back(std::make_unique<Bow>(L"Failnaught", true, L"Claude", L"18", L"75", L"20", L"2-3", L"9", L"E", L"20", SL::E));

		list.emplace_back(std::make_unique<Bow>(L"Venin Bow", false, L"NULL", L"6", L"85", L"0", L"2", L"6", L"C", L"20", SL::C));
		list.emplace_back(std::make_unique<Bow>(L"Venin Bow+", false, L"NULL", L"7", L"95", L"0", L"2", L"6", L"C", L"25", SL::C));

		list.emplace_back(std::make_unique<Bow>(L"Parthia", false, L"NULL", L"15", L"85", L"10", L"2", L"7", L"A", L"40", SL::A));
		list.emplace_back(std::make_unique<Bow>(L"Rusted Bow", false, L"NULL", L"0", L"30", L"0", L"2", L"5", L"E", L"45", SL::E));
		list.emplace_back(std::make_unique<Gauntlets>(L"Broken Gauntlets", false, L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0", SL::E));

		list.emplace_back(std::make_unique<Gauntlets>(L"Iron Gauntlets", false, L"NULL", L"1", L"85", L"5", L"1", L"3", L"E", L"50", SL::E));
		list.emplace_back(std::make_unique<Gauntlets>(L"Iron Gauntlets+", false, L"NULL", L"1", L"95", L"5", L"1", L"3", L"E", L"60", SL::E));

		list.emplace_back(std::make_unique<Gauntlets>(L"Steel Gauntlets", false, L"NULL", L"3", L"80", L"5", L"1", L"5", L"D", L"60", SL::D));
		list.emplace_back(std::make_unique<Gauntlets>(L"Steel Gauntlets+", false, L"NULL", L"3", L"85", L"5", L"1", L"5", L"D", L"70", SL::D));

		list.emplace_back(std::make_unique<Gauntlets>(L"Silver Gauntlets", false, L"NULL", L"4", L"85", L"5", L"1", L"7", L"B", L"40", SL::B));
		list.emplace_back(std::make_unique<Gauntlets>(L"Silver Gauntlets+", false, L"NULL", L"4", L"90", L"5", L"1", L"7", L"B", L"55", SL::B));

		list.emplace_back(std::make_unique<Gauntlets>(L"Training Gauntlets", false, L"NULL", L"0", L"90", L"5", L"1", L"1", L"E", L"70", SL::E));
		list.emplace_back(std::make_unique<Gauntlets>(L"Training Gauntlets+", false, L"NULL", L"0", L"100", L"5", L"1", L"1", L"E", L"90", SL::E));

		list.emplace_back(std::make_unique<Gauntlets>(L"Dragon Claws", false, L"NULL", L"4", L"75", L"5", L"1", L"7", L"A", L"30", SL::A));
		list.emplace_back(std::make_unique<Gauntlets>(L"Dragon Claws+", false, L"NULL", L"4", L"85", L"5", L"1", L"7", L"A", L"40", SL::A));

		list.emplace_back(std::make_unique<Gauntlets>(L"Killer Knuckles", false, L"NULL", L"3", L"80", L"20", L"1", L"5", L"B", L"30", SL::B));
		list.emplace_back(std::make_unique<Gauntlets>(L"Killer Knuckles+", false, L"NULL", L"3", L"80", L"30", L"1", L"5", L"B", L"40", SL::B));

		list.emplace_back(std::make_unique<Gauntlets>(L"Aura Gauntlets", false, L"NULL", L"2", L"70", L"0", L"1", L"4", L"A", L"30", SL::A));
		list.emplace_back(std::make_unique<Gauntlets>(L"Rusted Gauntlets", false, L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0", SL::E));
		list.emplace_back(std::make_unique<Gauntlets>(L"Vajra-Mushti", true, L"Balthus", L"7", L"90", L"10", L"1", L"7", L"E", L"30", SL::E));
		list.emplace_back(std::make_unique<BlackMagic>(L"Fire", false, L"NULL", L"3", L"90", L"0", L"1-2", L"3", L"E", L"10", SL::E));
		list.emplace_back(std::make_unique<BlackMagic>(L"Bolganone", false, L"NULL", L"8", L"85", L"0", L"1-2", L"6", L"C", L"5", SL::C));
		list.emplace_back(std::make_unique<BlackMagic>(L"Ragnarok", false, L"NULL", L"15", L"80", L"5", L"1-2", L"9", L"B", L"3", SL::B));
		list.emplace_back(std::make_unique<BlackMagic>(L"Thunder", false, L"NULL", L"4", L"80", L"5", L"1-2", L"4", L"E", L"8", SL::E));
		list.emplace_back(std::make_unique<BlackMagic>(L"Thoron", false, L"NULL", L"9", L"75", L"10", L"1-3", L"7", L"C", L"4", SL::C));
		list.emplace_back(std::make_unique<BlackMagic>(L"Bolting", false, L"NULL", L"12", L"65", L"15", L"3-10", L"18", L"B", L"2", SL::B));
		list.emplace_back(std::make_unique<BlackMagic>(L"Wind", false, L"NULL", L"2", L"100", L"10", L"1-2", L"2", L"E", L"12", SL::E));
		list.emplace_back(std::make_unique<BlackMagic>(L"Cutting Gale", false, L"NULL", L"7", L"95", L"10", L"1-2", L"5", L"C", L"6", SL::C));
		list.emplace_back(std::make_unique<BlackMagic>(L"Excalibur", false, L"NULL", L"11", L"100", L"15", L"1-2", L"8", L"B", L"4", SL::B));
		list.emplace_back(std::make_unique<BlackMagic>(L"Blizzard", false, L"NULL", L"3", L"70", L"15", L"1-2", L"4", L"E", L"10", SL::E));
		list.emplace_back(std::make_unique<BlackMagic>(L"Fimbulvetr", false, L"NULL", L"12", L"65", L"25", L"1-2", L"10", L"B", L"3", SL::B));
		list.emplace_back(std::make_unique<BlackMagic>(L"Sagittae", false, L"NULL", L"7", L"90", L"5", L"1-2", L"6", L"C", L"10", SL::C));
		list.emplace_back(std::make_unique<BlackMagic>(L"Meteor", false, L"NULL", L"10", L"80", L"0", L"3-10", L"19", L"B", L"1", SL::B));
		list.emplace_back(std::make_unique<BlackMagic>(L"Agnea's Arrow", false, L"NULL", L"16", L"70", L"5", L"1-2", L"13", L"A", L"2", SL::A));
		list.emplace_back(std::make_unique<DarkMagic>(L"Miasma", false, L"NULL", L"5", L"80", L"0", L"1-2", L"5", L"E", L"10", SL::E));
		list.emplace_back(std::make_unique<DarkMagic>(L"Mire", false, L"NULL", L"3", L"70", L"0", L"1-3", L"5", L"E", L"8", SL::E));
		list.emplace_back(std::make_unique<DarkMagic>(L"Swarm", false, L"NULL", L"4", L"70", L"0", L"1-2", L"4", L"E", L"8", SL::E));
		list.emplace_back(std::make_unique<DarkMagic>(L"Banshee", false, L"NULL", L"9", L"75", L"5", L"1-2", L"9", L"C", L"5", SL::C));
		list.emplace_back(std::make_unique<DarkMagic>(L"Death", false, L"NULL", L"6", L"70", L"20", L"1-3", L"8", L"C", L"4", SL::C));
		list.emplace_back(std::make_unique<DarkMagic>(L"Luna", false, L"NULL", L"1", L"65", L"0", L"1-2", L"7", L"C", L"2", SL::C));
		list.emplace_back(std::make_unique<DarkMagic>(L"Dark Spikes", false, L"NULL", L"13", L"80", L"0", L"1-2", L"11", L"B", L"3", SL::B));
		list.emplace_back(std::make_unique<DarkMagic>(L"Hades", false, L"NULL", L"18", L"65", L"10", L"1-2", L"16", L"A", L"2", SL::A));
		list.emplace_back(std::make_unique<DarkMagic>(L"Bohr", false, L"NULL", L"10", L"60", L"0", L"3-10", L"20", L"B", L"3", SL::B));
		list.emplace_back(std::make_unique<DarkMagic>(L"Quake", false, L"NULL", L"8", L"50", L"0", L"ALL", L"20", L"B", L"1", SL::B));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Heal", false, L"NULL", L"8", L"100", L"0", L"1", L"0", L"E", L"10", SL::E));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Recover", false, L"NULL", L"30", L"100", L"0", L"1", L"0", L"C", L"5", SL::C));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Physic", false, L"NULL", L"8", L"100", L"0", L"1", L"0", L"C", L"5", SL::C));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Fortify", false, L"NULL", L"15", L"100", L"0", L"0", L"0", L"A", L"2", SL::A));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Nosferatu", false, L"NULL", L"1", L"80", L"0", L"1-2", L"8", L"E", L"12", SL::E));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Seraphim", false, L"NULL", L"8", L"75", L"5", L"1-2", L"10", L"C", L"8", SL::C));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Aura", false, L"NULL", L"12", L"70", L"20", L"1-2", L"12", L"B", L"3", SL::B));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Abraxas", false, L"NULL", L"14", L"90", L"5", L"1-2", L"13", L"A", L"2", SL::A));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Torch", false, L"NULL", L"0", L"0", L"0", L"1-2", L"0", L"E", L"10", SL::E));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Restore", false, L"NULL", L"0", L"0", L"0", L"0", L"0", L"C", L"10", SL::C));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Ward", false, L"NULL", L"0", L"0", L"0", L"1", L"0", L"C", L"5", SL::C));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Silence", false, L"NULL", L"0", L"100", L"0", L"3-10", L"0", L"B", L"3", SL::B));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Rescue", false, L"NULL", L"0", L"0", L"0", L"0", L"0", L"B", L"3", SL::B));
		list.emplace_back(std::make_unique<WhiteMagic>(L"Warp", false, L"NULL", L"0", L"0", L"0", L"0", L"0", L"B", L"1", SL::B));

		list.emplace_back(std::make_unique<BlankEquipment>(L"---", false, L"NULL", L"0", L"0", L"NULL"));
		list.emplace_back(std::make_unique<Shield>(L"Leather Shield", false, L"NULL", L"1", L"1", L"NULL"));
		list.emplace_back(std::make_unique<Shield>(L"Iron Shield", false, L"NULL", L"2", L"2", L"NULL"));
		list.emplace_back(std::make_unique<Shield>(L"Steel Shield", false, L"NULL", L"3", L"3", L"NULL"));
		list.emplace_back(std::make_unique<Shield>(L"Silver Shield", false, L"NULL", L"4", L"4", L"NULL"));
		list.emplace_back(std::make_unique<Shield>(L"Talisman Shield", false, L"NULL", L"1", L"4", L"Resilience +2"));
		list.emplace_back(std::make_unique<Shield>(L"Hexlock Shield", false, L"NULL", L"2", L"5", L"Resilience +4"));
		list.emplace_back(std::make_unique<Shield>(L"Aegis Shield", true, L"Felix", L"6", L"6", L"Relic shield. Resilience +3, may halve damage for Crest of Fraldarius."));
		list.emplace_back(std::make_unique<Shield>(L"Ochain Shield", true, L"Seteth,Ferdinand", L"6", L"4", L"Sacred shield (Cichol); restores HP each turn and negates foe’s critical hits."));
		list.emplace_back(std::make_unique<Shield>(L"Seiros Shield", true, L"Edelgard", L"5", L"3", L"Sacred shield (Seiros); restores HP each turn and halves damage from Monsters."));
		list.emplace_back(std::make_unique<Shield>(L"Aurora Shield", false, L"NULL", L"3", L"0", L"Nullifies user’s Flying-type weakness."));
		list.emplace_back(std::make_unique<Shield>(L"Kadmos Shield", false, L"NULL", L"3", L"0", L"Nullifies user’s Armoured-type weakness."));
		list.emplace_back(std::make_unique<Shield>(L"Lampos Shield", false, L"NULL", L"3", L"0", L"Nullifies user’s Cavalry-type weakness."));
		list.emplace_back(std::make_unique<Ring>(L"Accuracy Ring", false, L"NULL", L"0", L"0", L"Hit rate +10"));
		list.emplace_back(std::make_unique<Ring>(L"Critical Ring", false, L"NULL", L"0", L"0", L"Critical rate +5."));
		list.emplace_back(std::make_unique<Ring>(L"Evasion Ring", false, L"NULL", L"0", L"0", L"Avoid +10."));
		list.emplace_back(std::make_unique<Ring>(L"Speed Ring", false, L"NULL", L"0", L"0", L"Speed +2."));
		list.emplace_back(std::make_unique<Ring>(L"March Ring", false, L"NULL", L"0", L"0", L"Movement +1."));
		list.emplace_back(std::make_unique<Ring>(L"Goddess Ring", false, L"NULL", L"0", L"0", L"Luck +8; restores HP each turn."));
		list.emplace_back(std::make_unique<Ring>(L"Prayer Ring", false, L"NULL", L"0", L"0", L"Grants Miracle ability; restores HP each turn."));
		list.emplace_back(std::make_unique<Ring>(L"Fetters of Dromi", true, L"Yuri", L"0", L"0", L"Relic ring (Aubin); Movement +1, user can continue moving after taking certain actions and may halve damage received."));
		list.emplace_back(std::make_unique<Staff>(L"Magic Staff", false, L"NULL", L"0", L"1", L"Increases Might of magic spells by 3."));
		list.emplace_back(std::make_unique<Staff>(L"Healing Staff", false, L"NULL", L"0", L"1", L"Increases Healing power by 10."));
		list.emplace_back(std::make_unique<Staff>(L"Caduceus Staff", true, L"Flayn,Linhardt", L"0", L"1", L"Sacred staff (Cethleann); offensive magic range +1, restores HP each turn."));
		list.emplace_back(std::make_unique<Staff>(L"Thyrsus", true, L"Lysithea,Lorenz", L"0", L"1", L"Relic staff (Gloucester); offensive magic range +2, may halve damage received."));
		list.emplace_back(std::make_unique<Gem>(L"Experience Gem", false, L"NULL", L"0", L"0", L"Base experience points +50%."));
		list.emplace_back(std::make_unique<Gem>(L"Knowledge Gem", false, L"NULL", L"0", L"0", L"Base skill level experience +100%."));
		list.emplace_back(std::make_unique<Gem>(L"Rafail Gem", true, L"Mercedes,Jeritza", L"0", L"0", L"Base skill level experience +100%."));

		list.emplace_back(std::make_unique<Class>(L"---", false, L"NULL",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Enlightened One", true, L"Byleth",
			L"28", L"6", L"17", L"8", L"12", L"14", L"10", L"12", L"10", L"0",
			L"1", L"2", L"2", L"3", L"1", L"1", L"1", L"2", L"2", L"1",
			L"0.2", L"0", L"0.1", L"0.1", L"0", L"0", L"0", L"0.05", L"0", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Armored Lord", true, L"Edelgard",
			L"38", L"5", L"17", L"8", L"12", L"6", L"10", L"17", L"8", L"0",
			L"5", L"1", L"0", L"0", L"0", L"-3", L"0", L"5", L"0", L"2",
			L"0.2", L"0", L"0.05", L"0.05", L"0", L"0", L"0", L"0.05", L"0.05", L"0.1",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"High Lord", true, L"Dimitri",
			L"30", L"5", L"16", L"7", L"11", L"13", L"9", L"13", L"9", L"0",
			L"3", L"1", L"1", L"0", L"0", L"3", L"0", L"1", L"0", L"2",
			L"0.2", L"0", L"0.05", L"0", L"0.05", L"", L"0", L"0.05", L"0", L"0.1",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Wyvern Master", true, L"Claude",
			L"30", L"7", L"17", L"9", L"13", L"19", L"11", L"14", L"11", L"0",
			L"2", L"0", L"1", L"0", L"3", L"0", L"0", L"1", L"0", L"2",
			L"0.2", L"0", L"0.1", L"0", L"0", L"0.05", L"0", L"0.05", L"0", L"0.1",
			L"0", L"3", L"1", L"0", L"0", L"1", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Emperor", true, L"Edelgard",
			L"38", L"5", L"17", L"8", L"12", L"6", L"10", L"17", L"8", L"0",
			L"8", L"1", L"0", L"0", L"0", L"-4", L"1", L"8", L"0", L"2",
			L"0.3", L"0", L"0.1", L"0.1", L"0", L"0", L"0", L"0.05", L"0.05", L"0.1",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Great Lord", true, L"Dimitri",
			L"35", L"6", L"17", L"8", L"12", L"14", L"10", L"14", L"10", L"0",
			L"5", L"2", L"2", L"0", L"0", L"4", L"1", L"1", L"0", L"2",
			L"0.3", L"0", L"0.1", L"0", L"0.1", L"1", L"0", L"0.05", L"0", L"0.1",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Barbarossa", true, L"Claude",
			L"35", L"8", L"18", L"10", L"14", L"20", L"12", L"15", L"12", L"0",
			L"3", L"2", L"3", L"0", L"5", L"0", L"0", L"2", L"0", L"2",
			L"0.3", L"0", L"0.15", L"0", L"0", L"0.1", L"0", L"0.05", L"0", L"0.1",
			L"0", L"2", L"0", L"0", L"0", L"2", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Commoner", false, L"NULL", 
			L"0", L"4", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"1", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Noble", false, L"NULL", 
			L"0", L"4", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"1", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Dancer", false, L"NULL", 
			L"0", L"6", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"1", L"0", L"0", L"0", L"0",
			L"0.2", L"0", L"-0.05", L"0", L"0", L"0", L"0", L"-0.05", L"-0.05", L"0.1",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Myrmidon", false, L"NULL",
			L"20", L"4", L"7", L"3", L"6", L"6", L"4", L"5", L"2", L"0",
			L"0", L"0", L"0", L"0", L"0", L"1", L"0", L"0", L"0", L"0",
			L"0.1", L"0", L"0", L"0", L"0", L"0.05", L"0", L"0", L"-0.05", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Soldier", false, L"NULL",
			L"20", L"4", L"8", L"3", L"6", L"6", L"4", L"5", L"2", L"0",
			L"0", L"0", L"0", L"0", L"1", L"0", L"0", L"0", L"0", L"0",
			L"0.1", L"0", L"0", L"0", L"0.05", L"0", L"0", L"0", L"-0.05", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Fighter", false, L"NULL",
			L"20", L"4", L"8", L"3", L"6", L"6", L"4", L"5", L"2", L"0",
			L"0", L"0", L"1", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0.1", L"0", L"0.05", L"0", L"0", L"0", L"0", L"0", L"-0.05", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Monk", false, L"NULL",
			L"20", L"4", L"4", L"8", L"6", L"6", L"4", L"3", L"4", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"0",
			L"0.05", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0.05", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Lord", false, L"NULL",
			L"25", L"5", L"9", L"6", L"10", L"10", L"8", L"6", L"3", L"0",
			L"1", L"1", L"0", L"0", L"0", L"1", L"1", L"0", L"0", L"2",
			L"0.2", L"0", L"0", L"0", L"0.1", L"0", L"0", L"0", L"0", L"0.1",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Mercenary", false, L"NULL",
			L"25", L"5", L"9", L"6", L"10", L"10", L"8", L"6", L"2", L"0",
			L"1", L"1", L"1", L"0", L"0", L"1", L"0", L"0", L"0", L"0",
			L"0.2", L"0", L"0.05", L"0", L"0", L"0.05", L"0", L"0", L"-0.05", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Thief", false, L"NULL", 
			L"25", L"5", L"9", L"6", L"11", L"11", L"8", L"6", L"2", L"0",
			L"0", L"1", L"0", L"0", L"2", L"2", L"0", L"0", L"0", L"0",
			L"0.2", L"0", L"0", L"0", L"0.1", L"0.1", L"0", L"0", L"0", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Armored Knight", false, L"NULL",
			L"30", L"4", L"9", L"6", L"7", L"4", L"8", L"12", L"1", L"0",
			L"3", L"0", L"0", L"0", L"0", L"-2", L"0", L"4", L"-1", L"0",
			L"0.2", L"0", L"0", L"0", L"0", L"-0.1", L"0", L"0.1", L"-0.05", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Cavalier", false, L"NULL",
			L"25", L"7", L"9", L"6", L"7", L"6", L"8", L"6", L"2", L"0",
			L"1", L"0", L"1", L"0", L"2", L"1", L"0", L"1", L"0", L"0",
			L"0.2", L"0", L"0.05", L"0", L"0.05", L"-0.1", L"0", L"0.05", L"0", L"0.05",
			L"0", L"3", L"0", L"0", L"0", L"-2", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Brigand", false, L"NULL",
			L"28", L"5", L"10", L"6", L"7", L"7", L"8", L"6", L"2", L"0",
			L"2", L"1", L"2", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0.3", L"0", L"0.1", L"0", L"0", L"1", L"0", L"0", L"-0.05", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Archer", false, L"NULL",
			L"25", L"5", L"8", L"6", L"8", L"7", L"8", L"5", L"2", L"0",
			L"0", L"1", L"0", L"0", L"2", L"0", L"2", L"0", L"0", L"0",
			L"0.05", L"0", L"0", L"0", L"0.1", L"0", L"0.05", L"0", L"0", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Brawler", false, L"NULL",
			L"28", L"5", L"9", L"6", L"7", L"8", L"8", L"6", L"1", L"0",
			L"1", L"1", L"0", L"0", L"2", L"2", L"0", L"0", L"-1", L"0",
			L"0.3", L"0", L"0", L"-0.1", L"0.1", L"0.1", L"0.1", L"0", L"0", L"-0.1",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Mage", false, L"NULL",
			L"25", L"4", L"4", L"10", L"7", L"6", L"8", L"3", L"5", L"0",
			L"0", L"0", L"0", L"1", L"1", L"0", L"0", L"0", L"2", L"0",
			L"0.05", L"0", L"-0.05", L"0.1", L"0.05", L"0", L"0", L"-0.05", L"0.05", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Dark Mage", false, L"NULL",
			L"25", L"4", L"4", L"10", L"7", L"6", L"8", L"3", L"5", L"0",
			L"0", L"0", L"2", L"1", L"0", L"0", L"0", L"1", L"0", L"0",
			L"0.05", L"0", L"-0.05", L"0.05", L"0.05", L"0", L"0", L"-0.05", L"0.1", L"0.1",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Priest", false, L"NULL",
			L"25", L"4", L"4", L"9", L"7", L"6", L"8", L"3", L"5", L"0",
			L"0", L"0", L"0", L"0", L"1", L"0", L"0", L"0", L"3", L"0",
			L"0.05", L"0", L"-0.05", L"0.05", L"0.05", L"0", L"0", L"-0.05", L"0.1", L"0.1",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Pegasus Knight", false, L"NULL",
			L"25", L"6", L"8", L"6", L"7", L"8", L"8", L"5", L"4", L"0",
			L"0", L"0", L"0", L"0", L"2", L"1", L"0", L"0", L"2", L"0",
			L"0.15", L"0", L"0", L"0", L"0", L"0.1", L"0", L"0", L"0.05", L"0.1",
			L"0", L"2", L"0", L"0", L"0", L"1", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Hero", false, L"NULL",
			L"30", L"5", L"17", L"8", L"12", L"14", L"10", L"12", L"8", L"0",
			L"3", L"1", L"2", L"0", L"0", L"2", L"1", L"1", L"0", L"0",
			L"0.3", L"0", L"0.1", L"0", L"0", L"0.1", L"0", L"0", L"-0.05", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Swordmaster", false, L"NULL",
			L"30", L"5", L"17", L"8", L"12", L"14", L"10", L"12", L"8", L"0",
			L"1", L"1", L"2", L"0", L"1", L"4", L"0", L"1", L"0", L"0",
			L"0.25", L"0", L"0.1", L"0", L"0", L"0.2", L"0", L"0", L"-0.05", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Assassin", false, L"NULL",
			L"30", L"6", L"17", L"8", L"12", L"14", L"10", L"12", L"8", L"0",
			L"0", L"2", L"0", L"0", L"3", L"5", L"1", L"0", L"0", L"0",
			L"0.2", L"0", L"0", L"0", L"0.2", L"0.2", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Fortress Knight", false, L"NULL",
			L"35", L"4", L"17", L"8", L"12", L"8", L"10", L"17", L"7", L"0",
			L"5", L"0", L"0", L"0", L"0", L"-6", L"0", L"10", L"0", L"0",
			L"0.3", L"0", L"0.1", L"0", L"0", L"-0.1", L"0", L"0.15", L"0", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Paladin", false, L"NULL",
			L"32", L"8", L"17", L"8", L"12", L"14", L"10", L"12", L"8", L"0",
			L"2", L"2", L"2", L"0", L"2", L"1", L"0", L"2", L"2", L"0",
			L"0.3", L"0", L"0.1", L"0", L"0", L"-0.1", L"0.05", L"0.05", L"0.05", L"0.05",
			L"0", L"2", L"0", L"0", L"0", L"-2", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Wyvern Rider", false, L"NULL",
			L"30", L"7", L"18", L"8", L"12", L"14", L"10", L"12", L"8", L"0",
			L"1", L"1", L"2", L"0", L"1", L"1", L"0", L"2", L"0", L"0",
			L"0.3", L"0", L"0.1", L"-0.05", L"0", L"0", L"0", L"0.05", L"-0.05", L"0.05",
			L"0", L"2", L"1", L"0", L"0", L"2", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Warrior", false, L"NULL",
			L"32", L"5", L"19", L"8", L"12", L"14", L"10", L"13", L"8", L"0",
			L"3", L"1", L"3", L"0", L"0", L"1", L"1", L"1", L"0", L"0",
			L"0.4", L"0", L"0.15", L"-0.05", L"0", L"0", L"0", L"0", L"0", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Sniper", false, L"NULL",
			L"30", L"5", L"17", L"8", L"12", L"14", L"10", L"12", L"8", L"0",
			L"0", L"1", L"1", L"0", L"5", L"0", L"3", L"0", L"0", L"0",
			L"0.1", L"0", L"0.05", L"0", L"0.2", L"0", L"0.1", L"0", L"0", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Grappler", false, L"NULL",
			L"32", L"6", L"17", L"8", L"12", L"14", L"10", L"14", L"7", L"0",
			L"2", L"2", L"1", L"0", L"3", L"3", L"0", L"1", L"-1", L"0",
			L"0.4", L"0", L"0.1", L"0", L"0.1", L"0.1", L"0", L"0", L"0", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Warlock", false, L"NULL",
			L"30", L"4", L"8", L"17", L"12", L"14", L"10", L"12", L"15", L"0",
			L"0", L"0", L"0", L"3", L"1", L"1", L"0", L"0", L"4", L"0",
			L"0.1", L"0", L"0", L"0.1", L"0", L"0", L"0", L"-0.05", L"0.05", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Dark Bishop", false, L"NULL",
			L"30", L"4", L"8", L"17", L"12", L"14", L"10", L"12", L"15", L"0",
			L"0", L"0", L"0", L"4", L"2", L"0", L"0", L"0", L"3", L"0",
			L"0.1", L"0", L"0", L"0.1", L"0", L"0", L"0", L"-0.05", L"0.05", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Bishop", false, L"NULL",
			L"30", L"4", L"8", L"15", L"12", L"14", L"10", L"12", L"15", L"0",
			L"1", L"0", L"0", L"2", L"1", L"0", L"0", L"0", L"5", L"0",
			L"0.1", L"0", L"0", L"0.1", L"0", L"0", L"0.1", L"-0.05", L"0.05", L"0.1",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Falcon Knight", false, L"NULL",
			L"32", L"8", L"18", L"10", L"14", L"20", L"12", L"13", L"14", L"0",
			L"0", L"2", L"0", L"0", L"4", L"3", L"0", L"0", L"4", L"0",
			L"0.3", L"0", L"0.1", L"0", L"0", L"0.2", L"0", L"0", L"0.05", L"0.1",
			L"0", L"2", L"1", L"0", L"0", L"2", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Wyvern Lord", false, L"NULL",
			L"32", L"8", L"18", L"10", L"14", L"20", L"12", L"15", L"12", L"0",
			L"2", L"2", L"2", L"0", L"1", L"2", L"0", L"3", L"0", L"0",
			L"0.3", L"0", L"0.15", L"-0.05", L"0", L"0.1", L"0", L"0.05", L"0", L"0.05",
			L"0", L"2", L"2", L"0", L"0", L"2", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Mortal Savant", false, L"NULL",
			L"32", L"6", L"17", L"17", L"14", L"16", L"12", L"14", L"12", L"0",
			L"1", L"2", L"1", L"2", L"1", L"1", L"0", L"2", L"2", L"0",
			L"0.2", L"0", L"0.1", L"0.1", L"0", L"-0.1", L"0.1", L"0", L"0", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Great Knight", false, L"NULL",
			L"34", L"7", L"18", L"10", L"14", L"10", L"12", L"17", L"10", L"0",
			L"5", L"0", L"1", L"0", L"0", L"-2", L"0", L"6", L"0", L"0",
			L"0.3", L"0", L"0.1", L"0", L"0", L"-0.1", L"0", L"0.05", L"-0.05", L"0.05",
			L"0", L"3", L"0", L"0", L"0", L"-2", L"0", L"-2", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Bow Knight", false, L"NULL",
			L"32", L"8", L"17", L"10", L"14", L"16", L"12", L"14", L"10", L"0",
			L"2", L"2", L"1", L"0", L"3", L"3", L"1", L"1", L"0", L"0",
			L"0.1", L"0", L"0", L"0", L"0", L"-0.05", L"0", L"0", L"0", L"0.05",
			L"0", L"2", L"0", L"0", L"0", L"-2", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Dark Knight", false, L"NULL",
			L"32", L"7", L"10", L"17", L"14", L"16", L"12", L"13", L"15", L"0",
			L"1", L"2", L"1", L"2", L"2", L"1", L"0", L"1", L"3", L"0",
			L"0.1", L"0", L"0.05", L"0.1", L"0", L"-0.05", L"0", L"0.05", L"0.1", L"0.05",
			L"0", L"1", L"0", L"0", L"0", L"-2", L"0", L"1", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Holy Knight", false, L"NULL",
			L"32", L"7", L"8", L"15", L"14", L"16", L"12", L"13", L"16", L"0",
			L"2", L"2", L"1", L"1", L"2", L"1", L"0", L"0", L"4", L"0",
			L"0.1", L"0", L"0", L"0.1", L"0", L"-0.05", L"0.1", L"0.05", L"0.1", L"0.1",
			L"0", L"1", L"0", L"0", L"0", L"-2", L"0", L"1", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"War Master", false, L"NULL",
			L"33", L"6", L"20", L"10", L"14", L"16", L"12", L"15", L"10", L"0",
			L"3", L"2", L"5", L"0", L"0", L"2", L"1", L"1", L"0", L"0",
			L"0.4", L"0", L"0.15", L"0", L"0", L"0.1", L"0", L"0", L"0", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Gremory", false, L"NULL",
			L"32", L"5", L"8", L"17", L"14", L"16", L"12", L"13", L"16", L"0",
			L"0", L"1", L"0", L"5", L"2", L"1", L"0", L"0", L"4", L"2",
			L"0.1", L"0", L"0", L"0.1", L"0.1", L"0", L"0", L"0", L"0.05", L"0.1",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Trickster", false, L"NULL",
			L"28", L"5", L"14", L"12", L"10", L"14", L"12", L"10", L"10", L"0",
			L"0", L"1", L"0", L"0", L"3", L"4", L"3", L"0", L"1", L"0",
			L"0.2", L"0", L"0", L"0", L"0.15", L"0.2", L"0.1", L"0", L"0.05", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"War Monk/Cleric", false, L"NULL",
			L"32", L"6", L"17", L"10", L"10", L"10", L"10", L"14", L"11", L"0",
			L"3", L"2", L"2", L"0", L"1", L"0", L"0", L"1", L"1", L"0",
			L"0.4", L"0", L"0.1", L"0.05", L"0.1", L"0", L"0", L"0", L"0.05", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Dark Flier", false, L"NULL",
			L"25", L"7", L"8", L"6", L"7", L"8", L"8", L"5", L"4", L"0",
			L"0", L"1", L"0", L"0", L"3", L"2", L"0", L"0", L"3", L"0",
			L"0.2", L"0", L"0", L"0", L"0", L"0.1", L"0", L"0", L"0.1", L"0.1",
			L"0", L"2", L"0", L"0", L"0", L"2", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Valkyrie", false, L"NULL",
			L"20", L"6", L"5", L"10", L"10", L"9", L"9", L"9", L"13", L"0",
			L"1", L"0", L"0", L"4", L"0", L"0", L"0", L"0", L"1", L"2",
			L"0.05", L"0", L"0", L"0.05", L"0", L"-0.05", L"0.05", L"0.05", L"0.1", L"0.1",
			L"0", L"2", L"0", L"0", L"0", L"-2", L"0", L"0", L"1", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Death Knight", false, L"NULL",
			L"32", L"7", L"10", L"17", L"14", L"16", L"12", L"13", L"15", L"0",
			L"5", L"1", L"3", L"0", L"0", L"3", L"0", L"2", L"3", L"0",
			L"0.3", L"0", L"0.1", L"0.1", L"0", L"-0.05", L"0", L"0.05", L"0.05", L"0",
			L"0", L"2", L"1", L"0", L"0", L"-2", L"0", L"1", L"0", L"0"));
	}

	UINT getSize() const { return list.size(); }
	Unit* operator[](UINT index);
};
class AbilityList {
private:
	std::vector<std::unique_ptr<Ability>> list;

public:
	AbilityList() {
		list.emplace_back(std::make_unique<BlankAbility>(L"---", L"---", SL::BLANK, WEAPONTYPE::BLANK, L"---"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Professor's Guidance", L"Byleth", L"+20% Experience Gained to user and adjacent ally"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Imperial Lineage", L"Edelgard", L"+20% Experience Gained"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Royal Lineage", L"Dimitri", L"+20% Experience Gained"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Leicester Lineage", L"Claude", L"+20% Experience Gained"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Officer Duty", L"Hubert", L"Boosts Gambit Might by 5."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Songstress", L"Dorothea", L"At the start of each turn, restores adjacent allies’ HP by 10%."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Confidence", L"Ferdinand", L"When HP is full, unit gains +15 Hit and Avoid"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Persecution Complex", L"Bernadetta", L"When HP is not full, unit gains +5 Damage"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Born Fighter", L"Caspar", L"Adjacent foes receive Avoid -10 during combat."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Catnap", L"Linhardt", L"If unit waits without performing an action, restores 10% HP."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Hunter's Boon", L"Petra", L"When foe has less than 50% HP, Critical rate +20"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Live to Serve", L"Mercedes", L"When healing allies with White Magic, unit is healed by the same amount"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Staunch Shield", L"Dedue", L"If user waits without acting, Defense +4 for one turn."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Lone Wolf", L"Felix", L"When a Battalion is not deployed or when battalion health is zero, damage dealt +5"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Lockpick", L"Ashe", L"Unit can open locks and chests without keys"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Perseverance", L"Annette", L"When Rally command is used on ally, grants Strength +4."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Philanderer", L"Sylvain", L"When adjacent to a female ally, damage dealt to foe +2, damage received from foe -2."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Lady Knight", L"Ingrid", L"When using a Gambit, Might +3 and Hit Rate +5."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Distinguished House", L"Lorenz", L"When a battalion is deployed, damage dealt +2"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Advocate", L"Hilda", L"When an adjacent male ally enters battle, ally’s damage dealt +3"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Goody Basket", L"Raphael", L"At the start of a turn, unit has Luck% chance of regaining 10% of HP"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Mastermind", L"Lysithea", L"Unit gains 2x skill EXP from combat"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Watchful Eye", L"Ignatz", L"Hit rate +20."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Animal Friend", L"Marianne", L"When adjacent to a horseback or flying ally, restores 20% HP at the start of the turn."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Rivalry", L"Leonie", L"When adjacent to a male ally, damage dealt to foe +2, damage received from foe -2."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Infirmary Master", L"Manuela", L"Adjacent allies gain Crit Avoid +10 during combat"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Crest Scholar", L"Hanneman", L"Use Rally to grant Mag +4 to an ally"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Fighting Spirit", L"Catherine", L"Unit takes 5 less damage when no battalion is assigned or when battalion endurance is 0."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Compassion", L"Alois", L"Use Rally to grant Lck +8 to an ally."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Guardian", L"Seteth", L"Adjacent female allies deal 3 extra damage during combat"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Lily's Poise", L"Flayn", L"Adjacent allies take 3 less damage during combat."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Veteran Knight", L"Gilbert", L"Unit takes 2 less damage while in formation with a battalion."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Survival Instinct", L"Shamir", L"If unit initiates combat and defeats foe, grants Str/Mag/Dex/Spd +4 for one turn."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Aptitude", L"Cyril", L"Makes each stat 20% more likely to increase on level up."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Murderous Intent", L"Jeritza", L"If unit initiates combat, grants Hit +20 during combat."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Business Prosperity", L"Anna", L"Grants Lck +5."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Honorable Spirit", L"Yuri", L"If unit is not near an ally, grants Atk +3 when in combat with a foe one space away."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Circadian Beat", L"Constance", L"Grants Str/Mag +3 when indoors and Def/Res +3 when outdoors."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"King of Grappling", L"Balthus", L"Grants Str/Def +6 when HP ≤ 50%."));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Monstrous Appeal", L"Hapi", L"Makes all attacks effective against monsters and makes it easier for monsters to target unit."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Charm", L"Lord,Wyvern Master,Barbarossa,Armored Lord,High Lord,Emperor,Great Lord", L"When allies adjacent to unit enter combat, allies gain +3 Damage."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Canto", L"Cavalier,Pegasus Knight,Barbarossa,Paladin,Wyvern Rider,Wyvern Master,Death Knight,Dark Flier,Valkyrie,Falcon Knight,Wyvern Lord,Great Knight,Bow Knight,Dark Knight,Holy Knight", L"After performing an action, user can use their leftover movement."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Unarmed", L"Brawler,Grappler,War Monk/Cleric", L"User can fight without a weapon equipped."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Fire", L"Mage", L"Enables the use of Fire. If already learned, doubles the number of uses."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Miasma", L"Dark Mage,Dark Bishop", L"Enables the use of Miasma Δ. If already learned, doubles the number of uses."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Heartseeker", L"Dark Mage,Dark Bishop", L"Reduces Avoid of adjacent foes by 20."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Steal", L"Thief", L"Unit can steal non-weapon items from enemies with lower Spd than self."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Locktouch", L"Thief,Assassin,Trickster", L"Unit can open locks and chests without keys."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Avoid +10", L"Pegasus Knight,Falcon Knight,Wyvern Lord", L"Increases Avoid by 10."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Bowrange +1", L"Archer,Sniper", L"Increases range of Bows by 1."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Bowrange +2", L"Bow Knight", L"Increases range of Bows by 2."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Heal", L"Priest,War Monk/Cleric", L"Unit can use Heal. If it has already been learnt, the number of times it can be used is doubled."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"White Magic Heal +5", L"Priest", L"White Magic heals +5 more HP."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"White Magic Heal +10", L"Bishop", L"White Magic heals +10 more HP."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Swordfaire", L"Hero,Swordmaster,Assassin,Mortal Savant,Enlighted One", L"Might +5 when a sword is equipped."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Axefaire", L"Fortress Knight,Warrior,Wyvern Rider,Wyvern Lord,Great Knight,War Master,Armored Lord,Emperor", L"Might +5 when a axe is equipped."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Lancefaire", L"Paladin,Death Knight,Falcon Knight,Great Knight,High Lord,Great Lord", L"Might +5 when a lance is equipped."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Bowfaire", L"Sniper,Wyvern Master,Barbarossa,Bow Knight", L"Might +5 when a bow is equipped."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Fistfaire", L"Grappler,War Monk/Cleric,War Master", L"Might +5 when a gaunlet is equipped."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Black Tomefaire", L"Warlock,Dark Knight,Dark Flier,Mortal Savant", L"Might +5 when Black Magic is equipped."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Dark Tomefaire", L"Dark Knight", L"Might +5 when Dark Magic is equipped."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"White Tomefaire", L"Holy Knight", L"Might +5 when White Magic is equipped."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Vantage", L"Hero", L"Always attack first when under 50% HP.﻿"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Weight -5", L"Fortress Knight", L"The combined weight of equipment is reduced by 5."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Terrain Resistance", L"Paladin,Bishop,Holy Knight,Enlightened One", L"Unit does not receive terrain damage."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Black Magic Uses x2", L"Warlock,Gremory", L"Doubles the number of uses of Black Magic spells."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Dark Magic Uses x2", L"Gremory", L"Doubles the number of uses of Dark Magic spells."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"White Magic Uses x2", L"Bishop,Gremory", L"Doubles the number of uses of White Magic spells."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Sword Critical +10", L"Swordmaster", L"Critical +10 when equipped with a sword."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Stealth", L"Assassin,Trickster", L"Unit is less likely to be targeted by enemies."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Axe Critical +10", L"Warrior", L"Critical +20"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Critical +20", L"War Master", L"Might +5 when a axe is equipped."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Fiendish Blow", L"Dark Bishop", L"Mag +6 when initiating attack."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Lucky Sevem", L"Trickster", L"Each turn, grants +5 to one of the following stats: Str, Mag, Spd, Def, Res, Hit or Avo."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Transmute", L"Dark Flier", L"If unit is hit with a magic attack during enemy phase, grants +3 to all stats until next player phase ends."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Black Magic Range +1", L"Valkyrie", L"Increases black magic range by 1."));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Dark Magic Range +1", L"Valkyrie", L"Increases dark magic range by 1."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Sword Prowess Lv. 1", L"Sword", SL::EPLUS, WEAPONTYPE::SWORD, L"Grants Hit +5, Avoid +7 and Critical Evade +5 when equipped with Sword"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Sword Prowess Lv. 2", L"Sword", SL::DPLUS, WEAPONTYPE::SWORD, L"Grants Hit +6, Avoid +10 and Critical Evade +6 when equipped with Sword"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Sword Prowess Lv. 3", L"Sword", SL::CPLUS, WEAPONTYPE::SWORD, L"Grants Hit +7, Avoid +13 and Critical Evade +7 when equipped with Sword"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axebreaker", L"Sword", SL::B, WEAPONTYPE::SWORD, L"Grants Hit/Avo +20 when using a sword against axe users."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Sword Prowess Lv.4", L"Sword", SL::BPLUS, WEAPONTYPE::SWORD, L"Grants Hit +8, Avoid +16 and Critical Evade +8 when equipped with Sword"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Sword Prowess Lv.5", L"Sword", SL::APLUS, WEAPONTYPE::SWORD, L"Grants Hit +10, Avoid +20 and Critical Evade +10 when equipped with Sword"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Sword Critical +10", L"Sword", SL::S, WEAPONTYPE::SWORD, L"Grants Crit +10 when using a sword."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Swordfaire", L"Sword", SL::SPLUS, WEAPONTYPE::SWORD, L"Might +5 when a sword is equipped."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lance Prowess Lv.1", L"Lance", SL::EPLUS, WEAPONTYPE::LANCE, L"Grants Hit +6, Avoid +6 and Critical Evade +5 when equipped with Lance"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lance Prowess Lv.2", L"Lance", SL::DPLUS, WEAPONTYPE::LANCE, L"Grants Hit +8, Avoid +8 and Critical Evade +6 when equipped with Lance"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lance Prowess Lv.3", L"Lance", SL::CPLUS, WEAPONTYPE::LANCE, L"Grants Hit +10, Avoid +10 and Critical Evade +7 when equipped with Lance"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Swordbreaker", L"Lance", SL::B, WEAPONTYPE::LANCE, L"Grants Hit/Avo +20 when using a lance against sword users."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lance Prowess Lv.4", L"Lance", SL::BPLUS, WEAPONTYPE::LANCE, L"Grants Hit +12, Avoid +12 and Critical Evade +8 when equipped with Lance"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lance Prowess Lv.5", L"Lance", SL::APLUS, WEAPONTYPE::LANCE, L"Grants Hit +15, Avoid +15 and Critical Evade +10 when equipped with Lance"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lance Critical +10", L"Lance", SL::S, WEAPONTYPE::LANCE, L"Grants Crit +10 when using a lance."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lancefaire", L"Lance", SL::SPLUS, WEAPONTYPE::LANCE, L"Might +5 when a lance is equipped."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axe Prowess Lv.1", L"Axe", SL::EPLUS, WEAPONTYPE::AXE, L"Grants Hit +7, Avoid +5 and Critical Evade +5 when equipped with Axe"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axe Prowess Lv.2", L"Axe", SL::DPLUS, WEAPONTYPE::AXE, L"Grants Hit +10, Avoid +6 and Critical Evade +6 when equipped with Axe"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axe Prowess Lv.3", L"Axe", SL::CPLUS, WEAPONTYPE::AXE, L"Grants Hit +13, Avoid +7 and Critical Evade +7 when equipped with Axe"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lancebreaker", L"Axe", SL::B, WEAPONTYPE::AXE, L"Grants Hit/Avo +20 when using an axe against lance users."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axe Prowess Lv.4", L"Axe", SL::BPLUS, WEAPONTYPE::AXE, L"Grants Hit +16, Avoid +8 and Critical Evade +8 when equipped with Axe"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axe Prowess Lv.5", L"Axe", SL::APLUS, WEAPONTYPE::AXE, L"Grants Hit +20, Avoid +10 and Critical Evade +10 when equipped with Axe"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axe Critical +10", L"Axe", SL::S, WEAPONTYPE::AXE, L"Grants Crit +10 when using an axe."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axefaire", L"Axe", SL::SPLUS, WEAPONTYPE::AXE, L"Might +5 when an axe is equipped."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bow Prowess Lv.1", L"Bow", SL::EPLUS, WEAPONTYPE::BOW, L"Grants Hit +6, Avoid +6 and Critical Evade +5 when equipped with Bow"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bow Prowess Lv.2", L"Bow", SL::DPLUS, WEAPONTYPE::BOW, L"Grants Hit +8, Avoid +8 and Critical Evade +6 when equipped with Bow"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Close Counter", L"Bow", SL::C, WEAPONTYPE::BOW, L"Allows unit to counterattack adjacent foes."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bow Prowess Lv.3", L"Bow", SL::CPLUS, WEAPONTYPE::BOW, L"Grants Hit +10, Avoid +10 and Critical Evade +7 when equipped with Bow"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bow Prowess Lv.4", L"Bow", SL::BPLUS, WEAPONTYPE::BOW, L"Grants Hit +12, Avoid +12 and Critical Evade +8 when equipped with Bow"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bow Prowess Lv.5", L"Bow", SL::APLUS, WEAPONTYPE::BOW, L"Grants Hit +15, Avoid +15 and Critical Evade +10 when equipped with Bow"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bow Critical +10", L"Bow", SL::S, WEAPONTYPE::BOW, L"Grants Crit +10 when using a bow."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bowfaire", L"Bow", SL::SPLUS, WEAPONTYPE::BOW, L"Might +5 when a bow is equipped."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Brawling Prowess Lv.1", L"Gauntlets", SL::EPLUS, WEAPONTYPE::GAUNTLETS, L"Grants Hit +5, Avoid +7 and Critical Evade +5 when brawling."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Brawling Prowess Lv.2", L"Gauntlets", SL::DPLUS, WEAPONTYPE::GAUNTLETS, L"Grants Hit +6, Avoid +10 and Critical Evade +6 when brawling"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Brawling Prowess Lv.3", L"Gauntlets", SL::CPLUS, WEAPONTYPE::GAUNTLETS, L"Grants Hit +7, Avoid +13 and Critical Evade +7 when brawling"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Brawling Prowess Lv.4", L"Gauntlets", SL::BPLUS, WEAPONTYPE::GAUNTLETS, L"Grants Hit +8, Avoid +16 and Critical Evade +8 when brawling"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Brawling Prowess Lv.5", L"Gauntlets", SL::APLUS, WEAPONTYPE::GAUNTLETS, L"Grants Hit +10, Avoid +20 and Critical Evade +10 when brawling"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Brawling Critical +10", L"Gauntlets", SL::S, WEAPONTYPE::GAUNTLETS, L"Grants Crit +10 when brawling."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Fistfaire", L"Gauntlets", SL::SPLUS, WEAPONTYPE::GAUNTLETS, L"Might +5 when a gauntlet is equipped."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Reason Prowess Lv.1", L"Reason", SL::EPLUS, WEAPONTYPE::REASON, L"Grants Hit +7, Avoid +5 and Critical Evade +5 when equipped with Reason Magic"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Reason Prowess Lv.2", L"Reason", SL::DPLUS, WEAPONTYPE::REASON, L"Grants Hit +10, Avoid +6 and Critical Evade +6 when equipped with Reason Magic"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Reason Prowess Lv.3", L"Reason", SL::CPLUS, WEAPONTYPE::REASON, L"Grants Hit +13, Avoid +7 and Critical Evade +7 when equipped with Reason Magic"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Reason Prowess Lv.4", L"Reason", SL::BPLUS, WEAPONTYPE::REASON, L"Grants Hit +16, Avoid +8 and Critical Evade +8 when equipped with Reason Magic"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Reason Prowess Lv.5", L"Reason", SL::APLUS, WEAPONTYPE::REASON, L"Grants Hit +20, Avoid +10 and Critical Evade +10 when equipped with Reason Magic"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Black Magic Range +1", L"Reason", SL::S, WEAPONTYPE::REASON, L"Increases black magic range by 1."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Dark Magic Range +1", L"Reason", SL::S, WEAPONTYPE::REASON, L"Increases dark magic range by 1."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Black Tomefaire", L"Reason", SL::SPLUS, WEAPONTYPE::REASON, L"Might +5 when Black Magic is equipped."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Dark Tomefaire", L"Reason", SL::SPLUS, WEAPONTYPE::REASON, L"Might +5 when Dark Magic is equipped."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Faith Prowess Lv.1", L"Faith", SL::EPLUS, WEAPONTYPE::FAITH, L"Grants Hit +5, Avoid +7 and Critical Evade +5 when equipped with Faith Magic"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Faith Prowess Lv.2", L"Faith", SL::DPLUS, WEAPONTYPE::FAITH, L"Grants Hit +6, Avoid +10 and Critical Evade +6 when equipped with Faith Magic"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Faith Prowess Lv.3", L"Faith", SL::CPLUS, WEAPONTYPE::FAITH, L"Grants Hit +7, Avoid +13 and Critical Evade +7 when equipped with Faith Magic"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Faith Prowess Lv.4", L"Faith", SL::BPLUS, WEAPONTYPE::FAITH, L"Grants Hit +8, Avoid +16 and Critical Evade +8 when equipped with Faith Magic"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Faith Prowess Lv.5", L"Faith", SL::APLUS, WEAPONTYPE::FAITH, L"Grants Hit +10, Avoid +20 and Critical Evade +10 when equipped with Faith Magic"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"White Magic Range +1", L"Faith", SL::S, WEAPONTYPE::FAITH, L"Increases White Magic range by 1 for attacks that damage foes."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"White Tomefaire", L"Faith", SL::SPLUS, WEAPONTYPE::FAITH, L"Might +5 when White Magic is equipped."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Authority Prowess Lv.1", L"Authority", SL::EPLUS, WEAPONTYPE::AUTHORITY, L"Grants Mt +2 with gambits."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Magic", L"Authority", SL::D, WEAPONTYPE::AUTHORITY, L"Use Rally to grant Mag +4 to an ally."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Charm", L"Authority", SL::D, WEAPONTYPE::AUTHORITY, L"Use Rally to grant Cha +8 to an ally."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Dexterity", L"Authority", SL::D, WEAPONTYPE::AUTHORITY, L"Use Rally to grant Dex +8 to an ally."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Resistance", L"Authority", SL::D, WEAPONTYPE::AUTHORITY, L"Use Rally to grant Res +4 to an ally."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Strength", L"Authority", SL::D, WEAPONTYPE::AUTHORITY, L"Use Rally to grant Str +4 to an ally."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Speed", L"Authority", SL::CPLUS, WEAPONTYPE::AUTHORITY, L"Use Rally to grant Spd +4 to an ally."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Defense", L"Authority", SL::D, WEAPONTYPE::AUTHORITY, L"Use Rally to grant Def +4 to an ally."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Luck", L"Authority", SL::D, WEAPONTYPE::AUTHORITY, L"Use Rally to grant Lck +8 to an ally."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Authority Prowess Lv.2", L"Authority", SL::DPLUS, WEAPONTYPE::AUTHORITY, L"Grants Mt +4 with gambits."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Battalion Vantage", L"Authority", SL::C, WEAPONTYPE::AUTHORITY, L"When foe initiates combat, unit still attacks first if battalion endurance is ≤ 1/3."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Battalion Wrath", L"Authority", SL::C, WEAPONTYPE::AUTHORITY, L"If foe initiates combat while unit’s battalion endurance is ≤ 1/3, grants Crit +50."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Battalion Desperation", L"Authority", SL::C, WEAPONTYPE::AUTHORITY, L"If unit initiates combat when battalion endurance is ≤ 1/3, unit’s follow-up attack (if possible) occurs before foe’s counterattack."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Battalion Renewal", L"Authority", SL::C, WEAPONTYPE::AUTHORITY, L"Unit recovers up to 30% of max HP at the start of each turn while battalion endurance is ≤ 1/3."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Authority Prowess Lv.3", L"Authority", SL::CPLUS, WEAPONTYPE::AUTHORITY, L"Grants Mt +6 with gambits."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Model Leader", L"Authority", SL::CPLUS, WEAPONTYPE::AUTHORITY, L"Doubles experience earned for battalions."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Defensive Tactics", L"Authority", SL::B, WEAPONTYPE::AUTHORITY, L"Battalion endurance takes half damage."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Authority Prowess Lv.4", L"Authority", SL::BPLUS, WEAPONTYPE::AUTHORITY, L"Grants Mt +8 with gambits."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Authority Prowess Lv.5", L"Authority", SL::APLUS, WEAPONTYPE::AUTHORITY, L"Grants Mt +10 with gambits."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Movement", L"Authority", SL::S, WEAPONTYPE::AUTHORITY, L"Use Rally to grant Mv +1 to an ally."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Offensive Tactics", L"Authority", SL::SPLUS, WEAPONTYPE::AUTHORITY, L"Grants Mt +5 and Hit +20 with gambits."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Weight -3", L"Heavy Armor", SL::C, WEAPONTYPE::HEAVYARMOR, L"The combined weight of equipment is reduced by 3."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Weight -5", L"Heavy Armor", SL::APLUS, WEAPONTYPE::HEAVYARMOR, L"The combined weight of equipment is reduced by 5."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Armored Effect Null", L"Heavy Armor", SL::SPLUS, WEAPONTYPE::HEAVYARMOR, L"Nullifies any extra effectiveness against armored units."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Dexterity +4", L"Riding", SL::C, WEAPONTYPE::RIDING, L"Increases Dex by 4."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Movement +1", L"Riding", SL::APLUS, WEAPONTYPE::RIDING, L"Increases Mv by 1."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Cavalry Effect Null", L"Riding", SL::SPLUS, WEAPONTYPE::RIDING, L"Nullifies any extra effectiveness against cavalry units."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Alert Stance", L"Flying", SL::B, WEAPONTYPE::FLYING, L"If unit takes no action except Wait, grants Avo +15 for 1 turn."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Alert Stance+", L"Flying", SL::APLUS, WEAPONTYPE::FLYING, L"If unit takes no action except Wait, grants Avo +30 for 1 turn."));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Flying Effect Null", L"Flying", SL::SPLUS, WEAPONTYPE::FLYING, L"Nullifies any extra effectiveness against flying units."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"HP +5", L"", L"Increases HP by 5"));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Speed +2", L"", L"Increases Spd by 2"));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Defense +2", L"", L"Increases Def by 2"));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Strength +2", L"", L"Increases Str by 2"));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Magic +2", L"", L"Increases Mag by 2"));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Resistance +2", L"", L"Increases Res by 2"));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Vantage", L"", L"Always attack first when under 50% HP."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Steal", L"", L"Unit can steal non-weapon items from enemies with lower Spd than self."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Desperation", L"", L"If unit initiates combat with HP ≤ 50%, unit’s follow-up attack (if possible) occurs before foe’s counterattack."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Darting Blow", L"", L"If unit initiates combat, grants AS +6 during combat."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Death Blow", L"", L"If unit initiates combat, grants Str +6 during combat."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Armored Blow", L"", L"If unit initiates combat, grants Def +6 during combat."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Hit +20", L"", L"Increases Hit by 20."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Unarmed Combat", L"", L"User can fight without a weapon equipped."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Fiendish Blow", L"", L"If unit initiates combat, grants Mag+6 during combat"));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Poison Strike", L"", L"If unit initiates combat, enemy loses up to 20% HP"));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Miracle", L"", L"Luck % chance to survive lethal damage with 1HP if HP is above 1"));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Special Dance", L"", L"Dex/Spd/Luck +4 to target ally when using Dance"));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Pomp & Circumstance", L"", L"Increases Lck/Cha by 4."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Sacred Power", L"", L"Adjacent allies deal 3 extra damage and take 3 less damage during combat."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Defiant Strength", L"", L"Grants Str +8 when HP is ≤ 25%."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Lethality", L"", L"Chance to instantly kill a foe when dealing damage. Trigger % = 0.25×Dex."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Aegis", L"", L"Chance to reduce bow/magic damage by half. Trigger % = Dex stat."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Wrath", L"", L"If foe initiates combat while unit’s HP is ≤ 50%, grants Crit +50."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Pavise", L"", L"Chance to reduce sword/lance/axe/brawling damage by half. Trigger % = Dex stat."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Seal Defense", L"", L"If unit damages foe during combat, foe suffers Def -6 for 1 turn after combat."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Tomebreaker", L"", L"Grants Hit/Avo +20 when brawling against magic users."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Bowbreaker", L"", L"Grants Hit/Avo +20 when using magic against bow users."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Lifetaker", L"", L"Unit recovers HP equal to 50% of damage dealt after defeating a foe."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Renewal", L"", L"Unit recovers up to 20% of max HP at the start of each turn."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Warding Blow", L"", L"If unit initiates combat, grants Res +6 during combat"));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Defiant Avoid", L"", L"Grants Avo +30 when HP is ≤ 25%."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Quick Riposte", L"", L"If foe initiates combat while unit’s HP is ≥ 50%, unit makes guaranteed follow-up attack."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Defiant Critical", L"", L"Grants Crit +50 when HP is ≤ 25%."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Defiant Defense", L"", L"Grants Def +8 when HP is ≤ 25%."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Defiant Speed", L"", L"Grants Spd +8 when HP is ≤ 25%."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Defiant Magic", L"", L"Grants Mag +8 when HP is ≤ 25%."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Seal Resistance", L"", L"If unit damages foe during combat, foe suffers Res -6 for 1 turn after combat."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Defiant Resistance", L"", L"Grants Res +8 when HP is ≤ 25%."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Counterattack", L"", L"Counters attacks regardless of enemies' range."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Duelist's Blow", L"", L"If unit initiates combat, grants Avo +20 during combat"));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Brawl Avo +20", L"", L"Grants Avo +20 when brawling."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Transmute", L"", L"If unit is hit with a magic attack during enemy phase, grants +3 to all stats until next player phase ends."));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(L"Uncanny Blow", L"", L"If unit initiates combat, grants Hit +30 during combat"));
	}
	~AbilityList() { list.clear(); }

	UINT getSize() const { return list.size(); }
	Ability* operator[](UINT index) const;
	std::vector<std::unique_ptr<Ability>>::iterator begin() { return list.begin(); }
	std::vector<std::unique_ptr<Ability>>::iterator end() { return list.end(); }
};

#endif
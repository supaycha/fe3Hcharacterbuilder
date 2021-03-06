﻿#ifndef ABILITYLIST_H
#define ABILITYLIST_H

#include <wx/wx.h>
#include <map>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/BlankAbility.h>
#include <Unit/Ability/CharacterInnateAbility.h>
#include <Unit/Ability/ClassInnateAbility/ClassInnateAbility.h>
#include <Unit/Ability/ClassInnateAbility/ClassInnateCharacterAbility.h>
#include <Unit/Ability/ClassInnateAbility/ClassInnateGeneralAbility.h>
#include <Unit/Ability/SkillLevelAbility/SkillLevelAbility.h>
#include <Unit/Ability/SkillLevelAbility/SkillLevelCharacterAbility.h>
#include <Unit/Ability/SkillLevelAbility/SkillLevelGeneral/SkillLevelGeneralAbility.h>
#include <Unit/Ability/SkillLevelAbility/SkillLevelGeneral/SkillLevelGeneralProwessAbility.h>

#include <Unit/Ability/ClassMasteryAbility.h>
#include "constants.h"
//#include <vld.h>

//
class AbilityList {
private:
	std::vector<std::unique_ptr<Ability>> list;

public:
	AbilityList() {
		///////////////////////////////////////////////////////////////////////////
		////CHARACTERINNATEABILITY//////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////
		//list.emplace_back(std::make_unique<CharacterInnateAbility>(L"---", L"---", L"---", true, STATTYPE::BLANK, L"---"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Professor's Guidance",
			L"Byleth", 
			L"+20% Experience Gained to user and adjacent ally", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Imperial Lineage",
			L"Edelgard",
			L"+20% Experience Gained",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Royal Lineage",
			L"Dimitri",
			L"+20% Experience Gained", 
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Leicester Lineage", 
			L"Claude", 
			L"+20% Experience Gained",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Officer Duty",
			L"Hubert",
			L"Boosts Gambit Might by 5.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::GMIGHT, "5")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Songstress",
			L"Dorothea", 
			L"At the start of each turn, restores adjacent allies’ HP by 10%.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Confidence", 
			L"Ferdinand",
			L"When HP is full, unit gains +15 Hit and Avoid", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Persecution Complex",
			L"Bernadetta", 
			L"When HP is not full, unit gains +5 Damage", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Born Fighter", 
			L"Caspar", 
			L"Adjacent foes receive Avoid -10 during combat.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Catnap",
			L"Linhardt", 
			L"If unit waits without performing an action, restores 10% HP.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Hunter's Boon",
			L"Petra",
			L"When foe has less than 50% HP, Critical rate +20", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Live to Serve",
			L"Mercedes", 
			L"When healing allies with White Magic, unit is healed by the same amount", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Staunch Shield", 
			L"Dedue",
			L"If user waits without acting, Defense +4 for one turn.", 
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Lone Wolf",
			L"Felix",
			L"When a Battalion is not deployed or when battalion health is zero, damage dealt +5", 
			true, true, false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::MIGHT, "5")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Lockpick", 
			L"Ashe", 
			L"Unit can open locks and chests without keys", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Perseverance", 
			L"Annette", 
			L"When Rally command is used on ally, grants Strength +4.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Philanderer",
			L"Sylvain",
			L"When adjacent to a female ally, damage dealt to foe +2, damage received from foe -2.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Lady Knight",
			L"Ingrid",
			L"When using a Gambit, Might +3 and Hit Rate +5.", 
			true, true, true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::GMIGHT, "3"), STATPACKAGE(STATTYPE::GHIT, "5")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Distinguished House",
			L"Lorenz", 
			L"When a battalion is deployed, damage dealt +2", 
			true, true, true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::MIGHT, "2")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Advocate", 
			L"Hilda",
			L"When an adjacent male ally enters battle, ally’s damage dealt +3",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Goody Basket", 
			L"Raphael", 
			L"At the start of a turn, unit has Luck% chance of regaining 10% of HP",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Mastermind",
			L"Lysithea",
			L"Unit gains 2x skill EXP from combat", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Watchful Eye"
			, L"Ignatz",
			L"Hit rate +20.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "20")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Animal Friend",
			L"Marianne",
			L"When adjacent to a horseback or flying ally, restores 20% HP at the start of the turn.", 
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Rivalry", 
			L"Leonie", 
			L"When adjacent to a male ally, damage dealt to foe +2, damage received from foe -2.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Infirmary Master", 
			L"Manuela", 
			L"Adjacent allies gain Crit Avoid +10 during combat", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Crest Scholar", 
			L"Hanneman", 
			L"Use Rally to grant Mag +4 to an ally", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Fighting Spirit", 
			L"Catherine",
			L"Unit takes 5 less damage when no battalion is assigned or when battalion endurance is 0.",
			true, true, false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::PROT, "5")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Compassion", 
			L"Alois",
			L"Use Rally to grant Lck +8 to an ally.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Guardian", 
			L"Seteth", 
			L"Adjacent female allies deal 3 extra damage during combat", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Lily's Poise", 
			L"Flayn", 
			L"Adjacent allies take 3 less damage during combat.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Veteran Knight", 
			L"Gilbert", 
			L"Unit takes 2 less damage while in formation with a battalion.", 
			true, true, true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::PROT, "2")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Survival Instinct", 
			L"Shamir", 
			L"If unit initiates combat and defeats foe, grants Str/Mag/Dex/Spd +4 for one turn.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Aptitude", 
			L"Cyril",
			L"Makes each stat 20% more likely to increase on level up.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Murderous Intent",
			L"Jeritza", 
			L"If unit initiates combat, grants Hit +20 during combat.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Business Prosperity",
			L"Anna", 
			L"Grants Luck +5.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::LCK, "5")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Honorable Spirit",
			L"Yuri", 
			L"If unit is not near an ally, grants Atk +3 when in combat with a foe one space away.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Circadian Beat",
			L"Constance",
			L"Grants Str/Mag +3 when indoors and Def/Res +3 when outdoors.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"King of Grappling", 
			L"Balthus", 
			L"Grants Str/Def +6 when HP ≤ 50%.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(
			L"Monstrous Appeal",
			L"Hapi", 
			L"Makes all attacks effective against monsters and makes it easier for monsters to target unit.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));



		///////////////////////////////////////////////////////////////////////////
		////CLASSINNATEGENERALABILITY//////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////
		//list.emplace_back(std::make_unique<ClassInnateAbility>(L"---", L"---", L"---", true, STATTYPE::BLANK, L"---")}));
		list.emplace_back(std::make_unique<ClassInnateGeneralAbility>(
			L"Charm", 
			L"Lord,Wyvern Master,Barbarossa,Armored Lord,High Lord,Emperor,Great Lord",
			L"When allies adjacent to unit enter combat, allies gain +3 Damage.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateGeneralAbility>(
			L"Canto", 
			L"Cavalier,Pegasus Knight,Barbarossa,Paladin,Wyvern Rider,Wyvern Master,Death Knight,Dark Flier,Valkyrie,Falcon Knight,Wyvern Lord,Great Knight,Bow Knight,Dark Knight,Holy Knight", 
			L"After performing an action, user can use their leftover movement.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateGeneralAbility>(
			L"Unarmed", 
			L"Brawler,Grappler,War Monk/Cleric", L"User can fight without a weapon equipped.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateGeneralAbility>(
			L"Heartseeker",
			L"Dark Mage,Dark Bishop", 
			L"Reduces Avoid of adjacent foes by 20.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateGeneralAbility>(
			L"Steal",
			L"Thief", 
			L"Unit can steal non-weapon items from enemies with lower Spd than self.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateGeneralAbility>(
			L"Locktouch", 
			L"Thief,Assassin,Trickster", L"Unit can open locks and chests without keys.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateGeneralAbility>(
			L"Vantage",
			L"Hero",
			L"Always attack first when under 50% HP.﻿",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateGeneralAbility>(
			L"Terrain Resistance",
			L"Paladin,Bishop,Holy Knight,Enlightened One",
			L"Unit does not receive terrain damage.",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateGeneralAbility>(
			L"Fiendish Blow",
			L"Dark Bishop",
			L"Mag +6 when initiating attack.",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateGeneralAbility>(
			L"Stealth",
			L"Assassin,Trickster",
			L"Unit is less likely to be targeted by enemies.",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateGeneralAbility>(
			L"Lucky Seven",
			L"Trickster",
			L"Each turn, grants +5 to one of the following stats: Str, Mag, Spd, Def, Res, Hit or Avo.",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateGeneralAbility>(
			L"Transmute",
			L"Dark Flier",
			L"If unit is hit with a magic attack during enemy phase, grants +3 to all stats until next player phase ends.",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));



		///////////////////////////////////////////////////////////////////////////
		////CLASSINNATECHARACTERABILITY//////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Fire",
			L"Mage",
			WEAPONTYPE::BLACKMAGIC, L"Enables the use of Fire. If already learned, doubles the number of uses.",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Miasma",
			L"Dark Mage,Dark Bishop",
			WEAPONTYPE::DARKMAGIC, L"Enables the use of Miasma Δ. If already learned, doubles the number of uses.",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Avoid +10",
			L"Pegasus Knight,Falcon Knight,Wyvern Lord",
			WEAPONTYPE::ALL, L"Increases Avoid by 10.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::AVO, "10")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Bowrange +1",
			L"Archer,Sniper", 
			WEAPONTYPE::BOW, L"Increases range of Bows by 1.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::RANGE, "1")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Bowrange +2", 
			L"Bow Knight", 
			WEAPONTYPE::BOW, L"Increases range of Bows by 2.",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::RANGE, "2")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Heal", 
			L"Priest,War Monk/Cleric",
			WEAPONTYPE::WHITEMAGIC, L"Unit can use Heal. If it has already been learnt, the number of times it can be used is doubled.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"White Magic Heal +5", 
			L"Priest",
			WEAPONTYPE::WHITEMAGIC, L"White Magic heals +5 more HP.",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HEAL, "5")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"White Magic Heal +10",
			L"Bishop",
			WEAPONTYPE::WHITEMAGIC, L"White Magic heals +10 more HP.",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HEAL, "10")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Swordfaire",
			L"Hero,Swordmaster,Assassin,Mortal Savant,Enlighted One", 
			WEAPONTYPE::SWORD, L"Might +5 when a sword is equipped.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::PMIGHT, "5")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Axefaire", 
			L"Fortress Knight,Warrior,Wyvern Rider,Wyvern Lord,Great Knight,War Master,Armored Lord,Emperor", 
			WEAPONTYPE::AXE, L"Might +5 when a axe is equipped.", 
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::PMIGHT, "5")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Lancefaire", 
			L"Paladin,Death Knight,Falcon Knight,Great Knight,High Lord,Great Lord", 
			WEAPONTYPE::LANCE, L"Might +5 when a lance is equipped.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::PMIGHT, "5")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Bowfaire",
			L"Sniper,Wyvern Master,Barbarossa,Bow Knight", 
			WEAPONTYPE::BOW, L"Might +5 when a bow is equipped.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::PMIGHT, "5")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Fistfaire",
			L"Grappler,War Monk/Cleric,War Master", 
			WEAPONTYPE::GAUNTLETS, L"Might +5 when a gauntlet is equipped.", 
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::PMIGHT, "5")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Black Tomefaire",
			L"Warlock,Dark Knight,Dark Flier,Mortal Savant", 
			WEAPONTYPE::BLACKMAGIC, L"Might +5 when Black Magic is equipped.",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::MMIGHT, "5")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Dark Tomefaire",
			L"Dark Knight",
			WEAPONTYPE::DARKMAGIC, L"Might +5 when Dark Magic is equipped.",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::MMIGHT, "5")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"White Tomefaire", 
			L"Holy Knight", 
			WEAPONTYPE::WHITEMAGIC, L"Might +5 when White Magic is equipped.",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::MMIGHT, "5")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Weight -5",
			L"Fortress Knight",
			WEAPONTYPE::ALL, L"The combined weight of equipment is reduced by 5.",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::WEIGHT, "-5")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Black Magic Uses x2",
			L"Warlock,Gremory", 
			WEAPONTYPE::BLACKMAGIC, L"Doubles the number of uses of Black Magic spells.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Dark Magic Uses x2", 
			L"Gremory", 
			WEAPONTYPE::DARKMAGIC, L"Doubles the number of uses of Dark Magic spells.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"White Magic Uses x2",
			L"Bishop,Gremory",
			WEAPONTYPE::WHITEMAGIC, L"Doubles the number of uses of White Magic spells.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Sword Critical +10", 
			L"Swordmaster",
			WEAPONTYPE::SWORD, L"Critical +10 when equipped with a sword.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::WCRIT, "10")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Axe Critical +10",
			L"Warrior", 
			WEAPONTYPE::AXE, L"Grants Crit +10 when using an axe.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::WCRIT, "10")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Critical +20",
			L"War Master", 
			WEAPONTYPE::ALL, L"Critical +20", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::WCRIT, "20")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Black Magic Range +1",
			L"Valkyrie", 
			WEAPONTYPE::BLACKMAGIC, L"Increases black magic range by 1.", 
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::RANGE, "1")}));
		list.emplace_back(std::make_unique<ClassInnateCharacterAbility>(
			L"Dark Magic Range +1", 
			L"Valkyrie",
			WEAPONTYPE::DARKMAGIC, L"Increases dark magic range by 1.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::RANGE, "1")}));



		///////////////////////////////////////////////////////////////////////////
		////SKILLLEVELGENERALABILITY//////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(L"---", L"---", SL::BLANK, SKILLTYPE::BLANK, WEAPONTYPE::BLANK, L"---", false, std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Sword Prowess Lv. 1", 
			L"Sword", SL::EPLUS, 
			SKILLTYPE::SWORD, WEAPONTYPE::SWORD, PROWESSTYPE::SWORD,
			L"Grants Hit +5, Avoid +7 and Critical Evade +5 when equipped with Sword", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "5"), STATPACKAGE(STATTYPE::AVO, "7"), STATPACKAGE(STATTYPE::CRITAVO, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Sword Prowess Lv. 2", 
			L"Sword", SL::DPLUS, 
			SKILLTYPE::SWORD, WEAPONTYPE::SWORD, PROWESSTYPE::SWORD,
			L"Grants Hit +6, Avoid +10 and Critical Evade +6 when equipped with Sword", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "6"), STATPACKAGE(STATTYPE::AVO, "10"), STATPACKAGE(STATTYPE::CRITAVO, "6")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Sword Prowess Lv. 3",
			L"Sword", SL::CPLUS, 
			SKILLTYPE::SWORD, WEAPONTYPE::SWORD, PROWESSTYPE::SWORD,
			L"Grants Hit +7, Avoid +13 and Critical Evade +7 when equipped with Sword", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "7"), STATPACKAGE(STATTYPE::AVO, "13"), STATPACKAGE(STATTYPE::CRITAVO, "7")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Axebreaker", 
			L"Sword", SL::B, 
			SKILLTYPE::SWORD, WEAPONTYPE::SWORD, PROWESSTYPE::SWORD,
			L"Grants Hit/Avo +20 when using a sword against axe users.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Sword Prowess Lv.4", 
			L"Sword", SL::BPLUS, 
			SKILLTYPE::SWORD, WEAPONTYPE::SWORD, PROWESSTYPE::SWORD,
			L"Grants Hit +8, Avoid +16 and Critical Evade +8 when equipped with Sword",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "8"), STATPACKAGE(STATTYPE::AVO, "16"), STATPACKAGE(STATTYPE::CRITAVO, "8")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Sword Prowess Lv.5", 
			L"Sword", SL::APLUS, 
			SKILLTYPE::SWORD, WEAPONTYPE::SWORD, PROWESSTYPE::SWORD,
			L"Grants Hit +10, Avoid +20 and Critical Evade +10 when equipped with Sword",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "10"), STATPACKAGE(STATTYPE::AVO, "20"), STATPACKAGE(STATTYPE::CRITAVO, "10")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Sword Critical +10", 
			L"Sword", SL::S,
			SKILLTYPE::SWORD, WEAPONTYPE::SWORD,
			L"Grants Crit +10 when using a sword.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::WCRIT, "10")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Swordfaire", 
			L"Sword", SL::SPLUS,
			SKILLTYPE::SWORD, WEAPONTYPE::SWORD,
			L"Might +5 when a sword is equipped.",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::PMIGHT, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Lance Prowess Lv.1",
			L"Lance", SL::EPLUS, 
			SKILLTYPE::LANCE, WEAPONTYPE::LANCE, PROWESSTYPE::LANCE,
			L"Grants Hit +6, Avoid +6 and Critical Evade +5 when equipped with Lance", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "6"), STATPACKAGE(STATTYPE::AVO, "6"), STATPACKAGE(STATTYPE::CRITAVO, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Lance Prowess Lv.2",
			L"Lance", SL::DPLUS,
			SKILLTYPE::LANCE, WEAPONTYPE::LANCE, PROWESSTYPE::LANCE,
			L"Grants Hit +8, Avoid +8 and Critical Evade +6 when equipped with Lance", 
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "8"), STATPACKAGE(STATTYPE::AVO, "8"), STATPACKAGE(STATTYPE::CRITAVO, "6")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Lance Prowess Lv.3",
			L"Lance", SL::CPLUS, 
			SKILLTYPE::LANCE, WEAPONTYPE::LANCE, PROWESSTYPE::LANCE,
			L"Grants Hit +10, Avoid +10 and Critical Evade +7 when equipped with Lance", 
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "10"), STATPACKAGE(STATTYPE::AVO, "10"), STATPACKAGE(STATTYPE::CRITAVO, "7")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Swordbreaker", 
			L"Lance", SL::B, 
			SKILLTYPE::LANCE, WEAPONTYPE::LANCE,
			L"Grants Hit/Avo +20 when using a lance against sword users.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Lance Prowess Lv.4", 
			L"Lance", SL::BPLUS, 
			SKILLTYPE::LANCE, WEAPONTYPE::LANCE, PROWESSTYPE::LANCE,
			L"Grants Hit +12, Avoid +12 and Critical Evade +8 when equipped with Lance", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "12"), STATPACKAGE(STATTYPE::AVO, "12"), STATPACKAGE(STATTYPE::CRITAVO, "8")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Lance Prowess Lv.5", 
			L"Lance", SL::APLUS, 
			SKILLTYPE::LANCE, WEAPONTYPE::LANCE, PROWESSTYPE::LANCE,
			L"Grants Hit +15, Avoid +15 and Critical Evade +10 when equipped with Lance", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "15"), STATPACKAGE(STATTYPE::AVO, "15"), STATPACKAGE(STATTYPE::CRITAVO, "10")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Lance Critical +10", 
			L"Lance", SL::S, 
			SKILLTYPE::LANCE, WEAPONTYPE::LANCE,
			L"Grants Crit +10 when using a lance.",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATPACKAGE(STATTYPE::WCRIT, "10"))}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Lancefaire", 
			L"Lance", SL::SPLUS, 
			SKILLTYPE::LANCE, WEAPONTYPE::LANCE,
			L"Might +5 when a lance is equipped.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATPACKAGE(STATTYPE::PMIGHT, "5"))}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Axe Prowess Lv.1", 
			L"Axe", SL::EPLUS, 
			SKILLTYPE::AXE, WEAPONTYPE::AXE, PROWESSTYPE::AXE,
			L"Grants Hit +7, Avoid +5 and Critical Evade +5 when equipped with Axe",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "7"), STATPACKAGE(STATTYPE::AVO, "5"), STATPACKAGE(STATTYPE::CRITAVO, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Axe Prowess Lv.2", 
			L"Axe", SL::DPLUS,
			SKILLTYPE::AXE, WEAPONTYPE::AXE, PROWESSTYPE::AXE,
			L"Grants Hit +10, Avoid +6 and Critical Evade +6 when equipped with Axe", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "10"), STATPACKAGE(STATTYPE::AVO, "6"), STATPACKAGE(STATTYPE::CRITAVO, "6")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Axe Prowess Lv.3", 
			L"Axe", SL::CPLUS,
			SKILLTYPE::AXE, WEAPONTYPE::AXE, PROWESSTYPE::AXE,
			L"Grants Hit +13, Avoid +7 and Critical Evade +7 when equipped with Axe", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "13"), STATPACKAGE(STATTYPE::AVO, "7"), STATPACKAGE(STATTYPE::CRITAVO, "7")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Lancebreaker",
			L"Axe", SL::B,
			SKILLTYPE::AXE, WEAPONTYPE::AXE, 
			L"Grants Hit/Avo +20 when using an axe against lance users.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Axe Prowess Lv.4", 
			L"Axe", SL::BPLUS,
			SKILLTYPE::AXE, WEAPONTYPE::AXE, PROWESSTYPE::AXE,
			L"Grants Hit +16, Avoid +8 and Critical Evade +8 when equipped with Axe", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "16"), STATPACKAGE(STATTYPE::AVO, "8"), STATPACKAGE(STATTYPE::CRITAVO, "8")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Axe Prowess Lv.5", 
			L"Axe", SL::APLUS, 
			SKILLTYPE::AXE, WEAPONTYPE::AXE, PROWESSTYPE::AXE,
			L"Grants Hit +20, Avoid +10 and Critical Evade +10 when equipped with Axe", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "20"), STATPACKAGE(STATTYPE::AVO, "10"), STATPACKAGE(STATTYPE::CRITAVO, "10")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Axe Critical +10", 
			L"Axe", SL::S, 
			SKILLTYPE::AXE, WEAPONTYPE::AXE,
			L"Grants Crit +10 when using an axe.",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::WCRIT, "10")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Axefaire",
			L"Axe", SL::SPLUS,
			SKILLTYPE::AXE, WEAPONTYPE::AXE,
			L"Might +5 when an axe is equipped.",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::PMIGHT, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Bow Prowess Lv.1",
			L"Bow", SL::EPLUS,
			SKILLTYPE::BOW, WEAPONTYPE::BOW, PROWESSTYPE::BOW,
			L"Grants Hit +6, Avoid +6 and Critical Evade +5 when equipped with Bow", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "6"), STATPACKAGE(STATTYPE::AVO, "6"), STATPACKAGE(STATTYPE::CRITAVO, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Bow Prowess Lv.2",
			L"Bow", SL::DPLUS,
			SKILLTYPE::BOW, WEAPONTYPE::BOW, PROWESSTYPE::BOW,
			L"Grants Hit +8, Avoid +8 and Critical Evade +6 when equipped with Bow", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "8"), STATPACKAGE(STATTYPE::AVO, "8"), STATPACKAGE(STATTYPE::CRITAVO, "6")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Close Counter", 
			L"Bow", SL::C,
			SKILLTYPE::BOW, WEAPONTYPE::BOW, 
			L"Allows unit to counterattack adjacent foes.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Bow Prowess Lv.3", 
			L"Bow", SL::CPLUS, 
			SKILLTYPE::BOW, WEAPONTYPE::BOW, PROWESSTYPE::BOW,
			L"Grants Hit +10, Avoid +10 and Critical Evade +7 when equipped with Bow", 
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "10"), STATPACKAGE(STATTYPE::AVO, "10"), STATPACKAGE(STATTYPE::CRITAVO, "7")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Bow Prowess Lv.4",
			L"Bow", SL::BPLUS, 
			SKILLTYPE::BOW, WEAPONTYPE::BOW, PROWESSTYPE::BOW,
			L"Grants Hit +12, Avoid +12 and Critical Evade +8 when equipped with Bow",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "12"), STATPACKAGE(STATTYPE::AVO, "12"), STATPACKAGE(STATTYPE::CRITAVO, "8")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Bow Prowess Lv.5",
			L"Bow", SL::APLUS, 
			SKILLTYPE::BOW, WEAPONTYPE::BOW, PROWESSTYPE::BOW,
			L"Grants Hit +15, Avoid +15 and Critical Evade +10 when equipped with Bow",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "15"), STATPACKAGE(STATTYPE::AVO, "15"), STATPACKAGE(STATTYPE::CRITAVO, "10")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Bow Critical +10",
			L"Bow", SL::S,
			SKILLTYPE::BOW, WEAPONTYPE::BOW,
			L"Grants Crit +10 when using a bow.",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::WCRIT, "10")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Bowfaire", 
			L"Bow", SL::SPLUS, 
			SKILLTYPE::BOW, WEAPONTYPE::BOW, 
			L"Might +5 when a bow is equipped.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::PMIGHT, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Brawling Prowess Lv.1", 
			L"Gauntlets", SL::EPLUS,
			SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS, PROWESSTYPE::GAUNTLETS,
			L"Grants Hit +5, Avoid +7 and Critical Evade +5 when brawling.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "5"), STATPACKAGE(STATTYPE::AVO, "7"), STATPACKAGE(STATTYPE::CRITAVO, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Brawling Prowess Lv.2",
			L"Gauntlets", SL::DPLUS,
			SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS, PROWESSTYPE::GAUNTLETS,
			L"Grants Hit +6, Avoid +10 and Critical Evade +6 when brawling",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "6"), STATPACKAGE(STATTYPE::AVO, "10"), STATPACKAGE(STATTYPE::CRITAVO, "6")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Brawling Prowess Lv.3", 
			L"Gauntlets", SL::CPLUS, 
			SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS, PROWESSTYPE::GAUNTLETS,
			L"Grants Hit +7, Avoid +13 and Critical Evade +7 when brawling",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "7"), STATPACKAGE(STATTYPE::AVO, "13"), STATPACKAGE(STATTYPE::CRITAVO, "7")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Brawling Prowess Lv.4",
			L"Gauntlets", SL::BPLUS, 
			SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS, PROWESSTYPE::GAUNTLETS,
			L"Grants Hit +8, Avoid +16 and Critical Evade +8 when brawling", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "8"), STATPACKAGE(STATTYPE::AVO, "16"), STATPACKAGE(STATTYPE::CRITAVO, "8")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Brawling Prowess Lv.5", 
			L"Gauntlets", SL::APLUS, 
			SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS, PROWESSTYPE::GAUNTLETS,
			L"Grants Hit +10, Avoid +20 and Critical Evade +10 when brawling",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "10"), STATPACKAGE(STATTYPE::AVO, "20"), STATPACKAGE(STATTYPE::CRITAVO, "10")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Brawling Critical +10", 
			L"Gauntlets", SL::S, 
			SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS,
			L"Grants Crit +10 when brawling.", 
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::WCRIT, "10")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Fistfaire", 
			L"Gauntlets", SL::SPLUS, 
			SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS, 
			L"Might +5 when a gauntlet is equipped.",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::PMIGHT, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Reason Prowess Lv.1", 
			L"Reason", SL::EPLUS, 
			SKILLTYPE::REASON, (WEAPONTYPE)((int)WEAPONTYPE::BLACKMAGIC + (int)WEAPONTYPE::DARKMAGIC), PROWESSTYPE::REASON,
			L"Grants Hit +7, Avoid +5 and Critical Evade +5 when equipped with Reason Magic", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "7"), STATPACKAGE(STATTYPE::AVO, "5"), STATPACKAGE(STATTYPE::CRITAVO, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Reason Prowess Lv.2",
			L"Reason", SL::DPLUS, 
			SKILLTYPE::REASON, (WEAPONTYPE)((int)WEAPONTYPE::BLACKMAGIC + (int)WEAPONTYPE::DARKMAGIC), PROWESSTYPE::REASON,
			L"Grants Hit +10, Avoid +6 and Critical Evade +6 when equipped with Reason Magic",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "10"), STATPACKAGE(STATTYPE::AVO, "6"), STATPACKAGE(STATTYPE::CRITAVO, "6")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Reason Prowess Lv.3",
			L"Reason", SL::CPLUS, 
			SKILLTYPE::REASON, (WEAPONTYPE)((int)WEAPONTYPE::BLACKMAGIC + (int)WEAPONTYPE::DARKMAGIC), PROWESSTYPE::REASON,
			L"Grants Hit +13, Avoid +7 and Critical Evade +7 when equipped with Reason Magic", 
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "13"), STATPACKAGE(STATTYPE::AVO, "7"), STATPACKAGE(STATTYPE::CRITAVO, "7")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Reason Prowess Lv.4",
			L"Reason", SL::BPLUS, 
			SKILLTYPE::REASON, (WEAPONTYPE)((int)WEAPONTYPE::BLACKMAGIC + (int)WEAPONTYPE::DARKMAGIC), PROWESSTYPE::REASON,
			L"Grants Hit +16, Avoid +8 and Critical Evade +8 when equipped with Reason Magic", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "16"), STATPACKAGE(STATTYPE::AVO, "8"), STATPACKAGE(STATTYPE::CRITAVO, "8")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Reason Prowess Lv.5",
			L"Reason", SL::APLUS,
			SKILLTYPE::REASON, (WEAPONTYPE)((int)WEAPONTYPE::BLACKMAGIC + (int)WEAPONTYPE::DARKMAGIC), PROWESSTYPE::REASON,
			L"Grants Hit +20, Avoid +10 and Critical Evade +10 when equipped with Reason Magic",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "20"), STATPACKAGE(STATTYPE::AVO, "10"), STATPACKAGE(STATTYPE::CRITAVO, "10")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Black Magic Range +1",
			L"Reason", SL::S,
			SKILLTYPE::REASON, WEAPONTYPE::BLACKMAGIC, 
			L"Increases black magic range by 1.",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::RANGE, "1")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Dark Magic Range +1",
			L"Reason", SL::S,
			SKILLTYPE::REASON, WEAPONTYPE::DARKMAGIC, 
			L"Increases dark magic range by 1.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::RANGE, "1")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Black Tomefaire",
			L"Reason", SL::SPLUS,
			SKILLTYPE::REASON, WEAPONTYPE::BLACKMAGIC,
			L"Might +5 when Black Magic is equipped.",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::MMIGHT, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Dark Tomefaire", 
			L"Reason", SL::SPLUS, 
			SKILLTYPE::REASON, WEAPONTYPE::DARKMAGIC,
			L"Might +5 when Dark Magic is equipped.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::MMIGHT, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Faith Prowess Lv.1", 
			L"Faith", SL::EPLUS, 
			SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC, PROWESSTYPE::FAITH,
			L"Grants Hit +5, Avoid +7 and Critical Evade +5 when equipped with Faith Magic", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "5"), STATPACKAGE(STATTYPE::AVO, "7"), STATPACKAGE(STATTYPE::CRITAVO, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Faith Prowess Lv.2",
			L"Faith", SL::DPLUS,
			SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC, PROWESSTYPE::FAITH,
			L"Grants Hit +6, Avoid +10 and Critical Evade +6 when equipped with Faith Magic",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "6"), STATPACKAGE(STATTYPE::AVO, "10"), STATPACKAGE(STATTYPE::CRITAVO, "6")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Faith Prowess Lv.3",
			L"Faith", SL::CPLUS,
			SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC, PROWESSTYPE::FAITH,
			L"Grants Hit +7, Avoid +13 and Critical Evade +7 when equipped with Faith Magic",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "7"), STATPACKAGE(STATTYPE::AVO, "13"), STATPACKAGE(STATTYPE::CRITAVO, "7")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Faith Prowess Lv.4", 
			L"Faith", SL::BPLUS, 
			SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC, PROWESSTYPE::FAITH,
			L"Grants Hit +8, Avoid +16 and Critical Evade +8 when equipped with Faith Magic", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "8"), STATPACKAGE(STATTYPE::AVO, "16"), STATPACKAGE(STATTYPE::CRITAVO, "8")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Faith Prowess Lv.5", 
			L"Faith", SL::APLUS, 
			SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC, PROWESSTYPE::FAITH,
			L"Grants Hit +10, Avoid +20 and Critical Evade +10 when equipped with Faith Magic", 
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::HIT, "10"), STATPACKAGE(STATTYPE::AVO, "20"), STATPACKAGE(STATTYPE::CRITAVO, "10")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"White Magic Range +1", 
			L"Faith", SL::S,
			SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC, 
			L"Increases White Magic range by 1 for attacks that damage foes.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"White Tomefaire",
			L"Faith", SL::SPLUS,
			SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC,
			L"Might +5 when White Magic is equipped.",
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::MMIGHT, "5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Authority Prowess Lv.1",
			L"Authority", SL::EPLUS,
			SKILLTYPE::AUTHORITY, WEAPONTYPE::ALL, PROWESSTYPE::AUTHORITY,
			L"Grants Mt +2 with gambits.", 
			true, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::GMIGHT, "2")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Authority Prowess Lv.2",
			L"Authority", SL::DPLUS, 
			SKILLTYPE::AUTHORITY, WEAPONTYPE::ALL, PROWESSTYPE::AUTHORITY,
			L"Grants Mt +4 with gambits.",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::GMIGHT, "4")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Authority Prowess Lv.3",
			L"Authority", SL::CPLUS,
			SKILLTYPE::AUTHORITY, WEAPONTYPE::ALL, PROWESSTYPE::AUTHORITY,
			L"Grants Mt +6 with gambits.",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::GMIGHT, "6")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Authority Prowess Lv.4",
			L"Authority", SL::BPLUS,
			SKILLTYPE::AUTHORITY, WEAPONTYPE::ALL, PROWESSTYPE::AUTHORITY,
			L"Grants Mt +8 with gambits.",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::GMIGHT, "8")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralProwessAbility>(
			L"Authority Prowess Lv.5",
			L"Authority", SL::APLUS,
			SKILLTYPE::AUTHORITY, WEAPONTYPE::ALL, PROWESSTYPE::AUTHORITY,
			L"Grants Mt +10 with gambits.",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::GMIGHT, "10")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Defensive Tactics",
			L"Authority", SL::B,
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK,
			L"Battalion endurance takes half damage.",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Offensive Tactics",
			L"Authority", SL::SPLUS,
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK,
			L"Grants Mt +5 and Hit +20 with gambits.",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::GMIGHT, "5"), STATPACKAGE(STATTYPE::GHIT, "20")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Weight -3",
			L"Heavy Armor", SL::C,
			SKILLTYPE::HEAVYARMOR, WEAPONTYPE::BLANK,
			L"The combined weight of equipment is reduced by 3.",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::WEIGHT, "-3")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Weight -5",
			L"Heavy Armor", SL::APLUS,
			SKILLTYPE::HEAVYARMOR, WEAPONTYPE::BLANK,
			L"The combined weight of equipment is reduced by 5.",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::WEIGHT, "-5")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Armored Effect Null",
			L"Heavy Armor", SL::SPLUS,
			SKILLTYPE::HEAVYARMOR, WEAPONTYPE::BLANK,
			L"Nullifies any extra effectiveness against armored units.",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Dexterity +4",
			L"Riding", SL::C,
			SKILLTYPE::RIDING, WEAPONTYPE::BLANK,
			L"Increases Dex by 4.",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::DEX, "4")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Movement +1",
			L"Riding", SL::APLUS,
			SKILLTYPE::RIDING, WEAPONTYPE::BLANK,
			L"Increases Mv by 1.",
			true,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::MOV, "1")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Cavalry Effect Null",
			L"Riding", SL::SPLUS,
			SKILLTYPE::RIDING, WEAPONTYPE::BLANK,
			L"Nullifies any extra effectiveness against cavalry units.",
			false, std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Alert Stance",
			L"Flying", SL::B,
			SKILLTYPE::FLYING, WEAPONTYPE::BLANK,
			L"If unit takes no action except Wait, grants Avo +15 for 1 turn.",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Alert Stance+",
			L"Flying", SL::APLUS,
			SKILLTYPE::FLYING, WEAPONTYPE::BLANK,
			L"If unit takes no action except Wait, grants Avo +30 for 1 turn.",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelGeneralAbility>(
			L"Flying Effect Null",
			L"Flying", SL::SPLUS,
			SKILLTYPE::FLYING, WEAPONTYPE::BLANK,
			L"Nullifies any extra effectiveness against flying units.",
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));



		///////////////////////////////////////////////////////////////////////////
		////SKILLLEVELCHARACTERABILITY//////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////
		list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(
			L"Rally Magic", 
			L"Authority", 
			std::vector<CHARSLPACKAGE>{CHARSLPACKAGE(SL::D, L"Hubert"), CHARSLPACKAGE(SL::D, L"Ingrid"), CHARSLPACKAGE(SL::D, L"Constance")}, 
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, 
			L"Use Rally to grant Mag +4 to an ally.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(
			L"Rally Charm", 
			L"Authority",
			std::vector<CHARSLPACKAGE>{CHARSLPACKAGE(SL::S, L"Edelgard"), CHARSLPACKAGE(SL::D, L"Dorothea"), CHARSLPACKAGE(SL::S, L"Dimitri"), CHARSLPACKAGE(SL::S, L"Claude"), CHARSLPACKAGE(SL::D, L"Manuela")}, 
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK,
			L"Use Rally to grant Cha +8 to an ally.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(
			L"Rally Dexterity",
			L"Authority", 
			std::vector<CHARSLPACKAGE>{CHARSLPACKAGE(SL::D, L"Ferdinand"), CHARSLPACKAGE(SL::CPLUS, L"Ignatz"), CHARSLPACKAGE(SL::D, L"Hapi")}, 
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK,
			L"Use Rally to grant Dex +8 to an ally.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(
			L"Rally Resistance",
			L"Authority",
			std::vector<CHARSLPACKAGE>{CHARSLPACKAGE(SL::CPLUS, L"Hubert"), CHARSLPACKAGE(SL::D, L"Annette"), CHARSLPACKAGE(SL::S, L"Seleth"), CHARSLPACKAGE(SL::C, L"Constance")}, 
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK,
			L"Use Rally to grant Res +4 to an ally.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(
			L"Rally Strength", 
			L"Authority",
			std::vector<CHARSLPACKAGE>{CHARSLPACKAGE(SL::D, L"Raphael"), CHARSLPACKAGE(SL::S, L"Ignatz"), CHARSLPACKAGE(SL::D, L"Alois"), CHARSLPACKAGE(SL::D, L"Balthus")}, 
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, 
			L"Use Rally to grant Str +4 to an ally.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(
			L"Rally Speed",
			L"Authority",
			std::vector<CHARSLPACKAGE>{CHARSLPACKAGE(SL::S, L"Hubert"), CHARSLPACKAGE(SL::CPLUS, L"Annette"), CHARSLPACKAGE(SL::D, L"Ignatz")}, 
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, 
			L"Use Rally to grant Spd +4 to an ally.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		//list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(L"Rally Defense", L"Authority", std::vector<CHARSLPACKAGE>{std}, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Use Rally to grant Def +4 to an ally.", false, std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(
			L"Rally Luck",
			L"Authority",
			std::vector<CHARSLPACKAGE>{CHARSLPACKAGE(SL::D, L"Flayn"), CHARSLPACKAGE(SL::D, L"Anna")},
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK,
			L"Use Rally to grant Lck +8 to an ally.", 
			false,
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(
			L"Battalion Vantage",
			L"Authority", 
			std::vector<CHARSLPACKAGE>{CHARSLPACKAGE(SL::C, L"Byleth"), CHARSLPACKAGE(SL::C, L"Edelgard"), CHARSLPACKAGE(SL::A, L"Dimitri"), CHARSLPACKAGE(SL::C, L"Felix"), CHARSLPACKAGE(SL::C, L"Sylvain"), 
										CHARSLPACKAGE(SL::C, L"Lorenz"), CHARSLPACKAGE(SL::A, L"Ignatz"), CHARSLPACKAGE(SL::C, L"Catherine"), CHARSLPACKAGE(SL::C, L"Yuri"), CHARSLPACKAGE(SL::C, L"Anna")}, 
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, 
			L"When foe initiates combat, unit still attacks first if battalion endurance is ≤ 1/3.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(
			L"Battalion Wrath", 
			L"Authority",
			std::vector<CHARSLPACKAGE>{CHARSLPACKAGE(SL::C, L"Hubert"), CHARSLPACKAGE(SL::C, L"Bernadetta"), CHARSLPACKAGE(SL::C, L"Caspar"), CHARSLPACKAGE(SL::C, L"Petra"), CHARSLPACKAGE(SL::C, L"Dimitri"),
										CHARSLPACKAGE(SL::C, L"Dedue"), CHARSLPACKAGE(SL::A, L"Annette"), CHARSLPACKAGE(SL::A, L"Claude"), CHARSLPACKAGE(SL::C, L"Hilda"), CHARSLPACKAGE(SL::C, L"Raphael"), 
										CHARSLPACKAGE(SL::C, L"Seleth"), CHARSLPACKAGE(SL::C, L"Alois"), CHARSLPACKAGE(SL::C, L"Gilbert"), CHARSLPACKAGE(SL::C, L"Hapi"), CHARSLPACKAGE(SL::C, L"Jeritza")}, 
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, 
			L"If foe initiates combat while unit’s battalion endurance is ≤ 1/3, grants Crit +50.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(
			L"Battalion Desperation",
			L"Authority",
			std::vector<CHARSLPACKAGE>{CHARSLPACKAGE(SL::A, L"Byleth"), CHARSLPACKAGE(SL::A, L"Hubert"), CHARSLPACKAGE(SL::C, L"Dorothea"), CHARSLPACKAGE(SL::C, L"Ferdinand"), CHARSLPACKAGE(SL::C, L"Ashe"), 
										CHARSLPACKAGE(SL::C, L"Ingrid"), CHARSLPACKAGE(SL::C, L"Claude"), CHARSLPACKAGE(SL::C, L"Lysithea"), CHARSLPACKAGE(SL::C, L"Ignatz"), CHARSLPACKAGE(SL::C, L"Leonie"),
										CHARSLPACKAGE(SL::C, L"Hannemann"), CHARSLPACKAGE(SL::A, L"Seleth"), CHARSLPACKAGE(SL::C, L"Cyril"), CHARSLPACKAGE(SL::C, L"Shamir"), CHARSLPACKAGE(SL::B, L"Balthus"), 
										CHARSLPACKAGE(SL::B, L"Jeritza")}, 
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK,
			L"If unit initiates combat when battalion endurance is ≤ 1/3, unit’s follow-up attack (if possible) occurs before foe’s counterattack.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(
			L"Battalion Renewal", 
			L"Authority",
			std::vector<CHARSLPACKAGE>{CHARSLPACKAGE(SL::A, L"Edelgard"), CHARSLPACKAGE(SL::C, L"Linhardt"), CHARSLPACKAGE(SL::C, L"Mercedes"),	CHARSLPACKAGE(SL::C, L"Annette"), CHARSLPACKAGE(SL::C, L"Marianne"), 
										CHARSLPACKAGE(SL::C, L"Manuela"), CHARSLPACKAGE(SL::C, L"Flayn")}, 
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, 
			L"Unit recovers up to 30% of max HP at the start of each turn while battalion endurance is ≤ 1/3.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(
			L"Model Leader",
			L"Authority", 
			std::vector<CHARSLPACKAGE>{CHARSLPACKAGE(SL::CPLUS, L"Byleth"), CHARSLPACKAGE(SL::CPLUS, L"Edelgard"), CHARSLPACKAGE(SL::CPLUS, L"Dimitri"), CHARSLPACKAGE(SL::CPLUS, L"Claude"), CHARSLPACKAGE(SL::CPLUS, L"Seleth"), 
										CHARSLPACKAGE(SL::CPLUS, L"Yuri")},
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, 
			L"Doubles experience earned for battalions.", 
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));
		list.emplace_back(std::make_unique<SkillLevelCharacterAbility>(
			L"Rally Movement", 
			L"Authority",
			std::vector<CHARSLPACKAGE>{CHARSLPACKAGE(SL::S, L"Byleth"), CHARSLPACKAGE(SL::S, L"Annette")},
			SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK,
			L"Use Rally to grant Mv +1 to an ally.",
			false, 
			std::vector<STATPACKAGE> {STATPACKAGE(STATTYPE::BLANK, "")}));



		///////////////////////////////////////////////////////////////////////////
		////CLASSMASTERYABILITY//////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"HP +5", 
			L"Noble,Commoner", 
			L"Increases HP by 5", 
			true, 
			std::vector<STATPACKAGE>{STATPACKAGE(STATTYPE::HP, "5")}));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Speed +2", 
			L"Myrmidon", 
			L"Increases Spd by 2",
			true,
			std::vector<STATPACKAGE>{STATPACKAGE(STATTYPE::SPD, "2")}));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Defense +2",
			L"Soldier",
			L"Increases Def by 2",
			true, 
			std::vector<STATPACKAGE>{STATPACKAGE(STATTYPE::DEF, "2")}));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Strength +2", 
			L"Fighter", 
			L"Increases Str by 2",
			true, 
			std::vector<STATPACKAGE>{STATPACKAGE(STATTYPE::STR, "2")}));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Magic +2", 
			L"Monk", 
			L"Increases Mag by 2", 
			true, 
			std::vector<STATPACKAGE>{STATPACKAGE(STATTYPE::MAG, "2")}));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Resistance +2"
			, L"Lord", 
			L"Increases Res by 2",
			true, 
			std::vector<STATPACKAGE>{STATPACKAGE(STATTYPE::RES, "2")}));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Vantage",
			L"Mercenary",
			L"Always attack first when under 50% HP.",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Steal", 
			L"Thief", 
			L"Unit can steal non-weapon items from enemies with lower Spd than self.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Desperation", 
			L"Cavalier", 
			L"If unit initiates combat with HP ≤ 50%, unit’s follow-up attack (if possible) occurs before foe’s counterattack.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Darting Blow",
			L"Pegasus Knight", 
			L"If unit initiates combat, grants AS +6 during combat.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Death Blow",
			L"Brigand", 
			L"If unit initiates combat, grants Str +6 during combat.",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Armored Blow", 
			L"Armored Knight",
			L"If unit initiates combat, grants Def +6 during combat.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Hit +20",
			L"Archer",
			L"Increases Hit by 20.",
			true,
			std::vector<STATPACKAGE>{STATPACKAGE(STATTYPE::HIT, "20")}));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Unarmed Combat", 
			L"Brawler", 
			L"User can fight without a weapon equipped.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Fiendish Blow", 
			L"Mage", 
			L"If unit initiates combat, grants Mag+6 during combat", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Poison Strike",
			L"Dark Mage", 
			L"If unit initiates combat, enemy loses up to 20% HP",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Miracle", 
			L"Priest", 
			L"Luck % chance to survive lethal damage with 1HP if HP is above 1", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Special Dance",
			L"Dancer",
			L"Dex/Spd/Luck +4 to target ally when using Dance", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Pomp & Circumstance", 
			L"Armored Lord,High Lord,Wyvern Master", 
			L"Increases Lck/Cha by 4.", 
			true, 
			std::vector<STATPACKAGE>{STATPACKAGE(STATTYPE::LCK, "4"), STATPACKAGE(STATTYPE::CHA, "2")}));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Sacred Power",
			L"Enlightened One",
			L"Adjacent allies deal 3 extra damage and take 3 less damage during combat.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Defiant Strength",
			L"Hero",
			L"Grants Str +8 when HP is ≤ 25%.",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Lethality", 
			L"Assassin", 
			L"Chance to instantly kill a foe when dealing damage. Trigger % = 0.25×Dex.",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Aegis", 
			L"Paladin", 
			L"Chance to reduce bow/magic damage by half. Trigger % = Dex stat.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Wrath", 
			L"Warrior",
			L"If foe initiates combat while unit’s HP is ≤ 50%, grants Crit +50.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Pavise", 
			L"Fortress Knight", 
			L"Chance to reduce sword/lance/axe/brawling damage by half. Trigger % = Dex stat.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Seal Defense", 
			L"Wyvern Rider",
			L"If unit damages foe during combat, foe suffers Def -6 for 1 turn after combat.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Tomebreaker",
			L"Grappler",
			L"Grants Hit/Avo +20 when brawling against magic users.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Bowbreaker", 
			L"Warlock", 
			L"Grants Hit/Avo +20 when using magic against bow users.",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Lifetaker", 
			L"Dark Bishop", 
			L"Unit recovers HP equal to 50% of damage dealt after defeating a foe.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Renewal",
			L"Bishop", 
			L"Unit recovers up to 20% of max HP at the start of each turn.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Warding Blow", 
			L"Mortal Savant", 
			L"If unit initiates combat, grants Res +6 during combat",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Defiant Avoid", 
			L"Falcon Knight", 
			L"Grants Avo +30 when HP is ≤ 25%.",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Quick Riposte", 
			L"War Master", 
			L"If foe initiates combat while unit’s HP is ≥ 50%, unit makes guaranteed follow-up attack.",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Defiant Critical", 
			L"Wyvern Lord", 
			L"Grants Crit +50 when HP is ≤ 25%.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Defiant Defense",
			L"Great Knight",
			L"Grants Def +8 when HP is ≤ 25%.",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Defiant Speed",
			L"Bow Knight",
			L"Grants Spd +8 when HP is ≤ 25%.",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Defiant Magic",
			L"Gremory", 
			L"Grants Mag +8 when HP is ≤ 25%.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Seal Resistance", 
			L"Dark Knight", 
			L"If unit damages foe during combat, foe suffers Res -6 for 1 turn after combat.",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Defiant Resistance",
			L"Holy Knight", 
			L"Grants Res +8 when HP is ≤ 25%.",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Counterattack", 
			L"Death Knight", 
			L"Counters attacks regardless of enemies' range.",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Duelist's Blow",
			L"Trickster",
			L"If unit initiates combat, grants Avo +20 during combat",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Brawl Avo +20", 
			L"War Monk,Cleric",
			L"Grants Avo +20 when brawling.", 
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Transmute",
			L"Dark Flier", 
			L"If unit is hit with a magic attack during enemy phase, grants +3 to all stats until next player phase ends.",
			false));
		list.emplace_back(std::make_unique<ClassMasteryAbility>(
			L"Uncanny Blow",
			L"Valkyrie",
			L"If unit initiates combat, grants Hit +30 during combat", 
			false));
	}
	~AbilityList() { list.clear(); }

	UINT getSize() const { return list.size(); }
	Ability* operator[](UINT index) const;
	std::vector<std::unique_ptr<Ability>>::iterator begin() { return list.begin(); }
	std::vector<std::unique_ptr<Ability>>::iterator end() { return list.end(); }
};

#endif
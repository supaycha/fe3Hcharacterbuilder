#ifndef ABILITYLIST_H
#define ABILITYLIST_H

#include <wx/wx.h>
#include <Unit/Ability/Ability.h>
#include <Unit/Ability/BlankAbility.h>
#include <Unit/Ability/CharacterInnateAbility.h>
#include <Unit/Ability/ClassInnateAbility.h>
#include <Unit/Ability/SkillLevelAbility.h>
#include <Unit/Ability/ClassMasteryAbility.h>
#include "constants.h"
//#include <vld.h>

//
class AbilityList {
private:
	std::vector<std::unique_ptr<Ability>> list;

public:
	AbilityList() {
		//list.emplace_back(std::make_unique<CharacterInnateAbility>(L"---", L"---", L"---", true, STATTYPE::BLANK, L"---"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Professor's Guidance", L"Byleth", L"+20% Experience Gained to user and adjacent ally", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Imperial Lineage", L"Edelgard", L"+20% Experience Gained", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Royal Lineage", L"Dimitri", L"+20% Experience Gained", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Leicester Lineage", L"Claude", L"+20% Experience Gained", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Officer Duty", L"Hubert", L"Boosts Gambit Might by 5.", false, STATTYPE::GMIGHT, "5"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Songstress", L"Dorothea", L"At the start of each turn, restores adjacent allies’ HP by 10%.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Confidence", L"Ferdinand", L"When HP is full, unit gains +15 Hit and Avoid", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Persecution Complex", L"Bernadetta", L"When HP is not full, unit gains +5 Damage", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Born Fighter", L"Caspar", L"Adjacent foes receive Avoid -10 during combat.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Catnap", L"Linhardt", L"If unit waits without performing an action, restores 10% HP.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Hunter's Boon", L"Petra", L"When foe has less than 50% HP, Critical rate +20", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Live to Serve", L"Mercedes", L"When healing allies with White Magic, unit is healed by the same amount", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Staunch Shield", L"Dedue", L"If user waits without acting, Defense +4 for one turn.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Lone Wolf", L"Felix", L"When a Battalion is not deployed or when battalion health is zero, damage dealt +5", true, true, false, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Lockpick", L"Ashe", L"Unit can open locks and chests without keys", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Perseverance", L"Annette", L"When Rally command is used on ally, grants Strength +4.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Philanderer", L"Sylvain", L"When adjacent to a female ally, damage dealt to foe +2, damage received from foe -2.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Lady Knight", L"Ingrid", L"When using a Gambit, Might +3 and Hit Rate +5.", true, true, true, STATTYPE::GMIGHT, "3", STATTYPE::GHIT, "5"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Distinguished House", L"Lorenz", L"When a battalion is deployed, damage dealt +2", true, true, true, STATTYPE::MIGHT, "2"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Advocate", L"Hilda", L"When an adjacent male ally enters battle, ally’s damage dealt +3", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Goody Basket", L"Raphael", L"At the start of a turn, unit has Luck% chance of regaining 10% of HP", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Mastermind", L"Lysithea", L"Unit gains 2x skill EXP from combat", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Watchful Eye", L"Ignatz", L"Hit rate +20.", true, STATTYPE::HIT, "20"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Animal Friend", L"Marianne", L"When adjacent to a horseback or flying ally, restores 20% HP at the start of the turn.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Rivalry", L"Leonie", L"When adjacent to a male ally, damage dealt to foe +2, damage received from foe -2.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Infirmary Master", L"Manuela", L"Adjacent allies gain Crit Avoid +10 during combat", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Crest Scholar", L"Hanneman", L"Use Rally to grant Mag +4 to an ally", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Fighting Spirit", L"Catherine", L"Unit takes 5 less damage when no battalion is assigned or when battalion endurance is 0.", true, true, false, STATTYPE::PROT, "-5"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Compassion", L"Alois", L"Use Rally to grant Lck +8 to an ally.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Guardian", L"Seteth", L"Adjacent female allies deal 3 extra damage during combat", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Lily's Poise", L"Flayn", L"Adjacent allies take 3 less damage during combat.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Veteran Knight", L"Gilbert", L"Unit takes 2 less damage while in formation with a battalion.", true, true, true, STATTYPE::PROT, "-2"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Survival Instinct", L"Shamir", L"If unit initiates combat and defeats foe, grants Str/Mag/Dex/Spd +4 for one turn.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Aptitude", L"Cyril", L"Makes each stat 20% more likely to increase on level up.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Murderous Intent", L"Jeritza", L"If unit initiates combat, grants Hit +20 during combat.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Business Prosperity", L"Anna", L"Grants Lck +5.", true, STATTYPE::LCK, "5"));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Honorable Spirit", L"Yuri", L"If unit is not near an ally, grants Atk +3 when in combat with a foe one space away.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Circadian Beat", L"Constance", L"Grants Str/Mag +3 when indoors and Def/Res +3 when outdoors.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"King of Grappling", L"Balthus", L"Grants Str/Def +6 when HP ≤ 50%.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<CharacterInnateAbility>(L"Monstrous Appeal", L"Hapi", L"Makes all attacks effective against monsters and makes it easier for monsters to target unit.", false, STATTYPE::BLANK, ""));
		//list.emplace_back(std::make_unique<ClassInnateAbility>(L"---", L"---", L"---", true, STATTYPE::BLANK, L"---"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Charm", L"Lord,Wyvern Master,Barbarossa,Armored Lord,High Lord,Emperor,Great Lord", L"When allies adjacent to unit enter combat, allies gain +3 Damage.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Canto", L"Cavalier,Pegasus Knight,Barbarossa,Paladin,Wyvern Rider,Wyvern Master,Death Knight,Dark Flier,Valkyrie,Falcon Knight,Wyvern Lord,Great Knight,Bow Knight,Dark Knight,Holy Knight", L"After performing an action, user can use their leftover movement.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Unarmed", L"Brawler,Grappler,War Monk/Cleric", L"User can fight without a weapon equipped.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Fire", L"Mage", L"Enables the use of Fire. If already learned, doubles the number of uses.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Miasma", L"Dark Mage,Dark Bishop", L"Enables the use of Miasma Δ. If already learned, doubles the number of uses.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Heartseeker", L"Dark Mage,Dark Bishop", L"Reduces Avoid of adjacent foes by 20.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Steal", L"Thief", L"Unit can steal non-weapon items from enemies with lower Spd than self.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Locktouch", L"Thief,Assassin,Trickster", L"Unit can open locks and chests without keys.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Avoid +10", L"Pegasus Knight,Falcon Knight,Wyvern Lord", L"Increases Avoid by 10.", true, STATTYPE::AVO, "10"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Bowrange +1", L"Archer,Sniper", L"Increases range of Bows by 1.", true, STATTYPE::RANGE, "1"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Bowrange +2", L"Bow Knight", L"Increases range of Bows by 2.", true, STATTYPE::RANGE, "2"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Heal", L"Priest,War Monk/Cleric", L"Unit can use Heal. If it has already been learnt, the number of times it can be used is doubled.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"White Magic Heal +5", L"Priest", L"White Magic heals +5 more HP.", true, STATTYPE::HEAL, "5"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"White Magic Heal +10", L"Bishop", L"White Magic heals +10 more HP.", true, STATTYPE::HEAL, "10"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Swordfaire", L"Hero,Swordmaster,Assassin,Mortal Savant,Enlighted One", L"Might +5 when a sword is equipped.", false, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Axefaire", L"Fortress Knight,Warrior,Wyvern Rider,Wyvern Lord,Great Knight,War Master,Armored Lord,Emperor", L"Might +5 when a axe is equipped.", false, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Lancefaire", L"Paladin,Death Knight,Falcon Knight,Great Knight,High Lord,Great Lord", L"Might +5 when a lance is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Bowfaire", L"Sniper,Wyvern Master,Barbarossa,Bow Knight", L"Might +5 when a bow is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Fistfaire", L"Grappler,War Monk/Cleric,War Master", L"Might +5 when a gaunlet is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Black Tomefaire", L"Warlock,Dark Knight,Dark Flier,Mortal Savant", L"Might +5 when Black Magic is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Dark Tomefaire", L"Dark Knight", L"Might +5 when Dark Magic is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"White Tomefaire", L"Holy Knight", L"Might +5 when White Magic is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Vantage", L"Hero", L"Always attack first when under 50% HP.﻿", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Weight -5", L"Fortress Knight", L"The combined weight of equipment is reduced by 5.", true, STATTYPE::WEIGHT, "-5"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Terrain Resistance", L"Paladin,Bishop,Holy Knight,Enlightened One", L"Unit does not receive terrain damage.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Black Magic Uses x2", L"Warlock,Gremory", L"Doubles the number of uses of Black Magic spells.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Dark Magic Uses x2", L"Gremory", L"Doubles the number of uses of Dark Magic spells.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"White Magic Uses x2", L"Bishop,Gremory", L"Doubles the number of uses of White Magic spells.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Sword Critical +10", L"Swordmaster", L"Critical +10 when equipped with a sword.", true, STATTYPE::TCRIT, "10"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Stealth", L"Assassin,Trickster", L"Unit is less likely to be targeted by enemies.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Axe Critical +10", L"Warrior", L"Critical +20", true, STATTYPE::CRIT, "20"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Critical +20", L"War Master", L"Might +5 when a axe is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Fiendish Blow", L"Dark Bishop", L"Mag +6 when initiating attack.", true, STATTYPE::MIGHT, "6"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Lucky Sevem", L"Trickster", L"Each turn, grants +5 to one of the following stats: Str, Mag, Spd, Def, Res, Hit or Avo.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Transmute", L"Dark Flier", L"If unit is hit with a magic attack during enemy phase, grants +3 to all stats until next player phase ends.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Black Magic Range +1", L"Valkyrie", L"Increases black magic range by 1.", true, STATTYPE::RANGE, "1"));
		list.emplace_back(std::make_unique<ClassInnateAbility>(L"Dark Magic Range +1", L"Valkyrie", L"Increases dark magic range by 1.", true, STATTYPE::RANGE, "1"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"---", L"---", SL::BLANK, SKILLTYPE::BLANK, WEAPONTYPE::BLANK, L"---", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Sword Prowess Lv. 1", L"Sword", SL::EPLUS, SKILLTYPE::SWORD, WEAPONTYPE::SWORD, L"Grants Hit +5, Avoid +7 and Critical Evade +5 when equipped with Sword", true, STATTYPE::HIT, "5", STATTYPE::AVO, "7", STATTYPE::CRITAVO, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Sword Prowess Lv. 2", L"Sword", SL::DPLUS, SKILLTYPE::SWORD, WEAPONTYPE::SWORD, L"Grants Hit +6, Avoid +10 and Critical Evade +6 when equipped with Sword", true, STATTYPE::HIT, "6", STATTYPE::AVO, "10", STATTYPE::CRITAVO, "6"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Sword Prowess Lv. 3", L"Sword", SL::CPLUS, SKILLTYPE::SWORD, WEAPONTYPE::SWORD, L"Grants Hit +7, Avoid +13 and Critical Evade +7 when equipped with Sword", true, STATTYPE::HIT, "7", STATTYPE::AVO, "13", STATTYPE::CRITAVO, "7"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axebreaker", L"Sword", SL::B, SKILLTYPE::SWORD, WEAPONTYPE::SWORD, L"Grants Hit/Avo +20 when using a sword against axe users.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Sword Prowess Lv.4", L"Sword", SL::BPLUS, SKILLTYPE::SWORD, WEAPONTYPE::SWORD, L"Grants Hit +8, Avoid +16 and Critical Evade +8 when equipped with Sword", true, STATTYPE::HIT, "8", STATTYPE::AVO, "16", STATTYPE::CRITAVO, "8"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Sword Prowess Lv.5", L"Sword", SL::APLUS, SKILLTYPE::SWORD, WEAPONTYPE::SWORD, L"Grants Hit +10, Avoid +20 and Critical Evade +10 when equipped with Sword", true, STATTYPE::HIT, "10", STATTYPE::AVO, "20", STATTYPE::CRITAVO, "10"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Sword Critical +10", L"Sword", SL::S, SKILLTYPE::SWORD, WEAPONTYPE::SWORD, L"Grants Crit +10 when using a sword.", true, STATTYPE::CRIT, "10"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Swordfaire", L"Sword", SL::SPLUS, SKILLTYPE::SWORD, WEAPONTYPE::SWORD, L"Might +5 when a sword is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lance Prowess Lv.1", L"Lance", SL::EPLUS, SKILLTYPE::LANCE, WEAPONTYPE::LANCE, L"Grants Hit +6, Avoid +6 and Critical Evade +5 when equipped with Lance", true, STATTYPE::HIT, "6", STATTYPE::AVO, "6", STATTYPE::CRITAVO, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lance Prowess Lv.2", L"Lance", SL::DPLUS, SKILLTYPE::LANCE, WEAPONTYPE::LANCE, L"Grants Hit +8, Avoid +8 and Critical Evade +6 when equipped with Lance", true, STATTYPE::HIT, "8", STATTYPE::AVO, "8", STATTYPE::CRITAVO, "6"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lance Prowess Lv.3", L"Lance", SL::CPLUS, SKILLTYPE::LANCE, WEAPONTYPE::LANCE, L"Grants Hit +10, Avoid +10 and Critical Evade +7 when equipped with Lance", true, STATTYPE::HIT, "10", STATTYPE::AVO, "10", STATTYPE::CRITAVO, "7"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Swordbreaker", L"Lance", SL::B, SKILLTYPE::LANCE, WEAPONTYPE::LANCE, L"Grants Hit/Avo +20 when using a lance against sword users.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lance Prowess Lv.4", L"Lance", SL::BPLUS, SKILLTYPE::LANCE, WEAPONTYPE::LANCE, L"Grants Hit +12, Avoid +12 and Critical Evade +8 when equipped with Lance", true, STATTYPE::HIT, "12", STATTYPE::AVO, "12", STATTYPE::CRITAVO, "8"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lance Prowess Lv.5", L"Lance", SL::APLUS, SKILLTYPE::LANCE, WEAPONTYPE::LANCE, L"Grants Hit +15, Avoid +15 and Critical Evade +10 when equipped with Lance", true, STATTYPE::HIT, "15", STATTYPE::AVO, "15", STATTYPE::CRITAVO, "10"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lance Critical +10", L"Lance", SL::S, SKILLTYPE::LANCE, WEAPONTYPE::LANCE, L"Grants Crit +10 when using a lance.", true, STATTYPE::CRIT, "10"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lancefaire", L"Lance", SL::SPLUS, SKILLTYPE::LANCE, WEAPONTYPE::LANCE, L"Might +5 when a lance is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axe Prowess Lv.1", L"Axe", SL::EPLUS, SKILLTYPE::AXE, WEAPONTYPE::AXE, L"Grants Hit +7, Avoid +5 and Critical Evade +5 when equipped with Axe", true, STATTYPE::HIT, "7", STATTYPE::AVO, "5", STATTYPE::CRITAVO, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axe Prowess Lv.2", L"Axe", SL::DPLUS, SKILLTYPE::AXE, WEAPONTYPE::AXE, L"Grants Hit +10, Avoid +6 and Critical Evade +6 when equipped with Axe", true, STATTYPE::HIT, "10", STATTYPE::AVO, "6", STATTYPE::CRITAVO, "6"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axe Prowess Lv.3", L"Axe", SL::CPLUS, SKILLTYPE::AXE, WEAPONTYPE::AXE, L"Grants Hit +13, Avoid +7 and Critical Evade +7 when equipped with Axe", true, STATTYPE::HIT, "13", STATTYPE::AVO, "7", STATTYPE::CRITAVO, "7"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Lancebreaker", L"Axe", SL::B, SKILLTYPE::AXE, WEAPONTYPE::AXE, L"Grants Hit/Avo +20 when using an axe against lance users.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axe Prowess Lv.4", L"Axe", SL::BPLUS, SKILLTYPE::AXE, WEAPONTYPE::AXE, L"Grants Hit +16, Avoid +8 and Critical Evade +8 when equipped with Axe", true, STATTYPE::HIT, "16", STATTYPE::AVO, "8", STATTYPE::CRITAVO, "8"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axe Prowess Lv.5", L"Axe", SL::APLUS, SKILLTYPE::AXE, WEAPONTYPE::AXE, L"Grants Hit +20, Avoid +10 and Critical Evade +10 when equipped with Axe", true, STATTYPE::HIT, "20", STATTYPE::AVO, "10", STATTYPE::CRITAVO, "10"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axe Critical +10", L"Axe", SL::S, SKILLTYPE::AXE, WEAPONTYPE::AXE, L"Grants Crit +10 when using an axe.", true, STATTYPE::CRIT, "10"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Axefaire", L"Axe", SL::SPLUS, SKILLTYPE::AXE, WEAPONTYPE::AXE, L"Might +5 when an axe is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bow Prowess Lv.1", L"Bow", SL::EPLUS, SKILLTYPE::BOW, WEAPONTYPE::BOW, L"Grants Hit +6, Avoid +6 and Critical Evade +5 when equipped with Bow", true, STATTYPE::HIT, "6", STATTYPE::AVO, "6", STATTYPE::CRITAVO, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bow Prowess Lv.2", L"Bow", SL::DPLUS, SKILLTYPE::BOW, WEAPONTYPE::BOW, L"Grants Hit +8, Avoid +8 and Critical Evade +6 when equipped with Bow", true, STATTYPE::HIT, "8", STATTYPE::AVO, "8", STATTYPE::CRITAVO, "6"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Close Counter", L"Bow", SL::C, SKILLTYPE::BOW, WEAPONTYPE::BOW, L"Allows unit to counterattack adjacent foes.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bow Prowess Lv.3", L"Bow", SL::CPLUS, SKILLTYPE::BOW, WEAPONTYPE::BOW, L"Grants Hit +10, Avoid +10 and Critical Evade +7 when equipped with Bow", true, STATTYPE::HIT, "10", STATTYPE::AVO, "10", STATTYPE::CRITAVO, "7"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bow Prowess Lv.4", L"Bow", SL::BPLUS, SKILLTYPE::BOW, WEAPONTYPE::BOW, L"Grants Hit +12, Avoid +12 and Critical Evade +8 when equipped with Bow", true, STATTYPE::HIT, "12", STATTYPE::AVO, "12", STATTYPE::CRITAVO, "8"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bow Prowess Lv.5", L"Bow", SL::APLUS, SKILLTYPE::BOW, WEAPONTYPE::BOW, L"Grants Hit +15, Avoid +15 and Critical Evade +10 when equipped with Bow", true, STATTYPE::HIT, "15", STATTYPE::AVO, "15", STATTYPE::CRITAVO, "10"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bow Critical +10", L"Bow", SL::S, SKILLTYPE::BOW, WEAPONTYPE::BOW, L"Grants Crit +10 when using a bow.", true, STATTYPE::CRIT, "10"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Bowfaire", L"Bow", SL::SPLUS, SKILLTYPE::BOW, WEAPONTYPE::BOW, L"Might +5 when a bow is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Brawling Prowess Lv.1", L"Gauntlets", SL::EPLUS, SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS, L"Grants Hit +5, Avoid +7 and Critical Evade +5 when brawling.", true, STATTYPE::HIT, "5", STATTYPE::AVO, "7", STATTYPE::CRITAVO, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Brawling Prowess Lv.2", L"Gauntlets", SL::DPLUS, SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS, L"Grants Hit +6, Avoid +10 and Critical Evade +6 when brawling", true, STATTYPE::HIT, "6", STATTYPE::AVO, "10", STATTYPE::CRITAVO, "6"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Brawling Prowess Lv.3", L"Gauntlets", SL::CPLUS, SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS, L"Grants Hit +7, Avoid +13 and Critical Evade +7 when brawling", true, STATTYPE::HIT, "7", STATTYPE::AVO, "13", STATTYPE::CRITAVO, "7"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Brawling Prowess Lv.4", L"Gauntlets", SL::BPLUS, SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS, L"Grants Hit +8, Avoid +16 and Critical Evade +8 when brawling", true, STATTYPE::HIT, "8", STATTYPE::AVO, "16", STATTYPE::CRITAVO, "8"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Brawling Prowess Lv.5", L"Gauntlets", SL::APLUS, SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS, L"Grants Hit +10, Avoid +20 and Critical Evade +10 when brawling", true, STATTYPE::HIT, "10", STATTYPE::AVO, "20", STATTYPE::CRITAVO, "10"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Brawling Critical +10", L"Gauntlets", SL::S, SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS, L"Grants Crit +10 when brawling.", true, STATTYPE::CRIT, "10"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Fistfaire", L"Gauntlets", SL::SPLUS, SKILLTYPE::GAUNTLETS, WEAPONTYPE::GAUNTLETS, L"Might +5 when a gauntlet is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Reason Prowess Lv.1", L"Reason", SL::EPLUS, SKILLTYPE::REASON, (WEAPONTYPE)((int)WEAPONTYPE::BLACKMAGIC + (int)WEAPONTYPE::DARKMAGIC), L"Grants Hit +7, Avoid +5 and Critical Evade +5 when equipped with Reason Magic", true, STATTYPE::HIT, "7", STATTYPE::AVO, "5", STATTYPE::CRITAVO, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Reason Prowess Lv.2", L"Reason", SL::DPLUS, SKILLTYPE::REASON, (WEAPONTYPE)((int)WEAPONTYPE::BLACKMAGIC + (int)WEAPONTYPE::DARKMAGIC), L"Grants Hit +10, Avoid +6 and Critical Evade +6 when equipped with Reason Magic", true, STATTYPE::HIT, "10", STATTYPE::AVO, "6", STATTYPE::CRITAVO, "6"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Reason Prowess Lv.3", L"Reason", SL::CPLUS, SKILLTYPE::REASON, (WEAPONTYPE)((int)WEAPONTYPE::BLACKMAGIC + (int)WEAPONTYPE::DARKMAGIC), L"Grants Hit +13, Avoid +7 and Critical Evade +7 when equipped with Reason Magic", true, STATTYPE::HIT, "13", STATTYPE::AVO, "7", STATTYPE::CRITAVO, "7"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Reason Prowess Lv.4", L"Reason", SL::BPLUS, SKILLTYPE::REASON, (WEAPONTYPE)((int)WEAPONTYPE::BLACKMAGIC + (int)WEAPONTYPE::DARKMAGIC), L"Grants Hit +16, Avoid +8 and Critical Evade +8 when equipped with Reason Magic", true, STATTYPE::HIT, "16", STATTYPE::AVO, "8", STATTYPE::CRITAVO, "8"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Reason Prowess Lv.5", L"Reason", SL::APLUS, SKILLTYPE::REASON, (WEAPONTYPE)((int)WEAPONTYPE::BLACKMAGIC + (int)WEAPONTYPE::DARKMAGIC), L"Grants Hit +20, Avoid +10 and Critical Evade +10 when equipped with Reason Magic", true, STATTYPE::HIT, "20", STATTYPE::AVO, "10", STATTYPE::CRITAVO, "10"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Black Magic Range +1", L"Reason", SL::S, SKILLTYPE::REASON, WEAPONTYPE::BLACKMAGIC, L"Increases black magic range by 1.", true, STATTYPE::RANGE, "1"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Dark Magic Range +1", L"Reason", SL::S, SKILLTYPE::REASON, WEAPONTYPE::DARKMAGIC, L"Increases dark magic range by 1.", true, STATTYPE::RANGE, "1"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Black Tomefaire", L"Reason", SL::SPLUS, SKILLTYPE::REASON, WEAPONTYPE::BLACKMAGIC, L"Might +5 when Black Magic is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Dark Tomefaire", L"Reason", SL::SPLUS, SKILLTYPE::REASON, WEAPONTYPE::DARKMAGIC, L"Might +5 when Dark Magic is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Faith Prowess Lv.1", L"Faith", SL::EPLUS, SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC, L"Grants Hit +5, Avoid +7 and Critical Evade +5 when equipped with Faith Magic", true, STATTYPE::HIT, "5", STATTYPE::AVO, "7", STATTYPE::CRITAVO, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Faith Prowess Lv.2", L"Faith", SL::DPLUS, SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC, L"Grants Hit +6, Avoid +10 and Critical Evade +6 when equipped with Faith Magic", true, STATTYPE::HIT, "6", STATTYPE::AVO, "10", STATTYPE::CRITAVO, "6"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Faith Prowess Lv.3", L"Faith", SL::CPLUS, SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC, L"Grants Hit +7, Avoid +13 and Critical Evade +7 when equipped with Faith Magic", true, STATTYPE::HIT, "7", STATTYPE::AVO, "13", STATTYPE::CRITAVO, "7"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Faith Prowess Lv.4", L"Faith", SL::BPLUS, SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC, L"Grants Hit +8, Avoid +16 and Critical Evade +8 when equipped with Faith Magic", true, STATTYPE::HIT, "8", STATTYPE::AVO, "16", STATTYPE::CRITAVO, "8"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Faith Prowess Lv.5", L"Faith", SL::APLUS, SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC, L"Grants Hit +10, Avoid +20 and Critical Evade +10 when equipped with Faith Magic", true, STATTYPE::HIT, "10", STATTYPE::AVO, "20", STATTYPE::CRITAVO, "10"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"White Magic Range +1", L"Faith", SL::S, SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC, L"Increases White Magic range by 1 for attacks that damage foes.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"White Tomefaire", L"Faith", SL::SPLUS, SKILLTYPE::FAITH, WEAPONTYPE::WHITEMAGIC, L"Might +5 when White Magic is equipped.", true, STATTYPE::MIGHT, "5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Authority Prowess Lv.1", L"Authority", SL::EPLUS, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Grants Mt +2 with gambits.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Magic", L"Authority", SL::D, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Use Rally to grant Mag +4 to an ally.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Charm", L"Authority", SL::D, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Use Rally to grant Cha +8 to an ally.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Dexterity", L"Authority", SL::D, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Use Rally to grant Dex +8 to an ally.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Resistance", L"Authority", SL::D, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Use Rally to grant Res +4 to an ally.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Strength", L"Authority", SL::D, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Use Rally to grant Str +4 to an ally.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Speed", L"Authority", SL::CPLUS, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Use Rally to grant Spd +4 to an ally.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Defense", L"Authority", SL::D, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Use Rally to grant Def +4 to an ally.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Luck", L"Authority", SL::D, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Use Rally to grant Lck +8 to an ally.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Authority Prowess Lv.2", L"Authority", SL::DPLUS, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Grants Mt +4 with gambits.", true, STATTYPE::GMIGHT, "4"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Battalion Vantage", L"Authority", SL::C, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"When foe initiates combat, unit still attacks first if battalion endurance is ≤ 1/3.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Battalion Wrath", L"Authority", SL::C, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"If foe initiates combat while unit’s battalion endurance is ≤ 1/3, grants Crit +50.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Battalion Desperation", L"Authority", SL::C, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"If unit initiates combat when battalion endurance is ≤ 1/3, unit’s follow-up attack (if possible) occurs before foe’s counterattack.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Battalion Renewal", L"Authority", SL::C, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Unit recovers up to 30% of max HP at the start of each turn while battalion endurance is ≤ 1/3.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Authority Prowess Lv.3", L"Authority", SL::CPLUS, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Grants Mt +6 with gambits.", true, STATTYPE::GMIGHT, "6"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Model Leader", L"Authority", SL::CPLUS, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Doubles experience earned for battalions.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Defensive Tactics", L"Authority", SL::B, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Battalion endurance takes half damage.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Authority Prowess Lv.4", L"Authority", SL::BPLUS, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Grants Mt +8 with gambits.", true, STATTYPE::GMIGHT, "8"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Authority Prowess Lv.5", L"Authority", SL::APLUS, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Grants Mt +10 with gambits.", true, STATTYPE::GMIGHT, "10"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Rally Movement", L"Authority", SL::S, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Use Rally to grant Mv +1 to an ally.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Offensive Tactics", L"Authority", SL::SPLUS, SKILLTYPE::AUTHORITY, WEAPONTYPE::BLANK, L"Grants Mt +5 and Hit +20 with gambits.", true, STATTYPE::GMIGHT, "5", STATTYPE::GHIT, "20"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Weight -3", L"Heavy Armor", SL::C, SKILLTYPE::HEAVYARMOR, WEAPONTYPE::BLANK, L"The combined weight of equipment is reduced by 3.", true, STATTYPE::WEIGHT, "-3"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Weight -5", L"Heavy Armor", SL::APLUS, SKILLTYPE::HEAVYARMOR, WEAPONTYPE::BLANK, L"The combined weight of equipment is reduced by 5.", true, STATTYPE::WEIGHT, "-5"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Armored Effect Null", L"Heavy Armor", SL::SPLUS, SKILLTYPE::HEAVYARMOR, WEAPONTYPE::BLANK, L"Nullifies any extra effectiveness against armored units.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Dexterity +4", L"Riding", SL::C, SKILLTYPE::RIDING, WEAPONTYPE::BLANK, L"Increases Dex by 4.", true, STATTYPE::DEX, "4"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Movement +1", L"Riding", SL::APLUS, SKILLTYPE::RIDING, WEAPONTYPE::BLANK, L"Increases Mv by 1.", true, STATTYPE::MOV, "1"));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Cavalry Effect Null", L"Riding", SL::SPLUS, SKILLTYPE::RIDING, WEAPONTYPE::BLANK, L"Nullifies any extra effectiveness against cavalry units.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Alert Stance", L"Flying", SL::B, SKILLTYPE::FLYING, WEAPONTYPE::BLANK, L"If unit takes no action except Wait, grants Avo +15 for 1 turn.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Alert Stance+", L"Flying", SL::APLUS, SKILLTYPE::FLYING, WEAPONTYPE::BLANK, L"If unit takes no action except Wait, grants Avo +30 for 1 turn.", false, STATTYPE::BLANK, ""));
		list.emplace_back(std::make_unique<SkillLevelAbility>(L"Flying Effect Null", L"Flying", SL::SPLUS, SKILLTYPE::FLYING, WEAPONTYPE::BLANK, L"Nullifies any extra effectiveness against flying units.", false, STATTYPE::BLANK, ""));
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
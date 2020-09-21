#ifndef UNITLIST_H
#define UNITLIST_H

#include <wx/wx.h>
#include <Unit/Unit.h>
#include <Unit/Battalion.h>
#include <Unit/Character.h>
#include <Unit/Weapon/Weapon.h>
#include <Unit/Weapon/BlankWeapon.h>
#include <Unit/Weapon/Axe.h>
#include <Unit/Weapon/BlackMagic.h>
#include <Unit/Weapon/Bow.h>
#include <Unit/Weapon/DarkMagic.h>
#include <Unit/Weapon/Gauntlets.h>
#include <Unit/Weapon/Lance.h>
#include <Unit/Weapon/Sword.h>
#include <Unit/Weapon/WhiteMagic.h>
#include <Unit/Equipment/Equipment.h>
#include <Unit/Equipment/BlankEquipment.h>
#include <Unit/Equipment/Gem.h>
#include <Unit/Equipment/Ring.h>
#include <Unit/Equipment/Shield.h>
#include <Unit/Equipment/Staff.h>
#include <Unit/Class.h>
#include <Unit/Gambit.h>
#include <constants.h>
//#include <vld.h>

class UnitList {
private:
	std::vector<std::unique_ptr<Unit>> list;
public:
	UnitList() {
		list.emplace_back(std::make_unique<Battalion>(L"---", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"---", 
			L"---", L"---", L"---", L"---",
			L"---",
			SL::BLANK));
		list.emplace_back(std::make_unique<Battalion>(L"Church of Seiros Soldiers", 
			L"0", L"0", L"0", L"0", L"0", L"1", L"1", L"1", L"30", 
			L"0", L"0", L"1.3", L"0", L"0", L"0.5", L"0.5", L"0", L"0", 
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Mercenaries", 
			L"1", L"-2", L"5", L"0", L"0", L"0", L"0", L"1", L"30", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. At the end of combat, pushes primary target one space away. The target will not be pushed back if there is a unit in the space they would be pushed to.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Holy Monks", 
			L"-1", L"0", L"5", L"0", L"0", L"0", L"1", L"1", L"30", 
			L"0", L"0", L"1.3", L"0", L"0", L"0", L"0.5", L"0", L"0", 
			L"Stride",
			L"---", L"100", L"1", L"2",
			L"Grants Stride status to all allies within its area of effect, giving them +5 Movement for one turn.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Sacred Monks",
			L"-1", L"0", L"5", L"0", L"0", L"0", L"2", L"1", L"30",
			L"0", L"0", L"1.3", L"0", L"0", L"0", L"0.5", L"0", L"0", 
			L"Resonant White Magic",
			L"8", L"100", L"1", L"3",
			L"Restores HP to all allies within its area of effect.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Brawlers", 
			L"2", L"-2", L"0", L"0", L"5", L"0", L"-1", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Magic Corps",
			L"-2", L"1", L"0", L"0", L"0", L"0", L"3", L"3", L"30",
			L"0", L"0.5", L"1.3", L"0", L"0", L"0", L"0.5", L"0", L"0", 
			L"Group of Flames",
			L"2", L"60", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.", 
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Archers", 
			L"0", L"0", L"10", L"0", L"5", L"0", L"0", L"3", L"45",
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0", L"0", L"0", L"0", 
			L"Fusillade",
			L"5", L"50", L"2-3", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status on all targets.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Armored Co.", 
			L"2", L"0", L"0", L"0", L"-10", L"2", L"0", L"3", L"60", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0", 
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.", 
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Seiros Pegasus Co.", 
			L"2", L"0", L"0", L"0", L"1", L"0", L"3", L"5", L"60",
			L"0.5", L"0", L"0", L"0", L"1", L"0.5", L"0.5", L"0", L"0", 
			L"Assembly",
			L"4", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. At the end of combat, user moves one space backward while the primary target moves into user's previous space.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Knights of Seiros",
			L"2", L"-1", L"0", L"0", L"1", L"1", L"1", L"5", L"60", 
			L"0.5", L"0", L"0", L"0", L"1", L"0.5", L"0.5", L"0", L"0",
			L"Blaze",
			L"10", L"50", L"1", L"1",
			L"Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Holy Knights of Seiros", 
			L"3", L"-2", L"0", L"0", L"0", L"1", L"3", L"7", L"75",
			L"1", L"0", L"0", L"0", L"0", L"1", L"1", L"0", L"0", 
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Indech Sword Fighters", 
			L"4", L"-2", L"10", L"2", L"0", L"0", L"0", L"10", L"105", 
			L"1", L"0", L"2.5", L"2", L"0", L"1", L"0", L"0", L"0", 
			L"Retribution",
			L"---", L"100", L"1", L"2",
			L"Grants Retribution status to all allies within its area of effect, allowing them to counter-attack regardless of the range between them and their targets for 5 turns.",
			SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Macuil Evil Repelling Co.", 
			L"0", L"3", L"20", L"0", L"0", L"1", L"2", L"10", L"105",
			L"0", L"1", L"2.5", L"0", L"0", L"0", L"1", L"0", L"0", 
			L"Resonant Lightning",
			L"8", L"40", L"1-2", L"1",
			L"Works as magical damage.Inflicts rattled status on all targets.",
			SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Infantry", 
			L"0", L"-2", L"5", L"0", L"0", L"1", L"0", L"1", L"30", 
			L"0", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Lure",
			L"4", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. At the end of combat, moves primary target behind the user.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Warriors", 
			L"2", L"-2", L"0", L"0", L"0", L"0", L"0", L"1", L"30",
			L"0.5", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"Random Shot",
			L"8", L"40", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Brawlers", 
			L"2", L"-2", L"0", L"0", L"5", L"0", L"-1", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", 
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Magic Corps", 
			L"-2", L"2", L"0", L"0", L"0", L"0", L"2", L"3", L"30", 
			L"0", L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", 
			L"Group of Flames",
			L"2", L"60", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.", 
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Archers", 
			L"1", L"-2", L"10", L"0", L"0", L"1", L"0", L"3", L"30", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", 
			L"Fusillade",
			L"5", L"50", L"2-3", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status on all targets.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Cavalry",
			L"2", L"-2", L"0", L"0", L"0", L"2", L"0", L"3", L"45",
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0", 
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Armored Co.", 
			L"1", L"-2", L"0", L"0", L"-10", L"3", L"0", L"3", L"60",
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", 
			L"Impregnable Wall",
			L"---", L"100", L"1", L"5",
			L"Grants Impregnable Wall status to all allies within its area of effect, reducing all damage dealt and taken by them to 1 for one turn.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Knights",
			L"3", L"-2", L"0", L"0", L"0", L"2", L"0", L"5", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", 
			L"Blaze",
			L"10", L"50", L"1", L"1",
			L"Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Snipers", 
			L"3", L"-2", L"5", L"0", L"0", L"1", L"0", L"5", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", 
			L"Flash-Fire Arrows",
			L"7", L"50", L"1", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Magic Users",
			L"-2", L"3", L"0", L"5", L"0", L"0", L"2", L"5", L"45", 
			L"0", L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0",
			L"Resonant Flames",
			L"6", L"60", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Pavise Co.",
			L"0", L"-2", L"0", L"0", L"-10", L"4", L"1", L"5", L"75",
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Blaze",
			L"10", L"50", L"1", L"1",
			L"Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Pegasus Co.", 
			L"2", L"0", L"10", L"0", L"0", L"1", L"2", L"6", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0.5", L"0", L"0", 
			L"Group Lance Attack",
			L"6", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Wyvern Co.",
			L"3", L"-2", L"5", L"5", L"0", L"2", L"0", L"5", L"60", 
			L"0.5", L"0", L"0", L"1.3", L"0", L"0.5", L"0", L"0", L"0", 
			L"Reversal",
			L"8", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. At the end of combat, user switches places with the primary target.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Heavy Soldiers", 
			L"2", L"-2", L"5", L"0", L"-10", L"5", L"1", L"7", L"75", 
			L"1", L"0", L"2.5", L"0", L"0", L"1", L"0", L"0", L"0", 
			L"Line of Lances",
			L"5", L"50", L"1", L"2",
			L"Deals bonus damage to cavalry units. Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Holy Magic Users", 
			L"-2", L"2", L"0", L"0", L"0", L"0", L"3", L"8", L"60", 
			L"0", L"1", L"0", L"0", L"0", L"1", L"1", L"0", L"0", 
			L"Blessing",
			L"---", L"100", L"1", L"1",
			L"Grants Blessing status to all allies within its area of effect, reducing lethal damage taken to leave them at 1 HP for one turn.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Raiders", 
			L"3", L"0", L"0", L"0", L"5", L"0", L"0", L"7", L"75",
			L"1", L"0", L"0", L"0", L"1.3", L"1", L"0", L"0", L"0", 
			L"Absorption",
			L"4", L"30", L"1", L"1",
			L"Inflicts rattled status on all targets. Restores(damage dealt / 2) HP to the user from each target in its area of effect.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Imperial Guard", 
			L"3", L"-2", L"0", L"10", L"0", L"0", L"0", L"7", L"75", 
			L"1", L"0", L"0", L"0", L"0", L"1", L"0", L"0", L"0", 
			L"Blaze",
			L"10", L"50", L"1", L"1",
			L"Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Elite Wyvern Co.", 
			L"4", L"-2", L"0", L"5", L"0", L"2", L"0", L"7", L"75", 
			L"1", L"0", L"0", L"1.3", L"0", L"1", L"0", L"0", L"0",
			L"Assembly",
			L"4", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. At the end of combat, user moves one space backward while the primary target moves into user's previous space.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Black Eagle Heavy Axes",
			L"3", L"0", L"0", L"10", L"-10", L"4", L"2", L"10", L"105",
			L"1", L"0", L"0", L"0", L"0", L"1", L"0", L"0", L"0", 
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.",
			SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Black Eagle Cavalry",
			L"3", L"0", L"10", L"0", L"5", L"1", L"0", L"10", L"105",
			L"1", L"0", L"2.5", L"0", L"0", L"1", L"0", L"0", L"0",
			L"Linked Horses",
			L"12", L"50", L"1", L"1",
			L"Inflicts rattled status on all targets.",
			SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Black Eagle Pegasus Co.",
			L"3", L"0", L"0", L"10", L"5", L"1", L"3", L"10", L"105", 
			L"1", L"0", L"0", L"0", L"1.3", L"1", L"1", L"0", L"0", 
			L"Retribution",
			L"---", L"100", L"1", L"2",
			L"Grants Retribution status to all allies within its area of effect, allowing them to counter-attack regardless of the range between them and their targets for 5 turns.",
			SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Infantry",
			L"1", L"-2", L"0", L"0", L"0", L"1", L"0", L"1", L"30", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", 
			L"Lure",
			L"4", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. At the end of combat, moves primary target behind the user.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Lance Co.", 
			L"1", L"-2", L"0", L"0", L"5", L"0", L"0", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0",
			L"Group Lance Attack",
			L"6", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Brawlers", 
			L"2", L"-2", L"0", L"0", L"5", L"0", L"-1", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", 
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Magic Corps", 
			L"-2", L"1", L"0", L"0", L"0", L"1", L"2", L"3", L"30", 
			L"0", L"0.5", L"1.3", L"0", L"0", L"0", L"0.5", L"0", L"0", 
			L"Group Ice",
			L"3", L"50", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Archers",
			L"2", L"-2", L"5", L"0", L"0", L"1", L"0", L"3", L"30",
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", 
			L"Retribution",
			L"---", L"100", L"1", L"2",
			L"Grants Retribution status to all allies within its area of effect, allowing them to counter-attack regardless of the range between them and their targets for 5 turns.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Cavalry", 
			L"2", L"-2", L"0", L"0", L"0", L"2", L"0", L"3", L"45",
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", 
			L"Stride",
			L"---", L"100", L"1", L"2",
			L"Grants Stride status to all allies within its area of effect, giving them +5 Movement for one turn.", 
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Armored Co.", 
			L"1", L"-2", L"0", L"0", L"-10", L"3", L"0", L"3", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Impregnable Wall",
			L"---", L"100", L"1", L"5",
			L"Grants Impregnable Wall status to all allies within its area of effect, reducing all damage dealt and taken by them to 1 for one turn.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Knights", 
			L"3", L"-2", L"0", L"0", L"0", L"2", L"1", L"5", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0", 
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Snipers	", 
			L"1", L"-2", L"5", L"0", L"0", L"1", L"1", L"5", L"60", 
			L"0.5", L"0", L"2.5", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Fusillade",
			L"5", L"50", L"2-3", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status on all targets.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Magic Users", 
			L"-2", L"3", L"0", L"0", L"0", L"1", L"1", L"5", L"45", 
			L"0", L"0.5", L"0", L"0", L"1.3", L"0", L"0.5", L"0", L"0", 
			L"Resonant Ice",
			L"7", L"50", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Brave Lance Co.", 
			L"2", L"-2", L"10", L"0", L"5", L"1", L"0", L"5", L"60", 
			L"0.5", L"0", L"2.5", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.", 
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Pegasus Co.", 
			L"2", L"0", L"0", L"0", L"0", L"1", L"2", L"6", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0.5", L"0", L"0", 
			L"Assembly",
			L"4", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. At the end of combat, user moves one space backward while the primary target moves into user's previous space.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Wyvern Co.", 
			L"3", L"-2", L"10", L"0", L"0", L"2", L"0", L"5", L"60", 
			L"0.5", L"0", L"1.3", L"1.3", L"0", L"0.5", L"0", L"0", L"0",
			L"Recovery Roar",
			L"---", L"100", L"1", L"5",
			L"Removes any status condition from all allies in range.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Heavy Soldiers",
			L"0", L"-2", L"0", L"0", L"-10", L"3", L"0", L"7", L"90", 
			L"1", L"0", L"1.3", L"1.3", L"0", L"1", L"0", L"0", L"0", 
			L"Group Lance Attack",
			L"6", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Holy Knights",
			L"3", L"-2", L"0", L"0", L"-10", L"1", L"3", L"7", L"75",
			L"1", L"0", L"1.3", L"0", L"0", L"1", L"1", L"0", L"0", 
			L"Linked Horses",
			L"12", L"50", L"1", L"1",
			L"Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Heavy Knights",
			L"0", L"-2", L"5", L"0", L"-15", L"3", L"0", L"7", L"90",
			L"1", L"0", L"2.5", L"0", L"0", L"1", L"0", L"0", L"0", 
			L"Sacred Shield",
			L"---", L"100", L"1", L"5",
			L"Grants Sacred Shield status to all allies within its area of effect, reducing all damage dealt to them from ranged attacks to 0 for one turn.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Royal Guard",
			L"2", L"0", L"10", L"10", L"-10", L"0", L"0", L"7", L"75",
			L"1", L"0", L"2.5", L"0", L"0", L"1", L"0", L"0", L"0", 
			L"Line of Lances",
			L"5", L"50", L"1", L"2",
			L"Deals bonus damage to cavalry units. Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Priests", 
			L"0", L"1", L"0", L"0", L"-5", L"0", L"3", L"7", L"60",
			L"0", L"1", L"1.3", L"0", L"0", L"0", L"1", L"0", L"0",
			L"Blessing",
			L"---", L"100", L"1", L"1",
			L"Grants Blessing status to all allies within its area of effect, reducing lethal damage taken to leave them at 1 HP for one turn.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Blue Lion Knights", 
			L"3", L"-2", L"0", L"10", L"-10", L"1", L"0", L"10", L"105",
			L"1", L"0", L"1.3", L"1.3", L"0", L"1", L"0", L"0", L"0", 
			L"Linked Horses",
			L"12", L"50", L"1", L"1",
			L"Inflicts rattled status on all targets.",
			SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Blue Lion Magic Corps",
			L"-2", L"3", L"0", L"0", L"-10", L"1", L"3", L"10", L"105", 
			L"0", L"1", L"1.3", L"0", L"0", L"1", L"1", L"0", L"0", 
			L"Resonant Ice",
			L"7", L"50", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets.",
			SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Blue Lion Dancers", 
			L"-5", L"-5", L"0", L"0", L"15", L"1", L"1", L"10", L"105", 
			L"1", L"1", L"0", L"0", L"1.3", L"0.5", L"0.5", L"0", L"0", 
			L"Dance of the Goddess",
			L"---", L"100", L"1", L"1",
			L"Refreshes all allies within its area of effect, allowing them to move again if they have already moved.",
			SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Infantry", 
			L"0", L"-2", L"5", L"0", L"5", L"0", L"0", L"1", L"30",
			L"0", L"0", L"1", L"0", L"1.3", L"0", L"0", L"0", L"0", 
			L"Lure",
			L"4", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. At the end of combat, moves primary target behind the user.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Duelists", 
			L"0", L"-2", L"0", L"5", L"5", L"0", L"0", L"1", L"30",
			L"0", L"0", L"0", L"1", L"1.3", L"0", L"0", L"0", L"0", 
			L"Mad Melee",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Brawlers", 
			L"2", L"-2", L"0", L"0", L"5", L"0", L"-1", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", 
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Magic Corps", 
			L"-2", L"1", L"0", L"0", L"5", L"0", L"2", L"3", L"30",
			L"0", L"0.5", L"0", L"0", L"1.3", L"0", L"0.5", L"0", L"0", 
			L"Group Lightning",
			L"4", L"40", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Archers", 
			L"1", L"-2", L"10", L"0", L"5", L"0", L"0", L"3", L"30", 
			L"0.5", L"0", L"1", L"0", L"1.3", L"0", L"0", L"0", L"0",
			L"Poisoned Arrows",
			L"4", L"60", L"2-3", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status and poison status on all targets.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Cavalry", 
			L"2", L"-2", L"0", L"0", L"5", L"0", L"0", L"3", L"45", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", 
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Armored Co.",
			L"1", L"-2", L"0", L"0", L"-5", L"2", L"0", L"3", L"60",
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Knights",
			L"2", L"-2", L"0", L"0", L"5", L"1", L"1", L"5", L"60", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0", 
			L"Blaze",
			L"10", L"50", L"1", L"1",
			L"Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Snipers", 
			L"1", L"-2", L"10", L"0", L"5", L"0", L"0", L"5", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0", L"0", L"0", L"0", 
			L"Fusillade",
			L"5", L"50", L"2-3", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status on all targets.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Magic Users",
			L"-2", L"2", L"0", L"0", L"5", L"0", L"2", L"5", L"45", 
			L"0", L"0.5", L"0", L"0", L"1.3", L"0", L"0.5", L"0", L"0",
			L"Resonant Lightning",
			L"8", L"40", L"1-2", L"1",
			L"Works as magical damage.Inflicts rattled status on all targets.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Veteran Duelists",
			L"2", L"-2", L"0", L"0", L"5", L"1", L"0", L"5", L"60", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0", 
			L"Absorption",
			L"4", L"30", L"1", L"1",
			L"Inflicts rattled status on all targets. Restores(damage dealt / 2) HP to the user from each target in its area of effect.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Pegasus Co.",
			L"2", L"0", L"0", L"0", L"5", L"0", L"1", L"6", L"60", 
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0.5", L"0", L"0", 
			L"Assembly",
			L"4", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. At the end of combat, user moves one space backward while the primary target moves into user's previous space.",
			SL::D));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Wyvern Co.", 
			L"3", L"-2", L"0", L"0", L"5", L"1", L"0", L"5", L"60", 
			L"0.5", L"0", L"0", L"1.3", L"1.3", L"0.5", L"0", L"0", L"0", 
			L"Impregnable Wall",
			L"---", L"100", L"1", L"5",
			L"Grants Impregnable Wall status to all allies within its area of effect, reducing all damage dealt and taken by them to 1 for one turn.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Pavise Co.",
			L"2", L"-2", L"0", L"0", L"-5", L"4", L"1", L"7", L"90", 
			L"0.5", L"0", L"1.3", L"0", L"0", L"1", L"0", L"0", L"0", 
			L"Group Lance Attack",
			L"6", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Physicians", 
			L"0", L"1", L"0", L"0", L"5", L"0", L"2", L"7", L"60", 
			L"0", L"0.5", L"0", L"0", L"1.3", L"0", L"0.5", L"0", L"0", 
			L"Resonant White Magic",
			L"8", L"100", L"1", L"3",
			L"Restores HP to all allies within its area of effect.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Sages", 
			L"0", L"4", L"0", L"0", L"-10", L"0", L"2", L"7", L"60", 
			L"0", L"1", L"1.3", L"1.3", L"0", L"0", L"1", L"0", L"0",
			L"Blessing",
			L"---", L"100", L"1", L"1",
			L"Grants Blessing status to all allies within its area of effect, reducing lethal damage taken to leave them at 1 HP for one turn.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Master Archers", 
			L"2", L"-1", L"0", L"10", L"5", L"0", L"0", L"7", L"60", 
			L"0.5", L"0", L"0", L"1.3", L"1.3", L"1", L"0", L"0", L"0", 
			L"Flash-Fire Arrows",
			L"7", L"50", L"1", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Guard", 
			L"3", L"0", L"0", L"5", L"1", L"0", L"0", L"7", L"75", 
			L"0.5", L"0", L"0", L"1.3", L"1", L"1", L"0", L"0", L"0", 
			L"Poison Tactic",
			L"5", L"60", L"1", L"1",
			L"Inflicts rattled status and poison status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Golden Deer Wyvern Co.",
			L"2", L"-2", L"0", L"0", L"5", L"1", L"0", L"10", L"105",
			L"1", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0", L"0", L"0", 
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Golden Deer Archers", 
			L"2", L"-2", L"15", L"0", L"10", L"0", L"1", L"10", L"105", 
			L"0", L"0", L"2.5", L"0", L"1.3", L"0.5", L"0.5", L"0", L"0", 
			L"Poison Tactic",
			L"5", L"60", L"1", L"1",
			L"Inflicts rattled status and poison status on all targets.",
			SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Golden Deer Cavalry", 
			L"4", L"-2", L"0", L"0", L"-5", L"3", L"2", L"10", L"105",
			L"1", L"0", L"1.3", L"0", L"0", L"1", L"0", L"0", L"0",
			L"Linked Horses",
			L"12", L"50", L"1", L"1",
			L"Inflicts rattled status on all targets.",
			SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Supreme Armored Co.", 
			L"3", L"2", L"0", L"0", L"-10", L"2", L"1", L"10", L"120",
			L"1", L"1", L"1.3", L"0", L"0", L"1", L"1", L"0", L"0", 
			L"Raging Flames",
			L"15", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"King of Lions Corps", 
			L"5", L"-2", L"0", L"10", L"-5", L"1", L"0", L"10", L"120",
			L"1.3", L"0", L"1.3", L"1.3", L"0", L"1", L"0", L"0", L"0",
			L"Wave Attack",
			L"13", L"60", L"1", L"2",
			L"Deals bonus damage to armored units. Inflicts Is ns01 status rattled.png rattled status on all targets.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Immortal Corps",
			L"4", L"-2", L"0", L"0", L"10", L"0", L"0", L"10", L"120", 
			L"1", L"0", L"0", L"0", L"1.3", L"1", L"0", L"0", L"0", 
			L"Ashes and Dust",
			L"12", L"50", L"2-3", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status on all targets.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Vestra Sorcery Engineers", 
			L"-2", L"3", L"0", L"0", L"5", L"0", L"2", L"7", L"75", 
			L"0", L"1", L"0", L"0", L"1.3", L"1", L"1", L"0", L"0", 
			L"Resonant Lightning",
			L"8", L"40", L"1-2", L"1",
			L"Works as magical damage.Inflicts rattled status on all targets.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Aegir Astral Knights",
			L"3", L"-2", L"0", L"0", L"15", L"0", L"0", L"7", L"105", 
			L"1", L"0", L"0", L"0", L"1.3", L"0.5", L"0.5", L"0", L"0", 
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Hevring Prayer Troops", 
			L"0", L"3", L"0", L"0", L"-10", L"0", L"3", L"7", L"75", 
			L"0", L"1", L"1.3", L"0", L"0", L"1", L"1", L"0", L"0", 
			L"Blessing",
			L"---", L"100", L"1", L"1",
			L"Grants Blessing status to all allies within its area of effect, reducing lethal damage taken to leave them at 1 HP for one turn.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Bergliez War Group", 
			L"4", L"0", L"0", L"0", L"-10", L"0", L"0", L"7", L"105", 
			L"1", L"0", L"1.3", L"0", L"0", L"1", L"0", L"0", L"0",
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.", 
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Varley Archers", 
			L"0", L"0", L"20", L"0", L"-10", L"1", L"0", L"7", L"75", 
			L"0", L"0", L"2.5", L"0", L"0", L"1", L"0", L"0", L"0",
			L"Fusillade",
			L"5", L"50", L"2-3", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Opera Co. Volunteers", 
			L"0", L"0", L"10", L"0", L"10", L"0", L"0", L"10", L"75",
			L"0", L"0", L"2.5", L"0", L"1.3", L"1", L"0", L"0", L"0",
			L"Dance of the Goddess",
			L"---", L"100", L"1", L"1",
			L"Refreshes all allies within its area of effect, allowing them to move again if they have already moved.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Brigid Hunters", 
			L"0", L"-2", L"0", L"5", L"15", L"0", L"0", L"7", L"105", 
			L"1", L"0", L"0", L"1.3", L"1.3", L"0", L"0", L"0", L"0",
			L"Poison Tactic",
			L"5", L"60", L"1", L"1",
			L"Inflicts rattled status and poison status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Duscur Heavy Soldiers", 
			L"4", L"-2", L"0", L"0", L"-15", L"5", L"0", L"7", L"120",
			L"1", L"0", L"1.3", L"0", L"0", L"1.3", L"0", L"0", L"0",
			L"Line of Lances",
			L"5", L"50", L"1", L"2",
			L"Deals bonus damage to cavalry units. Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Fraldarius Soldiers", 
			L"3", L"0", L"0", L"10", L"0", L"2", L"0", L"7", L"105",
			L"1", L"0", L"0", L"2.5", L"0", L"1", L"0", L"0", L"0",
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Gaspard Knights",
			L"1", L"0", L"0", L"0", L"-5", L"1", L"0", L"7", L"105", 
			L"1", L"0", L"1.3", L"0", L"0", L"1", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Gautier Knights",
			L"3", L"-2", L"0", L"0", L"15", L"0", L"0", L"7", L"105", 
			L"1", L"0", L"0", L"0", L"1.3", L"1.3", L"0", L"0", L"0",
			L"Stride",
			L"---", L"100", L"1", L"2",
			L"Grants Stride status to all allies within its area of effect, giving them +5 Movement for one turn.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Church Soldiers", 
			L"0", L"1", L"0", L"0", L"0", L"0", L"2", L"5", L"75",
			L"0", L"0.5", L"1.3", L"0", L"0", L"0", L"1", L"0", L"0",
			L"Resonant White Magic",
			L"8", L"100", L"1", L"3",
			L"Restores HP to all allies within its area of effect.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"School of Sorcery Soldiers", 
			L"-2", L"2", L"10", L"0", L"0", L"0", L"2", L"5", L"75", 
			L"0", L"1", L"2.5", L"0", L"0", L"0", L"0.5", L"0", L"0",
			L"Resonant Flames",
			L"6", L"60", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Galatea Pegasus Co.", 
			L"3", L"0", L"0", L"0", L"5", L"1", L"2", L"8", L"105", 
			L"1", L"0", L"1.3", L"0", L"1.3", L"1", L"1", L"0", L"0",
			L"Lure",
			L"4", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. At the end of combat, moves primary target behind the user.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Gloucester Knights", 
			L"2", L"2", L"10", L"0", L"0", L"1", L"1", L"7", L"105",
			L"1", L"1", L"1.3", L"0", L"0", L"1", L"1", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Leicester Mercenaries", 
			L"3", L"-2", L"10", L"10", L"0", L"0", L"0", L"7", L"105", 
			L"1", L"0", L"2.5", L"1.3", L"0", L"1", L"0", L"0", L"0",
			L"Blaze",
			L"10", L"50", L"1", L"1",
			L"Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Victor Private Military", 
			L"2", L"0", L"5", L"0", L"0", L"0", L"2", L"5", L"105", 
			L"1", L"0", L"2.5", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Assembly",
			L"4", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. At the end of combat, user moves one space backward while the primary target moves into user's previous space.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Ordelia Sorcery Co.", 
			L"-1", L"4", L"10", L"0", L"0", L"0", L"2", L"7", L"75", 
			L"0", L"1", L"2.5", L"0", L"0", L"0", L"1", L"0", L"0",
			L"Resonant Lightning",
			L"8", L"40", L"1-2", L"1",
			L"Works as magical damage.Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Edmund Troops", 
			L"1", L"1", L"30", L"0", L"0", L"0", L"0", L"7", L"105", 
			L"1", L"1", L"2.5", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Flash-Fire Arrows",
			L"7", L"50", L"1", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Goneril Valkyries",
			L"4", L"-2", L"10", L"10", L"0", L"2", L"1", L"7", L"105", 
			L"1", L"0", L"2.5", L"1.3", L"0", L"1", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Sauin Militia",
			L"1", L"0", L"10", L"0", L"5", L"0", L"0", L"5", L"75", 
			L"0", L"0", L"2.5", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Poisoned Arrows",
			L"4", L"60", L"2-3", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status and poison status on all targets.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Cichol Wyvern Co.",
			L"3", L"0", L"10", L"10", L"0", L"2", L"1", L"10", L"105", 
			L"1", L"0", L"1.3", L"1.3", L"1.3", L"1", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Cethleann Monks", 
			L"0", L"2", L"10", L"0", L"0", L"1", L"3", L"10", L"105", 
			L"0", L"1", L"2.5", L"0", L"0", L"0", L"1", L"0", L"0",
			L"Resonant White Magic",
			L"8", L"100", L"1", L"3",
			L"Restores HP to all allies within its area of effect.",
			SL::A));
		list.emplace_back(std::make_unique<Battalion>(L"Jeralt’s Mercenaries",
			L"1", L"0", L"0", L"5", L"5", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"1.3", L"2.5", L"0", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Reaper Knights", 
			L"3", L"-2", L"0", L"5", L"10", L"0", L"0", L"1", L"105",
			L"1", L"0", L"0", L"1.3", L"1.3", L"1", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Secret Transport Force",
			L"1", L"0", L"0", L"0", L"10", L"1", L"1", L"8", L"105",
			L"0.5", L"0", L"0", L"0", L"1.3", L"1", L"1", L"0", L"0",
			L"Stride",
			L"---", L"100", L"1", L"2",
			L"Grants Stride status to all allies within its area of effect, giving them +5 Movement for one turn.", 
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Mockingbird’s Thieves", 
			L"1", L"1", L"5", L"5", L"5", L"1", L"1", L"5", L"105", 
			L"1", L"1", L"1.3", L"1.3", L"1.3", L"0.5", L"0.5", L"0", L"0",
			L"Absorption",
			L"4", L"30", L"1", L"1",
			L"Inflicts rattled status on all targets. Restores(damage dealt / 2) HP to the user from each target in its area of effect.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Leicester Dicers Corps", 
			L"3", L"3", L"0", L"0", L"0", L"1", L"1", L"5", L"105",
			L"1", L"1", L"1.3", L"0", L"0", L"1", L"1", L"0", L"0",
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Nuvelle Fliers Corps", 
			L"0", L"3", L"0", L"0", L"5", L"0", L"3", L"8", L"105", 
			L"0", L"1", L"1.3", L"0", L"1.3", L"0", L"1", L"0", L"0",
			L"Resonant Lightning",
			L"8", L"40", L"1-2", L"1",
			L"Works as magical damage.Inflicts rattled status on all targets.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Timotheos Magi Corps", 
			L"0", L"3", L"5", L"5", L"0", L"0", L"1", L"7", L"105", 
			L"0", L"1.3", L"1.3", L"1.3", L"0", L"0.5", L"1", L"0", L"0",
			L"Resonant Flames",
			L"6", L"60", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::B));
		list.emplace_back(std::make_unique<Battalion>(L"Remire Militia", 
			L"0", L"0", L"0", L"0", L"0", L"1", L"0", L"1", L"30",
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Empire Youths", 
			L"0", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"30", 
			L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Kingdom Youths", 
			L"0", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"30",
			L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Alliance Youths",
			L"0", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"30",
			L"0", L"0", L"1.3", L"0", L"0", L"0", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Duscur Infantry", 
			L"1", L"-2", L"0", L"0", L"5", L"1", L"-1", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Almyra Mercenaries", 
			L"3", L"0", L"0", L"0", L"5", L"0", L"-2", L"1", L"30", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0",
			L"Fusillade",
			L"5", L"50", L"2-3", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Brigid Mercenaries",
			L"1", L"0", L"5", L"5", L"0", L"0", L"0", L"1", L"30", 
			L"0.5", L"0", L"1.3", L"1.3", L"0", L"0", L"0", L"0", L"0",
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Morfis Magic Corps",
			L"-2", L"3", L"0", L"0", L"0", L"0", L"3", L"5", L"45",
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Resonant Lightning",
			L"8", L"40", L"1-2", L"1",
			L"Works as magical damage.Inflicts rattled status on all targets.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Essar Research Group",
			L"1", L"1", L"20", L"0", L"0", L"0", L"0", L"1", L"60",
			L"1", L"1", L"2.5", L"0", L"0", L"0", L"0", L"0", L"0",
			L"Blessing",
			L"---", L"100", L"1", L"1",
			L"Grants Blessing status to all allies within its area of effect, reducing lethal damage taken to leave them at 1 HP for one turn.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Holst’s Chosen",
			L"3", L"0", L"0", L"0", L"0", L"3", L"0", L"3", L"60", 
			L"1", L"0", L"1.3", L"1.3", L"0", L"1", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Nuvelle Chamberlain Co.",
			L"3", L"0", L"5", L"5", L"0", L"1", L"3", L"5", L"45",
			L"1.3", L"0", L"1.3", L"1.3", L"0", L"0", L"1", L"0", L"0",
			L"Battleground Cafe",
			L"---", L"100", L"1", L"2",
			L"Grants +4 strength to all allies within its area of effect for one turn.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Nuvelle Attendants Co.",
			L"0", L"3", L"0", L"5", L"5", L"1", L"3", L"5", L"45", 
			L"0", L"1.3", L"0", L"1.3", L"1.3", L"0", L"1", L"0", L"0",
			L"Absolute Defense",
			L"---", L"100", L"1", L"2",
			L"Grants +6 defense to all allies within its area of effect for one turn.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Nuvelle Stewards Co.", 
			L"1", L"1", L"5", L"5", L"1", L"1", L"3", L"10", L"45", 
			L"1", L"1", L"1.3", L"1.3", L"1", L"0", L"1", L"0", L"0",
			L"Battleground Clean Up",
			L"15", L"40", L"1", L"1",
			L"Inflicts rattled status on all targets.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Iron King’s Thieves", 
			L"-1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Gaspard Militia", 
			L"-1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"West Church Corps",
			L"0", L"1", L"0", L"0", L"0", L"0", L"1", L"1", L"75",
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Group Lightning",
			L"4", L"40", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"West Church Mercenaries", 
			L"1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"West Church Sages", 
			L"0", L"2", L"0", L"0", L"-10", L"0", L"2", L"1", L"75", 
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Group Lightning",
			L"4", L"40", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"West Church Pegasus Co.", 
			L"1", L"0", L"0", L"0", L"0", L"0", L"1", L"3", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"West Church Knights", 
			L"2", L"-1", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Mysterious Infantry", 
			L"1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Mysterious Magic Corps", 
			L"0", L"1", L"0", L"0", L"0", L"0", L"1", L"1", L"75", 
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Group of Flames",
			L"2", L"60", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Mysterious Magic Users",
			L"-5", L"2", L"0", L"0", L"-5", L"0", L"2", L"1", L"75",
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Resonant Flames",
			L"6", L"60", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Miklan Private Militia",
			L"1", L"-2", L"5", L"0", L"0", L"1", L"0", L"1", L"75", 
			L"0.5", L"0", L"2.5", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Reaper Infantry",
			L"0", L"0", L"0", L"0", L"10", L"0", L"0", L"1", L"75",
			L"0", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Rampaging Villagers",
			L"1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Solon Subordinates", 
			L"-2", L"3", L"0", L"0", L"-5", L"0", L"2", L"1", L"75",
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Resonant Flames",
			L"6", L"60", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Kronya Subordinates	",
			L"0", L"0", L"0", L"0", L"20", L"0", L"0", L"1", L"75",
			L"0", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0",
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Pallardó Bodyguards", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Poison Tactic",
			L"5", L"60", L"1", L"1",
			L"Inflicts rattled status and poison status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Rowe Knights", 
			L"3", L"-1", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Linked Horses",
			L"12", L"50", L"1", L"1",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"House Rowe Archers", 
			L"2", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Flash-Fire Arrows",
			L"7", L"50", L"1", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Rowe Armored Co.",
			L"1", L"0", L"0", L"0", L"-10", L"1", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Group Lance Attack",
			L"6", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Rowe Cavalry",
			L"2", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Daphnel Duelists",
			L"3", L"-2", L"0", L"0", L"10", L"0", L"0", L"1", L"105",
			L"0.5", L"0", L"0", L"0", L"1.3", L"0", L"0", L"0", L"0",
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Almyra Wyvern Co.", 
			L"4", L"-2", L"-5", L"0", L"10", L"2", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Almyra Cavalry", 
			L"2", L"-2", L"0", L"0", L"10", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dark Infantry", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dark Magic Corps", 
			L"-1", L"2", L"0", L"0", L"0", L"0", L"2", L"1", L"75", 
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Resonant Lightning",
			L"8", L"40", L"1-2", L"1",
			L"Works as magical damage.Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Einherjar", 
			L"4", L"0", L"0", L"0", L"-10", L"1", L"0", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Enhanced Infantry", 
			L"2", L"0", L"0", L"0", L"-5", L"0", L"1", L"1", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Enhanced Heavy Co.", 
			L"1", L"0", L"0", L"0", L"-10", L"2", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Group Lance Attack",
			L"6", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Enhanced Cavalry", 
			L"3", L"0", L"0", L"0", L"-10", L"1", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Linked Horses",
			L"12", L"50", L"1", L"1",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Enhanced Wyvern Co.",
			L"2", L"0", L"0", L"0", L"-10", L"0", L"2", L"3", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Poison Tactic",
			L"5", L"60", L"1", L"1",
			L"Inflicts rattled status and poison status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Ancient Infantry", 
			L"2", L"0", L"0", L"0", L"-5", L"0", L"1", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Ancient Armored Co.", 
			L"1", L"0", L"0", L"0", L"-5", L"1", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Ancient Cavalry", 
			L"3", L"0", L"0", L"0", L"-5", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Ancient Wyvern Co.",
			L"2", L"0", L"0", L"0", L"-5", L"0", L"1", L"3", L"75",
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Lure",
			L"4", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. At the end of combat, moves primary target behind the user.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Phantasmal Cavalry", 
			L"2", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Phantasmal Infantry", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Phantasmal Wyvern Co.", 
			L"2", L"0", L"0", L"0", L"0", L"0", L"2", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Duscur Cavalry",
			L"2", L"0", L"0", L"0", L"-10", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dominic Cavalry",
			L"1", L"0", L"10", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"2.5", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Merchant Military",
			L"-1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0", L"0.5", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Poison Tactic",
			L"5", L"60", L"1", L"1",
			L"Inflicts rattled status and poison status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Thieves", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Rogues", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Bandits",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75", 
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Pirates", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"1.3", L"0", L"1.3", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Arundel Magic Corps",
			L"0", L"2", L"0", L"0", L"0", L"1", L"2", L"1", L"75",
			L"0", L"1", L"0", L"0", L"0", L"1", L"1", L"0", L"0",
			L"Resonant Flames",
			L"6", L"60", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Mysterious Wyvern Co.",
			L"1", L"0", L"0", L"0", L"5", L"1", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"2.5", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dark Wyvern Co.", 
			L"1", L"0", L"0", L"0", L"5", L"1", L"0", L"1", L"75", 
			L"0.5", L"0", L"0", L"0", L"2.5", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Ancient Sorcerers", 
			L"-5", L"2", L"0", L"0", L"-5", L"0", L"2", L"1", L"75",
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Resonant Flames",
			L"6", L"60", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Enhanced Sorcerers", 
			L"-5", L"4", L"0", L"0", L"-5", L"0", L"4", L"1", L"75", 
			L"0", L"0.5", L"0", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Resonant Lightning",
			L"8", L"40", L"1-2", L"1",
			L"Works as magical damage.Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Phantasmal Magic Corps",
			L"0", L"3", L"0", L"0", L"0", L"0", L"3", L"1", L"75",
			L"0", L"0.5", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0",
			L"Resonant Flames",
			L"6", L"60", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Phantasmal Archers", 
			L"1", L"0", L"10", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"2.5", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Gaspard Archers",
			L"-1", L"0", L"0", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0", L"0", L"0", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Thief Marksmen",
			L"-1", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Cliff Bandit Marksmen",
			L"-1", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Pirate Marksmen", 
			L"-1", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"West Church Archers", 
			L"1", L"0", L"5", L"0", L"0", L"0", L"0", L"1", L"75",
			L"0.5", L"0", L"1.3", L"0", L"0", L"0.5", L"0", L"0", L"0",
			L"Fusillade",
			L"5", L"50", L"2-3", L"2",
			L"Deals bonus damage to flying units. Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Flame Emperor Co.", 
			L"3", L"2", L"-5", L"0", L"-10", L"2", L"1", L"5", L"75", 
			L"0.5", L"0.5", L"0", L"1.3", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Raging Flames",
			L"15", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::C));
		list.emplace_back(std::make_unique<Battalion>(L"Thief Pegasus Corps", 
			L"2", L"0", L"0", L"0", L"1", L"0", L"3", L"5", L"60", 
			L"0.5", L"0", L"0", L"0", L"1", L"0.5", L"0.5", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Pirate Pegasus Corps",
			L"2", L"0", L"0", L"0", L"1", L"0", L"3", L"5", L"60", 
			L"0.5", L"0", L"0", L"0", L"1", L"0.5", L"0.5", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Bandit Pegasus Corps",
			L"2", L"0", L"0", L"0", L"1", L"0", L"3", L"5", L"60",
			L"0.5", L"0", L"0", L"0", L"1", L"0.5", L"0.5", L"0", L"0",
			L"Disturbance",
			L"4", L"60", L"1", L"2",
			L"Inflicts rattled status on all targets.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dahlman Guard", 
			L"0", L"3", L"20", L"0", L"0", L"3", L"3", L"10", L"105", 
			L"0", L"1.3", L"1.3", L"0", L"0", L"1", L"1", L"0", L"0",
			L"Resonant Flames",
			L"6", L"60", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dahlman Magic Co.", 
			L"0", L"2", L"10", L"0", L"0", L"2", L"3", L"5", L"75",
			L"0", L"1", L"1.3", L"0", L"0", L"0.5", L"0.5", L"0", L"0",
			L"Group of Flames",
			L"2", L"60", L"1-2", L"1",
			L"Works as magical damage. Inflicts rattled status on all targets. Converts grassland, forest, thicket, wasteland, and house terrain within its area of effect into flame terrain for one turn.", 
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dahlman Armored Group", 
			L"3", L"0", L"10", L"0", L"0", L"3", L"0", L"5", L"75", 
			L"1", L"0", L"1.3", L"0", L"0", L"1.3", L"0", L"0", L"0",
			L"Assault Troop",
			L"10", L"50", L"1", L"2",
			L"Inflicts rattled status on all targets.",
			SL::E));
		list.emplace_back(std::make_unique<Battalion>(L"Dahlman PMC",
			L"2", L"0", L"10", L"0", L"0", L"2", L"0", L"3", L"75", 
			L"1", L"0", L"1.3", L"0", L"0", L"1", L"0", L"0", L"0",
			L"Onslaught",
			L"8", L"50", L"1", L"2",
			L"Pushes foe 1 tile away.", 
			SL::E));

		list.emplace_back(std::make_unique<Character>(L"---", 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Character>(L"Byleth", 
			L"27", L"4", L"13", L"6", L"9", L"8", L"8", L"6", L"6", L"7",
			L"0.45", L"0", L"0.45", L"0.35", L"0.45", L"0.45", L"0.45", L"0.35", L"0.3", L"0.45"));
		list.emplace_back(std::make_unique<Character>(L"Edelgard",
			L"29", L"4", L"13", L"6", L"5", L"8", L"5", L"6", L"4", L"10",
			L"0.4", L"0", L"0.55", L"0.45", L"0.45", L"0.4", L"0.3", L"0.35", L"0.35", L"0.6"));
		list.emplace_back(std::make_unique<Character>(L"Dorothea",
			L"24", L"4", L"5", L"11", L"6", L"7", L"6", L"4", L"7", L"8",
			L"0.4", L"0", L"0.2", L"0.4", L"0.45", L"0.4", L"0.35", L"0.15", L"0.35", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Ferdinand",
			L"28", L"4", L"8", L"5", L"6", L"8", L"6", L"6", L"2", L"7",
			L"0.5", L"0", L"0.45", L"0.2", L"0.4", L"0.5", L"0.4", L"0.35", L"0.2", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Hubert", 
			L"22", L"4", L"6", L"12", L"6", L"7", L"6", L"4", L"7", L"6",
			L"0.35", L"0", L"0.3", L"0.55", L"0.45", L"0.45", L"0.35", L"0.25", L"0.4", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Linhardt", 
			L"24", L"4", L"5", L"10", L"6", L"5", L"7", L"5", L"9", L"3",
			L"0.3", L"0", L"0.3", L"0.45", L"0.4", L"0.4", L"0.45", L"0.3", L"0.45", L"0.2"));
		list.emplace_back(std::make_unique<Character>(L"Caspar",
			L"26", L"4", L"9", L"3", L"5", L"6", L"8", L"6", L"2", L"4",
			L"0.55", L"0", L"0.45", L"0.25", L"0.45", L"0.45", L"0.4", L"0.3", L"0.2", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Bernadetta",
			L"25", L"4", L"8", L"5", L"7", L"7", L"5", L"4", L"2", L"6",
			L"0.35", L"0", L"0.35", L"0.2", L"0.55", L"0.5", L"0.25", L"0.2", L"0.3", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Petra",
			L"25", L"4", L"9", L"3", L"7", L"10", L"7", L"5", L"2", L"6",
			L"0.45", L"0", L"0.4", L"0.25", L"0.5", L"0.6", L"0.45", L"0.3", L"0.15", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Dimitri",
			L"28", L"4", L"12", L"4", L"7", L"7", L"5", L"7", L"4", L"9",
			L"0.55", L"0", L"0.6", L"0.2", L"0.5", L"0.5", L"0.25", L"0.4", L"0.2", L"0.55"));
		list.emplace_back(std::make_unique<Character>(L"Dedue",
			L"30", L"4", L"12", L"2", L"5", L"7", L"5", L"8", L"1", L"4",
			L"0.6", L"0", L"0.5", L"0.15", L"0.3", L"0.2", L"0.25", L"0.5", L"0.1", L"0.3"));
		list.emplace_back(std::make_unique<Character>(L"Felix",
			L"26", L"4", L"10", L"5", L"6", L"9", L"5", L"5", L"3", L"5",
			L"0.45", L"0", L"0.55", L"0.3", L"0.45", L"0.55", L"0.4", L"0.3", L"0.2", L"0.3"));
		list.emplace_back(std::make_unique<Character>(L"Ashe",
			L"23", L"4", L"8", L"5", L"8", L"9", L"6", L"5", L"6", L"5",
			L"0.35", L"0", L"0.35", L"0.25", L"0.55", L"0.5", L"0.4", L"0.2", L"0.35", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Sylvain",
			L"27", L"4", L"9", L"5", L"5", L"8", L"6", L"6", L"2", L"7",
			L"0.55", L"0", L"0.45", L"0.3", L"0.35", L"0.5", L"0.35", L"0.4", L"0.25", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Mercedes",
			L"25", L"4", L"6", L"10", L"6", L"8", L"5", L"5", L"9", L"8",
			L"0.3", L"0", L"0.25", L"0.5", L"0.45", L"0.4", L"0.3", L"0.25", L"0.45", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Annette", 
			L"23", L"4", L"6", L"11", L"7", L"7", L"6", L"5", L"4", L"6",
			L"0.25", L"0", L"0.3", L"0.5", L"0.5", L"0.35", L"0.35", L"0.2", L"0.3", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Ingrid",
			L"27", L"4", L"8", L"6", L"6", L"8", L"6", L"5", L"8", L"8",
			L"0.4", L"0", L"0.35", L"0.35", L"0.4", L"0.6", L"0.45", L"0.3", L"0.4", L"0.45"));
		list.emplace_back(std::make_unique<Character>(L"Claude",
			L"26", L"4", L"11", L"5", L"8", L"8", L"7", L"6", L"4", L"8",
			L"0.35", L"0", L"0.4", L"0.25", L"0.6", L"0.55", L"0.45", L"0.3", L"0.25", L"0.55"));
		list.emplace_back(std::make_unique<Character>(L"Lorenz",
			L"28", L"4", L"8", L"7", L"6", L"7", L"5", L"6", L"6", L"3",
			L"0.55", L"0", L"0.4", L"0.4", L"0.45", L"0.4", L"0.25", L"0.3", L"0.4", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Raphael", 
			L"30", L"4", L"11", L"3", L"5", L"6", L"6", L"7", L"1", L"4",
			L"0.65", L"0", L"0.5", L"0.15", L"0.35", L"0.15", L"0.35", L"0.45", L"0.1", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Ignatz",
			L"25", L"4", L"8", L"5", L"7", L"8", L"8", L"4", L"6", L"4",
			L"0.35", L"0", L"0.35", L"0.3", L"0.5", L"0.5", L"0.55", L"0.25", L"0.35", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Lysithea",
			L"22", L"4", L"4", L"11", L"7", L"7", L"4", L"3", L"4", L"5",
			L"0.2", L"0", L"0.15", L"0.6", L"0.6", L"0.5", L"0.15", L"0.1", L"0.25", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Marianne",
			L"23", L"4", L"5", L"11", L"6", L"7", L"6", L"4", L"8", L"7",
			L"0.35", L"0", L"0.2", L"0.5", L"0.4", L"0.4", L"0.35", L"0.15", L"0.45", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Hilda", 
			L"29", L"4", L"10", L"5", L"5", L"8", L"6", L"6", L"3", L"7",
			L"0.5", L"0", L"0.45", L"0.25", L"0.3", L"0.5", L"0.35", L"0.35", L"0.2", L"0.5"));
		list.emplace_back(std::make_unique<Character>(L"Leonie",
			L"26", L"4", L"9", L"5", L"8", L"9", L"6", L"7", L"2", L"7",
			L"0.4", L"0", L"0.4", L"0.2", L"0.55", L"0.6", L"0.4", L"0.4", L"0.15", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Flayn",
			L"24", L"4", L"6", L"9", L"6", L"5", L"4", L"5", L"10", L"9",
			L"0.25", L"0", L"0.25", L"0.55", L"0.45", L"0.35", L"0.15", L"0.25", L"0.5", L"0.45"));
		list.emplace_back(std::make_unique<Character>(L"Hanneman",
			L"25", L"4", L"6", L"10", L"6", L"6", L"4", L"5", L"7", L"5",
			L"0.4", L"0", L"0.3", L"0.55", L"0.45", L"0.2", L"0.35", L"0.25", L"0.4", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Seteth",
			L"27", L"4", L"9", L"8", L"8", L"5", L"6", L"6", L"4", L"9",
			L"0.5", L"0", L"0.45", L"0.35", L"0.5", L"0.5", L"0.25", L"0.3", L"0.25", L"0.45"));
		list.emplace_back(std::make_unique<Character>(L"Manuela",
			L"26", L"4", L"10", L"8", L"6", L"8", L"6", L"5", L"4", L"7",
			L"0.5", L"0", L"0.35", L"0.35", L"0.4", L"0.6", L"0.35", L"0.3", L"0.25", L"0.5"));
		list.emplace_back(std::make_unique<Character>(L"Gilbert",
			L"30", L"4", L"9", L"4", L"6", L"5", L"4", L"5", L"2", L"6",
			L"0.55", L"0", L"0.45", L"0.2", L"0.45", L"0.3", L"0.15", L"0.45", L"0.1", L"0.35"));
		list.emplace_back(std::make_unique<Character>(L"Alois",
			L"28", L"4", L"9", L"4", L"5", L"6", L"5", L"5", L"2", L"7",
			L"0.45", L"0", L"0.45", L"0.2", L"0.35", L"0.4", L"0.3", L"0.4", L"0.2", L"0.4"));
		list.emplace_back(std::make_unique<Character>(L"Catherine", 
			L"27", L"4", L"8", L"5", L"6", L"7", L"6", L"5", L"2", L"4",
			L"0.5", L"0", L"0.5", L"0.25", L"0.4", L"0.55", L"0.3", L"0.3", L"0.2", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Shamir",
			L"26", L"4", L"8", L"4", L"7", L"6", L"8", L"5", L"2", L"6",
			L"0.35", L"0", L"0.4", L"0.2", L"0.55", L"0.4", L"0.55", L"0.2", L"0.15", L"0.3"));
		list.emplace_back(std::make_unique<Character>(L"Cyril", 
			L"24", L"4", L"7", L"4", L"6", L"6", L"6", L"5", L"2", L"4",
			L"0.35", L"0", L"0.2", L"0.15", L"0.4", L"0.4", L"0.3", L"0.1", L"0.1", L"0.15"));
		list.emplace_back(std::make_unique<Character>(L"Jeritza",
			L"30", L"4", L"8", L"6", L"6", L"8", L"4", L"7", L"5", L"3",
			L"0.5", L"0", L"0.5", L"0.35", L"0.35", L"0.6", L"0.3", L"0.4", L"0.25", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Anna",
			L"26", L"4", L"7", L"7", L"7", L"7", L"7", L"5", L"7", L"7",
			L"0.35", L"0", L"0.35", L"0.35", L"0.45", L"0.55", L"0.45", L"0.3", L"0.4", L"0.5"));
		list.emplace_back(std::make_unique<Character>(L"Yuri",
			L"24", L"4", L"10", L"6", L"7", L"9", L"7", L"5", L"7", L"8",
			L"0.3", L"0", L"0.4", L"0.35", L"0.4", L"0.65", L"0.45", L"0.3", L"0.35", L"0.5"));
		list.emplace_back(std::make_unique<Character>(L"Balthus", 
			L"28", L"4", L"11", L"5", L"4", L"7", L"3", L"7", L"4", L"4",
			L"0.5", L"0", L"0.5", L"0.3", L"0.25", L"0.3", L"0.2", L"0.45", L"0.3", L"0.3"));
		list.emplace_back(std::make_unique<Character>(L"Constance", 
			L"23", L"4", L"5", L"11", L"6", L"6", L"4", L"3", L"4", L"6",
			L"0.2", L"0", L"0.2", L"0.6", L"0.3", L"0.35", L"0.15", L"0.15", L"0.3", L"0.25"));
		list.emplace_back(std::make_unique<Character>(L"Hapi",
			L"26", L"4", L"6", L"11", L"8", L"6", L"4", L"4", L"7", L"4",
			L"0.35", L"0", L"0.35", L"0.45", L"0.45", L"0.4", L"0.2", L"0.15", L"0.45", L"0.25"));

		list.emplace_back(std::make_unique<BlankWeapon>(
			L"---", 
			false,
			L"NULL", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			SL::BLANK));
		list.emplace_back(std::make_unique<Sword>(
			L"Broken Sword", 
			false, 
			L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0", 
			SL::E));
		list.emplace_back(std::make_unique<Sword>(
			L"Iron Sword", 
			false,
			L"NULL", L"5", L"90", L"0", L"1", L"5", L"E", L"40", 
			SL::E));
		list.emplace_back(std::make_unique<Sword>(
			L"Iron Sword+", 
			false, 
			L"NULL", L"6", L"100", L"0", L"1", L"5", L"E", L"45", 
			SL::E));
		list.emplace_back(std::make_unique<Sword>(
			L"Steel Sword",
			false,
			L"NULL", L"8", L"85", L"0", L"1", L"10", L"D", L"50",
			SL::D));
		list.emplace_back(std::make_unique<Sword>(
			L"Steel Sword+", 
			false,
			L"NULL", L"10", L"85", L"0", L"1", L"10", L"D", L"55",
			SL::D));
		list.emplace_back(std::make_unique<Sword>(
			L"Silver Sword",
			false,
			L"NULL", L"12", L"90", L"0", L"1", L"8", L"B", L"30", 
			SL::B));
		list.emplace_back(std::make_unique<Sword>(
			L"Silver Sword+", 
			false,
			L"NULL", L"13", L"90", L"0", L"1", L"8", L"B", L"40", 
			SL::B));
		list.emplace_back(std::make_unique<Sword>(
			L"Brave Sword",
			false,
			L"NULL", L"9", L"75", L"0", L"1", L"12", L"B", L"30",
			SL::B));
		list.emplace_back(std::make_unique<Sword>(
			L"Brave Sword+", 
			false, 
			L"NULL", L"10", L"85", L"0", L"1", L"12", L"B", L"40", 
			SL::B));
		list.emplace_back(std::make_unique<Sword>(
			L"Killing Edge",
			false, 
			L"NULL", L"8", L"85", L"25", L"1", L"10", L"C", L"20",
			SL::C));
		list.emplace_back(std::make_unique<Sword>(
			L"Killing Edge+", 
			false, 
			L"NULL", L"9", L"85", L"35", L"1", L"10", L"C", L"25", 
			SL::C));
		list.emplace_back(std::make_unique<Sword>(
			L"Training Sword", 
			false, 
			L"NULL", L"3", L"100", L"0", L"1", L"4", L"E", L"50", 
			SL::E));
		list.emplace_back(std::make_unique<Sword>(
			L"Training Sword+", 
			false,
			L"NULL", L"3", L"100", L"0", L"1", L"2", L"E", L"65", 
			SL::E));
		list.emplace_back(std::make_unique<Sword>(
			L"Levin Sword", 
			false, 
			L"NULL", L"9", L"70", L"0", L"1-2", L"9", L"C", L"25",
			SL::C));
		list.emplace_back(std::make_unique<Sword>(
			L"Levin Sword+", 
			false, 
			L"NULL", L"9", L"70", L"0", L"1-3", L"9", L"C", L"30",
			SL::C));
		list.emplace_back(std::make_unique<Sword>(
			L"Armorslayer", 
			false, 
			L"NULL", L"8", L"80", L"0", L"1", L"11", L"D", L"20", 
			SL::D));
		list.emplace_back(std::make_unique<Sword>(
			L"Armorslayer+",
			false, 
			L"NULL", L"8", L"100", L"5", L"1", L"11", L"D", L"25",
			SL::D));
		list.emplace_back(std::make_unique<Sword>(
			L"Rapier", 
			false, 
			L"NULL", L"7", L"95", L"10", L"1", L"5", L"E", L"40",
			SL::E));
		list.emplace_back(std::make_unique<Sword>(
			L"Rapier+",
			false, 
			L"NULL", L"9", L"95", L"20", L"1", L"5", L"E", L"45",
			SL::E));
		list.emplace_back(std::make_unique<Sword>(
			L"Devil Sword",
			false, 
			L"NULL", L"13", L"65", L"0", L"1", L"10", L"D", L"30",
			SL::D));
		list.emplace_back(std::make_unique<Sword>(
			L"Devil Sword+",
			false,
			L"NULL", L"16", L"65", L"0", L"1", L"10", L"D", L"30",
			SL::D));
		list.emplace_back(std::make_unique<Sword>(
			L"Wo Dao",
			false, 
			L"NULL", L"8", L"90", L"30", L"1", L"5", L"B", L"15", 
			SL::B));
		list.emplace_back(std::make_unique<Sword>(
			L"Wo Dao+", 
			false, 
			L"NULL", L"9", L"90", L"40", L"1", L"5", L"B", L"25",
			SL::B));
		list.emplace_back(std::make_unique<Sword>(
			L"Sword of Seiros",
			false,
			L"NULL", L"11", L"80", L"10", L"1", L"6", L"A", L"30", 
			SL::A));
		list.emplace_back(std::make_unique<Sword>(
			L"Sword of Begalta",
			true,
			L"Claude", L"12", L"100", L"0", L"1", L"5", L"A", L"30",
			SL::A));
		list.emplace_back(std::make_unique<Sword>(
			L"Sword of Moralta", 
			false,
			L"NULL", L"13", L"75", L"25", L"1", L"9", L"A", L"30",
			SL::A));
		list.emplace_back(std::make_unique<Sword>(
			L"Cursed Ashiya Sword",
			true, 
			L"Felix", L"13", L"70", L"40", L"1", L"8", L"B", L"15",
			SL::B));
		list.emplace_back(std::make_unique<Sword>(
			L"Cursed Ashiya Sword+", 
			true, 
			L"Felix", L"14", L"70", L"50", L"1", L"8", L"B", L"20", 
			SL::B));
		list.emplace_back(std::make_unique<Sword>(
			L"Sword of Zoltan",
			false, 
			L"NULL", L"13", L"90", L"0", L"1", L"9", L"A", L"25",
			SL::A));
		list.emplace_back(std::make_unique<Sword>(
			L"Sword of Zoltan+", 
			false, 
			L"NULL", L"16", L"90", L"5", L"1", L"9", L"A", L"30",
			SL::A));
		list.emplace_back(std::make_unique<Sword>(
			L"Thunderbrand", 
			true, 
			L"Catherine", L"13", L"70", L"10", L"1", L"7", L"E", L"30",
			SL::E));
		list.emplace_back(std::make_unique<Sword>(
			L"Blutgang", 
			true, 
			L"Marianne", L"13", L"80", L"0", L"1", L"7", L"E", L"20",
			SL::E));
		list.emplace_back(std::make_unique<Sword>(
			L"Sword of the Creator", 
			true, 
			L"Byleth", L"7", L"90", L"0", L"1-2", L"9", L"E", L"20",
			SL::E));
		list.emplace_back(std::make_unique<Sword>(
			L"Venin Edge", 
			false, 
			L"NULL", L"5", L"90", L"0", L"1", L"6", L"C", L"20", 
			SL::C));
		list.emplace_back(std::make_unique<Sword>(
			L"Venin Edge+",
			false, 
			L"NULL", L"6", L"100", L"0", L"1", L"6", L"C", L"25",
			SL::C));
		list.emplace_back(std::make_unique<Sword>(
			L"Mercurius", 
			false, 
			L"NULL", L"15", L"100", L"10", L"1", L"7", L"A", L"40",
			SL::A));
		list.emplace_back(std::make_unique<Sword>(
			L"Rusted Sword", 
			false, 
			L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0",
			SL::E));
		list.emplace_back(std::make_unique<Lance>(
			L"Broken Lance", 
			false,
			L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0",
			SL::E));
		list.emplace_back(std::make_unique<Lance>(
			L"Iron Lance", 
			false,
			L"NULL", L"6", L"80", L"0", L"1", L"6", L"E", L"30", 
			SL::E));
		list.emplace_back(std::make_unique<Lance>(
			L"Iron Lance+", 
			false,
			L"NULL", L"7", L"90", L"0", L"1", L"6", L"E", L"35", 
			SL::E));
		list.emplace_back(std::make_unique<Lance>(
			L"Steel Lance", 
			false, 
			L"NULL", L"9", L"75", L"0", L"1", L"11", L"D", L"40", 
			SL::D));
		list.emplace_back(std::make_unique<Lance>(
			L"Steel Lance+", 
			false,
			L"NULL", L"11", L"75", L"0", L"1", L"11", L"D", L"45",
			SL::D));
		list.emplace_back(std::make_unique<Lance>(
			L"Silver Lance", 
			false,
			L"NULL", L"13", L"80", L"0", L"1", L"9", L"B", L"25",
			SL::B));
		list.emplace_back(std::make_unique<Lance>(
			L"Silver Lance+",
			false,
			L"NULL", L"14", L"80", L"0", L"1", L"9", L"B", L"35",
			SL::B));
		list.emplace_back(std::make_unique<Lance>(
			L"Brave Lance",
			false, 
			L"NULL", L"10", L"70", L"0", L"1", L"13", L"B", L"25",
			SL::B));
		list.emplace_back(std::make_unique<Lance>(
			L"Brave Lance+",
			false,
			L"NULL", L"11", L"80", L"0", L"1", L"13", L"B", L"35",
			SL::B));
		list.emplace_back(std::make_unique<Lance>(
			L"Killer Lance", 
			false, 
			L"NULL", L"9", L"80", L"25", L"1", L"11", L"C", L"20", 
			SL::C));
		list.emplace_back(std::make_unique<Lance>(
			L"Killer Lance+", 
			false, 
			L"NULL", L"10", L"80", L"35", L"1", L"11", L"C", L"25",
			SL::C));
		list.emplace_back(std::make_unique<Lance>(
			L"Training Lance",
			false,
			L"NULL", L"4", L"90", L"0", L"1", L"5", L"E", L"50",
			SL::E));
		list.emplace_back(std::make_unique<Lance>(
			L"Training Lance+",
			false,
			L"NULL", L"4", L"90", L"0", L"1", L"3", L"E", L"65",
			SL::E));
		list.emplace_back(std::make_unique<Lance>(
			L"Javelin",
			false, 
			L"NULL", L"2", L"80", L"0", L"1-2", L"8", L"D", L"30",
			SL::D));
		list.emplace_back(std::make_unique<Lance>(
			L"Javelin+", 
			false,
			L"NULL", L"3", L"80", L"0", L"1-2", L"8", L"D", L"40",
			SL::D));
		list.emplace_back(std::make_unique<Lance>(
			L"Short Spear", 
			false, 
			L"NULL", L"5", L"75", L"0", L"1-2", L"10", L"C", L"25", 
			SL::C));
		list.emplace_back(std::make_unique<Lance>(
			L"Short Spear+",
			false, 
			L"NULL", L"6", L"75", L"0", L"1-2", L"10", L"C", L"35", 
			SL::C));
		list.emplace_back(std::make_unique<Lance>(
			L"Spear",
			false,
			L"NULL", L"8", L"70", L"0", L"1-2", L"12", L"B", L"20",
			SL::B));
		list.emplace_back(std::make_unique<Lance>(
			L"Spear+", 
			false,
			L"NULL", L"9", L"70", L"0", L"1-2", L"12", L"B", L"30", 
			SL::B));
		list.emplace_back(std::make_unique<Lance>(
			L"Horseslayer",
			false, 
			L"NULL", L"8", L"70", L"0", L"1", L"13", L"D", L"20",
			SL::D));
		list.emplace_back(std::make_unique<Lance>(
			L"Horseslayer+",
			false, 
			L"NULL", L"8", L"90", L"5", L"1", L"13", L"D", L"25",
			SL::D));
		list.emplace_back(std::make_unique<Lance>(
			L"Blessed Lance", 
			false, 
			L"NULL", L"7", L"80", L"0", L"1", L"14", L"C", L"20",
			SL::C));
		list.emplace_back(std::make_unique<Lance>(
			L"Blessed Lance+", 
			false,
			L"NULL", L"9", L"80", L"0", L"1", L"14", L"C", L"20",
			SL::C));
		list.emplace_back(std::make_unique<Lance>(
			L"Crescent Sickle", 
			false, 
			L"NULL", L"10", L"80", L"0", L"1", L"12", L"B", L"50",
			SL::B));
		list.emplace_back(std::make_unique<Lance>(
			L"Crescent Sickle+",
			false, 
			L"NULL", L"11", L"80", L"10", L"1", L"12", L"B", L"55", 
			SL::B));
		list.emplace_back(std::make_unique<Lance>(
			L"Lance of Zoltan", 
			false, 
			L"NULL", L"15", L"80", L"0", L"1", L"10", L"A", L"20", 
			SL::A));
		list.emplace_back(std::make_unique<Lance>(
			L"Lance of Zoltan+",
			false,
			L"NULL", L"18", L"80", L"5", L"1", L"10", L"A", L"25",
			SL::A));
		list.emplace_back(std::make_unique<Lance>(
			L"Lance of Ruin", 
			true,
			L"Sylvain", L"22", L"65", L"20", L"1", L"9", L"E", L"20",
			SL::E));
		list.emplace_back(std::make_unique<Lance>(
			L"Areadbhar", 
			true, 
			L"Dimitri", L"19", L"75", L"10", L"1", L"9", L"E", L"20", 
			SL::E));
		list.emplace_back(std::make_unique<Lance>(
			L"Luin",
			true, 
			L"Ingrid", L"17", L"90", L"10", L"1", L"9", L"E", L"20",
			SL::E));
		list.emplace_back(std::make_unique<Lance>(
			L"Spear of Assal",
			true, 
			L"Seteth", L"14", L"85", L"10", L"1", L"9", L"A", L"30",
			SL::A));
		list.emplace_back(std::make_unique<Lance>(
			L"Arrow of Indra",
			false,
			L"NULL", L"12", L"75", L"0", L"1-2", L"14", L"C", L"30", 
			SL::C));
		list.emplace_back(std::make_unique<Lance>(
			L"Arrow of Indra+",
			false, 
			L"NULL", L"12", L"75", L"0", L"1-3", L"14", L"C", L"35", 
			SL::C));
		list.emplace_back(std::make_unique<Lance>(
			L"Venin Lance",
			false, 
			L"NULL", L"6", L"80", L"0", L"1", L"7", L"C", L"20", 
			SL::C));
		list.emplace_back(std::make_unique<Lance>(
			L"Venin Lance+", 
			false,
			L"NULL", L"7", L"90", L"0", L"1", L"7", L"C", L"25",
			SL::C));
		list.emplace_back(std::make_unique<Lance>(
			L"Gradivus",
			false, 
			L"NULL", L"17", L"90", L"10", L"1-2", L"8", L"A", L"30",
			SL::A));
		list.emplace_back(std::make_unique<Lance>(
			L"Rusted Lance",
			false, 
			L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0", 
			SL::E));
		list.emplace_back(std::make_unique<Axe>(
			L"Broken Axe",
			false, 
			L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0", 
			SL::E));		
		list.emplace_back(std::make_unique<Axe>(
			L"Iron Axe", 
			false, 
			L"NULL", L"8", L"70", L"0", L"1", L"7", L"E", L"45",
			SL::E));
		list.emplace_back(std::make_unique<Axe>(
			L"Iron Axe+", 
			false, 
			L"NULL", L"9", L"80", L"0", L"1", L"7", L"E", L"50",
			SL::E));
		list.emplace_back(std::make_unique<Axe>(
			L"Steel Axe",
			false, 
			L"NULL", L"11", L"65", L"0", L"1", L"12", L"D", L"55", 
			SL::D));
		list.emplace_back(std::make_unique<Axe>(
			L"Steel Axe+",
			false,
			L"NULL", L"13", L"65", L"0", L"1", L"12", L"D", L"60", 
			SL::D));
		list.emplace_back(std::make_unique<Axe>(
			L"Silver Axe", 
			false, 
			L"NULL", L"16", L"70", L"0", L"1", L"10", L"B", L"30",
			SL::B));
		list.emplace_back(std::make_unique<Axe>(
			L"Silver Axe+",
			false, 
			L"NULL", L"17", L"70", L"0", L"1", L"10", L"B", L"40",
			SL::B));
		list.emplace_back(std::make_unique<Axe>(
			L"Brave Axe",
			false,
			L"NULL", L"12", L"60", L"0", L"1", L"14", L"B", L"30", 
			SL::B));
		list.emplace_back(std::make_unique<Axe>(
			L"Brave Axe+", 
			false, 
			L"NULL", L"13", L"70", L"0", L"1", L"14", L"B", L"40",
			SL::B));
		list.emplace_back(std::make_unique<Axe>(
			L"Killer Axe", 
			false, 
			L"NULL", L"11", L"70", L"25", L"1", L"12", L"C", L"20", 
			SL::C));
		list.emplace_back(std::make_unique<Axe>(
			L"Killer Axe+", 
			false, 
			"NULL", L"12", L"70", L"35", L"1", L"12", L"C", L"25", 
			SL::C));
		list.emplace_back(std::make_unique<Axe>(
			L"Training Axe",
			false, 
			L"NULL", L"6", L"80", L"0", L"1", L"6", L"E", L"50",
			SL::E));
		list.emplace_back(std::make_unique<Axe>(
			L"Training Axe+",
			false,
			L"NULL", L"6", L"80", L"0", L"1", L"4", L"E", L"65", 
			SL::E));
		list.emplace_back(std::make_unique<Axe>(
			L"Bolt Axe",
			false, 
			L"NULL", L"14", L"60", L"0", L"1-2", L"15", L"B", L"25", 
			SL::B));
		list.emplace_back(std::make_unique<Axe>(
			L"Bolt Axe+", 
			false, 
			L"NULL", L"14", L"60", L"0", L"1-3", L"15", L"B", L"30", 
			SL::B));
		list.emplace_back(std::make_unique<Axe>(
			L"Hand Axe",
			false,
			L"NULL", L"4", L"70", L"0", L"1-2", L"10", L"D", L"30", 
			SL::D));
		list.emplace_back(std::make_unique<Axe>(
			L"Hand Axe+", 
			false, 
			L"NULL", L"5", L"70", L"0", L"1-2", L"10", L"D", L"40",
			SL::D));
		list.emplace_back(std::make_unique<Axe>(
			L"Short Axe",
			false, 
			L"NULL", L"8", L"65", L"0", L"1-2", L"12", L"C", L"25", 
			SL::C));
		list.emplace_back(std::make_unique<Axe>(
			L"Short Axe+", 
			false, 
			L"NULL", L"9", L"65", L"0", L"1-2", L"12", L"C", L"35",
			SL::C));
		list.emplace_back(std::make_unique<Axe>(
			L"Tomahawk", 
			false,
			L"NULL", L"12", L"60", L"0", L"1-2", L"14", L"B", L"20", 
			SL::B));
		list.emplace_back(std::make_unique<Axe>(
			L"Tomahawk+", 
			false, 
			L"NULL", L"13", L"60", L"0", L"1-2", L"14", L"B", L"30",
			SL::B));
		list.emplace_back(std::make_unique<Axe>(
			L"Hammer", 
			false, 
			L"NULL", L"10", L"60", L"0", L"1", L"15", L"D", L"20", 
			SL::D));
		list.emplace_back(std::make_unique<Axe>(
			L"Hammer+",
			false, 
			L"NULL", L"10", L"80", L"5", L"1", L"15", L"D", L"25", 
			SL::D));
		list.emplace_back(std::make_unique<Axe>(
			L"Devil Axe", 
			false, 
			L"NULL", L"18", L"60", L"0", L"1", L"14", L"D", L"30", 
			SL::D));
		list.emplace_back(std::make_unique<Axe>(
			L"Devil Axe+", 
			false, 
			L"NULL", L"21", L"60", L"0", L"1", L"14", L"D", L"30", 
			SL::D));
		list.emplace_back(std::make_unique<Axe>(
			L"Freikugel", 
			true, 
			L"Hilda", L"23", L"65", L"10", L"1", L"11", L"E", L"20", 
			SL::E));
		list.emplace_back(std::make_unique<Axe>(
			L"Crusher",
			true,
			L"Annette", L"18", L"60", L"0", L"1", L"11", L"E", L"20",
			SL::E));
		list.emplace_back(std::make_unique<Axe>(
			L"Axe of Ukonvasara",
			true,
			L"Lorenz", L"19", L"65", L"20", L"1", L"15", L"A", L"30", 
			SL::A));
		list.emplace_back(std::make_unique<Axe>(
			L"Axe of Zoltan", 
			false, 
			L"NULL", L"17", L"70", L"0", L"1", L"14", L"A", L"20",
			SL::A));
		list.emplace_back(std::make_unique<Axe>(
			L"Axe of Zoltan+",
			false,
			L"NULL", L"20", L"70", L"5", L"1", L"14", L"A", L"25",
			SL::A));
		list.emplace_back(std::make_unique<Axe>(
			L"Mace", 
			false,
			L"NULL", L"6", L"70", L"0", L"1", L"6", L"E", L"20",
			SL::E));
		list.emplace_back(std::make_unique<Axe>(
			L"Mace+", 
			false,
			L"NULL", L"6", L"90", L"5", L"1", L"6", L"E", L"25", 
			SL::E));
		list.emplace_back(std::make_unique<Axe>(
			L"Amyr", 
			true,
			L"Edelgard,Rhea", L"24", L"60", L"20", L"1", L"11", L"E", L"20",
			SL::E));
		list.emplace_back(std::make_unique<Axe>(
			L"Venin Axe", 
			false, 
			L"NULL", L"8", L"70", L"0", L"1", L"8", L"C", L"20",
			SL::C));
		list.emplace_back(std::make_unique<Axe>(
			L"Venin Axe+",
			false,
			L"NULL", L"9", L"80", L"0", L"1", L"8", L"C", L"25",
			SL::C));
		list.emplace_back(std::make_unique<Axe>(
			L"Hauteclere", 
			false, 
			L"NULL", L"19", L"80", L"10", L"1", L"12", L"A", L"40", 
			SL::A));
		list.emplace_back(std::make_unique<Axe>(
			L"Rusted Axe", 
			false, 
			L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0", 
			SL::E));
		list.emplace_back(std::make_unique<Bow>(
			L"Broken Bow",
			false, 
			L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0",
			SL::E));
		list.emplace_back(std::make_unique<Bow>(
			L"Iron Bow", 
			false, 
			L"NULL", L"6", L"85", L"0", L"2", L"6", L"E", L"40",
			SL::E));
		list.emplace_back(std::make_unique<Bow>(
			L"Iron Bow+",
			false, 
			L"NULL", L"7", L"95", L"0", L"2", L"5", L"E", L"45", 
			SL::E));
		list.emplace_back(std::make_unique<Bow>(
			L"Steel Bow",
			false, 
			L"NULL", L"9", L"80", L"0", L"2", L"11", L"D", L"50", 
			SL::D));
		list.emplace_back(std::make_unique<Bow>(L"Steel Bow+",
			false, 
			L"NULL", L"11", L"80", L"0", L"2", L"10", L"D", L"55",
			SL::D));
		list.emplace_back(std::make_unique<Bow>(
			L"Silver Bow",
			false, 
			L"NULL", L"12", L"75", L"0", L"2", L"9", L"B", L"30",
			SL::B));
		list.emplace_back(std::make_unique<Bow>(
			L"Silver Bow+", 
			false, 
			L"NULL", L"13", L"75", L"0", L"2", L"8", L"B", L"40",
			SL::B));
		list.emplace_back(std::make_unique<Bow>(
			L"Brave Bow", 
			false, 
			L"NULL", L"10", L"70", L"0", L"2", L"13", L"B", L"30", 
			SL::B));
		list.emplace_back(std::make_unique<Bow>(
			L"Brave Bow+", 
			false, 
			L"NULL", L"11", L"80", L"0", L"2", L"12", L"B", L"40", 
			SL::B));
		list.emplace_back(std::make_unique<Bow>(
			L"Killer Bow", 
			false, 
			L"NULL", L"9", L"80", L"25", L"2", L"11", L"C", L"20", 
			SL::C));
		list.emplace_back(std::make_unique<Bow>(
			L"Killer Bow+",
			false, 
			L"NULL", L"10", L"80", L"35", L"2", L"11", L"C", L"25", 
			SL::C));
		list.emplace_back(std::make_unique<Bow>(
			L"Training Bow",
			false, 
			L"NULL", L"3", L"90", L"0", L"2", L"5", L"E", L"50", 
			SL::E));
		list.emplace_back(std::make_unique<Bow>(
			L"Training Bow+",
			false, 
			L"NULL", L"3", L"90", L"0", L"2", L"3", L"E", L"65", 
			SL::E));
		list.emplace_back(std::make_unique<Bow>(
			L"Magic Bow", 
			false, 
			L"NULL", L"8", L"75", L"0", L"2", L"9", L"B", L"25", 
			SL::B));
		list.emplace_back(std::make_unique<Bow>(
			L"Magic Bow+", 
			false, 
			L"NULL", L"8", L"75", L"0", L"2-3", L"9", L"B", L"30",
			SL::B));
		list.emplace_back(std::make_unique<Bow>(
			L"Longbow", 
			false,
			L"NULL", L"9", L"70", L"0", L"2-3", L"13", L"C", L"20",
			SL::C));
		list.emplace_back(std::make_unique<Bow>(
			L"Longbow+", 
			false, 
			L"NULL", L"11", L"70", L"0", L"2-3", L"13", L"C", L"25",
			SL::C));
		list.emplace_back(std::make_unique<Bow>(
			L"Mini Bow",
			false,
			L"NULL", L"4", L"90", L"0", L"1-2", L"3", L"D", L"50",
			SL::D));
		list.emplace_back(std::make_unique<Bow>(
			L"Mini Bow+", 
			false,
			L"NULL", L"6", L"90", L"10", L"1-2", L"3", L"D", L"55",
			SL::D));
		list.emplace_back(std::make_unique<Bow>(
			L"Blessed Bow", 
			false,
			L"NULL", L"6", L"70", L"0", L"2", L"14", L"C", L"20",
			SL::C));
		list.emplace_back(std::make_unique<Bow>(
			L"Blessed Bow+", 
			false,
			L"NULL", L"8", L"70", L"0", L"2", L"14", L"C", L"20",
			SL::C));
		list.emplace_back(std::make_unique<Bow>(
			L"Tathlum Bow", 
			true,
			L"Mercedes,Jeritza", L"13", L"80", L"10", L"2", L"11", L"A", L"30",
			SL::A));
		list.emplace_back(std::make_unique<Bow>(
			L"The Inexhaustible",
			true,
			L"Seteth", L"11", L"80", L"0", L"2", L"11", L"A", L"30", 
			SL::A));
		list.emplace_back(std::make_unique<Bow>(
			L"Bow of Zoltan",
			false,
			L"NULL", L"13", L"75", L"0", L"2", L"8", L"A", L"20", 
			SL::A));
		list.emplace_back(std::make_unique<Bow>(
			L"Bow of Zoltan+", 
			false, 
			L"NULL", L"16", L"75", L"5", L"2", L"8", L"A", L"25", 
			SL::A));
		list.emplace_back(std::make_unique<Bow>(
			L"Failnaught", 
			true, 
			L"Claude", L"18", L"75", L"20", L"2-3", L"9", L"E", L"20",
			SL::E));
		list.emplace_back(std::make_unique<Bow>(
			L"Venin Bow",
			false, 
			L"NULL", L"6", L"85", L"0", L"2", L"6", L"C", L"20", 
			SL::C));
		list.emplace_back(std::make_unique<Bow>(
			L"Venin Bow+",
			false, 
			L"NULL", L"7", L"95", L"0", L"2", L"6", L"C", L"25", 
			SL::C));
		list.emplace_back(std::make_unique<Bow>(
			L"Parthia", 
			false, 
			L"NULL", L"15", L"85", L"10", L"2", L"7", L"A", L"40", 
			SL::A));
		list.emplace_back(std::make_unique<Bow>(
			L"Rusted Bow", 
			false,
			L"NULL", L"0", L"30", L"0", L"2", L"5", L"E", L"0",
			SL::E));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Broken Gauntlets",
			false, 
			L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0",
			SL::E));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Iron Gauntlets",
			false, 
			L"NULL", L"1", L"85", L"5", L"1", L"3", L"E", L"50",
			SL::E));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Iron Gauntlets+",
			false, 
			L"NULL", L"1", L"95", L"5", L"1", L"3", L"E", L"60",
			SL::E));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Steel Gauntlets", 
			false,
			L"NULL", L"3", L"80", L"5", L"1", L"5", L"D", L"60", 
			SL::D));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Steel Gauntlets+",
			false, 
			L"NULL", L"3", L"85", L"5", L"1", L"5", L"D", L"70", 
			SL::D));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Silver Gauntlets",
			false,
			L"NULL", L"4", L"85", L"5", L"1", L"7", L"B", L"40",
			SL::B));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Silver Gauntlets+", 
			false, 
			L"NULL", L"4", L"90", L"5", L"1", L"7", L"B", L"55", 
			SL::B));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Training Gauntlets",
			false, 
			L"NULL", L"0", L"90", L"5", L"1", L"1", L"E", L"70",
			SL::E));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Training Gauntlets+", 
			false, 
			L"NULL", L"0", L"100", L"5", L"1", L"1", L"E", L"90", 
			SL::E));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Dragon Claws",
			false,
			L"NULL", L"4", L"75", L"5", L"1", L"7", L"A", L"30",
			SL::A));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Dragon Claws+",
			false, 
			L"NULL", L"4", L"85", L"5", L"1", L"7", L"A", L"40",
			SL::A));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Killer Knuckles", 
			false,
			L"NULL", L"3", L"80", L"20", L"1", L"5", L"B", L"30",
			SL::B));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Killer Knuckles+", 
			false, 
			L"NULL", L"3", L"80", L"30", L"1", L"5", L"B", L"40",
			SL::B));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Aura Knuckles", 
			false, 
			L"NULL", L"2", L"70", L"0", L"1", L"4", L"A", L"30",
			SL::A));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Aura Knuckles+", 
			false,
			L"NULL", L"2", L"80", L"0", L"1", L"4", L"A", L"40",
			SL::A));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Rusted Gauntlets", 
			false, 
			L"NULL", L"0", L"30", L"0", L"1", L"20", L"E", L"0",
			SL::E));
		list.emplace_back(std::make_unique<Gauntlets>(
			L"Vajra-Mushti", 
			true, 
			L"Balthus", L"7", L"90", L"10", L"1", L"7", L"E", L"30", 
			SL::E));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Fire", 
			false,
			L"NULL", L"3", L"90", L"0", L"1-2", L"3", L"E", L"10",
			SL::E));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Bolganone", 
			false, 
			L"NULL", L"8", L"85", L"0", L"1-2", L"6", L"C", L"5",
			SL::C));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Ragnarok",
			false, 
			L"NULL", L"15", L"80", L"5", L"1-2", L"9", L"B", L"3",
			SL::B));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Thunder",
			false, 
			L"NULL", L"4", L"80", L"5", L"1-2", L"4", L"E", L"8", 
			SL::E));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Thoron", 
			false, 
			L"NULL", L"9", L"75", L"10", L"1-3", L"7", L"C", L"4", 
			SL::C));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Bolting", 
			false, 
			L"NULL", L"12", L"65", L"15", L"3-10", L"18", L"B", L"2",
			SL::B));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Wind",
			false,
			L"NULL", L"2", L"100", L"10", L"1-2", L"2", L"E", L"12",
			SL::E));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Cutting Gale", 
			false, 
			L"NULL", L"7", L"95", L"10", L"1-2", L"5", L"C", L"6", 
			SL::C));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Excalibur", 
			false, 
			L"NULL", L"11", L"100", L"15", L"1-2", L"8", L"B", L"4",
			SL::B));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Blizzard", 
			false,
			L"NULL", L"3", L"70", L"15", L"1-2", L"4", L"E", L"10", 
			SL::E));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Fimbulvetr", 
			false, 
			L"NULL", L"12", L"65", L"25", L"1-2", L"10", L"B", L"3", 
			SL::B));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Sagittae",
			false,
			L"NULL", L"7", L"90", L"5", L"1-2", L"6", L"C", L"10",
			SL::C));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Meteor", 
			false,
			L"NULL", L"10", L"80", L"0", L"3-10", L"19", L"B", L"1",
			SL::B));
		list.emplace_back(std::make_unique<BlackMagic>(
			L"Agnea's Arrow",
			false,
			L"NULL", L"16", L"70", L"5", L"1-2", L"13", L"A", L"2",
			SL::A));
		list.emplace_back(std::make_unique<DarkMagic>(
			L"Miasma", 
			false,
			L"NULL", L"5", L"80", L"0", L"1-2", L"5", L"E", L"10", 
			SL::E));
		list.emplace_back(std::make_unique<DarkMagic>(
			L"Mire",
			false, 
			L"NULL", L"3", L"70", L"0", L"1-3", L"5", L"E", L"8", 
			SL::E));
		list.emplace_back(std::make_unique<DarkMagic>(
			L"Swarm", 
			false, 
			L"NULL", L"4", L"70", L"0", L"1-2", L"4", L"E", L"8", 
			SL::E));
		list.emplace_back(std::make_unique<DarkMagic>(
			L"Banshee",
			false, 
			L"NULL", L"9", L"75", L"5", L"1-2", L"9", L"C", L"5", 
			SL::C));
		list.emplace_back(std::make_unique<DarkMagic>(
			L"Death", 
			false,
			L"NULL", L"6", L"70", L"20", L"1-3", L"8", L"C", L"4", 
			SL::C));
		list.emplace_back(std::make_unique<DarkMagic>(
			L"Luna", 
			false,
			L"NULL", L"1", L"65", L"0", L"1-2", L"7", L"C", L"2", 
			SL::C));
		list.emplace_back(std::make_unique<DarkMagic>(
			L"Dark Spikes",
			false, 
			L"NULL", L"13", L"80", L"0", L"1-2", L"11", L"B", L"3", 
			SL::B));
		list.emplace_back(std::make_unique<DarkMagic>(
			L"Hades",
			false, 
			L"NULL", L"18", L"65", L"10", L"1-2", L"16", L"A", L"2", 
			SL::A));
		list.emplace_back(std::make_unique<DarkMagic>(
			L"Bohr",
			false,
			L"NULL", L"10", L"60", L"0", L"3-10", L"20", L"B", L"3", 
			SL::B));
		list.emplace_back(std::make_unique<DarkMagic>(
			L"Quake",
			false,
			L"NULL", L"8", L"50", L"0", L"ALL", L"20", L"B", L"1",
			SL::B));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Heal", 
			false,

			L"NULL", L"8", L"100", L"0", L"1", L"0", L"E", L"10", SL::E));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Recover", 
			false, 
			L"NULL", L"30", L"100", L"0", L"1", L"0", L"C", L"5",
			SL::C));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Physic",
			false, 
			L"NULL", L"8", L"100", L"0", L"1", L"0", L"C", L"5", 
			SL::C));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Fortify", 
			false, 
			L"NULL", L"15", L"100", L"0", L"0", L"0", L"A", L"2", 
			SL::A));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Nosferatu",
			false, 
			L"NULL", L"1", L"80", L"0", L"1-2", L"8", L"E", L"12", 
			SL::E));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Seraphim", 
			false, 
			L"NULL", L"8", L"75", L"5", L"1-2", L"10", L"C", L"8", 
			SL::C));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Aura", 
			false,
			L"NULL", L"12", L"70", L"20", L"1-2", L"12", L"B", L"3", 
			SL::B));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Abraxas", 
			false, 
			L"NULL", L"14", L"90", L"5", L"1-2", L"13", L"A", L"2", 
			SL::A));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Torch", 
			false, 
			L"NULL", L"0", L"0", L"0", L"1-2", L"0", L"E", L"10",
			SL::E));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Restore", 
			false, 
			L"NULL", L"0", L"0", L"0", L"0", L"0", L"C", L"10", 
			SL::C));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Ward", 
			false, 
			L"NULL", L"0", L"0", L"0", L"1", L"0", L"C", L"5", 
			SL::C));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Silence", 
			false, 
			L"NULL", L"0", L"100", L"0", L"3-10", L"0", L"B", L"3", 
			SL::B));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Rescue",
			false,
			L"NULL", L"0", L"0", L"0", L"0", L"0", L"B", L"3", 
			SL::B));
		list.emplace_back(std::make_unique<WhiteMagic>(
			L"Warp", 
			false, 
			L"NULL", L"0", L"0", L"0", L"0", L"0", L"B", L"1", 
			SL::B));

		list.emplace_back(std::make_unique<BlankEquipment>(L"---", false, L"NULL", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"NULL"));

																								 //PROT, WEIGHT, RES, HIT, TCRIT, AVO, SPD, MOV, LCK, MATK, HEAL, RANGE
		list.emplace_back(std::make_unique<Shield>(
			L"Leather Shield", 
			false, 
			L"NULL",			
			L"1", L"1", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"NULL"));
		list.emplace_back(std::make_unique<Shield>(
			L"Iron Shield", 
			false, 
			L"NULL",				 
			L"2", L"2", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"NULL"));
		list.emplace_back(std::make_unique<Shield>(
			L"Steel Shield", 
			false, 
			L"NULL",				 
			L"3", L"3", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"NULL"));
		list.emplace_back(std::make_unique<Shield>(
			L"Silver Shield",
			false, 
			L"NULL",			
			L"4", L"4", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"NULL"));
		list.emplace_back(std::make_unique<Shield>(
			L"Talisman Shield",
			false,
			L"NULL",			
			L"1", L"4", L"2", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"Resilience +2"));
		list.emplace_back(std::make_unique<Shield>(
			L"Hexlock Shield", 
			false, 
			L"NULL",			
			L"2", L"5", L"4", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"Resilience +4"));
		list.emplace_back(std::make_unique<Shield>(
			L"Aegis Shield",
			true, 
			L"Felix",				 
			L"6", L"6", L"3", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"Relic shield. Resilience +3, may halve damage for Crest of Fraldarius."));
		list.emplace_back(std::make_unique<Shield>(
			L"Ochain Shield",
			true, 
			L"Seteth,Ferdinand", 
			L"6", L"4", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"Sacred shield (Cichol); restores HP each turn and negates foe’s critical hits."));
		list.emplace_back(std::make_unique<Shield>(
			L"Seiros Shield",
			true,
			L"Edelgard",		     
			L"5", L"3", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"Sacred shield (Seiros); restores HP each turn and halves damage from Monsters."));
		list.emplace_back(std::make_unique<Shield>(
			L"Aurora Shield", 
			false, 
			L"NULL",			 
			L"3", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"Nullifies user’s Flying-type weakness."));
		list.emplace_back(std::make_unique<Shield>(
			L"Kadmos Shield",
			false, 
			L"NULL",			 
			L"3", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"Nullifies user’s Armoured-type weakness."));
		list.emplace_back(std::make_unique<Shield>(
			L"Lampos Shield",
			false,
			L"NULL",			 
			L"3", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"Nullifies user’s Cavalry-type weakness."));
		list.emplace_back(std::make_unique<Ring>(
			L"Accuracy Ring", 
			false, 
			L"NULL",				 
			L"0", L"0", L"0", L"10", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"Hit rate +10"));
		list.emplace_back(std::make_unique<Ring>(
			L"Critical Ring", 
			false, 
			L"NULL",				 
			L"0", L"0", L"0", L"0",  L"5", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"Critical rate +5."));
		list.emplace_back(std::make_unique<Ring>(
			L"Evasion Ring", 
			false, 
			L"NULL",				
			L"0", L"0", L"0", L"0",  L"0", L"10",L"0", L"0", L"0", L"0", L"0", L"0", 
			L"Avoid +10."));
		list.emplace_back(std::make_unique<Ring>(
			L"Speed Ring",
			false, 
			L"NULL",					 
			L"0", L"0", L"0", L"0",  L"0", L"0", L"2", L"0", L"0", L"0", L"0", L"0", 
			L"Speed +2."));
		list.emplace_back(std::make_unique<Ring>(
			L"March Ring", 
			false,
			L"NULL",					
			L"0", L"0", L"0", L"0",  L"0", L"0", L"0", L"1", L"0", L"0", L"0", L"0", 
			L"Movement +1."));
		list.emplace_back(std::make_unique<Ring>(
			L"Goddess Ring", 
			false, 
			L"NULL",				 
			L"0", L"0", L"0", L"0",  L"0", L"0", L"0", L"0", L"8", L"0", L"0", L"0", 
			L"Luck +8; restores HP each turn."));
		list.emplace_back(std::make_unique<Ring>(
			L"Prayer Ring",
			false,
			L"NULL",				 
			L"0", L"0", L"0", L"0",  L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"Grants Miracle ability; restores HP each turn."));
		list.emplace_back(std::make_unique<Ring>(
			L"Fetters of Dromi",
			true, 
			L"Yuri",			 
			L"0", L"0", L"0", L"0",  L"0", L"0", L"0", L"1", L"0", L"0", L"0", L"0", 
			L"Relic ring (Aubin); Movement +1, user can continue moving after taking certain actions and may halve damage received."));
		list.emplace_back(std::make_unique<Staff>(
			L"Magic Staff", 
			false, 
			L"NULL",				
			L"0", L"1", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"3", L"0", L"0",
			L"Increases Might of magic spells by 3."));
		list.emplace_back(std::make_unique<Staff>(
			L"Healing Staff", 
			false, 
			L"NULL",				 
			L"0", L"1", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"10", L"0", 
			L"Increases Healing power by 10."));
		list.emplace_back(std::make_unique<Staff>(
			L"Caduceus Staff",
			true,
			L"Flayn,Linhardt",	
			L"0", L"1", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"1", 
			L"Sacred staff (Cethleann); offensive magic range +1, restores HP each turn."));
		list.emplace_back(std::make_unique<Staff>(
			L"Thyrsus", 
			true,
			L"Lysithea,Lorenz",			
			L"0", L"1", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"2", 
			L"Relic staff (Gloucester); offensive magic range +2, may halve damage received."));
		list.emplace_back(std::make_unique<Gem>(
			L"Experience Gem", 
			false,
			L"NULL",				 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"Base experience points +50%."));
		list.emplace_back(std::make_unique<Gem>(
			L"Knowledge Gem", 
			false, 
			L"NULL",				 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"Base skill level experience +100%."));
		list.emplace_back(std::make_unique<Gem>(
			L"Rafail Gem", 
			true, 
			L"Mercedes,Jeritza",		 
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", 
			L"Base skill level experience +100%."));

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
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Noble", false, L"NULL", 
			L"0", L"4", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0.05",
			L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0"));
		list.emplace_back(std::make_unique<Class>(L"Dancer", false, L"NULL", 
			L"0", L"6", L"0", L"0", L"0", L"0", L"0", L"0", L"0", L"0",
			L"0", L"2", L"1", L"0", L"3", L"3", L"0", L"2", L"1", L"2",
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
			L"0", L"3", L"0", L"0", L"0", L"-2", L"0", L"2", L"0", L"0"));
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

#endif
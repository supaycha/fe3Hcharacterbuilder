#include "../include/GTBmain.h"

void GTBWeaponStats::ReceiveLBWSelection(Stats stats) {
	weaponstats = stats;
}


void GTBEquipmentStats::ReceiveLBESelection(Stats stats) {
	equipmentstats = stats;
}


void GTBBattalionStats::ReceiveLBBSelection(Stats stats) {
	battalionstats = stats;
}


void GTBTotalStats::recalculate() {
	CalculateTotalPhysicalAttack();
	CalculateTotalMagicAttack();
	CalculateTotalPhysicalHit();
	CalculateTotalMagicHit();
	CalculateTotalCrit();
	CalculateAS();
	CalculateTotalProt();
	CalculateTotalResilience();
	CalculateTotalAvoid();
	CalculateTotalCritAvoid();
	CalculateTotalRange();
}

void GTBTotalStats::ReceiveGMTStats(Stats stats) {
	currentGMTstats = stats;
}

void GTBTotalStats::ReceiveGWSStats(Stats stats) {
	currentGWSstats = stats;
}

void GTBTotalStats::ReceiveGESStats(Stats stats) {
	currentGESstats = stats;
}

void GTBTotalStats::ReceiveGBSStats(Stats stats) {
	currentGBSstats = stats;
}

void GTBTotalStats::CalculateTotalPhysicalAttack() {
	std::wstring temp = currentGMTstats[2].getText();
	int lvcstat2 = _wtoi(temp.c_str());

	temp = currentGWSstats[0].getText();
	int lvwstat0 = _wtoi(temp.c_str());

	temp = currentGBSstats[0].getText();
	int lvbstat0 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat2 + lvwstat0 + lvbstat0);
	//	//+ ifEffective(Weapon Might x3)
	//	//+ Combat Art
	//	//+ Skills
	//	//+ Linked attacks
	//	//+/- Terrain Effects
	//	//- Enemies Protection);
	totalstats[0] = buffer;
}

void GTBTotalStats::CalculateTotalMagicAttack() {
	std::wstring temp = currentGMTstats[3].getText();
	int lvcstat3 = _wtoi(temp.c_str());

	temp = currentGWSstats[0].getText();
	int lvwstat0 = _wtoi(temp.c_str());

	temp = currentGBSstats[1].getText();
	int lvbstat1 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat3 + lvwstat0 + lvbstat1);
	//+ ifEffective(Weapon Might x3)
	//+ Combat Art
	//+ Skills
	//+/- Battalions
	//+ Staves
	//+ Linked attacks
	//+/- Terrain Effects
	//- Enemies Resilience);
	totalstats[1] = buffer;
}

void GTBTotalStats::CalculateTotalPhysicalHit() {
	std::wstring temp = currentGMTstats[4].getText();
	int lvcstat4 = _wtoi(temp.c_str());

	temp = currentGWSstats[1].getText();
	int lvwstat1 = _wtoi(temp.c_str());

	temp = currentGBSstats[2].getText();
	int lvbstat2 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat4 + lvwstat1 + lvbstat2);

	/*+ Combat Art
	+ Skills
	+/- Battalions
	+ Linked attacks
	+/- Terrain Effects
	- Enemies Avoid*/
	totalstats[2] = buffer;
}

void GTBTotalStats::CalculateTotalMagicHit() {
	std::wstring temp = currentGMTstats[4].getText();
	int lvcstat4 = _wtoi(temp.c_str());

	temp = currentGMTstats[6].getText();
	int lvcstat6 = _wtoi(temp.c_str());

	temp = currentGWSstats[1].getText();
	int lvwstat1 = _wtoi(temp.c_str());

	temp = currentGBSstats[2].getText();
	int lvbstat2 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring((lvcstat4 / 2) + (lvcstat6 / 2) + lvwstat1 + lvbstat2);

	/*+ Skills
	+ Linked attacks
	- Enemies Magic Avoid*/
	totalstats[3] = buffer;
}

void GTBTotalStats::CalculateTotalCrit() {
	std::wstring temp = currentGMTstats[4].getText();
	int lvcstat4 = _wtoi(temp.c_str());

	temp = currentGMTstats[6].getText();
	int lvcstat6 = _wtoi(temp.c_str());

	temp = currentGWSstats[2].getText();
	int lvwstat2 = _wtoi(temp.c_str());

	temp = currentGBSstats[3].getText();
	int lvbstat3 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat4 + (lvcstat6 / 2) + lvwstat2 + lvbstat3);

	totalstats[4] = buffer;
	/////*+Skills*/);
}

void GTBTotalStats::CalculateAS() {
	std::wstring temp = currentGMTstats[5].getText();
	int lvcstat5 = _wtoi(temp.c_str());

	temp = currentGWSstats[4].getText();
	int lvwstat4 = _wtoi(temp.c_str());

	temp = currentGWSstats[2].getText();
	int lvwstat2 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat5 + lvwstat4 - (lvwstat2 / 5));

	totalstats[5] = buffer;
}

void GTBTotalStats::CalculateTotalProt() {
	std::wstring temp = currentGMTstats[7].getText();
	int lvcstat7 = _wtoi(temp.c_str());

	temp = currentGESstats[6].getText();
	int lvestat6 = _wtoi(temp.c_str());

	temp = currentGBSstats[5].getText();
	int lvbstat5 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat7 + lvestat6 + lvbstat5);

	totalstats[6] = buffer;
}

void GTBTotalStats::CalculateTotalResilience() {
	std::wstring temp = currentGMTstats[8].getText();
	int lvcstat8 = _wtoi(temp.c_str());

	temp = currentGESstats[7].getText();
	int lvestat7 = _wtoi(temp.c_str());

	temp = currentGBSstats[6].getText();
	int lvbstat6 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat8 + lvestat7 + lvbstat6);

	totalstats[7] = buffer;
}

void GTBTotalStats::CalculateTotalAvoid() {
	std::wstring temp = totalstats[5].getText();
	int totalstats5 = _wtoi(temp.c_str());

	temp = currentGBSstats[4].getText();
	int lvbstat4 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(totalstats5 + lvbstat4);

	totalstats[8] = buffer;

	//	/*+ Skills
	//	+/- Terrain Effects*//*)*/;
}

void GTBTotalStats::CalculateTotalCritAvoid() {
	std::wstring temp = currentGWSstats[2].getText();
	int lvwstat2 = _wtoi(temp.c_str());

	temp = currentGMTstats[6].getText();
	int lvcstat6 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvwstat2 - lvcstat6);

	totalstats[9] = buffer;
}

void GTBTotalStats::CalculateTotalRange() {
	std::wstring temp = currentGWSstats[3].getText();
	int lvwstat3 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvwstat3);
	totalstats[10] = buffer;
}

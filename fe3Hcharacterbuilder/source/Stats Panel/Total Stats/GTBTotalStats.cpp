#include <Stats Panel/Total Stats/GTBTotalStats.h>

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

void GTBTotalStats::ReceiveGCHIASStats(Stats stats) {
	currentGCHIASstats = stats;
}

void GTBTotalStats::ReceiveGCLIASStats(Stats stats, int index) {
	currentGCLIASstats[index] = stats;
}

void GTBTotalStats::ReceiveGSLASStats(Stats stats, int index) {
	currentGSLASstats[index] = stats;
}

void GTBTotalStats::CalculateTotalPhysicalAttack() {
	std::wstring temp = currentGMTstats[2].getText();
	int lvcstat2 = _wtoi(temp.c_str());

	temp = currentGWSstats[0].getText();
	int lvwstat0 = _wtoi(temp.c_str());

	//temp = currentGWSstats[0].getText();
	//int lvwstat0 = _wtoi(temp.c_str());

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

	temp = currentGESstats[9].getText();
	int lvestat9 = _wtoi(temp.c_str());

	temp = currentGBSstats[1].getText();
	int lvbstat1 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat3 + lvwstat0 + lvestat9 + lvbstat1);
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

	temp = currentGESstats[3].getText();
	int lvestat3 = _wtoi(temp.c_str());

	temp = currentGBSstats[2].getText();
	int lvbstat2 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat4 + lvwstat1 + lvestat3 + lvbstat2);

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

	temp = currentGESstats[3].getText();
	int lvestat3 = _wtoi(temp.c_str());

	temp = currentGBSstats[2].getText();
	int lvbstat2 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring((lvcstat4 / 2) + (lvcstat6 / 2) + lvwstat1 + lvestat3 + lvbstat2);

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

	temp = currentGESstats[4].getText();
	int lvestat4 = _wtoi(temp.c_str());

	temp = currentGBSstats[3].getText();
	int lvbstat3 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat4 + (lvcstat6 / 2) + lvwstat2 + lvestat4 + lvbstat3);

	totalstats[4] = buffer;
	/////*+Skills*/);
}

void GTBTotalStats::CalculateAS() {

	//character strength
	std::wstring temp = currentGMTstats[2].getText();
	int lvcstat2 = _wtoi(temp.c_str());

	//character speed
	temp = currentGMTstats[5].getText();
	int lvcstat5 = _wtoi(temp.c_str());

	//weapon weight
	temp = currentGWSstats[4].getText();
	int lvwstat4 = _wtoi(temp.c_str());
	
	//equipment speed
	temp = currentGESstats[6].getText();
	int lvestat6 = _wtoi(temp.c_str());


	const std::wstring buffer = std::to_wstring((lvcstat5 + lvestat6) - (lvwstat4 - (lvcstat2 / 5)));

	totalstats[5] = buffer;
}

void GTBTotalStats::CalculateTotalProt() {

	std::wstring temp = currentGMTstats[7].getText();
	int lvcstat7 = _wtoi(temp.c_str());

	temp = currentGESstats[0].getText();
	int lvestat0 = _wtoi(temp.c_str());

	temp = currentGBSstats[5].getText();
	int lvbstat5 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat7 + lvestat0 + lvbstat5);

	totalstats[6] = buffer;
}

void GTBTotalStats::CalculateTotalResilience() {
	std::wstring temp = currentGMTstats[8].getText();
	int lvcstat8 = _wtoi(temp.c_str());

	temp = currentGESstats[2].getText();
	int lvestat2 = _wtoi(temp.c_str());

	temp = currentGBSstats[6].getText();
	int lvbstat6 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat8 + lvestat2 + lvbstat6);

	totalstats[7] = buffer;
}

void GTBTotalStats::CalculateTotalAvoid() {

	//total attack speed
	std::wstring temp = totalstats[5].getText();
	int totalstats5 = _wtoi(temp.c_str());

	//equipment avoid
	temp = currentGESstats[5].getText();
	int lvestat5 = _wtoi(temp.c_str());

	//battalion avoid 
	temp = currentGBSstats[4].getText();
	int lvbstat4 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(totalstats5 + lvestat5 + lvbstat4);

	totalstats[8] = buffer;

	//	/*+ Skills
	//	+/- Terrain Effects*//*)*/;
}

void GTBTotalStats::CalculateTotalCritAvoid() {
	//std::wstring temp = currentGWSstats[2].getText();
	//int lvwstat2 = _wtoi(temp.c_str());

	//character luck
	std::wstring temp = currentGMTstats[6].getText();
	int lvcstat6 = _wtoi(temp.c_str());

	temp = currentGESstats[8].getText();
	int lvestat8 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvcstat6 + lvestat8);

	totalstats[9] = buffer;
}

void GTBTotalStats::CalculateTotalRange() {
	std::wstring temp = currentGWSstats[3].getText();
	int lvwstat3 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(lvwstat3);
	totalstats[10] = buffer;
}
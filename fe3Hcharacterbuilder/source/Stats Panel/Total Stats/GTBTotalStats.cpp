#include <Stats Panel/Total Stats/GTBTotalStats.h>

void GTBTotalStats::recalculate() {
	CalculateAllAbilityStats();
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
void GTBTotalStats::CalculateAllAbilityStats() {
	CalculateCHIASStats();
	CalculateCLIASStats();
	CalculateSLASStats();
}

void GTBTotalStats::CalculateCHIASStats() {
	//ClearValues();
	for (auto awaystattype : incomingGCHIASstats) {
		for (auto& homestattype : currentCHIASvector) {
			if (awaystattype.stattype == homestattype.stattype) {
				homestattype.value = awaystattype.value;
			}
		}
	}
	int i = 9;
}

void GTBTotalStats::CalculateCLIASStats() {
	//ClearValues();
	for (auto awaystattype : incomingGCLIASstats) {
		for (auto& homestattype : currentCLIASvector) {
			if (awaystattype.stattype == homestattype.stattype) {
				homestattype.value = awaystattype.value;
			}
			//else if (awaystattype.stattype == STATTYPE::BLANK) {
			//	homestattype.value = "0";
			//}
		}
	}
	int i = 9;
}

void GTBTotalStats::CalculateSLASStats() {
	//ClearValues();
	for (auto awaystattype : incomingGSLASstats) {
		for (auto& homestattype : currentSLASvector) {
			if (awaystattype.stattype == homestattype.stattype) {
				homestattype.value = awaystattype.value;
			}
		}
	}
	int i = 9;
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

void GTBTotalStats::ReceiveGCHIASStats(STATPACKAGEVECTOR statsfromGCHIA) {
	incomingGCHIASstats = statsfromGCHIA;
}

void GTBTotalStats::ReceiveGCLIASStats(STATPACKAGEVECTOR statsfromGCLIA) {
	incomingGCLIASstats = statsfromGCLIA;
	int i = 0;
}

void GTBTotalStats::ReceiveGSLASStats(STATPACKAGEVECTOR statsfromGSLA) {
	incomingGSLASstats = statsfromGSLA;
	int i = 0;
}

int GTBTotalStats::RetrieveStatsFromAbilityPackages(STATTYPE st) {
	int tempchiavalue = RetrieveStatFromGCHIASPackage(st);
	int tempcliavalue = RetrieveStatFromGCLIASPackage(st);
	int tempslavalue = RetrieveStatFromGSLASPackage(st);

	int temptotal = tempchiavalue + tempcliavalue + tempslavalue;
	return temptotal;
}

int GTBTotalStats::RetrieveStatFromGCHIASPackage(STATTYPE st) {
	for (auto stattype : currentCHIASvector) {
		if (st == stattype.stattype) {
			int testing = _wtoi(stattype.value.c_str());
			return testing;
		}
	}

	return 0;
}

int GTBTotalStats::RetrieveStatFromGCLIASPackage(STATTYPE st) {
	for (auto stattype : currentCLIASvector) {
		if (st == stattype.stattype) {
			int testing = _wtoi(stattype.value.c_str());
			return testing;
		}
	}

	return 0;
}

int GTBTotalStats::RetrieveStatFromGSLASPackage(STATTYPE st) {
	for (auto stattype : currentSLASvector) {
		if (st == stattype.stattype) {
			int testing = _wtoi(stattype.value.c_str());
			return testing;
		}
	}

	return 0;
}

void GTBTotalStats::CalculateTotalPhysicalAttack() {
	std::wstring statstring;
	std::vector<int> relevantabilities(2, 0);
	relevantabilities[0] = RetrieveStatsFromAbilityPackages(STATTYPE::MIGHT);
	relevantabilities[1] = RetrieveStatsFromAbilityPackages(STATTYPE::STR);
	
	std::wstring temp = currentGMTstats[2].getText();
	int lvcstat2 = _wtoi(temp.c_str());

	temp = currentGWSstats[0].getText();
	int lvwstat0 = _wtoi(temp.c_str());

	//temp = currentGWSstats[0].getText();
	//int lvwstat0 = _wtoi(temp.c_str());

	temp = currentGBSstats[0].getText();
	int lvbstat0 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(relevantabilities[0] + relevantabilities[1] + lvcstat2 + lvwstat0 + lvbstat0);
	//	//+ ifEffective(Weapon Might x3)
	//	//+ Combat Art
	//	//+ Skills
	//	//+ Linked attacks
	//	//+/- Terrain Effects
	//	//- Enemies Protection);
	totalstats[0] = buffer;
}

void GTBTotalStats::CalculateTotalMagicAttack() {
	std::wstring statstring;
	std::vector<int> relevantabilities(3, 0);
	relevantabilities[0] = RetrieveStatsFromAbilityPackages(STATTYPE::MIGHT);
	relevantabilities[1] = RetrieveStatsFromAbilityPackages(STATTYPE::MAG);
	relevantabilities[2] = RetrieveStatsFromAbilityPackages(STATTYPE::MATK);

	std::wstring temp = currentGMTstats[3].getText();
	int lvcstat3 = _wtoi(temp.c_str());

	temp = currentGWSstats[0].getText();
	int lvwstat0 = _wtoi(temp.c_str());

	temp = currentGESstats[9].getText();
	int lvestat9 = _wtoi(temp.c_str());

	temp = currentGBSstats[1].getText();
	int lvbstat1 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(relevantabilities[0] + relevantabilities[1] + relevantabilities[2] + lvcstat3 + lvwstat0 + lvestat9 + lvbstat1);
	//+ ifEffective(Weapon Might x3)
	totalstats[1] = buffer;
}

void GTBTotalStats::CalculateTotalPhysicalHit() {
	std::wstring statstring;
	std::vector<int> relevantabilities(2, 0);
	relevantabilities[0] = RetrieveStatsFromAbilityPackages(STATTYPE::HIT);
	relevantabilities[1] = RetrieveStatsFromAbilityPackages(STATTYPE::DEX);

	std::wstring temp = currentGMTstats[4].getText();
	int lvcstat4 = _wtoi(temp.c_str());

	temp = currentGWSstats[1].getText();
	int lvwstat1 = _wtoi(temp.c_str());

	temp = currentGESstats[3].getText();
	int lvestat3 = _wtoi(temp.c_str());

	temp = currentGBSstats[2].getText();
	int lvbstat2 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(relevantabilities[0] + relevantabilities[1] + lvcstat4 + lvwstat1 + lvestat3 + lvbstat2);

	/*+ Combat Art
	+ Skills
	+/- Battalions
	+ Linked attacks
	+/- Terrain Effects
	- Enemies Avoid*/
	totalstats[2] = buffer;
}

void GTBTotalStats::CalculateTotalMagicHit() {
	std::wstring statstring;
	std::vector<int> relevantabilities(3, 0);
	relevantabilities[0] = RetrieveStatsFromAbilityPackages(STATTYPE::HIT);
	relevantabilities[1] = RetrieveStatsFromAbilityPackages(STATTYPE::DEX);
	relevantabilities[2] = RetrieveStatsFromAbilityPackages(STATTYPE::LCK);

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

	const std::wstring buffer = std::to_wstring(relevantabilities[0] + (((lvcstat4 + relevantabilities[1]) + (lvcstat6 + relevantabilities[2])) / 2) + lvwstat1 + lvestat3 + lvbstat2);

	/*+ Skills
	+ Linked attacks
	- Enemies Magic Avoid*/
	totalstats[3] = buffer;
}

void GTBTotalStats::CalculateTotalCrit() {
	std::wstring statstring;
	std::vector<int> relevantabilities(3, 0);
	relevantabilities[0] = RetrieveStatsFromAbilityPackages(STATTYPE::DEX);
	relevantabilities[1] = RetrieveStatsFromAbilityPackages(STATTYPE::LCK);
	relevantabilities[2] = RetrieveStatsFromAbilityPackages(STATTYPE::WCRIT);

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

	const std::wstring buffer = std::to_wstring(relevantabilities[2] + (((lvcstat4 + relevantabilities[0]) + (lvcstat6 + relevantabilities[1])) / 2) + lvwstat2 + lvestat4 + lvbstat3);

	totalstats[4] = buffer;
	/////*+Skills*/);
}

void GTBTotalStats::CalculateAS() {
	std::wstring statstring;
	std::vector<int> relevantabilities(3, 0);
	relevantabilities[0] = RetrieveStatsFromAbilityPackages(STATTYPE::SPD);
	relevantabilities[1] = RetrieveStatsFromAbilityPackages(STATTYPE::WEIGHT);
	relevantabilities[2] = RetrieveStatsFromAbilityPackages(STATTYPE::STR);

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

	int miniszero = ((lvwstat4 + relevantabilities[1]) - ((lvcstat2 + relevantabilities[2]) / 5));
	if (miniszero < 0) {
		miniszero = 0;
	}

	const std::wstring buffer = std::to_wstring((lvcstat5 + lvestat6 + relevantabilities[0]) - miniszero);

	totalstats[5] = buffer;
}

void GTBTotalStats::CalculateTotalProt() {
	std::wstring statstring;
	std::vector<int> relevantabilities(2, 0);
	relevantabilities[0] = RetrieveStatsFromAbilityPackages(STATTYPE::DEF);
	relevantabilities[1] = RetrieveStatsFromAbilityPackages(STATTYPE::PROT);

	std::wstring temp = currentGMTstats[7].getText();
	int lvcstat7 = _wtoi(temp.c_str());

	temp = currentGESstats[0].getText();
	int lvestat0 = _wtoi(temp.c_str());

	temp = currentGBSstats[5].getText();
	int lvbstat5 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(relevantabilities[0] + relevantabilities[1] + lvcstat7 + lvestat0 + lvbstat5);

	totalstats[6] = buffer;
}

void GTBTotalStats::CalculateTotalResilience() {
	std::wstring statstring;
	std::vector<int> relevantabilities(1, 0);
	relevantabilities[0] = RetrieveStatsFromAbilityPackages(STATTYPE::RES);

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
	std::wstring statstring;
	std::vector<int> relevantabilities(1, 0);
	relevantabilities[0] = RetrieveStatsFromAbilityPackages(STATTYPE::AVO);

	//total attack speed
	std::wstring temp = totalstats[5].getText();
	int totalstats5 = _wtoi(temp.c_str());

	//equipment avoid
	temp = currentGESstats[5].getText();
	int lvestat5 = _wtoi(temp.c_str());

	//battalion avoid 
	temp = currentGBSstats[4].getText();
	int lvbstat4 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(relevantabilities[0] + totalstats5 + lvestat5 + lvbstat4);

	totalstats[8] = buffer;

	//	/*+ Skills
	//	+/- Terrain Effects*//*)*/;
}

void GTBTotalStats::CalculateTotalCritAvoid() {
	std::wstring statstring;
	std::vector<int> relevantabilities(1, 0);
	relevantabilities[0] = RetrieveStatsFromAbilityPackages(STATTYPE::CRITAVO);

	//std::wstring temp = currentGWSstats[2].getText();
	//int lvwstat2 = _wtoi(temp.c_str());

	//character luck
	std::wstring temp = currentGMTstats[6].getText();
	int lvcstat6 = _wtoi(temp.c_str());

	temp = currentGESstats[8].getText();
	int lvestat8 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(relevantabilities[0] + lvcstat6 + lvestat8);

	totalstats[9] = buffer;
}

void GTBTotalStats::CalculateTotalRange() {
	std::wstring statstring;
	std::vector<int> relevantabilities(1, 0);
	relevantabilities[0] = RetrieveStatsFromAbilityPackages(STATTYPE::RANGE);

	std::wstring temp = currentGWSstats[3].getText();
	int lvwstat3 = _wtoi(temp.c_str());

	const std::wstring buffer = std::to_wstring(relevantabilities[0] + lvwstat3);
	totalstats[10] = buffer;
}

//void GTBTotalStats::ClearValues() {
//	for (auto element : thisshouldreflectcurrent) {
//		element.value = "0";
//	}
//}
//switch (stattype.stattype) {
//	case STATTYPE::HP: {
//		as.hp += stattype.value;
//		break;
//	}
//	case STATTYPE::MOV: {
//		as.mov += stattype.value;
//		break;
//	}
//	case STATTYPE::STR: {
//		as.str += stattype.value;
//		break;
//	}
//	case STATTYPE::MAG: {
//		as.mag += stattype.value;
//		break;
//	}
//	case STATTYPE::DEX: {
//		as.dex += stattype.value;
//		break;
//	}
//	case STATTYPE::SPD: {
//		as.spd += stattype.value;
//		break;
//	}
//	case STATTYPE::LCK: {
//		as.lck += stattype.value;
//		break;
//	}
//	case STATTYPE::DEF: {
//		as.def += stattype.value;
//		break;
//	}
//	case STATTYPE::RES: {
//		as.res += stattype.value;
//		break;
//	}
//	case STATTYPE::CHA: {
//		as.cha += stattype.value;
//		break;
//	}
//	case STATTYPE::MIGHT: {
//		as.might += stattype.value;
//		break;
//	}
//	case STATTYPE::GMIGHT: {
//		as.gmight += stattype.value;
//		break;
//	}
//	case STATTYPE::HIT: {
//		as.hit += stattype.value;
//		break;
//	}
//	case STATTYPE::GHIT: {
//		as.ghit += stattype.value;
//		break;
//	}
//	case STATTYPE::CRIT: {
//		as.crit += stattype.value;
//		break;
//	}
//	case STATTYPE::RANGE: {
//		as.range += stattype.value;
//		break;
//	}
//	case STATTYPE::WEIGHT: {
//		as.weight += stattype.value;
//		break;
//	}
//	case STATTYPE::USES: {
//		as.uses += stattype.value;
//		break;
//	}
//	case STATTYPE::PROT: {
//		as.prot += stattype.value;
//		break;
//	}
//	case STATTYPE::TCRIT: {
//		as.tcrit += stattype.value;
//		break;
//	}
//	case STATTYPE::AVO: {
//		as.avo += stattype.value;
//		break;
//	}
//	case STATTYPE::MATK: {
//		as.matk += stattype.value;
//		break;
//	}
//	case STATTYPE::HEAL: {
//		as.heal += stattype.value;
//		break;
//	}
//	case STATTYPE::PATK: {
//		as.patk += stattype.value;
//		break;
//	}
//	case STATTYPE::END: {
//		as.end += stattype.value;
//		break;
//	}
//	case STATTYPE::CRITAVO: {
//		as.critavo += stattype.value;
//		break;
//	}
//}

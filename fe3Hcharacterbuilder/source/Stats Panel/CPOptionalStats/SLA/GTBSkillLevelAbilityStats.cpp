#include <Stats Panel/CPOptionalStats/SLA/GTBSkillLevelAbilityStats.h>

GTBSkillLevelAbilityStats::GTBSkillLevelAbilityStats(std::map<wxString, wxClientData*> uskilllevelabilities)
{
	skilllevelabilities = uskilllevelabilities;
}

void GTBSkillLevelAbilityStats::ReceiveSLASSelection(wxString ucurrentSLAselection) {
	currentSLAselection = ucurrentSLAselection;
	recalculate();
}

void GTBSkillLevelAbilityStats::ReceiveLBWSelection_weapontypeifneeded(WEAPONTYPE type) {
	currentWeaponTypeofEquippedWeapon = type;
	recalculate();
}

//void GTBSkillLevelAbilityStats::ReceiveLBBSelection(bool ubattalionselectionmade) {
//	battalionselectionmade = ubattalionselectionmade;
//	recalculate();
//}

void GTBSkillLevelAbilityStats::recalculate() {	
	statpVector.clear();
	currentheaders.clear();
	for (int i = 0; i < 3; ++i) {
		statpVector.push_back(STATPACKAGE(STATTYPE::BLANK, "---"));
		currentheaders.push_back("---");
	}

	hasStats = DetermineStatsPresence();
	if (hasStats) {
		statpVector = RetrieveSTATPackage();
		currentheaders = GetCurrentHeaders();

		equivalentWTs = DetermineWTMatch();
		if (!equivalentWTs) {
			for (auto& stattype : statpVector) {
				stattype.value = "0";
			}
		}
	}
}

bool GTBSkillLevelAbilityStats::DetermineStatsPresence() {
	for (auto element : skilllevelabilities) {
		if (currentSLAselection == element.first) {
			SkillLevelAbility* tempability = dynamic_cast<SkillLevelAbility*>(element.second)->clone();
			return tempability->getHasStatUp();
		}
	}

	return false;
}

bool GTBSkillLevelAbilityStats::DetermineWTMatch() {
	WEAPONTYPE abilitywt = RetrieveABILITYWEAPONTYPE();
	if (currentWeaponTypeofEquippedWeapon == abilitywt/* || abilitywt == WEAPONTYPE::ALL*/) {
		if (currentWeaponTypeofEquippedWeapon > WEAPONTYPE::BLANK) {
			return true;

		}
	}

	return false;
}

WEAPONTYPE GTBSkillLevelAbilityStats::RetrieveABILITYWEAPONTYPE() {
	for (auto element : skilllevelabilities) {
		if (currentSLAselection == element.first) {
			SkillLevelAbility* tempability = dynamic_cast<SkillLevelAbility*>(element.second)->clone();
			int test = 9;
			return tempability->getWeaponType();
		}
	}

	return WEAPONTYPE();
}

std::vector<STATPACKAGE> GTBSkillLevelAbilityStats::RetrieveSTATPackage() {
	for (auto element : skilllevelabilities) {
		if (currentSLAselection == element.first) {
			SkillLevelAbility* tempability = dynamic_cast<SkillLevelAbility*>(element.second)->clone();
			int test = 9;
			return tempability->getSTATP();
		}
	}
	
	return std::vector<STATPACKAGE>();
}

std::vector<wxString> GTBSkillLevelAbilityStats::GetCurrentHeaders() {
	std::vector<wxString> tempvector;
	for (unsigned int i = 0; i < statpVector.size(); ++i) {
		for (unsigned int k = 0; k < headers.size(); ++k) {
			if (statpVector[i].stattype == headers[k].stattype) {
				tempvector.push_back(headers[k].value);
			}
		}
	}

	return tempvector;
}
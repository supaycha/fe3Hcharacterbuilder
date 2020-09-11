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

void GTBSkillLevelAbilityStats::recalculate() {	
	statpVector.clear();
	currentheaders.clear();
	for (int i = 0; i < 3; ++i) {
		statpVector.push_back(STATPACKAGE(STATTYPE::BLANK, "---"));
		currentheaders.push_back("---");
	}

	hasStats = DetermineStatsPresence();
	if (hasStats) {
		equivalentWTs = DetermineWTMatch();
		if (equivalentWTs) {
			statpVector = RetrieveSTATPackage();
			currentheaders = GetCurrentHeaders();
		}
	}
}

std::vector<STATPACKAGE> GTBSkillLevelAbilityStats::RetrieveSTATPackage() {
	for (auto element : skilllevelabilities) {
		if (currentSLAselection == element.first) {
			SkillLevelAbility* tempability = dynamic_cast<SkillLevelAbility*>(element.second)->clone();
			int test = 9;
			return tempability->getWTP();
		}
	}
	
	return std::vector<STATPACKAGE>();
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

//bool GTBSkillLevelAbilityStats::DetermineWeaponType() {
//	for (auto element : skilllevelabilities) {
//		if (currentSLAselection == element.first) {
//			SkillLevelAbility* tempability = dynamic_cast<SkillLevelAbility*>(element.second)->clone();
//
//			type = tempability->getWeaponType();
//			if ((int)type > (int)WEAPONTYPE::BLANK && (int)type < (int)WEAPONTYPE::AUTHORITY) {
//				return true;
//			}
//		}
//	}
//	
//	return false;
//}

std::vector<wxString> GTBSkillLevelAbilityStats::GetCurrentHeaders() {
	std::vector<wxString> tempvector;
	for (unsigned int i = 0; i < statpVector.size(); ++i) {
		for (unsigned int k = 0; k < headers.size(); ++k) {
			if (statpVector[i].stattype == headers[k].stattype) {
				tempvector.push_back(headers[k].name);
			}
		}
	}

	return tempvector;
}

bool GTBSkillLevelAbilityStats::DetermineWTMatch() {
	if (currentWeaponTypeofEquippedWeapon == type) {
		return true;
	}

	return false;
}
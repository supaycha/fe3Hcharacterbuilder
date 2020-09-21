#include <Stats Panel/CPOptionalStats/CLIA/GTBClassInnateAbilityStats.h>

GTBClassInnateAbilityStats::GTBClassInnateAbilityStats(std::map<wxString, wxClientData*> uclassinnateabilities)
{
	classinnateabilities = uclassinnateabilities;
}

void GTBClassInnateAbilityStats::ReceiveCLIASSelection(wxString ucurrentCLIAselection) {
	currentCLIAselection = ucurrentCLIAselection;
	recalculate();
}

void GTBClassInnateAbilityStats::ReceiveLBWSelection_weapontypeifneeded(WEAPONTYPE type) {
	currentWeaponTypeofEquippedWeapon = type;
	recalculate();
}

void GTBClassInnateAbilityStats::recalculate() {
	statpVector.clear();
	currentheaders.clear();
	for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_COLS_IN_GCLIAS; ++i) {
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

bool GTBClassInnateAbilityStats::DetermineStatsPresence() {
	for (auto element : classinnateabilities) {
		if (currentCLIAselection == element.first) {
			ClassInnateAbility* tempability = dynamic_cast<ClassInnateAbility*>(element.second)->clone();
			return tempability->getHasStatUp();
		}
	}

	return false;
}

bool GTBClassInnateAbilityStats::DetermineWTMatch() {
	WEAPONTYPE abilitywt = RetrieveABILITYWEAPONTYPE();
	if (currentWeaponTypeofEquippedWeapon == abilitywt || abilitywt == WEAPONTYPE::ALL) {
		if (currentWeaponTypeofEquippedWeapon > WEAPONTYPE::BLANK) {
			return true;

		}
	}

	return false;
}

WEAPONTYPE GTBClassInnateAbilityStats::RetrieveABILITYWEAPONTYPE() {
	for (auto element : classinnateabilities) {
		if (currentCLIAselection == element.first) {
			ClassInnateCharacterAbility* tempability = dynamic_cast<ClassInnateCharacterAbility*>(element.second)->clone();
			int test = 9;
			return tempability->getWeaponType();
		}
	}

	return WEAPONTYPE();
}

std::vector<STATPACKAGE> GTBClassInnateAbilityStats::RetrieveSTATPackage() {
	for (auto element : classinnateabilities) {
		if (currentCLIAselection == element.first) {
			ClassInnateAbility* tempability = dynamic_cast<ClassInnateAbility*>(element.second)->clone();
			return tempability->getSTATP();
		}
	}

	return std::vector<STATPACKAGE>();
}

std::vector<wxString> GTBClassInnateAbilityStats::GetCurrentHeaders() {
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
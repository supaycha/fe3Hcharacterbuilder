#include <Stats Panel/CPOptionalStats/CHIA/GTBCharInnateAbilityStats.h>

GTBCharInnateAbilityStats::GTBCharInnateAbilityStats(std::map<wxString, wxClientData*> ucharacterinnateabilities)
{
	characterinnateabilities = ucharacterinnateabilities;
}

void GTBCharInnateAbilityStats::ReceiveCHIASSelection(wxString abilityname) {
	currentCHIAselection = abilityname;
	recalculate();
}

void GTBCharInnateAbilityStats::ReceiveLBBSelection(bool ubattalionselectionmade) {
	battalionselectionmade = ubattalionselectionmade;
	recalculate();
}

void GTBCharInnateAbilityStats::recalculate() {
	statpVector.clear();
	currentheaders.clear();
	for (int i = 0; i < 2; ++i) {
		statpVector.push_back(STATPACKAGE(STATTYPE::BLANK, "---"));
		currentheaders.push_back("---");
	}

	hasStats = DetermineStatsPresence();
	if (hasStats) {
		statpVector = RetrieveSTATPackage();
		currentheaders = GetCurrentHeaders();

		battalionmustexist = DetermineWhetherBattalionMustExist();
		if (battalionselectionmade && !battalionmustexist) {
			for (auto& stattype : statpVector) {
				stattype.value = "0";
			}
		}
		else if (!battalionselectionmade && battalionmustexist) {
			for (auto& stattype : statpVector) {
				stattype.value = "0";
			}
		}
	}
}

bool GTBCharInnateAbilityStats::DetermineStatsPresence() {
	for (auto element : characterinnateabilities) {
		if (currentCHIAselection == element.first) {
			CharacterInnateAbility* tempability = dynamic_cast<CharacterInnateAbility*>(element.second)->clone();
			return tempability->getHasStatUp();
		}
	}

	return false;
}

bool GTBCharInnateAbilityStats::DetermineWhetherBattalionMustExist() {
	for (auto element : characterinnateabilities) {
		if (currentCHIAselection == element.first) {
			CharacterInnateAbility* tempability = dynamic_cast<CharacterInnateAbility*>(element.second)->clone();
			return tempability->getBattalionMustExist();
		}
	}

	return false;
}

std::vector<STATPACKAGE> GTBCharInnateAbilityStats::RetrieveSTATPackage() {
	for (auto element : characterinnateabilities) {
		if (currentCHIAselection == element.first) {
			CharacterInnateAbility* tempability = dynamic_cast<CharacterInnateAbility*>(element.second)->clone();
			return tempability->getSTATP();
		}
	}

	return std::vector<STATPACKAGE>();
}

std::vector<wxString> GTBCharInnateAbilityStats::GetCurrentHeaders() {
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
#include <Stats Panel/CPOptionalStats/CLIA/GTBClassInnateAbilityStats.h>

GTBClassInnateAbilityStats::GTBClassInnateAbilityStats(std::map<wxString, wxClientData*> uclassinnateabilities)
{
	classinnateabilities = uclassinnateabilities;
}

void GTBClassInnateAbilityStats::ReceiveCLIASSelection(wxString abilityname) {
	currentCLIAselection = abilityname;
	recalculate();
}

void GTBClassInnateAbilityStats::recalculate() {
	statpVector.clear();
	currentheaders.clear();
	for (int i = 0; i < 3; ++i) {
		statpVector.push_back(STATPACKAGE(STATTYPE::BLANK, "---"));
		currentheaders.push_back("---");
	}

	hasStats = DetermineStatsPresence();
	if (hasStats) {
		//equivalentWTs = DetermineWTMatch();
		//if (equivalentWTs) {
			statpVector = RetrieveSTATPackage();
			currentheaders = GetCurrentHeaders();
		//}
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
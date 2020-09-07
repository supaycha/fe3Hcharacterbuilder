#include <Stats Panel/CPOptionalStats/SLA/GTBSkillLevelAbilityStats.h>

void GTBSkillLevelAbilityStats::ReceiveSLASSelection(std::vector<STPACKAGE> ustp) {
	stpVector = ustp;
	currentheaders = GetCurrentHeaders();
}

std::vector<wxString> GTBSkillLevelAbilityStats::GetCurrentHeaders() {
	std::vector<wxString> tempvector;
	for (unsigned int i = 0; i < stpVector.size(); ++i) {
		for (unsigned int k = 0; k < headers.size(); ++k) {
			if (stpVector[i].stattype == headers[k].stattype) {
				tempvector.push_back(headers[k].name);
			}
		}
	}

	return tempvector;
}
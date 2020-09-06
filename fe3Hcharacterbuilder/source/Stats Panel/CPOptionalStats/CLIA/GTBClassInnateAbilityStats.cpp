#include <Stats Panel/CPOptionalStats/CLIA/GTBClassInnateAbilityStats.h>

void GTBClassInnateAbilityStats::ReceiveCLIASSelection(STPACKAGE ustp) {
	stp = ustp;
	currentheader = GetCurrentHeader();
}

wxString GTBClassInnateAbilityStats::GetCurrentHeader() {
	for (unsigned int i = 0; i < headers.size(); ++i) {
		if (stp.stattype == headers[i].stattype) {
			return headers[i].name;
		}
	}
}
#include <Stats Panel/CPOptionalStats/CLIA/GTBClassInnateAbilityStats.h>

void GTBClassInnateAbilityStats::ReceiveCLIASSelection(STATPACKAGE ustatp) {
	statp = ustatp;
	currentheader = GetCurrentHeader();
}

wxString GTBClassInnateAbilityStats::GetCurrentHeader() {
	for (unsigned int i = 0; i < headers.size(); ++i) {
		if (statp.stattype == headers[i].stattype) {
			return headers[i].value;
		}
	}
}
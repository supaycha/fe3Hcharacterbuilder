#include <Stats Panel/CPOptionalStats/CHIA/GTBCharInnateAbilityStats.h>

void GTBCharInnateAbilityStats::ReceiveCHIASSelection(STATPACKAGE ustatp) {
	statp = ustatp;
	currentheader = GetCurrentHeader();
}

wxString GTBCharInnateAbilityStats::GetCurrentHeader() {
	for (unsigned int i = 0; i < headers.size(); ++i) {
		if (statp.stattype == headers[i].stattype) {
			return headers[i].name;
		}
	}
}
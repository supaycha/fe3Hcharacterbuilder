#include <Stats Panel/CPOptionalStats/CHIA/GTBCharInnateAbilityStats.h>

void GTBCharInnateAbilityStats::ReceiveCHIASSelection(STPACKAGE ustp) {
	stp = ustp;
	currentheader = GetCurrentHeader();
}

wxString GTBCharInnateAbilityStats::GetCurrentHeader() {
	for (unsigned int i = 0; i < headers.size(); ++i) {
		if (stp.stattype == headers[i].stattype) {
			return headers[i].name;
		}
	}
}
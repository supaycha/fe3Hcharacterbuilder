#include <Stats Panel/CPOptionalStats/GambitStats/GTBGambitStats.h>

void GTBGambitStats::ReceiveLBBSelection(Stats stats) {
	gambitstats = stats;
	recalculate();
}

void GTBGambitStats::ReceiveAugmenttoStats(wxString value) {
	gmight = value;
	recalculate();
}

void GTBGambitStats::recalculate() {
	augmentedgambitstats = gambitstats;
	int basegmight = _wtoi(gambitstats[0].getText().c_str());
	int augmenttobasegmight = _wtoi(gmight.c_str());

	int tempnewgmight = basegmight + augmenttobasegmight;

	augmentedgambitstats[0] = std::to_wstring(tempnewgmight);
}
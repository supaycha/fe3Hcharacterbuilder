#include <Stats Panel/CPOptionalStats/BattalionStats/GTBBattalionStats.h>

void GTBBattalionStats::ReceiveLBBSelection(Stats stats) {
	battalionstats = stats;
}

//void GTBBattalionStats::ReceiveAugmenttoStats(wxString value) {
//	
//	wxString temp = battalionstats[0].getText();
//	int basegmight = _wtoi(temp.c_str());
//	int augmenttobasegmight = _wtoi(value.c_str());
//
//	int tempnewgmight = basegmight + augmenttobasegmight;
//
//	battalionstats[0] = std::to_wstring(tempnewgmight);
//}
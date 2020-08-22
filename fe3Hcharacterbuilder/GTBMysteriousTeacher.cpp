#include "GTBMysteriousTeacher.h"

void GTBMysteriousTeacher::UpdateDDCHSelection(Character character) {
	currentDDCHstats = character.getStats();
	currentDDCHgrowths = character.getGrowths();

	recalculate();
}

void GTBMysteriousTeacher::UpdateSCLSelection(int level, int ID) {
	switch (ID) {
		case ID_SPIN1: {
			currentSCL1selection = level;
			break;
		}

		case ID_SPIN2: {
			currentSCL2selection = level;
			break;
		}
	}

	recalculate();
}

void GTBMysteriousTeacher::UpdateDDCLSelection(Class cLass, int ID) {
	switch (ID) {
		case ID_DDCL1: {
			currentDDCL1growths = cLass.getGrowths();
			break;
		}

		case ID_DDCL2: {
			currentDDCL2growths = cLass.getGrowths();
			break;
		}

		case ID_DDCL3: {
			currentDDCL3booststostats = cLass.getBoostedStats();
			currentDDCL3minstats = cLass.getStats();
			currentDDCL3mountvars = cLass.getMountedStats();
			break;
		}
	}

	recalculate();
}

void GTBMysteriousTeacher::recalculate() {
	for (int i = 0; i < 10; ++i) {
		totals1[i] = currentDDCHgrowths[i];
	}

	for (int i = 0; i < 10; ++i) {
		totals2[i] = currentDDCHstats[i];
	}

	for (int i = 0; i < 10; ++i) {
		float chargrowth = _wtof(currentDDCHgrowths[i].getText().c_str());
		float classgrowth = _wtof(currentDDCL1growths[i].getText().c_str());
		totals3[i] = std::to_wstring(chargrowth + classgrowth);
	}

	for (int i = 0; i < 10; ++i) {
		float chargrowth = _wtof(currentDDCHgrowths[i].getText().c_str());
		float classgrowth = _wtof(currentDDCL1growths[i].getText().c_str());
		float subtotal = chargrowth + classgrowth;
		int level = currentSCL1selection;
		int avgtotal = subtotal * level;
		totals4[i] = std::to_wstring(avgtotal);
	}

	for (int i = 0; i < 10; ++i) {
		float chargrowth = _wtof(currentDDCHgrowths[i].getText().c_str());
		float classgrowth2 = _wtof(currentDDCL2growths[i].getText().c_str());
		totals5[i] = std::to_wstring(chargrowth + classgrowth2);
	}

	for (int i = 0; i < 10; ++i) {
		float chargrowth = _wtof(currentDDCHgrowths[i].getText().c_str());
		float classgrowth2 = _wtof(currentDDCL2growths[i].getText().c_str());
		float subtotal2 = chargrowth + classgrowth2;
		int level2 = currentSCL2selection;
		int avgtotal2 = subtotal2 * level2;
		totals6[i] = std::to_wstring(avgtotal2);
	}

	for (int i = 0; i < 10; ++i) {
		int charstat = _wtoi(currentDDCHstats[i].getText().c_str());

		float chargrowth = _wtof(currentDDCHgrowths[i].getText().c_str());

		float classgrowth1 = _wtof(currentDDCL1growths[i].getText().c_str());
		float classgrowth2 = _wtof(currentDDCL2growths[i].getText().c_str());

		int level1 = currentSCL1selection;
		int level2 = currentSCL2selection;

		float subtotal = chargrowth + classgrowth1;
		float subtotal2 = chargrowth + classgrowth2;

		int avgtotal1 = subtotal * level1;
		int avgtotal2 = subtotal2 * level2;

		int grandtotal = charstat + avgtotal1 + avgtotal2;
		totals7[i] = std::to_wstring(grandtotal);
	}

	for (int i = 0; i < 10; ++i) {
		int charstat = _wtoi(currentDDCHstats[i].getText().c_str());

		float chargrowth = _wtof(currentDDCHgrowths[i].getText().c_str());

		float classgrowth1 = _wtof(currentDDCL1growths[i].getText().c_str());
		float classgrowth2 = _wtof(currentDDCL2growths[i].getText().c_str());

		int classboost = _wtoi(currentDDCL3booststostats[i].getText().c_str());

		int level1 = currentSCL1selection;
		int level2 = currentSCL2selection;

		float subtotal = chargrowth + classgrowth1;
		float subtotal2 = chargrowth + classgrowth2;

		int avgtotal1 = subtotal * level1;
		int avgtotal2 = subtotal2 * level2;

		int grandtotal = charstat + avgtotal1 + avgtotal2;
		int megagrandtotal = grandtotal + classboost;
		totals8[i] = std::to_wstring(megagrandtotal);
	}
}
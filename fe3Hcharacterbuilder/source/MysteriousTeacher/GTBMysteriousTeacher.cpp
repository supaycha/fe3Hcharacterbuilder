#include <MysteriousTeacher/GTBMysteriousTeacher.h>

void GTBMysteriousTeacher::UpdateDDCHSelection(Character character) {
	statsVector[0] = character.getStats();
	growthsVector[0] = character.getGrowths();

	recalculate();
}

void GTBMysteriousTeacher::UpdateSCLSelection(int level, int ID) {
	switch (ID) {
		case (int)ID_MISC::ID_SPIN1: {
			currentSCL1selection = level;
			break;
		}

		case (int)ID_MISC::ID_SPIN2: {
			currentSCL2selection = level;
			break;
		}
	}

	recalculate();
}

void GTBMysteriousTeacher::UpdateDDCLSelection(Class cLass, int ID) {
	switch (ID) {
		case (int)ID_MISC::ID_DDCL1: {
			growthsVector[1] = cLass.getGrowths();
			break;
		}

		case (int)ID_MISC::ID_DDCL2: {
			growthsVector[2] = cLass.getGrowths();
			break;
		}

		case (int)ID_MISC::ID_DDCL3: {
			statsVector[1] = cLass.getBoostedStats();
			statsVector[2] = cLass.getStats();
			statsVector[3] = cLass.getMountedStats();
			break;
		}
	}

	recalculate();
}

void GTBMysteriousTeacher::recalculate() {
	//charactergrowths to totalsgrowths1(totals1)
	for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_GMT_COLS; ++i) {
		growthsVector[3][i] = growthsVector[0][i];
	}

	//characterstats to totalstats1(totals2)
	for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_GMT_COLS; ++i) {
		statsVector[4][i] = statsVector[0][i];
	}

	//charactergrowths and classgrowths1 to totalgrowths2(totals3)
	for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_GMT_COLS; ++i) {
		float chargrowth = _wtof(growthsVector[0][i].getText().c_str());
		float classgrowth = _wtof(growthsVector[1][i].getText().c_str());
		growthsVector[4][i] = std::to_wstring(chargrowth + classgrowth);
	}

	//charactergrowths and classgrowths1 to totalstats2(totals4)
	for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_GMT_COLS; ++i) {
		float chargrowth = _wtof(growthsVector[0][i].getText().c_str());
		float classgrowth = _wtof(growthsVector[1][i].getText().c_str());
		float subtotal = chargrowth + classgrowth;
		int level = currentSCL1selection;
		int avgtotal = subtotal * level;
		statsVector[5][i] = std::to_wstring(avgtotal);
	}

	//charactergrowths and classgrowths1 to totalgrowths3(totals5)
	for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_GMT_COLS; ++i) {
		float chargrowth = _wtof(growthsVector[0][i].getText().c_str());
		float classgrowth2 = _wtof(growthsVector[2][i].getText().c_str());
		growthsVector[5][i] = std::to_wstring(chargrowth + classgrowth2);
	}

	//charactergrowths and classgrowths1 to totalgrowths3(totals5)
	for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_GMT_COLS; ++i) {
		float chargrowth = _wtof(growthsVector[0][i].getText().c_str());
		float classgrowth2 = _wtof(growthsVector[2][i].getText().c_str());
		float subtotal2 = chargrowth + classgrowth2;
		int level2 = currentSCL2selection;
		int avgtotal2 = subtotal2 * level2;
		statsVector[6][i] = std::to_wstring(avgtotal2);
	}

	for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_GMT_COLS; ++i) {
		int charstat = _wtoi(statsVector[0][i].getText().c_str());

		float chargrowth = _wtof(growthsVector[0][i].getText().c_str());

		float classgrowth1 = _wtof(growthsVector[1][i].getText().c_str());
		float classgrowth2 = _wtof(growthsVector[2][i].getText().c_str());

		int level1 = currentSCL1selection;
		int level2 = currentSCL2selection;

		float subtotal = chargrowth + classgrowth1;
		float subtotal2 = chargrowth + classgrowth2;

		int avgtotal1 = subtotal * level1;
		int avgtotal2 = subtotal2 * level2;

		int grandtotal = charstat + avgtotal1 + avgtotal2;
		statsVector[7][i] = std::to_wstring(grandtotal);
	}

	for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_GMT_COLS; ++i) {
		int charstat = _wtoi(statsVector[0][i].getText().c_str());

		float chargrowth = _wtof(growthsVector[0][i].getText().c_str());

		float classgrowth1 = _wtof(growthsVector[1][i].getText().c_str());
		float classgrowth2 = _wtof(growthsVector[2][i].getText().c_str());

		int classboost = _wtoi(statsVector[1][i].getText().c_str());

		int level1 = currentSCL1selection;
		int level2 = currentSCL2selection;

		float subtotal = chargrowth + classgrowth1;
		float subtotal2 = chargrowth + classgrowth2;

		int avgtotal1 = subtotal * level1;
		int avgtotal2 = subtotal2 * level2;

		int grandtotal = charstat + avgtotal1 + avgtotal2;
		int megagrandtotal = grandtotal + classboost;
		statsVector[8][i] = std::to_wstring(megagrandtotal);
	}
}
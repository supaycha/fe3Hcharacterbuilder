#include <MysteriousTeacher\GridMysteriousTeacher.h>

GridMysteriousTeacher::GridMysteriousTeacher(wxWindow* parent, wxWindowID id, bool hidecolheaders) :
	wxGrid(parent, id)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbmt = new GTBMysteriousTeacher;

	CreateGrid(8, 10);
	SetDefaultRowSize((int)CONSTANT_SIZE::MIN_HEIGHT_OF_COMBOBOX);
	SetDefaultColSize((int)CONSTANT_SIZE::SET_LENGTH_OF_COLUMNS);
	SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
	EnableEditing(false);
	DisableDragGridSize();

	for (unsigned int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_GMT_COLS; ++i) {
		SetColLabelValue(i, gtbmt->GetHeader(i));

	}
	SetUseNativeColLabels(true);

	if (hidecolheaders) {
		SetColLabelSize(0);
	}

	SetRowLabelSize(0);
	//initpopulate();
}

//void GridMysteriousTeacher::initpopulate() {
//	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
//		SetCellValue(0, i, L"0");
//		int k = 0;
//	}
//}

void GridMysteriousTeacher::repopulate() {
	std::vector<Stat> tempvectforstats;
	int floatcount = 0, standardcount = 0;
	for (int i = 0; i < gtbmt->GetRowsCount(); ++i) {
		switch (i) {
			case 1:
			case 3:
			case 5:
			case 6:
			case 7: {
				standardcount++;
				FillStandardRow(standardcount, i);
				break;
			}
			case 0:
			case 2:
			case 4: {
				floatcount++;
				FillFloatRow(floatcount, i);
				break;
			}
		}
	}

	Stats* ptrtostats = new Stats(tempvectforstats);
	wxCommandEvent event(TRANSMIT_GMT_STATS, (int)ID_MISC::ID_GMT);
	wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);
}

void GridMysteriousTeacher::FillStandardRow(int row, int casenum) {
	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue(casenum, i);
		SetCellValue(casenum, i, stattoset);
	}
}

void GridMysteriousTeacher::FillFloatRow(int row, int casenum) {
	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		wxGridCellFloatRenderer* renderer = new wxGridCellFloatRenderer(3, 2);
		std::wstring stattoset = gtbmt->GetValue(casenum, i);
		SetCellRenderer(casenum, i, renderer->Clone());
		SetCellAlignment(casenum, i, wxALIGN_CENTER, wxALIGN_CENTER);
		SetCellValue(casenum, i, stattoset);
	}
}

void GridMysteriousTeacher::UpdateDDCHSelection(Character character) {
	gtbmt->UpdateDDCHSelection(character);
	Freeze();
	repopulate();
	Thaw();
}

void GridMysteriousTeacher::UpdateSCLSelection(int level, int ID) {
	switch (ID) {
		case (int)ID_MISC::ID_SPIN1: {
			gtbmt->UpdateSCLSelection(level, (int)ID_MISC::ID_SPIN1);
			Freeze();
			repopulate();
			Thaw();
			break;
		}

		case (int)ID_MISC::ID_SPIN2: {
			gtbmt->UpdateSCLSelection(level, (int)ID_MISC::ID_SPIN2);
			Freeze();
			repopulate();
			Thaw();
			break;
		}
	}
}

void GridMysteriousTeacher::UpdateDDCLSelection(Class cLass, int ID) {
	switch (ID) {
		case (int)ID_MISC::ID_DDCL1: {
			gtbmt->UpdateDDCLSelection(cLass, (int)ID_MISC::ID_DDCL1);
			Freeze();
			repopulate();
			Thaw();

			break;
		}

		case (int)ID_MISC::ID_DDCL2: {
			gtbmt->UpdateDDCLSelection(cLass, (int)ID_MISC::ID_DDCL2);
			Freeze();
			repopulate();
			Thaw();

			break;
		}

		case (int)ID_MISC::ID_DDCL3: {
			gtbmt->UpdateDDCLSelection(cLass, (int)ID_MISC::ID_DDCL3);
			Freeze();
			repopulate();
			Thaw();

			break;
		}
	}
}
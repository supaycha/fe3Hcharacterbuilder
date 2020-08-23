#include "../include/GridMysteriousTeacher.h"

GridMysteriousTeacher::GridMysteriousTeacher(wxWindow* parent, wxWindowID id, bool hidecolheaders) :
	wxGrid(parent, id)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	gtbmt = new GTBMysteriousTeacher;

	CreateGrid(8, 10);
	SetDefaultRowSize((int)VARIOUS_SIZE::MIN_HEIGHT_OF_COMBOBOX);
	SetDefaultColSize((int)VARIOUS_SIZE::SET_LENGTH_OF_COLUMNS);
	SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
	EnableEditing(false);
	DisableDragGridSize();

	for (unsigned int i = 0; i < 10; ++i) {
		SetColLabelValue(i, gtbmt->GetHeader(i));

	}
	SetUseNativeColLabels(true);

	if (hidecolheaders) {
		SetColLabelSize(0);
	}

	SetRowLabelSize(0);
	initpopulate();
}

void GridMysteriousTeacher::initpopulate() {
	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		SetCellValue(0, i, L"0");
		int k = 0;
	}
}

void GridMysteriousTeacher::repopulate() {
	wxGridCellFloatRenderer* testerlulz = new wxGridCellFloatRenderer(3, 2);
	std::vector<Stat> tempvectforstats;
	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue(0, i);
		SetCellValue(0, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue2(0, i);
		SetCellValue(1, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue3(0, i);
		SetCellRenderer(2, i, testerlulz->Clone());
		SetCellAlignment(2, i, wxALIGN_CENTER, wxALIGN_CENTER);
		SetCellValue(2, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue4(0, i);
		SetCellValue(3, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue5(0, i);
		SetCellRenderer(4, i, testerlulz->Clone());
		SetCellAlignment(4, i, wxALIGN_CENTER, wxALIGN_CENTER);
		SetCellValue(4, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue6(0, i);
		SetCellValue(5, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue7(0, i);
		SetCellValue(6, i, stattoset);
	}

	for (int i = 0; i < gtbmt->GetColsCount(); ++i) {
		std::wstring stattoset = gtbmt->GetValue8(0, i);
		SetCellValue(7, i, stattoset);
		tempvectforstats.push_back(Stat(stattoset));
	}

	Stats* ptrtostats = new Stats(tempvectforstats);
	wxCommandEvent event(TRANSMIT_GMT_STATS, (int)ID_MISC::ID_GMT);
	wxClientData* tempdata = dynamic_cast<wxClientData*>(ptrtostats/*->clone()*/);
	event.SetClientObject(tempdata);
	ProcessEvent(event);

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
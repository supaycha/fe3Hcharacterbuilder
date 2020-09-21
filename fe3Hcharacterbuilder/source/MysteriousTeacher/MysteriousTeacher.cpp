#include <MysteriousTeacher\MysteriousTeacher.h>

MysteriousTeacher::MysteriousTeacher(std::vector<wxString> characternames, std::vector<wxClientData*> characterdata, std::map<wxString, wxClientData*> classmap, wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	gmt = new GridMysteriousTeacher(this, (int)ID_MISC::ID_GMT, 0);
	gmt->SetMargins(0, 0);

	wxArrayString emptybuffer;
	ddc = new DropDownCharacters(characternames, characterdata, this, (int)ID_MISC::ID_DDCH, emptybuffer, wxCB_DROPDOWN | wxCB_READONLY);

	wxString test = "1";
	for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_SCL_IN_MT; ++i) {
		sclVector.push_back(new SpinCtrlLevel(this, (int)ID_MISC::ID_SPIN1 + i, test, 1));
	}

	for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_DDCL_IN_MT; ++i) {
		ddclVector.push_back(new DropDownClasses(classmap, this, (int)ID_MISC::ID_DDCL1 + i, emptybuffer, wxCB_DROPDOWN | wxCB_READONLY | wxCB_SORT));
	}

	total = new wxBoxSizer(wxHORIZONTAL);
	for (int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_COLS_IN_MT_SIZER; ++i) {
		columns.push_back(new wxBoxSizer(wxVERTICAL));
	}

	int offset = 3;
	wxStaticText* basechargrowthtext = new wxStaticText(this, wxID_ANY, "BASE CHAR GROWTHS ->", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE);
	//basechargrowthtext->SetMinSize(wxSize(wxDEFAULT, gmt->GetRowHeight(0)));
	wxStaticText* baseclassgrowthtext1 = new wxStaticText(this, wxID_ANY, "BASE CLASS GROWTHS ->", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE);
	//baseclassgrowthtext1->SetMinSize(wxSize(wxDEFAULT, gmt->GetRowHeight(0)));
	wxStaticText* baseclassgrowthtext2 = new wxStaticText(this, wxID_ANY, "BASE CLASS GROWTHS ->", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE);
	//baseclassgrowthtext2->SetMinSize(wxSize(wxDEFAULT, gmt->GetRowHeight(0)));
	wxStaticText* beforeclassbooststext = new wxStaticText(this, wxID_ANY, "BEFORE CLASS BOOSTS ->", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE);

	columns[0]->AddSpacer(gmt->GetRowHeight(0));
	columns[0]->AddSpacer(gmt->GetRowHeight(0));
	columns[0]->AddSpacer(gmt->GetRowHeight(0));
	columns[0]->AddSpacer(gmt->GetRowHeight(0));
	columns[0]->Add(sclVector[0]);
	columns[0]->AddSpacer(gmt->GetRowHeight(0));
	columns[0]->Add(sclVector[1]);
	columns[0]->AddSpacer(gmt->GetRowHeight(0));
	columns[0]->AddSpacer(gmt->GetRowHeight(0));

	columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->Add(basechargrowthtext, 1, wxEXPAND, 0);
	//columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->Add(ddc);
	columns[1]->Add(baseclassgrowthtext1, 1, wxEXPAND, 0);
	//columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->Add(ddclVector[0], 1, wxEXPAND, 0);
	columns[1]->Add(baseclassgrowthtext2, 1, wxEXPAND, 0);
	//columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->Add(ddclVector[1], 1, wxEXPAND, 0);
	columns[1]->Add(beforeclassbooststext, 1, wxEXPAND, 0);
	//columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->Add(ddclVector[2], 1, wxEXPAND, 0);
	columns[2]->Add(gmt);

	for (unsigned int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_COLS_IN_MT_SIZER; ++i) {
		total->Add(columns[i]);
	}

	SetSizerAndFit(total);
	Bind(TRANSMIT_DDCH_SELECTION, &MysteriousTeacher::BounceDDCHSelection, this, (int)ID_MISC::ID_DDCH);
	Bind(TRANSMIT_SCL_SELECTION, &MysteriousTeacher::BounceSCLSelection, this, (int)ID_MISC::ID_SPIN1, (int)ID_MISC::ID_SPIN2);
	Bind(TRANSMIT_DDCL_SELECTION, &MysteriousTeacher::BounceDDCLSelection, this, (int)ID_MISC::ID_DDCL1, (int)ID_MISC::ID_DDCL3);
	Bind(TRANSMIT_GMT_STATS, &MysteriousTeacher::ForwardGMTStats, this, (int)ID_MISC::ID_GMT);
}

void MysteriousTeacher::BounceDDCHSelection(wxCommandEvent& transmission) {
	wxCommandEvent repetition(REPEAT_DDCH_SELECTION, (int)ID_MISC::ID_MT);
	repetition.SetClientObject(transmission.GetClientObject());
	ProcessEvent(repetition);

	Character* tempcharacter = dynamic_cast<Character*>(transmission.GetClientObject());
	gmt->UpdateDDCHSelection(*tempcharacter);

	wxString exclusivitycheck = tempcharacter->getName();
	for (unsigned int i = 0; i < (int)CONSTANT_SIZE::NUM_OF_DDCL_IN_MT; ++i) {
		ddclVector[i]->ReceiveExclusivity(exclusivitycheck);
	}
}

void MysteriousTeacher::BounceSCLSelection(wxSpinEvent& transmission) {
	switch (transmission.GetId()) {
		case (int)ID_MISC::ID_SPIN1: {
			int templevel = transmission.GetInt();
			gmt->UpdateSCLSelection(templevel, (int)ID_MISC::ID_SPIN1);

			break;
		}

		case (int)ID_MISC::ID_SPIN2: {
			int templevel = transmission.GetInt();
			gmt->UpdateSCLSelection(templevel, (int)ID_MISC::ID_SPIN2);

			break;
		}
	}
}

void MysteriousTeacher::BounceDDCLSelection(wxCommandEvent& transmission) {
	Class* tempclass = dynamic_cast<Class*>(transmission.GetClientObject());
	switch (transmission.GetId()) {
		case (int)ID_MISC::ID_DDCL1: {
			gmt->UpdateDDCLSelection(*tempclass, (int)ID_MISC::ID_DDCL1);
			break;
		}

		case (int)ID_MISC::ID_DDCL2: {
			gmt->UpdateDDCLSelection(*tempclass, (int)ID_MISC::ID_DDCL2);
			break;
		}

		case (int)ID_MISC::ID_DDCL3: {	
			wxCommandEvent repetition(REPEAT_DDCL_SELECTION, (int)ID_MISC::ID_MT);
			repetition.SetClientObject(transmission.GetClientObject());
			ProcessEvent(repetition);

			gmt->UpdateDDCLSelection(*tempclass, (int)ID_MISC::ID_DDCL3);
			break;
		}
	}
}

void MysteriousTeacher::ForwardGMTStats(wxCommandEvent& forwarded) {
	wxCommandEvent event(REPEAT_GMT_STATS, (int)ID_MISC::ID_MT);
	event.SetClientObject(forwarded.GetClientObject());
	ProcessEvent(event);
}
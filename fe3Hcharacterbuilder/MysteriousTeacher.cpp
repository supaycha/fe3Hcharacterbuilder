#include "MysteriousTeacher.h"

MysteriousTeacher::MysteriousTeacher(std::vector<wxString> characternames, std::vector<wxClientData*> characterdata, std::map<wxString, wxClientData*> classmap, MyFrame* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	gmt = new GridMysteriousTeacher(this, ID_GMT, 0);
	gmt->SetMargins(0, 0);

	wxArrayString emptybuffer;
	ddc = new DropDownCharacters(characternames, characterdata, this, ID_DDCH, emptybuffer, wxCB_DROPDOWN | wxCB_READONLY);

	wxString test = "1";
	for (int i = 0; i < 2; ++i) {
		sclVector.push_back(new SpinCtrlLevel(this, ID_SPIN1 + i, test, 1));
	}

	for (int i = 0; i < 3; ++i) {
		ddclVector.push_back(new DropDownClasses(classmap, this, ID_DDCL1 + i, emptybuffer, wxCB_DROPDOWN | wxCB_READONLY | wxCB_SORT));
	}

	total = new wxBoxSizer(wxHORIZONTAL);
	for (int i = 0; i < 3; ++i) {
		columns.push_back(new wxBoxSizer(wxVERTICAL));
	}

	int offset = 3;

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
	columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->Add(ddc);
	columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->Add(ddclVector[0], 0, wxEXPAND, 0);
	columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->Add(ddclVector[1], 0, wxEXPAND, 0);
	columns[1]->AddSpacer(gmt->GetRowHeight(0));
	columns[1]->Add(ddclVector[2], 0, wxEXPAND, 0);

	columns[2]->Add(gmt);

	for (unsigned int i = 0; i < columns.size(); ++i) {
		total->Add(columns[i]);
	}

	SetSizerAndFit(total);
	Bind(TRANSMIT_DDCH_SELECTION, &MysteriousTeacher::BounceDDCHSelection, this, ID_DDCH);
	Bind(TRANSMIT_SCL_SELECTION, &MysteriousTeacher::BounceSCLSelection, this, ID_SPIN1, ID_SPIN2);
	Bind(TRANSMIT_DDCL_SELECTION, &MysteriousTeacher::BounceDDCLSelection, this, ID_DDCL1, ID_DDCL3);
	Bind(TRANSMIT_GMT_STATS, &MysteriousTeacher::ForwardGMTStats, this, ID_GMT);
}

void MysteriousTeacher::BounceDDCHSelection(wxCommandEvent& transmission) {
	wxCommandEvent repetition(REPEAT_DDCH_SELECTION, ID_MT);
	repetition.SetClientObject(transmission.GetClientObject());
	ProcessEvent(repetition);

	Character* tempcharacter = dynamic_cast<Character*>(transmission.GetClientObject());
	gmt->UpdateDDCHSelection(*tempcharacter);

	wxString exclusivitycheck = tempcharacter->getName();
	for (unsigned int i = 0; i < ddclVector.size(); ++i) {
		ddclVector[i]->ReceiveExclusivity(exclusivitycheck);
	}
}

void MysteriousTeacher::BounceSCLSelection(wxSpinEvent& transmission) {
	switch (transmission.GetId()) {
		case ID_SPIN1: {
			int templevel = transmission.GetInt();
			gmt->UpdateSCLSelection(templevel, ID_SPIN1);

			break;
		}

		case ID_SPIN2: {
			int templevel = transmission.GetInt();
			gmt->UpdateSCLSelection(templevel, ID_SPIN2);

			break;
		}
	}
}

void MysteriousTeacher::BounceDDCLSelection(wxCommandEvent& transmission) {
	wxCommandEvent repetition(REPEAT_DDCL_SELECTION, ID_MT);
	repetition.SetClientObject(transmission.GetClientObject());
	ProcessEvent(repetition);

	Class* tempclass = dynamic_cast<Class*>(transmission.GetClientObject());
	switch (transmission.GetId()) {
		case ID_DDCL1: {
			//Class* tempclass = dynamic_cast<Class*>(transmission.GetClientObject());
			gmt->UpdateDDCLSelection(*tempclass, ID_DDCL1);
			break;
		}

		case ID_DDCL2: {
			//Class* tempclass = dynamic_cast<Class*>(transmission.GetClientObject());
			gmt->UpdateDDCLSelection(*tempclass, ID_DDCL2);
			break;
		}

		case ID_DDCL3: {
			//Class* tempclass = dynamic_cast<Class*>(transmission.GetClientObject());
			gmt->UpdateDDCLSelection(*tempclass, ID_DDCL3);
			break;
		}
	}
}

void MysteriousTeacher::ForwardGMTStats(wxCommandEvent& forwarded) {
	wxCommandEvent event(REPEAT_GMT_STATS, ID_MT);
	event.SetClientObject(forwarded.GetClientObject());
	ProcessEvent(event);
}
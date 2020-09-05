#include <EquippedPanel/Ability/CLIA/EquippedClassInnateAbility.h>

EquippedClassInnateAbility::EquippedClassInnateAbility(std::map<wxString, wxClientData*> uclassinnateabilities, wxWindow* parent, wxWindowID id, const wxString& label) :
	wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize)
{
	classinnateabilities = uclassinnateabilities;
}

void EquippedClassInnateAbility::ReceiveClassInnateAbility(wxString classname) {
	if (classname.empty()) {
		currentLBCselection == "---";
	}
	
	else {
		currentLBCselection = classname;
	}

	repopulate();
}

void EquippedClassInnateAbility::repopulate() {
	this->SetLabelText(currentLBCselection);
	if (currentLBCselection == "---") {
		SetToolTip(NULL);
	}
	else {
		wxString description = this->RetrieveDescription(currentLBCselection);
		SetToolTip(description);
	}
}

wxString EquippedClassInnateAbility::RetrieveDescription(wxString currentLBCselection) {
	for (auto element : classinnateabilities) {
		if (currentLBCselection == element.first) {
			ClassInnateAbility* tempability = dynamic_cast<ClassInnateAbility*>(element.second);
			wxString tempdescription = tempability->getDescription();
			return tempdescription;
		}
	}

	return "ERROR";
}
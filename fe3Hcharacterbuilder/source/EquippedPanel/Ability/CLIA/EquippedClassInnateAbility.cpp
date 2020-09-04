#include <EquippedPanel/Ability/CLIA/EquippedClassInnateAbility.h>

EquippedClassInnateAbility::EquippedClassInnateAbility(std::map<wxString, wxClientData*> uclassinnateabilities, wxWindow* parent, wxWindowID id, const wxString& label) :
	wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize)
{
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
}
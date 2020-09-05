#include <EquippedPanel/Ability/SLA/EquippedSkillLvlAbilities.h>

EquippedSkillLvlAbilities::EquippedSkillLvlAbilities(std::map<wxString, wxClientData*> uskilllevelabilities, wxWindow* parent, wxWindowID id, const wxString& label) :
	wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize)
{
	skilllevelabilities = uskilllevelabilities;
}

void EquippedSkillLvlAbilities::ReceiveSkillLevelAbility(wxString slname) {
	if (slname.empty()) {
		currentLBASLAselection == "---";
	}

	else {
		currentLBASLAselection = slname;
	}

	repopulate();
}

void EquippedSkillLvlAbilities::repopulate() {
	this->SetLabelText(currentLBASLAselection);
	if (currentLBASLAselection == "---") {
		SetToolTip(NULL);
	}
	else {
		wxString description = this->RetrieveDescription(currentLBASLAselection);
		SetToolTip(description);
	}
}

wxString EquippedSkillLvlAbilities::RetrieveDescription(wxString currentLBCselection) {
	for (auto element : skilllevelabilities) {
		if (currentLBASLAselection == element.first) {
			SkillLevelAbility* tempability = dynamic_cast<SkillLevelAbility*>(element.second);
			wxString tempdescription = tempability->getDescription();
			return tempdescription;
		}
	}

	return "ERROR";
}
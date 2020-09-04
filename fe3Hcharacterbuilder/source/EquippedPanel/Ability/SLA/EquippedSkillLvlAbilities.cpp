#include <EquippedPanel/Ability/SLA/EquippedSkillLvlAbilities.h>

EquippedSkillLvlAbilities::EquippedSkillLvlAbilities(std::map<wxString, wxClientData*> skilllevelabilities, wxWindow* parent, wxWindowID id, const wxString& label) :
	wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize)
{

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
}
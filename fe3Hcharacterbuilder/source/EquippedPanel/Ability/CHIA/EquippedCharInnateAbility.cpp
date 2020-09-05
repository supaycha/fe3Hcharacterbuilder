#include <EquippedPanel/Ability/CHIA/EquippedCharInnateAbility.h>

EquippedCharInnateAbility::EquippedCharInnateAbility(std::map<wxString, wxClientData*> ucharacterinnateabilities, wxWindow* parent, wxWindowID id, const wxString& label) :
	wxStaticText(parent, id, label, wxDefaultPosition, wxDefaultSize)
{
	characterinnateabilities = ucharacterinnateabilities;
}

void EquippedCharInnateAbility::ReceiveCharacterInnateExclusivity(wxString charactername) {
	currentDDCselection = charactername;
	repopulate();
}

void EquippedCharInnateAbility::repopulate() {
	std::wstring abilityname;
	for (auto element : characterinnateabilities) {
		CharacterInnateAbility* tempability = dynamic_cast<CharacterInnateAbility*>(element.second)->clone();
		if (tempability->getSource() == currentDDCselection) {
			abilityname = tempability->getName();
		}
	}

	this->SetLabelText(abilityname);
	wxString description = this->RetrieveDescription(abilityname);
	SetToolTip(description);
}

wxString EquippedCharInnateAbility::RetrieveDescription(wxString abilityname) {
	for (auto element : characterinnateabilities) {
		if (abilityname == element.first) {
			CharacterInnateAbility* tempability = dynamic_cast<CharacterInnateAbility*>(element.second);
			wxString tempdescription = tempability->getDescription();
			return tempdescription;
		}
	}

	return "ERROR";
}
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
}
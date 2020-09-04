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
	//for (auto element : characterinnateabilities) {
	//	Ability* tempability = dynamic_cast<Ability*>(element.second)->clone();
	//	if (CharacterInnateAbility* tempchia = dynamic_cast<CharacterInnateAbility*>(tempability)) {
	//		characterinnateabilities.push_back(tempchia);
	//	}
	//}
	std::wstring abilityname;
	for (auto element : characterinnateabilities) {
		CharacterInnateAbility* tempability = dynamic_cast<CharacterInnateAbility*>(element.second)->clone();
		if (tempability->getSource() == currentDDCselection) {
			abilityname = tempability->getName();
		}
	}

	this->SetLabelText(abilityname);
	//gchias->ReceiveAbilityStats(abilitystats);
	//Freeze();
	//Thaw();
}
#include "AbilityManager.h"

AbilityManager::AbilityManager(MyFrame* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	std::vector<wxString> abilitynames;
	std::vector<wxClientData*> abilitydata;
	AbilityList alist;

	for (unsigned int i = 0; i < alist.getSize(); ++i) {
		abilitynames.push_back(alist[i]->getName());
		abilitydata.push_back(alist[i]->clone());
	}

	for (unsigned int i = 0; i < alist.getSize(); ++i) {
		abilitymap.emplace(abilitynames[i], abilitydata[i]);
	}

	const wxArrayString buffer{};

	lbaa = new ListBoxAA(this, ID_LBAA, 0, 0, 150, 400, buffer, wxLB_MULTIPLE);
	lbsa = new ListBoxSA(this, ID_LBSA, 200, 0, 150, 400, buffer, wxLB_MULTIPLE);
	bmr = new ButtonMoveRight(this, ID_BMR, "->", 150, 50, 50, 50);
	bml = new ButtonMoveLeft(this, ID_BML, "<-", 150, 100, 50, 50);

	Bind(SELECTION_HAS_CHANGED, &AbilityManager::BounceSelectionstoRight, this, ID_BMR);
	Bind(SELECTION_HAS_CHANGED, &AbilityManager::BounceSelectionstoLeft, this, ID_BML);
}

void AbilityManager::ReceiveExclusivity(wxString charactername) {
	currentDDCselection = charactername;
	FilterAbilities();
}

void AbilityManager::ReceiveClassInnate(wxString classname) {
	currentLBCselection = classname;
	FilterAbilities();
}

void AbilityManager::ReceiveSLInfo(SLPACKAGE* slpackage) {
	SLfilter[slpackage->index] = slpackage->sl;
	FilterAbilities();
}

void AbilityManager::FilterAbilities() {
	std::vector<CharacterInnateAbility*> characterinnateabilities;
	std::vector<ClassInnateAbility*> classinnateabilities;
	std::vector<SkillLevelAbility*> skilllevelabilities;
	//std::vector<ClassMasteryAbility*> exclusiveweapons;

	std::vector<wxString> abilitynames;

	for (auto element : abilitymap) {
		Ability* tempability = dynamic_cast<Ability*>(element.second)->clone();
		if (CharacterInnateAbility* tempchia = dynamic_cast<CharacterInnateAbility*>(tempability)) {
			characterinnateabilities.push_back(tempchia);
		}
		if (ClassInnateAbility* tempclia = dynamic_cast<ClassInnateAbility*>(tempability)) {
			classinnateabilities.push_back(tempclia);
		}
		if (SkillLevelAbility* tempsla = dynamic_cast<SkillLevelAbility*>(tempability)) {
			skilllevelabilities.push_back(tempsla);
		}
	}

	for (auto ability : characterinnateabilities) {
		if (ability->getSource() == currentDDCselection) {
			abilitynames.push_back(ability->getName());
		}
	}

	for (auto ability : classinnateabilities) {
		std::wstring abilityns = ability->getSource(), buffer;
		std::wstringstream stream(abilityns);
		std::vector<std::wstring> namesfromstream;

		while (std::getline(stream, buffer, L',')) {
			namesfromstream.push_back(buffer);
		}

		for (auto possiblematch : namesfromstream) {
			if (possiblematch == currentLBCselection) {
				abilitynames.push_back(ability->getName());
			}
		}
	}

	for (auto ability : skilllevelabilities) {
		SL abilitySL = ability->getSL();

		if (abilitySL <= SLfilter[(int)ability->getWeaponType()]) {
			abilitynames.push_back(ability->getName());
		}
	}

	lbaa->ReceiveAbilityFiltration(abilitynames);
	lbsa->ReceiveAbilityFiltration(abilitynames);
}

void AbilityManager::BounceSelectionstoRight(wxCommandEvent& eventfromOnClick) {
	lbsa->ReceiveSelectionsfromBounceR(lbaa->GetSelectionsAA());
}

void AbilityManager::BounceSelectionstoLeft(wxCommandEvent& eventfromOnClick) {
	lbaa->ReceiveSelectionsfromBounceL(lbsa->GetSelectionsSAAndClear());
}

ListBoxAA::ListBoxAA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxPoint(x, y), wxSize(x2, y2), choices, style)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void ListBoxAA::OnSelection(wxCommandEvent& event) {
	selectedAAnames = UpdateSelections();
}

std::vector<wxString> ListBoxAA::UpdateSelections() {
	wxArrayInt selections;
	std::vector<wxString> tempvector;
	this->GetSelections(selections);

	for (auto selection : selections) {
		tempvector.push_back(this->GetString(selection));
	}

	return tempvector;
}

void ListBoxAA::ReceiveAbilityFiltration(std::vector<wxString> dirtynames) {
	filteredAAnames = dirtynames;

	std::vector<wxString> tempselected;

	for (auto newname : dirtynames) {
		for (auto oldname : selectedAAnames) {
			if (newname == oldname) {
				tempselected.push_back(newname);
				break;
			}
		}
	}
	selectedAAnames = tempselected;

	Freeze();
	repopulate();
	Thaw();
}

void ListBoxAA::ReceiveSelectionsfromBounceL(std::vector<wxString> uSelections) {
	for (auto newselect : uSelections) {
		std::erase(selectedAAnames, newselect);
	}

	Freeze();
	repopulate();
	Thaw();
}

void ListBoxAA::repopulate() {
	this->Set(ToArrayString(filteredAAnames));

	reselection();
}

void ListBoxAA::reselection() {
	for (auto selection : selectedAAnames) {
		int index = this->FindString(selection);
		if (!(this->IsSelected(index))) {
			this->SetSelection(index);
		}
	}
}

wxArrayString ListBoxAA::ToArrayString(std::vector<wxString> names) {
	wxArrayString temparraystring;
	for (auto name : names) {
		temparraystring.Add(name);
	}

	return temparraystring;
}

ListBoxSA::ListBoxSA(wxWindow* panel, wxWindowID id, int x, int y, int x2, int y2, const wxArrayString& choices, long style) :
	wxListBox(panel, id, wxPoint(x, y), wxSize(x2, y2), choices, style)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void ListBoxSA::OnSelection(wxCommandEvent& event) {
	selectedSAnames = UpdateSelections();
}

std::vector<wxString> ListBoxSA::UpdateSelections() {
	wxArrayInt selections;
	std::vector<wxString> tempvector;
	this->GetSelections(selections);

	for (auto selection : selections) {
		tempvector.push_back(this->GetString(selection));
	}

	return tempvector;
}

void ListBoxSA::ReceiveAbilityFiltration(std::vector<wxString> dirtynames) {
	std::vector<wxString> tempfiltered;
	std::vector<wxString> tempselected;

	for (auto newname : dirtynames) {
		for (auto oldname : filteredSAnames) {
			if (newname == oldname) {
				tempfiltered.push_back(newname);
				break;
			}
		}
	}

	for (auto newname : tempfiltered) {
		for (auto oldname : selectedSAnames) {
			if (newname == oldname) {
				tempselected.push_back(newname);
				break;
			}
		}
	}

	filteredSAnames = tempfiltered;
	selectedSAnames = tempselected;

	Freeze();
	repopulate();
	Thaw();
}

void ListBoxSA::ReceiveSelectionsfromBounceR(std::vector<wxString> uSelections) {
	filteredSAnames = uSelections;
	Freeze();
	repopulate();
	Thaw();
}

void ListBoxSA::repopulate() {
	this->Set(ToArrayString(filteredSAnames));

	reselection();
}

void ListBoxSA::reselection() {
	for (auto selection : selectedSAnames) {
		int index = this->FindString(selection);
		if (!(this->IsSelected(index))) {
			this->SetSelection(index);
		}
	}
}

std::vector<wxString> ListBoxSA::GetSelectionsSAAndClear() {
	std::vector<wxString> temp;

	for (auto element : selectedSAnames) {
		std::erase(filteredSAnames, element);
	}

	temp = selectedSAnames;
	selectedSAnames.clear();
	Freeze();
	repopulate();
	Thaw();
	return temp;
}

wxArrayString ListBoxSA::ToArrayString(std::vector<wxString> names) {
	wxArrayString temparraystring;
	for (auto name : names) {
		temparraystring.Add(name);
	}

	return temparraystring;
}

ButtonMoveRight::ButtonMoveRight(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2) :
	wxButton(panel, id, label, wxPoint(x, y), wxSize(x2, y2))
{
}

void ButtonMoveRight::OnClick(wxCommandEvent& uevent) {
	wxCommandEvent event(SELECTION_HAS_CHANGED, ID_BMR);
	ProcessEvent(event);
}

ButtonMoveLeft::ButtonMoveLeft(wxWindow* panel, wxWindowID id, const wxString& label, int x, int y, int x2, int y2) :
	wxButton(panel, id, label, wxPoint(x, y), wxSize(x2, y2))
{
}

void ButtonMoveLeft::OnClick(wxCommandEvent& uevent) {
	wxCommandEvent event(SELECTION_HAS_CHANGED, ID_BML);
	ProcessEvent(event);
}

wxBEGIN_EVENT_TABLE(AbilityManager, wxPanel)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(ListBoxAA, wxListBox)
	EVT_LISTBOX(ID_LBAA, ListBoxAA::OnSelection)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(ListBoxSA, wxListBox)
	EVT_LISTBOX(ID_LBSA, ListBoxSA::OnSelection)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(ButtonMoveRight, wxButton)
	EVT_BUTTON(ID_BMR, ButtonMoveRight::OnClick)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(ButtonMoveLeft, wxButton)
	EVT_BUTTON(ID_BML, ButtonMoveLeft::OnClick)
wxEND_EVENT_TABLE()
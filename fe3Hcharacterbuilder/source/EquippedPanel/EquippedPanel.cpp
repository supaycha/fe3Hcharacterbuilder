#include <EquippedPanel/EquippedPanel.h>

EquippedPanel::EquippedPanel(std::map<wxString, wxClientData*> abilitymap, wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
	const wxString buffer;
	panelsizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* physicalequipped = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* intangibleequipped = new wxBoxSizer(wxVERTICAL);
	wxStaticText* equippedbattalionlabel = new wxStaticText(this, wxID_ANY, "Equipped Battalion");
	eb = new EquippedBattalion(this, (int)ID_SINGLE_CONTROL::ID_EB, buffer);
	wxStaticText* equippedweaponlabel = new wxStaticText(this, wxID_ANY, "Equipped Weapon");
	ew = new EquippedWeapon(this, (int)ID_SINGLE_CONTROL::ID_EW, buffer);
	wxStaticText* equippedequipmentlabel = new wxStaticText(this, wxID_ANY, "Equipped Equipment");
	ee = new EquippedEquipment(this, (int)ID_SINGLE_CONTROL::ID_EE, buffer);
	ap = new AbilityPanel(abilitymap, this, (int)ID_SINGLE_CONTROL::ID_AP);
	physicalequipped->Add(equippedbattalionlabel);
	physicalequipped->Add(eb);
	physicalequipped->Add(equippedweaponlabel);
	physicalequipped->Add(ew);
	physicalequipped->Add(equippedequipmentlabel);
	physicalequipped->Add(ee);
	intangibleequipped->Add(ap);
	panelsizer->Add(physicalequipped);
	panelsizer->Add(intangibleequipped);
	this->SetSizer(panelsizer);
}

void EquippedPanel::ReceiveCharacterInnateExclusivity(wxString charactername) {
	ap->ReceiveCharacterInnateExclusivity(charactername);
}

void EquippedPanel::ReceiveClassInnateExclusivity(wxString classname) {
	ap->ReceiveClassInnateExclusivity(classname);
}

void EquippedPanel::ReceiveSLASelections(AbilitySelections* selections) {
	ap->ReceiveSLASelections(selections);
}

void EquippedPanel::ReceiveLBWSelection(wxString weaponname) {
	ew->ReceiveLBWSelection(weaponname);
}

void EquippedPanel::ReceiveLBESelection(wxString equipmentname) {
	ee->ReceiveLBESelection(equipmentname);
}

void EquippedPanel::ReceiveLBBSelection(wxString battalionname) {
	eb->ReceiveLBBSelection(battalionname);
}

void EquippedPanel::OnSize(wxSizeEvent& event) {
	if (ap) {
		ap->Fit();
		ap->GetParent()->Fit();
	}

	wxSize test = this->GetMinSize();
	event.Skip();
}

//void EquippedPanel::OnCollChange(wxCollapsiblePaneEvent& event) {
//	SendSizeEventToParent();
//}

//wxBEGIN_EVENT_TABLE(EquippedPanel, wxPanel)
//	EVT_SIZE(EquippedPanel::OnSize)
//	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPB, EquippedPanel::OnCollChange)
//	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPW, EquippedPanel::OnCollChange)
//	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPE, EquippedPanel::OnCollChange)
//wxEND_EVENT_TABLE()
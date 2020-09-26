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
	wxStaticText* equippedgambitlabel = new wxStaticText(this, wxID_ANY, "Equipped Gambit");
	eg = new EquippedGambit(this, (int)ID_SINGLE_CONTROL::ID_EG, buffer);
	wxStaticText* equippedweaponlabel = new wxStaticText(this, wxID_ANY, "Equipped Weapon");
	ew = new EquippedWeapon(this, (int)ID_SINGLE_CONTROL::ID_EW, buffer);
	wxStaticText* equippedequipmentlabel = new wxStaticText(this, wxID_ANY, "Equipped Equipment");
	ee = new EquippedEquipment(this, (int)ID_SINGLE_CONTROL::ID_EE, buffer);
	abp = new AbilityPanel(abilitymap, this, (int)ID_SINGLE_CONTROL::ID_ABP);
	physicalequipped->Add(equippedbattalionlabel);
	physicalequipped->Add(eb);
	physicalequipped->Add(equippedgambitlabel);
	physicalequipped->Add(eg);
	physicalequipped->Add(equippedweaponlabel);
	physicalequipped->Add(ew);
	physicalequipped->Add(equippedequipmentlabel);
	physicalequipped->Add(ee);
	intangibleequipped->Add(abp);
	panelsizer->Add(physicalequipped);
	panelsizer->Add(intangibleequipped);
	this->SetSizer(panelsizer);
}

void EquippedPanel::ReceiveCharacterInnateExclusivity(wxString charactername) {
	abp->ReceiveCharacterInnateExclusivity(charactername);
}

void EquippedPanel::ReceiveClassInnateExclusivity(wxString classname) {
	abp->ReceiveClassInnateExclusivity(classname);
}

void EquippedPanel::ReceiveSLASelections(AbilitySelections* selections) {
	abp->ReceiveSLASelections(selections);
}

void EquippedPanel::ReceiveLBWSelection(wxString weaponname) {
	ew->ReceiveLBWSelection(weaponname);
}

void EquippedPanel::ReceiveLBESelection(wxString equipmentname, wxString equipmentdescription) {
	ee->ReceiveLBESelection(equipmentname, equipmentdescription);
}

void EquippedPanel::ReceiveLBBSelection(wxString battalionname, wxString gambitname) {
	eb->ReceiveLBBSelection(battalionname);
	eg->ReceiveLBBSelection(gambitname);
}

void EquippedPanel::OnSize(wxSizeEvent& event) {
	if (abp) {
		abp->Fit();
		abp->GetParent()->Fit();
	}

	wxSize test = this->GetMinSize();
	event.Skip();
}
#ifndef EQUIPPEDPANEL_H
#define EQUIPPEDPANEL_H

#include <wx/wx.h>
#include <map>
#include <AbilitySelections.h>
#include <constants.h>
#include <EquippedPanel/Weapon/EquippedWeapon.h>
#include <EquippedPanel/Battalion/EquippedBattalion.h>
#include <EquippedPanel/Gambit/EquippedGambit.h>
#include <EquippedPanel/Equipment/EquippedEquipment.h>
#include <EquippedPanel/Ability/AbilityPanel.h>

class EquippedPanel : public wxPanel {
private:
	wxBoxSizer* panelsizer;
	EquippedBattalion* eb;
	EquippedGambit* eg;
	EquippedWeapon* ew;
	EquippedEquipment* ee;
	AbilityPanel* ap;
public:
	EquippedPanel(std::map<wxString, wxClientData*> abilitymap, wxWindow* parent, wxWindowID id);
	~EquippedPanel() {}

	void ReceiveLBWSelection(wxString weaponname);
	void ReceiveLBESelection(wxString equipmentname, wxString equipmentdescription);
	void ReceiveLBBSelection(wxString battalionname, wxString gambitname);
	void ReceiveCharacterInnateExclusivity(wxString charactername);
	void ReceiveClassInnateExclusivity(wxString classname);
	void ReceiveSLASelections(AbilitySelections* selections);
	void OnSize(wxSizeEvent& event);
};

#endif
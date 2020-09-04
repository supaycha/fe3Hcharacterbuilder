#ifndef MYFRAME_H
#define MYFRAME_H

#include <wx/wx.h>
//#include <wx/collpane.h>
#include <map>
#include <Stat.h>
#include <Unit/Unit.h>
#include <Unit/Battalion.h>
#include <Unit/Character.h>
#include <Unit/Weapon/Weapon.h>
#include <Unit/Weapon/BlankWeapon.h>
#include <Unit/Weapon/Axe.h>
#include <Unit/Weapon/BlackMagic.h>
#include <Unit/Weapon/Bow.h>
#include <Unit/Weapon/DarkMagic.h>
#include <Unit/Weapon/Gauntlets.h>
#include <Unit/Weapon/Lance.h>
#include <Unit/Weapon/Sword.h>
#include <Unit/Weapon/WhiteMagic.h>
#include <Unit/Class.h>
#include <Unit/Equipment/Equipment.h>
#include <AbilitySelections.h>
#include "UnitList.h"
#include <constants.h>
#include <SkillLevelPanel.h>
#include <ListBox/ListBoxWeapons.h>
#include <ListBox/ListBoxEquipment.h>
#include <ListBox/ListBoxBattalions.h>
#include <ListBoxASLA.h>
#include <EquippedOptions/EquippedCharInnateAbility.h>
#include <EquippedOptions/EquippedClassInnateAbility.h>
#include <EquippedOptions/EquippedSkillLvlAbilities.h>
#include <StatsPanel.h>
#include <GridMain/GridWeaponStats.h>
#include <GridMain/GridEquipmentStats.h>
#include <GridMain/GridBattalionStats.h>
#include <GridMain/GridTotalStats.h>
#include <MysteriousTeacher/MysteriousTeacher.h>
#include <EquippedPanel.h>
#include <WeaponManager.h>
//#include <vld.h>

wxDECLARE_EVENT(REPEAT_DDCH_SELECTION, wxCommandEvent);
wxDECLARE_EVENT(REPEAT_DDCL_SELECTION, wxCommandEvent);
wxDECLARE_EVENT(REPEAT_LBASLA_SELECTION, wxCommandEvent);
wxDECLARE_EVENT(REPEAT_GMT_STATS, wxCommandEvent);
wxDECLARE_EVENT(SELECTION_HAS_CHANGED, wxCommandEvent);
wxDECLARE_EVENT(TRANSMIT_GWS_STATS, wxCommandEvent);
wxDECLARE_EVENT(TRANSMIT_GES_STATS, wxCommandEvent);
wxDECLARE_EVENT(TRANSMIT_GBS_STATS, wxCommandEvent);
wxDECLARE_EVENT(TRANSMIT_DDCH_SELECTION, wxCommandEvent);
wxDECLARE_EVENT(TRANSMIT_SCL_SELECTION, wxSpinEvent);
wxDECLARE_EVENT(TRANSMIT_DDCL_SELECTION, wxCommandEvent);
wxDECLARE_EVENT(TRANSMIT_GMT_STATS, wxCommandEvent);

class MysteriousTeacher;
class ListBoxASLA;
class SkillLevelPanel;

class MyFrame : public wxFrame {
private:
	wxBoxSizer* framesizer;
	wxBoxSizer* column1;

	MysteriousTeacher* mt;
	EquippedPanel* ep;
	WeaponManager* wm;
	wxBoxSizer* column2;
	wxBoxSizer* column3;
	wxBoxSizer* column4;
	wxBoxSizer* column5;
	wxBoxSizer* column6;

	//ListBoxWeapons* lbw;
	ListBoxEquipment* lbe;
	ListBoxBattalions* lbb;
	ListBoxASLA* lbasla;
	EquippedCharInnateAbility* echia;
	EquippedClassInnateAbility* eclia;
	EquippedSkillLvlAbilities* esla;
	GridEquipmentStats* ges;
	GridTotalStats* gts;	
	SkillLevelPanel* slp;
	StatsPanel* sp;
	wxDECLARE_EVENT_TABLE();
public:
	MyFrame(wxWindowID id, const wxString& title);
	~MyFrame() {}
	void BounceRepeatedDDCHSelection_exclusivitycheck(wxCommandEvent& repititionfromMT);
	void BounceRepeatedDDCLSelection_classinnatecheck(wxCommandEvent& repititionfromMT);
	void BounceRepeatedLBASLASelection_updateselabiliities(wxCommandEvent& repititionfromSLP);
	void BounceRepeatedGMTStats_partoftotalstats(wxCommandEvent& repititionfromMT);
	void BounceLBWSelection(wxCommandEvent& selection);
	void BounceLBESelection(wxCommandEvent& selection);
	void BounceLBBSelection(wxCommandEvent& selection);
	void BounceGWSStats_partoftotalstats(wxCommandEvent& eventfromGWS);
	void BounceGESStats_partoftotalstats(wxCommandEvent& eventfromGES);
	void BounceGBSStats_partoftotalstats(wxCommandEvent& eventfromGBS);
	void BounceSLInfo(wxCommandEvent& eventfromwho);
	void DetermineWeaponType(Unit* unit, std::vector<wxClientData*>& weapondata);

	void OnQuit(wxCommandEvent& event);
	void OnSize(wxSizeEvent& event);
	void OnCollPaneChange(wxCollapsiblePaneEvent& event);
};

#endif
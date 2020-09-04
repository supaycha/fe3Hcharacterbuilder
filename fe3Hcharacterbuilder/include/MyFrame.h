#ifndef MYFRAME_H
#define MYFRAME_H

#include <wx/wx.h>
#include <map>
#include <AbilitySelections.h>
#include <Unit/Unit.h>
#include <Unit/Battalion.h>
#include <Unit/Character.h>
#include <Unit/Class.h>
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
#include <Unit/Equipment/Equipment.h>
#include <Lists/AbilityList.h>
#include <Lists/UnitList.h>
#include <constants.h>
#include <MysteriousTeacher/MysteriousTeacher.h>
#include <EquippedPanel/EquippedPanel.h>
#include <AvailablePanel/SkillLevelPanel/SkillLevelPanel.h>
#include <AvailablePanel/ListBoxEquipment.h>
#include <Stats Panel/StatsPanel.h>
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

class MyFrame : public wxFrame {
private:
	wxBoxSizer* framesizer;
	wxBoxSizer* column1;
	wxBoxSizer* column2;
	wxBoxSizer* column3;
	wxBoxSizer* column4;
	wxBoxSizer* column5;
	wxBoxSizer* column6;

	MysteriousTeacher* mt;
	EquippedPanel* ep;	
	ListBoxEquipment* lbe;
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
	void DetermineWeaponType(Unit* unit, std::vector<wxClientData*>& weapondata);

	void OnQuit(wxCommandEvent& event);
	void OnSize(wxSizeEvent& event);
};

#endif
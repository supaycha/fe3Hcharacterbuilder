#ifndef MYFRAME_H
#define MYFRAME_H

#include <wx/wx.h>
#include <map>
#include "Stat.h"
#include "Unit.h"
#include "UnitList.h"
#include "constants.h"
#include "ListBox.h"
#include "Gridmain.h"
#include <AbilityManager/AbilityManager.h>
#include <SkillLevelManager/SkillLevelManager.h>
#include <MysteriousTeacher/MysteriousTeacher.h>
//#include <vld.h>

wxDECLARE_EVENT(REPEAT_DDCH_SELECTION, wxCommandEvent);
wxDECLARE_EVENT(REPEAT_DDCL_SELECTION, wxCommandEvent);
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
class SkillLevelManager;
class AbilityManager;

class MyFrame : public wxFrame {
private:
	wxBoxSizer* Buildersizer;
	wxBoxSizer* MTandGridStats_col;
	wxBoxSizer* gridstatssizer;
	wxBoxSizer* lbsizer;
	wxBoxSizer* slablsizer;

	MysteriousTeacher* mt;
	ListBoxWeapons* lbw;
	ListBoxEquipment* lbe;
	ListBoxBattalions* lbb;
	GridWeaponStats* gws;
	GridEquipmentStats* ges;
	GridBattalionStats* gbs;
	GridTotalStats* gts;
	SkillLevelManager* slm;
	AbilityManager* am;

	wxDECLARE_EVENT_TABLE();
public:
	MyFrame(wxWindowID id, const wxString& title);
	~MyFrame() {}
	void BounceRepeatedDDCHSelection_exclusivitycheck(wxCommandEvent& repititionfromMT);
	void BounceRepeatedDDCLSelection_classinnatecheck(wxCommandEvent& repititionfromMT);
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
};


#endif
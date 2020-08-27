#ifndef MYSTERIOUSTEACHER_H
#define MYSTERIOUSTEACHER_H

#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/grid.h>
#include <map>
#include <Unit/Unit.h>
#include <Unit/Character.h>
#include <Unit/Class.h>
#include <constants.h>
#include <MysteriousTeacher/DropDownCharacters.h>
#include <MysteriousTeacher/DropDownClasses.h>
#include <MysteriousTeacher/SpinCtrlLevel.h>
#include <MysteriousTeacher/GTBMysteriousTeacher.h>
#include <MysteriousTeacher/GridMysteriousTeacher.h>
#include <MyFrame.h>

//#include <vld.h>

wxDECLARE_EVENT(TRANSMIT_DDCH_SELECTION, wxCommandEvent);
wxDECLARE_EVENT(TRANSMIT_DDCL_SELECTION, wxCommandEvent);
wxDECLARE_EVENT(TRANSMIT_GMT_STATS, wxCommandEvent);
wxDECLARE_EVENT(TRANSMIT_SCL_SELECTION, wxSpinEvent);

wxDECLARE_EVENT(REPEAT_DDCH_SELECTION, wxCommandEvent);
wxDECLARE_EVENT(REPEAT_DDCL_SELECTION, wxCommandEvent);
wxDECLARE_EVENT(REPEAT_GMT_STATS, wxCommandEvent);

class MysteriousTeacher : public wxPanel {
private:
	GridMysteriousTeacher* gmt;

	DropDownCharacters* ddc;
	wxBoxSizer* total;
	std::wstring currentDDCselection;

	std::vector<SpinCtrlLevel*> sclVector;
	std::vector<DropDownClasses*> ddclVector;
	std::vector<wxBoxSizer*> columns;
public:
	MysteriousTeacher(std::vector<wxString> characternames, std::vector<wxClientData*> characterdata, std::map<wxString, wxClientData*> classmap, wxWindow* parent, wxWindowID id);
	~MysteriousTeacher() {}

	void BounceDDCHSelection(wxCommandEvent& transmission);
	void BounceSCLSelection(wxSpinEvent& transmission);
	void BounceDDCLSelection(wxCommandEvent& transmission);

	void ForwardGMTStats(wxCommandEvent& forwarded);
};

#endif
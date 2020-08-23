#ifndef GRIDMYSTERIOUSTEACHER_H
#define GRIDMYSTERIOUSTEACHER_H

#include <wx/wx.h>
#include <wx/grid.h>
#include "Unit.h"
#include "GTBMysteriousTeacher.h"

wxDECLARE_EVENT(TRANSMIT_GMT_STATS, wxCommandEvent);

class GridMysteriousTeacher : public wxGrid {
private:
	std::vector<wxString> headers{ "HP", "MOV", "STR", "MAG", "DEX", "SPD", "LCK", "DEF", "RES", "CHA" };
	GTBMysteriousTeacher* gtbmt;
public:
	GridMysteriousTeacher(wxWindow* parent, wxWindowID id, bool hidecolheaders);
	~GridMysteriousTeacher() {}

	void initpopulate();
	void repopulate();

	void UpdateDDCHSelection(Character character);
	void UpdateSCLSelection(int level, int ID);
	void UpdateDDCLSelection(Class cLass, int ID);
};

#endif
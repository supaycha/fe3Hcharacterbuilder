#ifndef GRIDWEAPONSTATS_H
#define GRIDWEAPONSTATS_H

#include <wx/wx.h>
#include <Stat.h>
#include <constants.h>
#include <GTBMain/GTBWeaponStats.h>

wxDECLARE_EVENT(TRANSMIT_GWS_STATS, wxCommandEvent);

class GridWeaponStats : public wxGrid {
private:
	GTBWeaponStats* gtbws;
public:
	GridWeaponStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBWSelection(Stats stats);
	void repopulate();
};

#endif
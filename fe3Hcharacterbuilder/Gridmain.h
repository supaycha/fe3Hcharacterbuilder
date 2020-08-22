#ifndef GRIDMAIN_H
#define GRIDMAIN_H

#include <wx/wx.h>
#include <wx/grid.h>
#include "Stat.h"
#include "constants.h"
#include "GTBmain.h"
//#include <vld.h>

wxDECLARE_EVENT(TRANSMIT_GWS_STATS, wxCommandEvent);
wxDECLARE_EVENT(TRANSMIT_GES_STATS, wxCommandEvent);
wxDECLARE_EVENT(TRANSMIT_GBS_STATS, wxCommandEvent);

class GridWeaponStats : public wxGrid {
private:
	GTBWeaponStats* gtbws;
public:
	GridWeaponStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBWSelection(Stats stats);
	void repopulate();
};


class GridEquipmentStats : public wxGrid {
private:
	GTBEquipmentStats* gtbes;
public:
	GridEquipmentStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBESelection(Stats stats);
	void repopulate();
};


class GridBattalionStats : public wxGrid {
private:
	GTBBattalionStats* gtbbs;
public:
	GridBattalionStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBBSelection(Stats stats);
	void repopulate();
};


class GridTotalStats : public wxGrid {
private:
	GTBTotalStats* gtbts;
public:
	GridTotalStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveGMTStats(Stats stats);
	void ReceiveGWSStats(Stats stats);
	void ReceiveGESStats(Stats stats);
	void ReceiveGBSStats(Stats stats);
	void repopulate();
};

#endif
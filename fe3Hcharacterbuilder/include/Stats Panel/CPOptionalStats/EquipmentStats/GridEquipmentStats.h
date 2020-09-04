#ifndef GRIDEQUIPMENTSTATS_H
#define	GRIDEQUIPMENTSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>
#include <constants.h>
#include <Stats Panel/CPOptionalStats/EquipmentStats/GTBEquipmentStats.h>

wxDECLARE_EVENT(TRANSMIT_GES_STATS, wxCommandEvent);

class GridEquipmentStats : public wxGrid {
private:
	GTBEquipmentStats* gtbes;
public:
	GridEquipmentStats(wxWindow* parent, wxWindowID id);
	void initpopulate();
	void ReceiveLBESelection(Stats stats);
	void repopulate();
};

#endif
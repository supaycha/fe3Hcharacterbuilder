#ifndef GTBEQUIPMENTSTATS_H
#define GTBEQUIPMENTSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>

class GTBEquipmentStats : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "PROT", "WGT", "RES", "HIT", "TCRIT", "AVO", "SPD", "MOV", "LCK", "MATK", "HEAL", "RANGE" };
	Stats equipmentstats;
public:
	GTBEquipmentStats() {}
	~GTBEquipmentStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { return equipmentstats[col].getText(); }
	void SetValue(int row, int col, const wxString& value) override { equipmentstats[col] = Stat(value); }

	void ReceiveLBESelection(Stats stats);

	wxString GetHeader(int index) { return headers[index]; }
};

#endif
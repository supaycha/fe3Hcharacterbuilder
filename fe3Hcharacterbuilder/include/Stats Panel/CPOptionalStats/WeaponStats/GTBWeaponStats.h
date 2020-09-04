#ifndef GTBWEAPONSTATS_H
#define GTBWEAPONSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>

class GTBWeaponStats : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "MIGHT", "HIT", "CRIT", "RANGE", "WEIGHT", "SL", "USES" };
	Stats weaponstats;
public:
	GTBWeaponStats() {}
	~GTBWeaponStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { return weaponstats[col].getText(); }
	void SetValue(int row, int col, const wxString& value) override { weaponstats[col] = Stat(value); }

	void ReceiveLBWSelection(Stats stats);

	wxString GetHeader(int index) { return headers[index]; }
};

#endif
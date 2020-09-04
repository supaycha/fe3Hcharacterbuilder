#ifndef GTBCHARINNATEABILITYSTATS_H
#define GTBCHARINNATEABILITYSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>

class GTBCharInnateAbilityStats : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "PROT", "WGT", "RES", "HIT", "AVO", "TCRIT", "AVO", "SPD", "MOV", "LCK", "MATK", "HEAL", "RANGE" };
	Stats gtbcharinnateabilitystats;
public:
	GTBCharInnateAbilityStats() {}
	~GTBCharInnateAbilityStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { return gtbcharinnateabilitystats[col].getText(); }
	void SetValue(int row, int col, const wxString& value) override { gtbcharinnateabilitystats[col] = Stat(value); }

	void ReceiveLBBSelection(Stats stats);

	wxString GetHeader(int index) { return headers[index]; }
};

#endif
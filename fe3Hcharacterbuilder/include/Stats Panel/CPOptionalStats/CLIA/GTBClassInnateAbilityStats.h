#ifndef GTBCLASSINNATEABILITYSTATS_H
#define GTBCLASSINNATEABILITYSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>

class GTBClassInnateAbilityStats : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "PROT", "WGT", "RES", "HIT", "AVO", "TCRIT", "AVO", "SPD", "MOV", "LCK", "MATK", "HEAL", "RANGE" };
	Stats gtbclassinnateabilitystats;
public:
	GTBClassInnateAbilityStats() {}
	~GTBClassInnateAbilityStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { return gtbclassinnateabilitystats[col].getText(); }
	void SetValue(int row, int col, const wxString& value) override { gtbclassinnateabilitystats[col] = Stat(value); }

	void ReceiveLBBSelection(Stats stats);

	wxString GetHeader(int index) { return headers[index]; }
};

#endif
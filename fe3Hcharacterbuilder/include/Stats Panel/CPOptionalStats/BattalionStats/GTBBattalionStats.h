#ifndef GTBBATTALIONSTATS_H
#define GTBBATTALIONSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>

class GTBBattalionStats : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "PATK", "MATK", "HIT", "CRIT", "AVO", "PROT", "RES", "CHA", "END" };
	Stats battalionstats;
public:
	GTBBattalionStats() {}
	~GTBBattalionStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { return battalionstats[col].getText(); }
	void SetValue(int row, int col, const wxString& value) override { battalionstats[col] = Stat(value); }

	void ReceiveLBBSelection(Stats stats);

	wxString GetHeader(int index) { return headers[index]; }
};

#endif
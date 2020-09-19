#ifndef GTBGAMBITSTATS_H
#define GTBGAMBITSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>

class GTBGambitStats : public wxGridTableBase {
private:
	std::vector<wxString> headers{ "GMIGHT", "GHIT", "RANGE", "USES" };
	Stats gambitstats;
	Stats augmentedgambitstats;
	wxString gmight;
public:
	GTBGambitStats() {}
	~GTBGambitStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return headers.size(); }
	wxString GetValue(int row, int col) override { return augmentedgambitstats[col].getText(); }
	void SetValue(int row, int col, const wxString& value) override { gambitstats[col] = Stat(value); }

	void ReceiveLBBSelection(Stats stats);
	void ReceiveAugmenttoStats(wxString value);
	void recalculate();

	wxString GetHeader(int index) { return headers[index]; }
};

#endif
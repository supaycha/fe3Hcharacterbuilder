#ifndef GTBCLASSINNATEABILITYSTATS_H
#define GTBCLASSINNATEABILITYSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>
#include <constants.h>

class GTBClassInnateAbilityStats : public wxGridTableBase {
private:
	std::vector<STPACKAGE> headers{ { STATTYPE::PROT, "PROT" }, { STATTYPE::WEIGHT, "WGT" }, { STATTYPE::RES, "RES" }, { STATTYPE::HIT, "HIT" },
									{ STATTYPE::AVO, "AVO" }, { STATTYPE::TCRIT, "TCRIT" }, { STATTYPE::SPD, "SPD" }, { STATTYPE::MOV, "MOV" },
									{ STATTYPE::LCK, "LCK" }, { STATTYPE::MATK, "MATK" }, { STATTYPE::HEAL, "HEAL" }, { STATTYPE::RANGE, "RANGE" },
									{ STATTYPE::MIGHT, "MIGHT" } };
	STPACKAGE stp;
	wxString currentheader;
public:
	GTBClassInnateAbilityStats() {}
	~GTBClassInnateAbilityStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return 1; }
	wxString GetValue(int row, int col) override { return stp.name; }
	void SetValue(int row, int col, const wxString& value) override { stp.name = value; }

	void ReceiveCLIASSelection(STPACKAGE stp);

	wxString GetHeader(int index) { return currentheader; }
	wxString GetCurrentHeader();
};

#endif
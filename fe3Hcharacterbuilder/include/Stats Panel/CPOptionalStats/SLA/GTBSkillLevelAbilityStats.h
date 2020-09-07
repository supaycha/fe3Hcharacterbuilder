#ifndef GTBSKILLLEVELABILITYSTATS_H
#define GTBSKILLLEVELABILITYSTATS_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <Stat.h>
#include <constants.h>

class GTBSkillLevelAbilityStats : public wxGridTableBase {
private:
	std::vector<STPACKAGE> headers{ { STATTYPE::PROT, "PROT" }, { STATTYPE::WEIGHT, "WGT" }, { STATTYPE::RES, "RES" }, { STATTYPE::HIT, "HIT" },
									{ STATTYPE::AVO, "AVO" }, { STATTYPE::TCRIT, "TCRIT" }, { STATTYPE::SPD, "SPD" }, { STATTYPE::MOV, "MOV" },
									{ STATTYPE::LCK, "LCK" }, { STATTYPE::MATK, "MATK" }, { STATTYPE::HEAL, "HEAL" }, { STATTYPE::RANGE, "RANGE" },
									{ STATTYPE::MIGHT, "MIGHT" }, { STATTYPE::BLANK, "---" }, { STATTYPE::CRITAVO, "CRITAVO" } };
	std::vector<STPACKAGE> stpVector{ 1, STPACKAGE(STATTYPE::BLANK, "---") };
	std::vector<wxString> currentheaders{ "---" };
public:
	GTBSkillLevelAbilityStats() {}
	~GTBSkillLevelAbilityStats() {}
	int GetNumberRows() override { return 1; }
	int GetNumberCols() override { return stpVector.size(); }
	wxString GetValue(int nothing, int index) override { return stpVector[index].name; }
	void SetValue(int nothing, int index, const wxString& value) override { stpVector[index].name = value; }

	void ReceiveSLASSelection(std::vector<STPACKAGE> vector);

	wxString GetHeader(int index) { return currentheaders[index]; }
	std::vector<wxString> GetCurrentHeaders();
};

#endif
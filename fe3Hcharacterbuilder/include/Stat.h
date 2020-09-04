#ifndef STAT_H
#define STAT_H

#include <string>
#include <wx/wx.h>
//#include <vld.h>

class Stat {
private:
	std::wstring stat;
public:
	Stat() : stat{} {}
	Stat(std::wstring change) : stat{ change } {}
	std::wstring getText() const { return stat; }
	Stat& operator=(const Stat& source) = default;  //in cpp
	Stat(const Stat&) = default;
};

class Stats : public wxClientData {
private:
	std::vector<Stat> stats;
public:
	Stats() : stats{ 10, Stat{} } {}
	Stats(int size, std::wstring value) : stats(size, value) {}
	Stats(std::vector<Stat> change) : stats(change) {}
	Stats(std::wstring uPROT, std::wstring uWGT, std::wstring uRES, std::wstring uHIT, std::wstring uTCRIT,
		std::wstring uAVO, std::wstring uSPD, std::wstring uMOV, std::wstring uLCK, std::wstring uMATK, 
		std::wstring uHEAL, std::wstring uRANGE) : 
		stats{ uPROT, uWGT, uRES, uHIT, uTCRIT, uAVO, uSPD, uMOV, uLCK, uMATK, uHEAL, uRANGE } {}
	Stats(std::wstring uHP, std::wstring uMOV, std::wstring uSTR,
		std::wstring uMAG, std::wstring uDEX, std::wstring uSPD,
		std::wstring uLCK, std::wstring uDEF, std::wstring uRES,
		std::wstring uCHA) :
		stats{ uHP, uMOV, uSTR, uMAG, uDEX, uSPD, uLCK, uDEF, uRES, uCHA }
	{}
	Stats(std::wstring uMight, std::wstring uHit, std::wstring uCrit,
		std::wstring uRange, std::wstring uWeight, std::wstring uSkillLVL,
		std::wstring uUses) :
		stats{ uMight, uHit, uCrit, uRange, uWeight, uSkillLVL, uUses }
	{}
	Stats(std::wstring uPHYSATK, std::wstring uMGKATK, std::wstring uHIT,
		std::wstring uCRIT, std::wstring uAVO, std::wstring uPROT,
		std::wstring uRES, std::wstring uCHA, std::wstring uEND) :
		stats{ uPHYSATK, uMGKATK, uHIT, uCRIT, uAVO, uPROT, uRES, uCHA, uEND }
	{}
	Stats(std::wstring uPHYSATK, std::wstring uMGKATK, std::wstring uPHYSHIT,
		std::wstring uMGKHIT, std::wstring uTCRIT, std::wstring uAS,
		std::wstring TPROT, std::wstring TRSL, std::wstring uAVO, std::wstring uCRITAVO, std::wstring uRNGE) :
		stats{ uPHYSATK, uMGKATK, uPHYSHIT, uMGKHIT, uTCRIT, uAS, TPROT, TRSL, uAVO, uCRITAVO, uRNGE }
	{}

	int Size() const { return stats.size(); }
	Stat& operator[](UINT index) { return stats[index]; }
	Stats& operator=(const Stats& source) = default;
	Stats(const Stats&) = default;
	Stats* new_expr() { return new Stats(); }
	Stats* clone() { return new Stats(*this); }

	void push_back(std::wstring stringforstat) { stats.push_back(stringforstat); }
};

#endif
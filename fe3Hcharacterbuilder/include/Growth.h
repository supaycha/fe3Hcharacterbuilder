#ifndef GROWTH_H
#define GROWTH_H

#include <string>
#include <wx/wx.h>
//#include <vld.h>

class Growth {
private:
	std::wstring growth;
public:
	Growth() : growth{} {}
	Growth(std::wstring change) : growth{ change } {}
	std::wstring getText() const { return growth; }
	Growth& operator=(const Growth& source) = default;  //in cpp
	Growth(const Growth&) = default;
};

class Growths : public wxClientData {
private:
	std::vector<Growth> growths;
public:
	Growths() : growths{ 10, Growth{} } {}
	Growths(int size, std::wstring value) : growths(size, value) {}
	Growths(std::vector<Growth> change) : growths(change) {}
	Growths(std::wstring uPROT, std::wstring uRES) : growths{ uPROT, uRES } {}
	Growths(std::wstring uHP, std::wstring uMOV, std::wstring uSTR,
		std::wstring uMAG, std::wstring uDEX, std::wstring uSPD,
		std::wstring uLCK, std::wstring uDEF, std::wstring uRES,
		std::wstring uCHA) :
		growths{ uHP, uMOV, uSTR, uMAG, uDEX, uSPD, uLCK, uDEF, uRES, uCHA }
	{}

	int Size() const { return growths.size(); }
	Growth& operator[](UINT index) { return growths[index]; }
	Growths& operator=(const Growths& source) = default;
	Growths(const Growths&) = default;
	Growths* new_expr() { return new Growths(); }
	Growths* clone() { return new Growths(*this); }

	void push_back(std::wstring stringforgrowth) { growths.push_back(stringforgrowth); }
	//auto begin() { return growths.begin(); }
	//auto end() { return growths.end(); }
};

#endif
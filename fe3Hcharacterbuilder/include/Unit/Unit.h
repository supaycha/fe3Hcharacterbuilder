#ifndef UNIT_H
#define UNIT_H

#include <wx/wx.h>
#include "Stat.h"
//#include "Growth.h"
//#include "constants.h"
//#include <vld.h>

class Unit : public wxClientData {
public:
	virtual const std::wstring getName() = 0;
	virtual const Stats getStats() = 0;

	Unit() {};
	Unit(const Unit&) = default;
	virtual ~Unit() {}
	virtual Unit* new_expr() = 0;
	virtual Unit* clone() = 0;
};

//class Gambit : public Unit {
//private:
//	std::wstring name;
//	Stats gambitstats;
//public:
//	Gambit() {}
//	~Gambit() {}
//
//	const std::wstring getName() override { return name; }
//	const Stats getStats() override { return gambitstats; }
//
//	Gambit* new_expr() override { return new Gambit(); }
//	Gambit* clone() override { return new Gambit(*this); }
//};
#endif
#ifndef UNIT_H
#define UNIT_H

#include <wx/wx.h>
#include "Stat.h"
//#include <vld.h>

class Unit : public wxClientData {
public:

	Unit() {};
	Unit(const Unit&) = default;
	virtual ~Unit() {}	
	
	virtual const std::wstring getName() = 0;
	virtual const Stats getStats() = 0;

	virtual Unit* new_expr() = 0;
	virtual Unit* clone() = 0;
};

#endif
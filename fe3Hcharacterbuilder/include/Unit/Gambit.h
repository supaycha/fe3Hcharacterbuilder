#ifndef GAMBIT_H
#define GAMBIT_H

#include <Unit/Unit.h>

class Gambit : public Unit {
private:
	std::wstring name;
	Stats gambitstats;
public:
	Gambit() {}
	Gambit(std::wstring uName, std::wstring uGMIGHT, std::wstring uHIT, std::wstring uGRANGE, std::wstring uUSES, std::wstring uDESCRIPTION) :
		name{ uName }, gambitstats{ uGMIGHT, uHIT, uGRANGE, uUSES,uDESCRIPTION } {}
	~Gambit() {}

	const std::wstring getName() override { return name; }
	const Stats getStats() override { return gambitstats; }

	Gambit* new_expr() override { return new Gambit(); }
	Gambit* clone() override { return new Gambit(*this); }

};

#endif
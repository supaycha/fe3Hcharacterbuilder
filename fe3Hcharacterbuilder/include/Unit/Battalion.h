#ifndef BATTALION_H
#define BATTALION_H

#include <wx/wx.h>
#include <Stat.h>
#include <constants.h>
#include <Unit/Unit.h>

class Battalion : public Unit {
private:
	std::wstring name;
	Stats battstats;
	Stats levelincreases;
	std::wstring gambit;
	SL sl;
public:
	Battalion() {}
	Battalion(std::wstring uName,
		std::wstring uPA, std::wstring uMA, std::wstring uHIT, std::wstring uCRIT, std::wstring uAVO,
		std::wstring uPROT, std::wstring uRES, std::wstring uCHA, std::wstring uEND,
		std::wstring bPA, std::wstring bMA, std::wstring bHIT, std::wstring bCRIT, std::wstring bAVO,
		std::wstring bPROT, std::wstring bRES, std::wstring bCHA, std::wstring bEND, std::wstring uGambit, SL uSL) :
		name{ uName },
		battstats{ uPA, uMA, uHIT, uCRIT, uAVO, uPROT, uRES, uCHA, uEND },
		levelincreases{ bPA, bMA, bHIT, bCRIT, bAVO, bPROT, bRES, bCHA, bEND },
		gambit{ uGambit },
		sl{ uSL }
	{}
	~Battalion() {}

	const std::wstring getName() override { return name; }
	const Stats getStats() override { return battstats; }
	SL getSL() { return sl; }

	Battalion* new_expr() override { return new Battalion(); }
	Battalion* clone() override { return new Battalion(*this); }
};


#endif
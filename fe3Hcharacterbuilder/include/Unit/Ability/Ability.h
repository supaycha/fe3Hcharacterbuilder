#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <Stat.h>
#include <Unit/Unit.h>

class Ability : public Unit {
private:
	std::wstring abname;
	std::wstring source;
	std::wstring description;
public:
	Ability() {}
	Ability(std::wstring uName, std::wstring uSource, std::wstring uDescription) :
		abname(uName),
		source(uSource),
		description(uDescription) {}
	Ability(const Ability&) = default;
	virtual ~Ability() {}

	const std::wstring getName() override { return abname; }
	const Stats getStats() { Stats nothing; return nothing; };  //does nothing

	virtual Ability* new_expr() = 0;
	virtual Ability* clone() = 0;	

	std::wstring getDescription() { return description; }
	std::wstring getSource() { return source; }	
	
	virtual std::wstring getType() = 0;
};

#endif
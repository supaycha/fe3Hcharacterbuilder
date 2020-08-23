#ifndef RING_H
#define RING_H

class Ring : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::RING;
public:
	Ring() {}
	Ring(std::wstring uName, bool uExclusivity, std::wstring uCharacterNameorNames, std::wstring uProtection, std::wstring uResilience, std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterNameorNames, uProtection, uResilience, uDescription } {}
	~Ring() {}

	EQUIPMENTTYPE getType() override { return et; };
	Ring* new_expr() override { return new Ring(); }
	Ring* clone() override { return new Ring(*this); }
};

#endif
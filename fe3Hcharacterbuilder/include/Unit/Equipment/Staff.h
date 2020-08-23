#ifndef STAFF_H
#define STAFF_H

class Staff : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::STAFF;
public:
	Staff() {}
	Staff(std::wstring uName, bool uExclusivity, std::wstring uCharacterNameorNames, std::wstring uProtection, std::wstring uResilience, std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterNameorNames, uProtection, uResilience, uDescription } {}
	~Staff() {}

	EQUIPMENTTYPE getType() override { return et; };
	Staff* new_expr() override { return new Staff(); }
	Staff* clone() override { return new Staff(*this); }
};

#endif
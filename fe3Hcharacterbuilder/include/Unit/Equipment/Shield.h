#ifndef SHIELD_H
#define SHIELD_H

class Shield : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::SHIELD;
public:
	Shield() {}
	Shield(std::wstring uName, bool uExclusivity, std::wstring uCharacterName, std::wstring uProtection, std::wstring uResilience, std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterName, uProtection, uResilience, uDescription } {}
	~Shield() {}

	EQUIPMENTTYPE getType() override { return et; };
	Shield* new_expr() override { return new Shield(); }
	Shield* clone() override { return new Shield(*this); }
};

#endif
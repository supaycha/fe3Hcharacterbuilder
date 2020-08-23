#ifndef GEM_H
#define GEM_H

class Gem : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::STAFF;
public:
	Gem() {}
	Gem(std::wstring uName, bool uExclusivity, std::wstring uCharacterNameorNames, std::wstring uProtection, std::wstring uResilience, std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterNameorNames, uProtection, uResilience, uDescription } {}
	~Gem() {}

	EQUIPMENTTYPE getType() override { return et; };
	Gem* new_expr() override { return new Gem(); }
	Gem* clone() override { return new Gem(*this); }
};

#endif
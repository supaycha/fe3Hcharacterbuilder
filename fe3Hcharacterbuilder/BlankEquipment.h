#ifndef BLANKEQUIPMENT_H
#define BLANKEQUIPMENT_H

class BlankEquipment : public Equipment {
private:
	EQUIPMENTTYPE et = EQUIPMENTTYPE::BLANK;
public:
	BlankEquipment() {}
	BlankEquipment(std::wstring uName, bool uExclusivity, std::wstring uCharacterNameorNames, std::wstring uProtection, std::wstring uResilience, std::wstring uDescription) :
		Equipment{ uName, uExclusivity, uCharacterNameorNames, uProtection, uResilience, uDescription } {}
	~BlankEquipment() {}

	EQUIPMENTTYPE getType() override { return et; };
	BlankEquipment* new_expr() override { return new BlankEquipment(); }
	BlankEquipment* clone() override { return new BlankEquipment(*this); }
};

#endif
#ifndef CLASSMASTERYABILITY_H
#define CLASSMASTERYABILITY_H

class ClassMasteryAbility : public Ability {
private:
	std::wstring cmaType = L"ClassMastery";
public:
	ClassMasteryAbility() {}
	ClassMasteryAbility(std::wstring uName, std::wstring uSource, std::wstring uDescription) : Ability{ uName, uSource, uDescription } {}
	~ClassMasteryAbility() {}
	std::wstring getType() { return cmaType; }
	ClassMasteryAbility* new_expr() override { return new ClassMasteryAbility(); }
	ClassMasteryAbility* clone() override { return new ClassMasteryAbility(*this); }
};

#endif
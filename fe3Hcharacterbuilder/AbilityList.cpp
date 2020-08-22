#include "AbilityList.h"

Ability* AbilityList::operator[] (UINT index) const {
	return list[index].get();
}
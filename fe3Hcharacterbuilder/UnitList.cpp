#include "UnitList.h"
#include <vld.h>

Unit* UnitList::operator[] (UINT index) {
	return list[index].get();
}

Ability* AbilityList::operator[] (UINT index) const {
	return list[index].get();
}
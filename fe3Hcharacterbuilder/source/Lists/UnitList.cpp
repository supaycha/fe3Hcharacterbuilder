#include <Lists/UnitList.h>

Unit* UnitList::operator[] (UINT index) {
	return list[index].get();
}
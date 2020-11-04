#include "BigDecimalInt.h"

std::ostream& operator << (std::ostream& out, BigDecimalInt obj) {
	out << obj.decStr;
	out << obj.decInt;
	return out;
}

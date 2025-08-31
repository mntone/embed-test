#include "test.h"

packed_int16x2_t addsub(packed_int16x2_t x, packed_int16x2_t y) {
	x.upperval += y.upperval;
	x.lowerval -= y.lowerval;
	return x;
}

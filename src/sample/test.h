#pragma once

#include "macro.h"
#include <stdint.h>

int EMBED_TEST_EXPORT add_positive(int x, int y);

typedef struct packed_int16x2 {
	int16_t upperval;
	int16_t lowerval;
} packed_int16x2_t;

packed_int16x2_t EMBED_TEST_EXPORT addsub(packed_int16x2_t x, packed_int16x2_t y);

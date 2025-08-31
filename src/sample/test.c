#include "test.h"

int add_positive(int x, int y) {
	EMBED_TEST_ASSUME(x >= 0, "ERROR: x < 0");
	EMBED_TEST_ASSUME(y >= 0, "ERROR: y < 0");

	return x + y;
}

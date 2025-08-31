#include "assertion.h"

#if _DEBUG

#include <stdio.h>
#include <stdlib.h>

#define ASSERT_FORMAT        \
	"Assertion failed: %s\n" \
	"- cond: %s\n"           \
	"- file: %s, line: %d\n" \
	"- func: %s\n"

void _embed_test_default_assert_handler(
	const char *EMBED_TEST_RESTRICT __message,
	const char *EMBED_TEST_RESTRICT __condition,
	const char *EMBED_TEST_RESTRICT __file,
	const char *EMBED_TEST_RESTRICT __func,
	int                             __line,
	void                           *data
) {
	(void)data;

	fprintf(stderr, ASSERT_FORMAT, __message, __condition, __file, __line, __func);
	abort();
}

static struct embed_test_assert_info __embed_test_assert_info
	= {_embed_test_default_assert_handler, NULL};

struct embed_test_assert_info
embed_test_hook_assert(embed_test_assert_t handler, void *EMBED_TEST_RESTRICT data) {
	struct embed_test_assert_info prev_info = __embed_test_assert_info;

	__embed_test_assert_info.handler = handler;
	__embed_test_assert_info.data    = data;
	return prev_info;
}

void _embed_test_assert(
	const char *EMBED_TEST_RESTRICT __message,
	const char *EMBED_TEST_RESTRICT __condition,
	const char *EMBED_TEST_RESTRICT __file,
	const char *EMBED_TEST_RESTRICT __func,
	int                             __line
) {
	struct embed_test_assert_info info = __embed_test_assert_info;

	if (info.handler != NULL) {
		info.handler(__message, __condition, __file, __func, __line, info.data);
	}
}

#endif

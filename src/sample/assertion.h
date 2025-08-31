#pragma once

#if _DEBUG
#include "macro.h"

typedef void (*embed_test_assert_t)(
	const char *EMBED_TEST_RESTRICT __message,
	const char *EMBED_TEST_RESTRICT __condition,
	const char *EMBED_TEST_RESTRICT __file,
	const char *EMBED_TEST_RESTRICT __func,
	int                             __line,
	void *EMBED_TEST_RESTRICT       data
);

struct embed_test_assert_info {
	embed_test_assert_t       handler;
	void *EMBED_TEST_RESTRICT data;
};

struct embed_test_assert_info EMBED_TEST_EXPORT embed_test_hook_assert(
	embed_test_assert_t handler, void *EMBED_TEST_RESTRICT data
) EMBED_TEST_NONNULL(1, 2);

void _embed_test_assert(
	const char *EMBED_TEST_RESTRICT __message,
	const char *EMBED_TEST_RESTRICT __condition,
	const char *EMBED_TEST_RESTRICT __file,
	const char *EMBED_TEST_RESTRICT __func,
	int                             __line
) EMBED_TEST_NONNULL(1, 2, 3, 4);
#endif

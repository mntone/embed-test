#pragma once

#if _DEBUG
#include "assertion.h"
#define EMBED_TEST_ASSERT(expr, msg)                                            \
	if (!(expr)) _embed_test_assert((msg), #expr, __FILE__, __func__, __LINE__)
#else
#define EMBED_TEST_ASSERT(expr, msg)
#endif

#if _DEBUG
#define EMBED_TEST_ASSUME(expr, msg) EMBED_TEST_ASSERT(expr, msg)
#else
#if defined(__clang__)
#define EMBED_TEST_ASSUME(expr, msg) __builtin_assume(expr)
#elif defined(__GNUC__)
#define EMBED_TEST_ASSUME(expr, msg)     \
	if (!(expr)) __builtin_unreachable()
#elif defined(_MSC_VER)
#define EMBED_TEST_ASSUME(expr, msg) __assume(expr)
#else
#define EMBED_TEST_ASSUME(expr, msg) ((void)0)
#endif
#endif

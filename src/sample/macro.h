#pragma once

#ifdef EMBED_TEST_SHARED
#if defined(__GNUC__) || defined(__clang__)
#ifdef EMBED_TEST_EXPORTS
#define EMBED_TEST_EXPORT __attribute__((visibility("default")))
#else
#define EMBED_TEST_EXPORT
#endif
#elif defined(_MSC_VER)
#ifdef EMBED_TEST_EXPORTS
#define EMBED_TEST_EXPORT __declspec(dllexport)
#else
#define EMBED_TEST_EXPORT __declspec(dllimport)
#endif
#else
#define EMBED_TEST_EXPORT
#endif
#else
#define EMBED_TEST_EXPORT
#endif

#if defined(__GNUC__) || defined(__clang__)
#define EMBED_TEST_NONNULL(...) __attribute__((nonnull(__VA_ARGS__)))
#else
#define EMBED_TEST_NONNULL(...)
#endif

#ifdef __cplusplus
#ifdef _MSC_VER
#define EMBED_TEST_RESTRICT __restrict
#else
#define EMBED_TEST_RESTRICT __restrict__
#endif
#else
#define EMBED_TEST_RESTRICT restrict
#endif

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

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

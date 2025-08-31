if(BUILD_SHARED_LIBS OR EMBED_TEST_BUILD_SHARED_LIBS)
	set(EMBED_TEST_SHARED 1)
	add_library(${PROJECT_NAME} SHARED)
else()
	set(EMBED_TEST_SHARED 0)
	add_library(${PROJECT_NAME} STATIC)
endif()

target_compile_definitions(${PROJECT_NAME}
	PRIVATE
		$<$<BOOL:${INKNIT_ENABLE_EXPORTS}>:EMBED_TEST_ENABLE_EXPORTS>
		$<$<BOOL:${EMBED_TEST_SHARED}>:EMBED_TEST_EXPORTS>
	PUBLIC
		$<$<BOOL:${EMBED_TEST_SHARED}>:EMBED_TEST_SHARED>
	)

target_sources(${PROJECT_NAME} PRIVATE
	$<$<NOT:$<STREQUAL:${CMAKE_BUILD_TYPE},Release>>:assertion.c>
	test.c
	)

if(INKNIT_PROCESSOR STREQUAL "armv6m")
	target_sources(${PROJECT_NAME} PRIVATE
		addsub_armv6m.s
		)
elseif(INKNIT_PROCESSOR STREQUAL "armv8m")
	target_sources(${PROJECT_NAME} PRIVATE
		addsub_armv8m.s
		)
else()
	target_sources(${PROJECT_NAME} PRIVATE
		addsub.c
		)
endif()

if(EMBED_TEST_ENABLE_OBJDUMP)
	enable_disassemble(${PROJECT_NAME})
endif()

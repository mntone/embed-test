cmake_minimum_required(VERSION 3.21)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Bootstrap.cmake" NO_POLICY_SCOPE)

project(embed_test
	LANGUAGES ASM C
	)

include(CompilerConfig)
include(Utils)

add_subdirectory(src)

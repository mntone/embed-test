include_guard(GLOBAL)

# Set version
set(CMAKE_PROJECT_VERSION "${INKNIT_CMAKE_VERSION}")

# Set build configuration
if(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
	message(FATAL_ERROR "CMAKE_BUILD_TYPE is not allowed. Please use our custom build system.")
endif()
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo" CACHE STRING "" FORCE)

# Add "d" suffix on debug/relwithdebinfo build
set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_RELWITHDEBINFO_POSTFIX d)

# Set C and C++ language standards to C17 and C++20
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE STREQUAL "Release")
	add_compile_definitions(
		_DEBUG
		)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	# Set symbols to be hidden by default for C and C++
	set(CMAKE_C_VISIBILITY_PRESET hidden)
	set(CMAKE_CXX_VISIBILITY_PRESET hidden)
	set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)
endif()

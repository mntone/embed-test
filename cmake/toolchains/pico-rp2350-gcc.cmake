set(CMAKE_SYSTEM_NAME Pico)
set(CMAKE_SYSTEM_PROCESSOR cortex-m33)

if(GNU_ARM_TOOLCHAIN)
	set(EMBED_TEST_TOOLCHAIN_PREFIX "${GNU_ARM_TOOLCHAIN}" CACHE INTERNAL "")
else()
	set(EMBED_TEST_TOOLCHAIN_PREFIX "arm-none-eabi" CACHE INTERNAL "")
endif()
set(EMBED_TEST_GCC_CPU_FLAGS "-mcpu=cortex-m33 -mthumb -mno-unaligned-access -march=armv8-m.main+fp+dsp -mfloat-abi=softfp")
#if (NOT INKNIT_NO_CMSE)
#	set(EMBED_TEST_GCC_CPU_FLAGS "${CMAKE_C_FLAGS} -mcmse")
#endif()

include(${CMAKE_CURRENT_LIST_DIR}/pico-common-gcc.cmake)

unset(EMBED_TEST_GCC_CPU_FLAGS)

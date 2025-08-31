function(enable_disassemble target)
	cmake_parse_arguments("EMBED_TEST_OBJDUMP_${target}" "" "" "OPTIONS" ${ARGN})

	set(EMBED_TEST_OBJDUMP_${target}_COMMAND
		"-d"  # --disassemble
		"--no-show-raw-insn"
		${EMBED_TEST_OBJDUMP_FLAGS}
		)
	if(NOT "NO_SOURCE" IN_LIST EMBED_TEST_OBJDUMP_${target}_OPTIONS)
		list(APPEND EMBED_TEST_OBJDUMP_${target}_COMMAND "-S")  # --source
	endif()
	if("LINES"  IN_LIST EMBED_TEST_OBJDUMP_${target}_OPTIONS)
		list(APPEND EMBED_TEST_OBJDUMP_${target}_COMMAND "-l")  # --line-numbers
	endif()

	add_custom_command(
		TARGET  ${target} POST_BUILD
		COMMAND ${CMAKE_OBJDUMP} ARGS
			${EMBED_TEST_OBJDUMP_${target}_COMMAND}
			"$<TARGET_FILE:${target}>"
			> "$<TARGET_FILE_PREFIX:${target}>$<TARGET_FILE_BASE_NAME:${target}>.dis"
		VERBATIM
		)
endfunction()

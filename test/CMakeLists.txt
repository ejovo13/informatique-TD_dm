set(TESTS
    hello
    TD2
)

set(TEST_LIBS
    ejovo all_td
)

if (NOT WIN32)
    list(APPEND TEST_LIBS m)
endif()

list(APPEND TEST_INC
    ${INC}
)

# set(TEST_BIN_DIR "${CMAKE_CURRENT_BINARY_DIR}" PARENT_SCOPE)

macro(ejovo_add_test TESTNAME)

    # create an exectuable in which the tests will be stored
    set(TEST_BIN "test_${TESTNAME}")

    message(STATUS "Adding test ${TESTNAME}")
    add_executable(${TEST_BIN} "${TESTNAME}.c")
    target_link_libraries(${TEST_BIN} ${TEST_LIBS})
    target_include_directories(${TEST_BIN} PUBLIC ${TEST_INC})
    set_target_properties(${TEST_BIN}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    )
    add_test(${TESTNAME} "test_${TESTNAME}")

endmacro()

foreach(T ${TESTS})
    ejovo_add_test(${T})
endforeach(T)

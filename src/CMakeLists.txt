list(APPEND SRC_FILES
    demo
)

set(ALL_TD_LIB

    # TD1
    $<TARGET_OBJECTS:TD2>
    # TD3
    # TD4
    $<TARGET_OBJECTS:TD5>
    $<TARGET_OBJECTS:TD6>

)



add_subdirectory(TD1)
add_subdirectory(TD2)
add_subdirectory(TD3)
add_subdirectory(TD4)
add_subdirectory(TD5)
add_subdirectory(TD6)
add_subdirectory(EXAMEN)
add_subdirectory(ejovo)

add_library(all_td ${ALL_TD_LIB})
# add_subdirectory(ex9)
# add_subdirectory(ejovo)

foreach(FILE ${SRC_FILES})
    message(STATUS "Adding executable ${FILE}")
    add_executable(${FILE} "${FILE}.c")
    target_link_libraries(${FILE} all_td m)
endforeach(FILE)
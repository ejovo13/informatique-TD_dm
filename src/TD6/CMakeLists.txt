set(TD6_SRC




)

set(TD6_LIB

    ex1.c
    ex4.c



)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN}/TD6)

message(STATUS "ADDING LIBRARY TD6")
add_library(TD6 OBJECT ${TD6_LIB})

foreach(s ${TD6_SRC})
    add_executable(TD6_${s} ${s}.c)
    target_link_libraries(TD6_${s} TD6 ejovo)
    set_target_properties(TD6_${s} PROPERTIES OUTPUT_NAME ${s})
endforeach(s)
set(TD2_SRC

    ex6

)

set(TD2_LIB

    ex1.c
    ex2.c
    ex3.c
    ex4.c
    ex5.c
    # ex6.c
    ex7.c

)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN}/TD2)

message(STATUS "ADDING LIBRARY TD2")
add_library(TD2 OBJECT ${TD2_LIB})

foreach(s ${TD2_SRC})
    add_executable(TD2_${s} ${s}.c)
    target_link_libraries(TD2_${s} TD2 ejovo)
    set_target_properties(TD2_${s} PROPERTIES OUTPUT_NAME ${s})
endforeach(s)

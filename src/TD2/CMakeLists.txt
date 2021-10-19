set(TD2_SRC

    6

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

message(STATUS "ADDING LIBRARY TD2")
add_library(TD2 OBJECT ${TD2_LIB})

foreach(s ${TD2_SRC})
    add_executable("ex2_${s}" "ex${s}.c")
    target_link_libraries("ex2_${s}" TD2 ejovo)
endforeach(s)

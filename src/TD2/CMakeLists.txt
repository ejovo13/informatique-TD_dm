set(TD2_SRC



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

# foreach(s ${TD2_SRC})
#     add_executable(${s} "${s}.c")
#     target_link_libraries(${s} TD2)
# endforeach(s)

set(TD6_SRC




)

set(TD6_LIB

    ex1.c
    ex4.c



)

add_library(TD6 OBJECT ${TD6_LIB})

# foreach(s ${TD6_SRC})
#     add_executable(${s} "${s}.c")
#     target_link_libraries(${s} TD6)
# endforeach(s)
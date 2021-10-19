set(TD5_SRC




)

set(TD5_LIB


    ex1.c



)

add_library(TD5 ${TD5_LIB})

# foreach(s ${TD5_SRC})
#     add_executable(${s} "${s}.c")
#     target_link_libraries(${s} TD5)
# endforeach(s)
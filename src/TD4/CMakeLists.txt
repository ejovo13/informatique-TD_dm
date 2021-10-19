set(TD4_SRC

    ex4


)

set(TD4_LIB






)

# add_library(TD4 ${TD4_LIB})

foreach(s ${TD4_SRC})
    add_executable(${s} "${s}.c")
    # target_link_libraries(${s} TD4)
endforeach(s)
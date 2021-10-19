set(TD3_SRC

    1
    6



)

set(TD3_LIB






)

# add_library(TD3 ${TD3_LIB})

foreach(s ${TD3_SRC})
    add_executable("ex3_${s}" "ex${s}.c")
    # target_link_libraries(${s} TD3)
endforeach(s)
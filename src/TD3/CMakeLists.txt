set(TD3_SRC

    ex6



)

set(TD3_LIB






)

# add_library(TD3 ${TD3_LIB})

foreach(s ${TD3_SRC})
    add_executable(${s} "${s}.c")
    # target_link_libraries(${s} TD3)
endforeach(s)
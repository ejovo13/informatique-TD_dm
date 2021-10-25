set(TD3_SRC

    ex1
    ex6



)

set(TD3_LIB






)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN}/TD3)

message(STATUS "ADDING LIBRARY TD3")
# add_library(TD3 OBJECT ${TD3_LIB})

foreach(s ${TD3_SRC})
    add_executable(TD3_${s} ${s}.c)
    # target_link_libraries(TD3_${s} TD3 ejovo)
    set_target_properties(TD3_${s} PROPERTIES OUTPUT_NAME ${s})
endforeach(s)
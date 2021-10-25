set(TD4_SRC

    ex4


)

set(TD4_LIB






)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN}/TD4)

message(STATUS "ADDING LIBRARY TD4")
# add_library(TD4 OBJECT ${TD4_LIB})

foreach(s ${TD4_SRC})
    add_executable(TD4_${s} ${s}.c)
    # target_link_libraries(TD4_${s} TD4 ejovo)
    set_target_properties(TD4_${s} PROPERTIES OUTPUT_NAME ${s})
endforeach(s)
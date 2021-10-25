set(TD5_SRC




)

set(TD5_LIB


    ex1.c



)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN}/TD5)

message(STATUS "ADDING LIBRARY TD5")
add_library(TD5 OBJECT ${TD5_LIB})

foreach(s ${TD5_SRC})
    add_executable(TD5_${s} ${s}.c)
    target_link_libraries(TD5_${s} TD5 ejovo)
    set_target_properties(TD5_${s} PROPERTIES OUTPUT_NAME ${s})
endforeach(s)
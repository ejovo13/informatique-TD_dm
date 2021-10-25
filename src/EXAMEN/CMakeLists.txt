set(EXAMEN_SRC

    ex3


)

set(EXAMEN_LIB





)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN}/examen)

message(STATUS "ADDING LIBRARY examen")
# add_library(examen OBJECT ${EXAMEN_LIB})

foreach(s ${EXAMEN_SRC})
    add_executable(EXAMEN_${s} ${s}.c)
    # target_link_libraries(EXAMEN_${s} examen ejovo)
    set_target_properties(EXAMEN_${s} PROPERTIES OUTPUT_NAME ${s})
endforeach(s)
set(EXAMEN_SRC

    ex3


)

set(EXAMEN_LIB





)

# add_library(EXAMEN OBJECT ${TEXAMEN_LIB})

foreach(s ${EXAMEN_SRC})
    add_executable("test_${s}" "${s}.c")
    # target_link_libraries(${s} EXAMEN)
endforeach(s)
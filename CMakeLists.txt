cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(DevoirsMaison)
enable_language(C)
enable_testing(ON)

set(BIN ${CMAKE_SOURCE_DIR}/bin)
set(INC ${CMAKE_SOURCE_DIR}/inc)
set(SRC ${CMAKE_SOURCE_DIR}/src)
set(TEST ${CMAKE_SOURCE_DIR}/test)
set(LIB ${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB})

add_compile_options(-Wall)

file(MAKE_DIRECTORY ${LIB})
file(MAKE_DIRECTORY ${BIN})

include_directories(${INC})

add_subdirectory(${SRC})
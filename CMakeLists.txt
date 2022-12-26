cmake_minimum_required(VERSION 3.15)
project(misc VERSION 1.0.0)

execute_process(COMMAND git rev-parse HEAD
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE COMMIT
    OUTPUT_STRIP_TRAILING_WHITESPACE)

configure_file(version.hh.in ${CMAKE_CURRENT_LIST_DIR}/include/version.hh)

set(BIN_DIR ${CMAKE_BINARY_DIR}/bin/)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR})
add_compile_options(-Wpedantic -Wall -Wextra -Werror)

set(APP misc)
add_executable(${APP} main.cc)
target_include_directories(${APP} PUBLIC include/)

add_subdirectory(src/)
add_subdirectory(test/)

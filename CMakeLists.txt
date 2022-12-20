cmake_minimum_required(VERSION 3.15)
project(misc VERSION 1.0)
configure_file(version.hh.in ${CMAKE_CURRENT_LIST_DIR}/include/version.hh)

set(TARGET misc)
set(BIN_DIR bin/)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR})

add_compile_options(-Wpedantic -Wall -Wextra -Werror)

add_executable(${TARGET} main.cc)
target_include_directories(${TARGET} PUBLIC include/)
add_subdirectory(src/)

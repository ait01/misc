cmake_minimum_required(VERSION 3.15)
project(misc VERSION 1.0)
configure_file(version.hh.in ${CMAKE_CURRENT_LIST_DIR}/include/version.hh)
set(TARGET misc)
add_executable(${TARGET} main.cc)
set(BIN_DIR ../bin/ CACHE STRING "Directory for all binaries.")
set_target_properties(${TARGET} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BIN_DIR})
target_compile_options(${TARGET} PRIVATE -Wpedantic -Wall -Wextra -Werror)
target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include/)
add_subdirectory(src/)

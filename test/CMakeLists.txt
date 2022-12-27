set(TEST test)
add_executable(${TEST} main.cc test.cc)
target_include_directories(${TEST} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/)
target_link_libraries(${TEST} PRIVATE gtest pthread util log)

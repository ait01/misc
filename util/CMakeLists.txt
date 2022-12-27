set(UTIL util)
add_library(${UTIL} util.cc)
target_include_directories(${UTIL} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/)
target_link_libraries(${UTIL} PRIVATE log)

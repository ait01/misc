set(LOG log)
add_library(${LOG} log.cc)
target_include_directories(${LOG} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/)

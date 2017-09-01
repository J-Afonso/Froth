cmake_minimum_required(VERSION 3.0)
add_library(GLAD glad.c)
target_include_directories (GLAD PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glad)
add_library(Bezier src/cubic_bezier.cpp)

enable_testing()


target_include_directories (Bezier PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries (Bezier eigen)

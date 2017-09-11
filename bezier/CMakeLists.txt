add_library(Bezier src/cubic_bezier.cpp src/cubic_bezier_renderer.cpp)
target_include_directories (Bezier PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries (Bezier LINK_PUBLIC GLAD eigen)

add_executable(cubic_bezier_test test/test_cubic_bezier.cpp)
add_test(cubic_bezier_test cubic_bezier_test)
target_link_libraries (cubic_bezier_test gtest Bezier)

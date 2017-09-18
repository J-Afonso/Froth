set(SOURCE_FILES src/cubic_bezier.cpp src/cubic_bezier_renderer.cpp src/bezier_animator.cpp)
set(HEADER_FILES include/cubic_bezier.h include/cubic_bezier_renderer.h include/bezier_animator.h)

add_library(Bezier ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories (Bezier PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries (Bezier LINK_PUBLIC GLAD eigen)

add_executable(cubic_bezier_test test/test_cubic_bezier.cpp)
add_test(cubic_bezier_test cubic_bezier_test)
target_link_libraries (cubic_bezier_test gtest Bezier)

add_executable(bezier_animator_test test/test_bezier_animator.cpp)
add_test(bezier_animator_test bezier_animator_test)
target_link_libraries (bezier_animator_test gtest Bezier)

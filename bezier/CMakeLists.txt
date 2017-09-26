set(SOURCE_FILES
        src/cubic_bezier.cpp
        src/bezier_path_renderer.cpp
        src/bezier_path_animator.cpp
        src/bezier_path.cpp)

set(HEADER_FILES include/cubic_bezier.h
        include/bezier_path_renderer.h
        include/bezier_path_animator.h
        include/bezier_path.h)

add_library(Bezier ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories (Bezier PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries (Bezier LINK_PUBLIC GLAD eigen)

add_executable(bezier_path_test test/test_bezier_path.cpp)
add_test(bezier_path_test bezier_path_test)
target_link_libraries (bezier_path_test gtest Bezier)

add_executable(cubic_bezier_test test/test_cubic_bezier.cpp)
add_test(cubic_bezier_test cubic_bezier_test)
target_link_libraries (cubic_bezier_test gtest Bezier)

add_executable(path_animator_test test/test_path_animator.cpp)
add_test(path_animator_test path_animator_test)
target_link_libraries (path_animator_test gtest Bezier)
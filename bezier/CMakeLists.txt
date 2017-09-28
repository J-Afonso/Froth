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
target_link_libraries (Bezier LINK_PUBLIC glad eigen glog)

add_executable(bezier_tests
        test/test_bezier_path.cpp
        test/test_cubic_bezier.cpp
        test/test_path_animator.cpp)

add_test(bezier_tests bezier_tests)
target_link_libraries (bezier_tests gtest gtest_main glog)
target_link_libraries (bezier_tests Bezier)
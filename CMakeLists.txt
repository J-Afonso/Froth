set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_minimum_required(VERSION 3.0.2)

enable_testing()

# I have no idea why, put there are some warnings on OSX if we don't setup this flag.
set(CMAKE_MACOSX_RPATH 1)
add_subdirectory(third_party)
add_subdirectory(bezier)
add_subdirectory(rendering)
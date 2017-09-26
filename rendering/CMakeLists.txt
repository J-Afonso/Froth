cmake_minimum_required(VERSION 2.8)
project(Wave)

if (MSVC)
    # Tell MSVC to use main instead of WinMain for Windows subsystem executables
    set_target_properties(${WINDOWS_BINARIES} PROPERTIES
                          LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

add_executable(executioner src/executioner.cpp ../bezier/src/bezier_path_renderer.cpp)

target_link_libraries (executioner LINK_PUBLIC GLAD glfw Bezier)
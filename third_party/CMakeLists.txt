add_subdirectory(glad)
add_subdirectory(glfw)
add_subdirectory(eigen)
# Can't enable gtest, the linker freaks out, its recomended to add config_compiler_and_linker() 
# but it freaks out the rest of the API's. I give up for now, i hate buildsystems.
#add_subdirectory(gtest)
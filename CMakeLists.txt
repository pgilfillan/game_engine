cmake_minimum_required(VERSION 3.13.2)
project(engine)
set(CMAKE_MACOSX_RPATH 1)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(main ${SOURCES})

set_property(TARGET main PROPERTY CXX_STANDARD 11)
target_compile_options(main PRIVATE -Wall)

# Link libraries
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE glfw)

# glew
add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glew EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE libglew_static)

# glm
#add_subdirectory(lib/glm EXCLUDE_FROM_ALL)
#target_link_libraries(main PRIVATE glm)
include_directories(lib/glm)

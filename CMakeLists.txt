cmake_minimum_required(VERSION 3.23)
project(Logic-Simulator)
set(CMAKE_CXX_STANDARD 20)

set(EXTERNAL external/glad/src/glad.c)
set(SOURCE_FILES src/main.cpp)

add_executable(Logic-Simulator ${SOURCE_FILES} ${EXTERNAL})

include_directories(include)
include_directories(external/glad/include)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw-3.3.8)
target_link_libraries(Logic-Simulator glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(Logic-Simulator OpenGL::GL)

cmake_minimum_required(VERSION 3.16)

project(openGL-glfw LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_library(glad glad/src/glad.c)

target_include_directories(glad PUBLIC glad/include)

add_executable(opengl_app main.cpp)

target_link_libraries(opengl_app
    glad
    glfw
    OpenGL::GL
)

cmake_minimum_required(VERSION 3.10)
project(monoglint VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(external/glfw)

add_library(glad external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

add_executable(monoglint
    resources/resources.rc
    
    src/main.cc
)

target_include_directories(monoglint PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external
)

find_package(OpenGL REQUIRED)

target_link_libraries(monoglint PRIVATE
    glfw
    glad
    OpenGL::GL
)

if (WIN32)
    target_link_libraries(monoglint PRIVATE opengl32)
endif()

# Set C++ standard
set_property(TARGET monoglint PROPERTY CXX_STANDARD 17)
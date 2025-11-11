cmake_minimum_required(VERSION 3.10)
project(monoglint VERSION 0.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# External dependencies
add_subdirectory(external/glfw)
add_library(glad STATIC external/glad/glad.c)
target_include_directories(glad PUBLIC external/glad)

# Engine
file(GLOB_RECURSE ALL_SOURCES "monoglint_engine/*.cc")
add_library(monoglint_engine ${ALL_SOURCES})
target_include_directories(monoglint_engine PUBLIC monoglint_engine)
target_include_directories(monoglint_engine PUBLIC external)
target_include_directories(monoglint_engine PUBLIC external/glfw/include)

# Executable
add_executable(monoglint
    resources/resources.rc
    src/main.cc
)

# Includes
target_include_directories(monoglint PRIVATE external)

# Link libraries
find_package(OpenGL REQUIRED)
target_link_libraries(monoglint PRIVATE
    glfw
    glad
    monoglint_engine
    OpenGL::GL
)

if(WIN32)
    target_link_libraries(monoglint PRIVATE opengl32)
endif()

cmake_minimum_required(VERSION 3.10)

project(GameOfLife)

add_executable(GameOfLife
    src/main.cpp
    vendor/glad/src/glad.c
    src/utils/shader.cpp
    src/grid.cpp
    src/quad.cpp
)

include_directories(
    vendor/
    vendor/glad/include/
    vendor/glfw/include/
    src/utils/
    src/
)

target_link_libraries(GameOfLife
    ${CMAKE_SOURCE_DIR}/vendor/glfw/build/src/libglfw3.a
    GL
)

cmake_minimum_required(VERSION 3.5.0)
project(HellEngine VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory( glfw )

include_directories(glfw/include 
                    include
)

find_package( OpenGL REQUIRED )


add_executable(HellEngine src/main.cpp src/glad.c)

target_link_libraries( HellEngine ${OPENGL_LIBRARIES} glfw)

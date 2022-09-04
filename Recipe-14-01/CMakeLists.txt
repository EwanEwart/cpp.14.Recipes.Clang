cmake_minimum_required(VERSION 3.5)

project(Recipe-14-01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(/usr/include)

add_executable(Recipe-14-01 main.cpp)

target_link_libraries(Recipe-14-01 glfw3 GLEW GLU GL rt m dl X11 pthread xcb Xau Xdmcp OpenGL)

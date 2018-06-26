cmake_minimum_required(VERSION 3.10)
project(t4)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(t4 main.cpp)

target_link_libraries(t4 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
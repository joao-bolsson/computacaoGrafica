cmake_minimum_required(VERSION 3.10)
project(testeCanvas2D)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES src/main.cpp src/Relogio.h src/Relogio.cpp src/Bola.h src/gl_canvas2d.cpp src/gl_canvas2d.h)

add_executable(testeCanvas2D ${SOURCE_FILES})

target_link_libraries(testeCanvas2D ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
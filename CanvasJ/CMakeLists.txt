cmake_minimum_required(VERSION 3.10)
project(CanvasJ)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(CanvasJ main.cpp src/gl_canvas2d.h src/gl_canvas2d.cpp src/Component.cpp src/Component.h src/Window.cpp src/Window.h)
target_link_libraries(CanvasJ ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
cmake_minimum_required(VERSION 3.10)
project(canvasGraphics)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(canvasGraphics main.cpp src/gl_canvas2d.cpp src/gl_canvas2d.h src/File.h src/File.cpp src/Point.cpp src/Point.h)
target_link_libraries(canvasGraphics ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
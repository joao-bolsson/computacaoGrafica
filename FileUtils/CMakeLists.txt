cmake_minimum_required(VERSION 3.10)
project(FileUtils)

set(CMAKE_CXX_STANDARD 17)

add_executable(FileUtils main.cpp src/File.cpp src/File.h)
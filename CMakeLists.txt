cmake_minimum_required(VERSION 3.15)
project(BeginnerTutorial C)

set(CMAKE_C_STANDARD 99)

add_executable(BeginnerTutorial demo1/Main.c)
add_library(Library1 demoLibrary/Library1.c)
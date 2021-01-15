cmake_minimum_required(VERSION 3.16)
project(TimeManagement)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TimeManagement
        main.cpp
        TimeClass.cpp
        TimeClass.h)

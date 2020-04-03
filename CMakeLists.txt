cmake_minimum_required(VERSION 3.15)
project(BeginnerTutorial C)

set(CMAKE_C_STANDARD 99)

add_executable(BeginnerTutorial demo1/Main.c FelixWorkspace/Workspace.c FloWorkspace/Workspace.c johnnyWorkspace/Workspace.c Uebung1/Vorlesung.c)
add_library(Library1 demoLibrary/Library1.c FelixWorkspace/Workspace.c FloWorkspace/Workspace.c johnnyWorkspace/Workspace.c Uebung1/Vorlesung.c)
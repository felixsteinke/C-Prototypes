cmake_minimum_required(VERSION 3.16)
project(OsHandling C)

set(CMAKE_C_STANDARD 99)

#if(${CMAKE_SYSTEM_NAME} MATCHES "WIN32")
set(SOURCES print_win32.c)
#endif

#if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set(SOURCES print_linux.c)
#endif

add_executable(OsHandling main.c ${SOURCES})
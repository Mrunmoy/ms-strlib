cmake_minimum_required(VERSION 3.9)
project(ms_strlib C)

set(CMAKE_C_STANDARD 99)
add_definitions(-DMODULE_MS_STRLIB_ENABLED=1)

include_directories(inc
                    test)
add_library(ms_strlib src/ms_strop.c inc/ms_strop.h)
cmake_minimum_required(VERSION 3.7)

# Project Name
project(strlib-unit-tests C CXX)

# Compiler Standards
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/inc)

# Directories Settings
set(BUILD_DIR ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set(CMAKE_INSTALL_LIBDIR ${BUILD_DIR}/lib)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/scripts)

# message( "-------------------" )
# message( ${CMAKE_SOURCE_DIR} )
# message( "-------------------" )

# Build Flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
SET(CPP_PLATFORM Gcc)

# add cpputest library
SET(CppUTestRootDirectory ${PROJECT_SOURCE_DIR}/dependencies/cpputest)
SET(CPP_PLATFORM Gcc)
# add_subdirectory(${CppUTestRootDirectory})

include_directories(${PROJECT_SOURCE_DIR}
        ${CppUTestRootDirectory}/include)

set(CMAKE_CXX_FLAGS "-include ${CppUTestRootDirectory}/include/CppUTest/MemoryLeakDetectorNewMacros.h")
set(CMAKE_C_FLAGS "-include ${CppUTestRootDirectory}/include/CppUTest/MemoryLeakDetectorMallocMacros.h")

# add cpputest library
add_library(imp_cpputest STATIC IMPORTED)
set_property(TARGET imp_cpputest PROPERTY
        IMPORTED_LOCATION
        ${CppUTestRootDirectory}/cpputest_build/lib/libCppUTest.a)

add_executable(${PROJECT_NAME} AllTests.cpp TestStrLib.cpp)

# Link all the binaries/libraries to build the executable

# Link the static library from subproject1 using it's alias sub::lib1
# Link the header only library from subproject2 using it's alias sub::lib2
# This will cause the include directories for that target to be added to this project
target_link_libraries(${PROJECT_NAME}
        ms_strlib
        imp_cpputest
        )

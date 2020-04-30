cmake_minimum_required(VERSION 3.10)

set(this C_project)

project(${THIS}/src C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(lib/googletest)

set(Headers
    LinearAlgebraFunctions.h)

set(Sources
    LinearAlgebraFunctions.c)

add_library(${this}/src ${Sources} ${Headers})

add_subdirectory(test)
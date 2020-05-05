cmake_minimum_required(VERSION 3.16)
project(C_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(C_project
        src/algebraFunctions.c
        src/algebraFunctions.h
        src/keplerUniversal.c
        src/keplerUniversal.h
        src/main.c
        src/picardChebyshevDemo.c
        src/picardChebyshevDemo.h
        src/VMPCM.c
        src/VMPCM.h)

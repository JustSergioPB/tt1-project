cmake_minimum_required(VERSION 3.16)
project(C_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(test)

add_executable(C_project
        main.c
        src/algebraFunctions.c
        src/algebraFunctions.h
        src/keplerUniversal.c
        src/keplerUniversal.h
        src/picardChebyshevDemo.c
        src/picardChebyshevDemo.h
        src/VMPCM.c
        src/VMPCM.h
        test/kepler_Test.c
        test/kepler_Test.h test/algebraFun_Test.h test/algebraFun_Test.c test/VMPCM_Test.c test/VMPCM_Test.h test/picard_Test.c test/picard_Test.h)

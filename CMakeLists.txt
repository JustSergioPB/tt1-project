cmake_minimum_required(VERSION 3.16)
project(C_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(test)

add_executable(C_project
        test/main.c
        src/VMCPMModule/algebraFunctions.c
        src/VMCPMModule/algebraFunctions.h
        src/VMCPMModule/keplerUniversal.c
        src/VMCPMModule/keplerUniversal.h
        src/VMCPMModule/picardChebyshevDemo.c
        src/VMCPMModule/picardChebyshevDemo.h
        src/VMCPMModule/VMPCM.c
        src/VMCPMModule/VMPCM.h
        test/kepler_Test.c
        test/kepler_Test.h test/algebraFun_Test.h test/algebraFun_Test.c test/VMPCM_Test.c test/VMPCM_Test.h test/picard_Test.c test/picard_Test.h)

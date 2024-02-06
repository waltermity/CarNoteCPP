cmake_minimum_required(VERSION 3.25)
project(LaMappa)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LaMappa
        Adat.h
        Auto.cpp
        Auto.h
        gtest_lite.h
        Jarmu.cpp
        Jarmu.h
        Main.cpp
        Main.h
        memtrace.cpp
        memtrace.h
        Motor.cpp
        Motor.h
        Teherauto.cpp
        Teherauto.h
        Tesztek.cpp
        Tesztek.h)

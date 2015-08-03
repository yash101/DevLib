project(DevLib)
cmake_minimum_required(VERSION 2.8)

file(GLOB_RECURSE SRC_C "src/*.c")
file(GLOB_RECURSE SRC_CPP "src/*.cpp")
file(GLOB_RECURSE SRC_H "src/*.h")

add_executable(${PROJECT_NAME} main.cpp main.h ${SRC_C} ${SRC_CPP} ${SRC_H})

IF(WIN32)
ELSE(WIN32)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -ggdb")
ENDIF(WIN32)

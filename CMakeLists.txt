cmake_minimum_required(VERSION 3.23)
project(netlib_muduo)

set(CMAKE_CXX_STANDARD 14)

add_executable(netlib_muduo
        EventLoop.cc
        EventLoop.h
        main.cpp)
target_link_libraries(netlib_muduo muduo_base pthread)
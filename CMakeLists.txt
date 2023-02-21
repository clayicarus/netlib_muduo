cmake_minimum_required(VERSION 3.23)
project(netlib_muduo)

set(CMAKE_CXX_STANDARD 14)

add_executable(netlib_muduo
        EventLoop.cc
        EventLoop.h
        main.cpp)
target_link_libraries(netlib_muduo muduo_base pthread)

add_executable(eventloop_test1
        EventLoop.cc
        EventLoop.h
        test/test1.cpp)
target_link_libraries(eventloop_test1 muduo_base pthread)

add_executable(eventloop_test2
        EventLoop.cc
        EventLoop.h
        test/test2.cpp)
target_link_libraries(eventloop_test2 muduo_base pthread)

add_executable(eventloop_test3
        EventLoop.cc
        EventLoop.h
        test/test3.cpp)
target_link_libraries(eventloop_test3 muduo_base pthread)

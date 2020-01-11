cmake_minimum_required(VERSION 3.15)
project(one_time_pad)

set(CMAKE_CXX_STANDARD 20)

add_executable(one_time_pad main.cpp one_time_pad.cpp one_time_pad.h)
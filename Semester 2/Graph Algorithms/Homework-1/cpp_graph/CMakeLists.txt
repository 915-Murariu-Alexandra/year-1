cmake_minimum_required(VERSION 3.17)
project(cpp_graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_graph main.cpp Graph.cpp Graph.h Console.cpp Console.h)
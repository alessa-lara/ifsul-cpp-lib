cmake_minimum_required(VERSION 3.10.0)
project(lib VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_BUILD_TYPE Debug)

add_executable(dlist doublyLinkedList.cpp lib/doublyLinkedList.hpp)
add_executable(btree btree.cpp lib/btree.hpp)
add_executable(graph graph.cpp lib/graph.hpp)

cmake_minimum_required(VERSION 3.26)
project(Project3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project3 main.cpp
        data_structures.h
        heap.cpp
        heap.h
        stack.h
        stack.cpp
        graph.h
        graph.cpp
        util.cpp
        util.h
        main.h)

cmake_minimum_required(VERSION 3.26)
project(graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(graph main.cpp
        DFS.cpp
        create_graph.cpp
        BFS.cpp
)

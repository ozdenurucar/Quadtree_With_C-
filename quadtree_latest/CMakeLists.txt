cmake_minimum_required(VERSION 3.10)
project(quadtree_latest)

set(CMAKE_CXX_STANDARD 11)
set(Sources main.cpp Quadtree.cpp)
set(Headers Quadtree.h Node.h Vertex.h)

include_directories("${/home/ozdenur/Quadtree/quadtree_latest}/inc/")
add_executable(quadtree_latest src/main.cpp)
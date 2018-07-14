cmake_minimum_required(VERSION 3.10)
project(ai)

set(CMAKE_CXX_STANDARD 11)

add_executable(ai main.cpp player/Player.cpp player/Player.h player/Astar.cpp player/Astar.h)
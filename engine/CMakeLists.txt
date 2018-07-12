cmake_minimum_required(VERSION 3.10)
project(engine)

set(CMAKE_CXX_STANDARD 11)

add_executable(engine main.cpp player/Player.cpp player/Player.h bomb/Bomb.cpp bomb/Bomb.h)
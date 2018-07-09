cmake_minimum_required(VERSION 3.10)
project(engine)

set(CMAKE_CXX_STANDARD 11)

add_executable(engine main.cpp)
#add_executable(engine main.cpp game-engine/GameEngine.cpp game-engine/GameEngine.h player/Player.cpp player/Player.h bomb/Bomb.cpp bomb/Bomb.h item/Item.cpp item/Item.h)
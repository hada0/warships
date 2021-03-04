cmake_minimum_required(VERSION 3.15)
project(warships)

set(CMAKE_CXX_STANDARD 17)

add_executable(warships main.cpp board/board.cpp board/board.h mini/ini.h utils/utils.cpp utils/utils.h player/player.cpp player/player.h config/configuration.cpp config/configuration.h)

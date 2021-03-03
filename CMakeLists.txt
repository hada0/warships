cmake_minimum_required(VERSION 3.15)
project(warships)

set(CMAKE_CXX_STANDARD 17)

add_executable(warships main.cpp board.cpp board.h mini/ini.h helper.cpp helper.h player.cpp player.h configuration.cpp configuration.h)
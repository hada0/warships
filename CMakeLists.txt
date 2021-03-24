cmake_minimum_required(VERSION 3.10.2)
project(warships)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)
add_executable(warships main.cpp board/board.cpp board/board.h utils/utils.cpp utils/utils.h player/player.cpp player/player.h config/configuration.cpp config/configuration.h)

set_target_properties(warships PROPERTIES CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.15)
project(warships)

set(CMAKE_CXX_STANDARD 17)
add_executable(warships main.cpp board/board.cpp board/board.h mini/ini.h utils/utils.cpp utils/utils.h player/player.cpp player/player.h configuration.cpp configuration.h)

##Target for .ini config file.
#ADD_EXECUTABLE(foo ${foo_SOURCES} ${foo_HEADERS})
#
#ADD_CUSTOM_COMMAND(
#   OUTPUT "${PROJECT_BINARY_DIR}/config.ini"
#   COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/config.ini"
#"${PROJECT_BINARY_DIR}"
#   DEPENDS "${PROJECT_SOURCE_DIR}/config.ini"
#   COMMENT "Localizing \"config.ini\"")
#
#ADD_CUSTOM_TARGET(copy_bar.ini DEPENDS "${PROJECT_BINARY_DIR}/config.ini")
#ADD_DEPENDENCIES(foo copy_bar.ini)
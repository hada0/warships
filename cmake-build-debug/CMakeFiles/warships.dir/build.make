# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vuhongann/CLionProjects/warships

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vuhongann/CLionProjects/warships/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/warships.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/warships.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/warships.dir/flags.make

CMakeFiles/warships.dir/main.cpp.o: CMakeFiles/warships.dir/flags.make
CMakeFiles/warships.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vuhongann/CLionProjects/warships/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/warships.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/warships.dir/main.cpp.o -c /Users/vuhongann/CLionProjects/warships/main.cpp

CMakeFiles/warships.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warships.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vuhongann/CLionProjects/warships/main.cpp > CMakeFiles/warships.dir/main.cpp.i

CMakeFiles/warships.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warships.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vuhongann/CLionProjects/warships/main.cpp -o CMakeFiles/warships.dir/main.cpp.s

CMakeFiles/warships.dir/board/board.cpp.o: CMakeFiles/warships.dir/flags.make
CMakeFiles/warships.dir/board/board.cpp.o: ../board/board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vuhongann/CLionProjects/warships/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/warships.dir/board/board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/warships.dir/board/board.cpp.o -c /Users/vuhongann/CLionProjects/warships/board/board.cpp

CMakeFiles/warships.dir/board/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warships.dir/board/board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vuhongann/CLionProjects/warships/board/board.cpp > CMakeFiles/warships.dir/board/board.cpp.i

CMakeFiles/warships.dir/board/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warships.dir/board/board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vuhongann/CLionProjects/warships/board/board.cpp -o CMakeFiles/warships.dir/board/board.cpp.s

CMakeFiles/warships.dir/utils/utils.cpp.o: CMakeFiles/warships.dir/flags.make
CMakeFiles/warships.dir/utils/utils.cpp.o: ../utils/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vuhongann/CLionProjects/warships/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/warships.dir/utils/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/warships.dir/utils/utils.cpp.o -c /Users/vuhongann/CLionProjects/warships/utils/utils.cpp

CMakeFiles/warships.dir/utils/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warships.dir/utils/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vuhongann/CLionProjects/warships/utils/utils.cpp > CMakeFiles/warships.dir/utils/utils.cpp.i

CMakeFiles/warships.dir/utils/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warships.dir/utils/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vuhongann/CLionProjects/warships/utils/utils.cpp -o CMakeFiles/warships.dir/utils/utils.cpp.s

CMakeFiles/warships.dir/player/player.cpp.o: CMakeFiles/warships.dir/flags.make
CMakeFiles/warships.dir/player/player.cpp.o: ../player/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vuhongann/CLionProjects/warships/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/warships.dir/player/player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/warships.dir/player/player.cpp.o -c /Users/vuhongann/CLionProjects/warships/player/player.cpp

CMakeFiles/warships.dir/player/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warships.dir/player/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vuhongann/CLionProjects/warships/player/player.cpp > CMakeFiles/warships.dir/player/player.cpp.i

CMakeFiles/warships.dir/player/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warships.dir/player/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vuhongann/CLionProjects/warships/player/player.cpp -o CMakeFiles/warships.dir/player/player.cpp.s

CMakeFiles/warships.dir/config/configuration.cpp.o: CMakeFiles/warships.dir/flags.make
CMakeFiles/warships.dir/config/configuration.cpp.o: ../config/configuration.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vuhongann/CLionProjects/warships/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/warships.dir/config/configuration.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/warships.dir/config/configuration.cpp.o -c /Users/vuhongann/CLionProjects/warships/config/configuration.cpp

CMakeFiles/warships.dir/config/configuration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warships.dir/config/configuration.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vuhongann/CLionProjects/warships/config/configuration.cpp > CMakeFiles/warships.dir/config/configuration.cpp.i

CMakeFiles/warships.dir/config/configuration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warships.dir/config/configuration.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vuhongann/CLionProjects/warships/config/configuration.cpp -o CMakeFiles/warships.dir/config/configuration.cpp.s

# Object files for target warships
warships_OBJECTS = \
"CMakeFiles/warships.dir/main.cpp.o" \
"CMakeFiles/warships.dir/board/board.cpp.o" \
"CMakeFiles/warships.dir/utils/utils.cpp.o" \
"CMakeFiles/warships.dir/player/player.cpp.o" \
"CMakeFiles/warships.dir/config/configuration.cpp.o"

# External object files for target warships
warships_EXTERNAL_OBJECTS =

../warships: CMakeFiles/warships.dir/main.cpp.o
../warships: CMakeFiles/warships.dir/board/board.cpp.o
../warships: CMakeFiles/warships.dir/utils/utils.cpp.o
../warships: CMakeFiles/warships.dir/player/player.cpp.o
../warships: CMakeFiles/warships.dir/config/configuration.cpp.o
../warships: CMakeFiles/warships.dir/build.make
../warships: CMakeFiles/warships.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vuhongann/CLionProjects/warships/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../warships"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/warships.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/warships.dir/build: ../warships

.PHONY : CMakeFiles/warships.dir/build

CMakeFiles/warships.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/warships.dir/cmake_clean.cmake
.PHONY : CMakeFiles/warships.dir/clean

CMakeFiles/warships.dir/depend:
	cd /Users/vuhongann/CLionProjects/warships/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vuhongann/CLionProjects/warships /Users/vuhongann/CLionProjects/warships /Users/vuhongann/CLionProjects/warships/cmake-build-debug /Users/vuhongann/CLionProjects/warships/cmake-build-debug /Users/vuhongann/CLionProjects/warships/cmake-build-debug/CMakeFiles/warships.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/warships.dir/depend


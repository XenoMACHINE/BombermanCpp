# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alexandremenielle/Documents/4A/C++/BombermanCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug

# Include any dependencies generated for this target.
include engine/CMakeFiles/engine.dir/depend.make

# Include the progress variables for this target.
include engine/CMakeFiles/engine.dir/progress.make

# Include the compile flags for this target's objects.
include engine/CMakeFiles/engine.dir/flags.make

engine/CMakeFiles/engine.dir/main.cpp.o: engine/CMakeFiles/engine.dir/flags.make
engine/CMakeFiles/engine.dir/main.cpp.o: ../engine/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object engine/CMakeFiles/engine.dir/main.cpp.o"
	cd /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/engine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/main.cpp.o -c /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/engine/main.cpp

engine/CMakeFiles/engine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/main.cpp.i"
	cd /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/engine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/engine/main.cpp > CMakeFiles/engine.dir/main.cpp.i

engine/CMakeFiles/engine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/main.cpp.s"
	cd /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/engine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/engine/main.cpp -o CMakeFiles/engine.dir/main.cpp.s

engine/CMakeFiles/engine.dir/main.cpp.o.requires:

.PHONY : engine/CMakeFiles/engine.dir/main.cpp.o.requires

engine/CMakeFiles/engine.dir/main.cpp.o.provides: engine/CMakeFiles/engine.dir/main.cpp.o.requires
	$(MAKE) -f engine/CMakeFiles/engine.dir/build.make engine/CMakeFiles/engine.dir/main.cpp.o.provides.build
.PHONY : engine/CMakeFiles/engine.dir/main.cpp.o.provides

engine/CMakeFiles/engine.dir/main.cpp.o.provides.build: engine/CMakeFiles/engine.dir/main.cpp.o


engine/CMakeFiles/engine.dir/player/Player.cpp.o: engine/CMakeFiles/engine.dir/flags.make
engine/CMakeFiles/engine.dir/player/Player.cpp.o: ../engine/player/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object engine/CMakeFiles/engine.dir/player/Player.cpp.o"
	cd /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/engine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/player/Player.cpp.o -c /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/engine/player/Player.cpp

engine/CMakeFiles/engine.dir/player/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/player/Player.cpp.i"
	cd /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/engine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/engine/player/Player.cpp > CMakeFiles/engine.dir/player/Player.cpp.i

engine/CMakeFiles/engine.dir/player/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/player/Player.cpp.s"
	cd /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/engine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/engine/player/Player.cpp -o CMakeFiles/engine.dir/player/Player.cpp.s

engine/CMakeFiles/engine.dir/player/Player.cpp.o.requires:

.PHONY : engine/CMakeFiles/engine.dir/player/Player.cpp.o.requires

engine/CMakeFiles/engine.dir/player/Player.cpp.o.provides: engine/CMakeFiles/engine.dir/player/Player.cpp.o.requires
	$(MAKE) -f engine/CMakeFiles/engine.dir/build.make engine/CMakeFiles/engine.dir/player/Player.cpp.o.provides.build
.PHONY : engine/CMakeFiles/engine.dir/player/Player.cpp.o.provides

engine/CMakeFiles/engine.dir/player/Player.cpp.o.provides.build: engine/CMakeFiles/engine.dir/player/Player.cpp.o


engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.o: engine/CMakeFiles/engine.dir/flags.make
engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.o: ../engine/bomb/Bomb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.o"
	cd /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/engine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/bomb/Bomb.cpp.o -c /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/engine/bomb/Bomb.cpp

engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/bomb/Bomb.cpp.i"
	cd /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/engine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/engine/bomb/Bomb.cpp > CMakeFiles/engine.dir/bomb/Bomb.cpp.i

engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/bomb/Bomb.cpp.s"
	cd /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/engine && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/engine/bomb/Bomb.cpp -o CMakeFiles/engine.dir/bomb/Bomb.cpp.s

engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.o.requires:

.PHONY : engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.o.requires

engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.o.provides: engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.o.requires
	$(MAKE) -f engine/CMakeFiles/engine.dir/build.make engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.o.provides.build
.PHONY : engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.o.provides

engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.o.provides.build: engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.o


# Object files for target engine
engine_OBJECTS = \
"CMakeFiles/engine.dir/main.cpp.o" \
"CMakeFiles/engine.dir/player/Player.cpp.o" \
"CMakeFiles/engine.dir/bomb/Bomb.cpp.o"

# External object files for target engine
engine_EXTERNAL_OBJECTS =

engine/engine: engine/CMakeFiles/engine.dir/main.cpp.o
engine/engine: engine/CMakeFiles/engine.dir/player/Player.cpp.o
engine/engine: engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.o
engine/engine: engine/CMakeFiles/engine.dir/build.make
engine/engine: engine/CMakeFiles/engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable engine"
	cd /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/engine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/CMakeFiles/engine.dir/build: engine/engine

.PHONY : engine/CMakeFiles/engine.dir/build

engine/CMakeFiles/engine.dir/requires: engine/CMakeFiles/engine.dir/main.cpp.o.requires
engine/CMakeFiles/engine.dir/requires: engine/CMakeFiles/engine.dir/player/Player.cpp.o.requires
engine/CMakeFiles/engine.dir/requires: engine/CMakeFiles/engine.dir/bomb/Bomb.cpp.o.requires

.PHONY : engine/CMakeFiles/engine.dir/requires

engine/CMakeFiles/engine.dir/clean:
	cd /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/engine && $(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean.cmake
.PHONY : engine/CMakeFiles/engine.dir/clean

engine/CMakeFiles/engine.dir/depend:
	cd /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alexandremenielle/Documents/4A/C++/BombermanCpp /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/engine /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/engine /Users/alexandremenielle/Documents/4A/C++/BombermanCpp/cmake-build-debug/engine/CMakeFiles/engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : engine/CMakeFiles/engine.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zmarian1/cs480/cs480project1/CovertChannel-RNG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/build

# Include any dependencies generated for this target.
include channel/drng/CMakeFiles/cc_drng.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include channel/drng/CMakeFiles/cc_drng.dir/compiler_depend.make

# Include the progress variables for this target.
include channel/drng/CMakeFiles/cc_drng.dir/progress.make

# Include the compile flags for this target's objects.
include channel/drng/CMakeFiles/cc_drng.dir/flags.make

channel/drng/CMakeFiles/cc_drng.dir/drng.cpp.o: channel/drng/CMakeFiles/cc_drng.dir/flags.make
channel/drng/CMakeFiles/cc_drng.dir/drng.cpp.o: ../channel/drng/drng.cpp
channel/drng/CMakeFiles/cc_drng.dir/drng.cpp.o: channel/drng/CMakeFiles/cc_drng.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zmarian1/cs480/cs480project1/CovertChannel-RNG/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object channel/drng/CMakeFiles/cc_drng.dir/drng.cpp.o"
	cd /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -mrdseed -pthread -MD -MT channel/drng/CMakeFiles/cc_drng.dir/drng.cpp.o -MF CMakeFiles/cc_drng.dir/drng.cpp.o.d -o CMakeFiles/cc_drng.dir/drng.cpp.o -c /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/channel/drng/drng.cpp

channel/drng/CMakeFiles/cc_drng.dir/drng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cc_drng.dir/drng.cpp.i"
	cd /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -mrdseed -pthread -E /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/channel/drng/drng.cpp > CMakeFiles/cc_drng.dir/drng.cpp.i

channel/drng/CMakeFiles/cc_drng.dir/drng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cc_drng.dir/drng.cpp.s"
	cd /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -mrdseed -pthread -S /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/channel/drng/drng.cpp -o CMakeFiles/cc_drng.dir/drng.cpp.s

# Object files for target cc_drng
cc_drng_OBJECTS = \
"CMakeFiles/cc_drng.dir/drng.cpp.o"

# External object files for target cc_drng
cc_drng_EXTERNAL_OBJECTS =

channel/drng/cc_drng: channel/drng/CMakeFiles/cc_drng.dir/drng.cpp.o
channel/drng/cc_drng: channel/drng/CMakeFiles/cc_drng.dir/build.make
channel/drng/cc_drng: channel/drng/CMakeFiles/cc_drng.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zmarian1/cs480/cs480project1/CovertChannel-RNG/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cc_drng"
	cd /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cc_drng.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
channel/drng/CMakeFiles/cc_drng.dir/build: channel/drng/cc_drng
.PHONY : channel/drng/CMakeFiles/cc_drng.dir/build

channel/drng/CMakeFiles/cc_drng.dir/clean:
	cd /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng && $(CMAKE_COMMAND) -P CMakeFiles/cc_drng.dir/cmake_clean.cmake
.PHONY : channel/drng/CMakeFiles/cc_drng.dir/clean

channel/drng/CMakeFiles/cc_drng.dir/depend:
	cd /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zmarian1/cs480/cs480project1/CovertChannel-RNG /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/channel/drng /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/build /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng /home/zmarian1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng/CMakeFiles/cc_drng.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : channel/drng/CMakeFiles/cc_drng.dir/depend


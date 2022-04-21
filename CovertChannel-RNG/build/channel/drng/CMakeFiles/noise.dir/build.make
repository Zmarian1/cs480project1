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
CMAKE_SOURCE_DIR = /home/sforker1/cs480/cs480project1/CovertChannel-RNG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sforker1/cs480/cs480project1/CovertChannel-RNG/build

# Include any dependencies generated for this target.
include channel/drng/CMakeFiles/noise.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include channel/drng/CMakeFiles/noise.dir/compiler_depend.make

# Include the progress variables for this target.
include channel/drng/CMakeFiles/noise.dir/progress.make

# Include the compile flags for this target's objects.
include channel/drng/CMakeFiles/noise.dir/flags.make

channel/drng/CMakeFiles/noise.dir/noise.cpp.o: channel/drng/CMakeFiles/noise.dir/flags.make
channel/drng/CMakeFiles/noise.dir/noise.cpp.o: ../channel/drng/noise.cpp
channel/drng/CMakeFiles/noise.dir/noise.cpp.o: channel/drng/CMakeFiles/noise.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sforker1/cs480/cs480project1/CovertChannel-RNG/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object channel/drng/CMakeFiles/noise.dir/noise.cpp.o"
	cd /home/sforker1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -mrdrnd -mrdseed -MD -MT channel/drng/CMakeFiles/noise.dir/noise.cpp.o -MF CMakeFiles/noise.dir/noise.cpp.o.d -o CMakeFiles/noise.dir/noise.cpp.o -c /home/sforker1/cs480/cs480project1/CovertChannel-RNG/channel/drng/noise.cpp

channel/drng/CMakeFiles/noise.dir/noise.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/noise.dir/noise.cpp.i"
	cd /home/sforker1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -mrdrnd -mrdseed -E /home/sforker1/cs480/cs480project1/CovertChannel-RNG/channel/drng/noise.cpp > CMakeFiles/noise.dir/noise.cpp.i

channel/drng/CMakeFiles/noise.dir/noise.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/noise.dir/noise.cpp.s"
	cd /home/sforker1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -mrdrnd -mrdseed -S /home/sforker1/cs480/cs480project1/CovertChannel-RNG/channel/drng/noise.cpp -o CMakeFiles/noise.dir/noise.cpp.s

# Object files for target noise
noise_OBJECTS = \
"CMakeFiles/noise.dir/noise.cpp.o"

# External object files for target noise
noise_EXTERNAL_OBJECTS =

channel/drng/noise: channel/drng/CMakeFiles/noise.dir/noise.cpp.o
channel/drng/noise: channel/drng/CMakeFiles/noise.dir/build.make
channel/drng/noise: channel/drng/CMakeFiles/noise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sforker1/cs480/cs480project1/CovertChannel-RNG/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable noise"
	cd /home/sforker1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/noise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
channel/drng/CMakeFiles/noise.dir/build: channel/drng/noise
.PHONY : channel/drng/CMakeFiles/noise.dir/build

channel/drng/CMakeFiles/noise.dir/clean:
	cd /home/sforker1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng && $(CMAKE_COMMAND) -P CMakeFiles/noise.dir/cmake_clean.cmake
.PHONY : channel/drng/CMakeFiles/noise.dir/clean

channel/drng/CMakeFiles/noise.dir/depend:
	cd /home/sforker1/cs480/cs480project1/CovertChannel-RNG/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sforker1/cs480/cs480project1/CovertChannel-RNG /home/sforker1/cs480/cs480project1/CovertChannel-RNG/channel/drng /home/sforker1/cs480/cs480project1/CovertChannel-RNG/build /home/sforker1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng /home/sforker1/cs480/cs480project1/CovertChannel-RNG/build/channel/drng/CMakeFiles/noise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : channel/drng/CMakeFiles/noise.dir/depend


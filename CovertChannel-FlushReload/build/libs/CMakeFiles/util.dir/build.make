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
CMAKE_SOURCE_DIR = /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/build

# Include any dependencies generated for this target.
include libs/CMakeFiles/util.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/CMakeFiles/util.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/CMakeFiles/util.dir/progress.make

# Include the compile flags for this target's objects.
include libs/CMakeFiles/util.dir/flags.make

libs/CMakeFiles/util.dir/util.c.o: libs/CMakeFiles/util.dir/flags.make
libs/CMakeFiles/util.dir/util.c.o: ../libs/util.c
libs/CMakeFiles/util.dir/util.c.o: libs/CMakeFiles/util.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/CMakeFiles/util.dir/util.c.o"
	cd /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/build/libs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libs/CMakeFiles/util.dir/util.c.o -MF CMakeFiles/util.dir/util.c.o.d -o CMakeFiles/util.dir/util.c.o -c /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/libs/util.c

libs/CMakeFiles/util.dir/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/util.dir/util.c.i"
	cd /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/build/libs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/libs/util.c > CMakeFiles/util.dir/util.c.i

libs/CMakeFiles/util.dir/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/util.dir/util.c.s"
	cd /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/build/libs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/libs/util.c -o CMakeFiles/util.dir/util.c.s

# Object files for target util
util_OBJECTS = \
"CMakeFiles/util.dir/util.c.o"

# External object files for target util
util_EXTERNAL_OBJECTS =

libs/libutil.a: libs/CMakeFiles/util.dir/util.c.o
libs/libutil.a: libs/CMakeFiles/util.dir/build.make
libs/libutil.a: libs/CMakeFiles/util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libutil.a"
	cd /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/build/libs && $(CMAKE_COMMAND) -P CMakeFiles/util.dir/cmake_clean_target.cmake
	cd /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/build/libs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/CMakeFiles/util.dir/build: libs/libutil.a
.PHONY : libs/CMakeFiles/util.dir/build

libs/CMakeFiles/util.dir/clean:
	cd /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/build/libs && $(CMAKE_COMMAND) -P CMakeFiles/util.dir/cmake_clean.cmake
.PHONY : libs/CMakeFiles/util.dir/clean

libs/CMakeFiles/util.dir/depend:
	cd /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/libs /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/build /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/build/libs /home/jseiber1/cs480/project/cs480project1/CovertChannel-FlushReload/build/libs/CMakeFiles/util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/CMakeFiles/util.dir/depend


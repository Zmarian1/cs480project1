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
CMAKE_SOURCE_DIR = /home/sforker1/cs480/cs480project1/CovertChannel-FlushReload

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sforker1/cs480/cs480project1/CovertChannel-FlushReload/build

# Include any dependencies generated for this target.
include CMakeFiles/receiver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/receiver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/receiver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/receiver.dir/flags.make

CMakeFiles/receiver.dir/receiver.c.o: CMakeFiles/receiver.dir/flags.make
CMakeFiles/receiver.dir/receiver.c.o: ../receiver.c
CMakeFiles/receiver.dir/receiver.c.o: CMakeFiles/receiver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sforker1/cs480/cs480project1/CovertChannel-FlushReload/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/receiver.dir/receiver.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/receiver.dir/receiver.c.o -MF CMakeFiles/receiver.dir/receiver.c.o.d -o CMakeFiles/receiver.dir/receiver.c.o -c /home/sforker1/cs480/cs480project1/CovertChannel-FlushReload/receiver.c

CMakeFiles/receiver.dir/receiver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/receiver.dir/receiver.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sforker1/cs480/cs480project1/CovertChannel-FlushReload/receiver.c > CMakeFiles/receiver.dir/receiver.c.i

CMakeFiles/receiver.dir/receiver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/receiver.dir/receiver.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sforker1/cs480/cs480project1/CovertChannel-FlushReload/receiver.c -o CMakeFiles/receiver.dir/receiver.c.s

# Object files for target receiver
receiver_OBJECTS = \
"CMakeFiles/receiver.dir/receiver.c.o"

# External object files for target receiver
receiver_EXTERNAL_OBJECTS =

bin/receiver: CMakeFiles/receiver.dir/receiver.c.o
bin/receiver: CMakeFiles/receiver.dir/build.make
bin/receiver: libs/libutil.a
bin/receiver: CMakeFiles/receiver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sforker1/cs480/cs480project1/CovertChannel-FlushReload/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/receiver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/receiver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/receiver.dir/build: bin/receiver
.PHONY : CMakeFiles/receiver.dir/build

CMakeFiles/receiver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/receiver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/receiver.dir/clean

CMakeFiles/receiver.dir/depend:
	cd /home/sforker1/cs480/cs480project1/CovertChannel-FlushReload/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sforker1/cs480/cs480project1/CovertChannel-FlushReload /home/sforker1/cs480/cs480project1/CovertChannel-FlushReload /home/sforker1/cs480/cs480project1/CovertChannel-FlushReload/build /home/sforker1/cs480/cs480project1/CovertChannel-FlushReload/build /home/sforker1/cs480/cs480project1/CovertChannel-FlushReload/build/CMakeFiles/receiver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/receiver.dir/depend


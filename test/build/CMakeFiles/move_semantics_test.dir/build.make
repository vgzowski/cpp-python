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
CMAKE_SOURCE_DIR = /home/vgzowski/study/cpp-python/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vgzowski/study/cpp-python/test/build

# Include any dependencies generated for this target.
include CMakeFiles/move_semantics_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/move_semantics_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/move_semantics_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/move_semantics_test.dir/flags.make

CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.o: CMakeFiles/move_semantics_test.dir/flags.make
CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.o: ../runtime_test/zipper/move_semantics_test.cpp
CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.o: CMakeFiles/move_semantics_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vgzowski/study/cpp-python/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.o -MF CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.o.d -o CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.o -c /home/vgzowski/study/cpp-python/test/runtime_test/zipper/move_semantics_test.cpp

CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vgzowski/study/cpp-python/test/runtime_test/zipper/move_semantics_test.cpp > CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.i

CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vgzowski/study/cpp-python/test/runtime_test/zipper/move_semantics_test.cpp -o CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.s

# Object files for target move_semantics_test
move_semantics_test_OBJECTS = \
"CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.o"

# External object files for target move_semantics_test
move_semantics_test_EXTERNAL_OBJECTS =

move_semantics_test: CMakeFiles/move_semantics_test.dir/runtime_test/zipper/move_semantics_test.cpp.o
move_semantics_test: CMakeFiles/move_semantics_test.dir/build.make
move_semantics_test: CMakeFiles/move_semantics_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vgzowski/study/cpp-python/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable move_semantics_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/move_semantics_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/move_semantics_test.dir/build: move_semantics_test
.PHONY : CMakeFiles/move_semantics_test.dir/build

CMakeFiles/move_semantics_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/move_semantics_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/move_semantics_test.dir/clean

CMakeFiles/move_semantics_test.dir/depend:
	cd /home/vgzowski/study/cpp-python/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vgzowski/study/cpp-python/test /home/vgzowski/study/cpp-python/test /home/vgzowski/study/cpp-python/test/build /home/vgzowski/study/cpp-python/test/build /home/vgzowski/study/cpp-python/test/build/CMakeFiles/move_semantics_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/move_semantics_test.dir/depend


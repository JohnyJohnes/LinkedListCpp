# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug

# Include any dependencies generated for this target.
include tests/list/CMakeFiles/tests_doubly.dir/depend.make

# Include the progress variables for this target.
include tests/list/CMakeFiles/tests_doubly.dir/progress.make

# Include the compile flags for this target's objects.
include tests/list/CMakeFiles/tests_doubly.dir/flags.make

tests/list/CMakeFiles/tests_doubly.dir/test_runner.cpp.o: tests/list/CMakeFiles/tests_doubly.dir/flags.make
tests/list/CMakeFiles/tests_doubly.dir/test_runner.cpp.o: ../tests/list/test_runner.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/list/CMakeFiles/tests_doubly.dir/test_runner.cpp.o"
	cd /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug/tests/list && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests_doubly.dir/test_runner.cpp.o -c /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/tests/list/test_runner.cpp

tests/list/CMakeFiles/tests_doubly.dir/test_runner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests_doubly.dir/test_runner.cpp.i"
	cd /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug/tests/list && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/tests/list/test_runner.cpp > CMakeFiles/tests_doubly.dir/test_runner.cpp.i

tests/list/CMakeFiles/tests_doubly.dir/test_runner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests_doubly.dir/test_runner.cpp.s"
	cd /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug/tests/list && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/tests/list/test_runner.cpp -o CMakeFiles/tests_doubly.dir/test_runner.cpp.s

tests/list/CMakeFiles/tests_doubly.dir/list_tests.cpp.o: tests/list/CMakeFiles/tests_doubly.dir/flags.make
tests/list/CMakeFiles/tests_doubly.dir/list_tests.cpp.o: ../tests/list/list_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/list/CMakeFiles/tests_doubly.dir/list_tests.cpp.o"
	cd /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug/tests/list && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests_doubly.dir/list_tests.cpp.o -c /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/tests/list/list_tests.cpp

tests/list/CMakeFiles/tests_doubly.dir/list_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests_doubly.dir/list_tests.cpp.i"
	cd /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug/tests/list && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/tests/list/list_tests.cpp > CMakeFiles/tests_doubly.dir/list_tests.cpp.i

tests/list/CMakeFiles/tests_doubly.dir/list_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests_doubly.dir/list_tests.cpp.s"
	cd /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug/tests/list && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/tests/list/list_tests.cpp -o CMakeFiles/tests_doubly.dir/list_tests.cpp.s

# Object files for target tests_doubly
tests_doubly_OBJECTS = \
"CMakeFiles/tests_doubly.dir/test_runner.cpp.o" \
"CMakeFiles/tests_doubly.dir/list_tests.cpp.o"

# External object files for target tests_doubly
tests_doubly_EXTERNAL_OBJECTS =

tests/list/tests_doubly: tests/list/CMakeFiles/tests_doubly.dir/test_runner.cpp.o
tests/list/tests_doubly: tests/list/CMakeFiles/tests_doubly.dir/list_tests.cpp.o
tests/list/tests_doubly: tests/list/CMakeFiles/tests_doubly.dir/build.make
tests/list/tests_doubly: lib/libgtestd.a
tests/list/tests_doubly: lib/libgtest_maind.a
tests/list/tests_doubly: lib/libgtestd.a
tests/list/tests_doubly: tests/list/CMakeFiles/tests_doubly.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tests_doubly"
	cd /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug/tests/list && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests_doubly.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/list/CMakeFiles/tests_doubly.dir/build: tests/list/tests_doubly

.PHONY : tests/list/CMakeFiles/tests_doubly.dir/build

tests/list/CMakeFiles/tests_doubly.dir/clean:
	cd /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug/tests/list && $(CMAKE_COMMAND) -P CMakeFiles/tests_doubly.dir/cmake_clean.cmake
.PHONY : tests/list/CMakeFiles/tests_doubly.dir/clean

tests/list/CMakeFiles/tests_doubly.dir/depend:
	cd /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/tests/list /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug/tests/list /Users/arseniybelyakov/Documents/Datastructures/week-1-lists-JohnyJohnes/cmake-build-debug/tests/list/CMakeFiles/tests_doubly.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/list/CMakeFiles/tests_doubly.dir/depend


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/sda3/UBA/Algoritmos 2/Clase7"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/sda3/UBA/Algoritmos 2/Clase7"

# Include any dependencies generated for this target.
include CMakeFiles/correrTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/correrTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/correrTests.dir/flags.make

CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o: CMakeFiles/correrTests.dir/flags.make
CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o: tests/conjunto-tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/sda3/UBA/Algoritmos 2/Clase7/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o -c "/mnt/sda3/UBA/Algoritmos 2/Clase7/tests/conjunto-tests.cpp"

CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/sda3/UBA/Algoritmos 2/Clase7/tests/conjunto-tests.cpp" > CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.i

CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/sda3/UBA/Algoritmos 2/Clase7/tests/conjunto-tests.cpp" -o CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.s

CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o.requires:

.PHONY : CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o.requires

CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o.provides: CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o.requires
	$(MAKE) -f CMakeFiles/correrTests.dir/build.make CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o.provides.build
.PHONY : CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o.provides

CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o.provides.build: CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o


# Object files for target correrTests
correrTests_OBJECTS = \
"CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o"

# External object files for target correrTests
correrTests_EXTERNAL_OBJECTS =

correrTests: CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o
correrTests: CMakeFiles/correrTests.dir/build.make
correrTests: libgtest.a
correrTests: libgtest_main.a
correrTests: CMakeFiles/correrTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/sda3/UBA/Algoritmos 2/Clase7/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable correrTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/correrTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/correrTests.dir/build: correrTests

.PHONY : CMakeFiles/correrTests.dir/build

CMakeFiles/correrTests.dir/requires: CMakeFiles/correrTests.dir/tests/conjunto-tests.cpp.o.requires

.PHONY : CMakeFiles/correrTests.dir/requires

CMakeFiles/correrTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/correrTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/correrTests.dir/clean

CMakeFiles/correrTests.dir/depend:
	cd "/mnt/sda3/UBA/Algoritmos 2/Clase7" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/sda3/UBA/Algoritmos 2/Clase7" "/mnt/sda3/UBA/Algoritmos 2/Clase7" "/mnt/sda3/UBA/Algoritmos 2/Clase7" "/mnt/sda3/UBA/Algoritmos 2/Clase7" "/mnt/sda3/UBA/Algoritmos 2/Clase7/CMakeFiles/correrTests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/correrTests.dir/depend


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
CMAKE_SOURCE_DIR = "/mnt/sda3/UBA/Algoritmos 2/Clase2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/sda3/UBA/Algoritmos 2/Clase2/build"

# Include any dependencies generated for this target.
include CMakeFiles/libreta.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libreta.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libreta.dir/flags.make

CMakeFiles/libreta.dir/tests/test_libreta.cpp.o: CMakeFiles/libreta.dir/flags.make
CMakeFiles/libreta.dir/tests/test_libreta.cpp.o: ../tests/test_libreta.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/sda3/UBA/Algoritmos 2/Clase2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libreta.dir/tests/test_libreta.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libreta.dir/tests/test_libreta.cpp.o -c "/mnt/sda3/UBA/Algoritmos 2/Clase2/tests/test_libreta.cpp"

CMakeFiles/libreta.dir/tests/test_libreta.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libreta.dir/tests/test_libreta.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/sda3/UBA/Algoritmos 2/Clase2/tests/test_libreta.cpp" > CMakeFiles/libreta.dir/tests/test_libreta.cpp.i

CMakeFiles/libreta.dir/tests/test_libreta.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libreta.dir/tests/test_libreta.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/sda3/UBA/Algoritmos 2/Clase2/tests/test_libreta.cpp" -o CMakeFiles/libreta.dir/tests/test_libreta.cpp.s

CMakeFiles/libreta.dir/tests/test_libreta.cpp.o.requires:

.PHONY : CMakeFiles/libreta.dir/tests/test_libreta.cpp.o.requires

CMakeFiles/libreta.dir/tests/test_libreta.cpp.o.provides: CMakeFiles/libreta.dir/tests/test_libreta.cpp.o.requires
	$(MAKE) -f CMakeFiles/libreta.dir/build.make CMakeFiles/libreta.dir/tests/test_libreta.cpp.o.provides.build
.PHONY : CMakeFiles/libreta.dir/tests/test_libreta.cpp.o.provides

CMakeFiles/libreta.dir/tests/test_libreta.cpp.o.provides.build: CMakeFiles/libreta.dir/tests/test_libreta.cpp.o


# Object files for target libreta
libreta_OBJECTS = \
"CMakeFiles/libreta.dir/tests/test_libreta.cpp.o"

# External object files for target libreta
libreta_EXTERNAL_OBJECTS =

libreta: CMakeFiles/libreta.dir/tests/test_libreta.cpp.o
libreta: CMakeFiles/libreta.dir/build.make
libreta: libgtest.a
libreta: libgtest_main.a
libreta: CMakeFiles/libreta.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/sda3/UBA/Algoritmos 2/Clase2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable libreta"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libreta.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libreta.dir/build: libreta

.PHONY : CMakeFiles/libreta.dir/build

CMakeFiles/libreta.dir/requires: CMakeFiles/libreta.dir/tests/test_libreta.cpp.o.requires

.PHONY : CMakeFiles/libreta.dir/requires

CMakeFiles/libreta.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libreta.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libreta.dir/clean

CMakeFiles/libreta.dir/depend:
	cd "/mnt/sda3/UBA/Algoritmos 2/Clase2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/sda3/UBA/Algoritmos 2/Clase2" "/mnt/sda3/UBA/Algoritmos 2/Clase2" "/mnt/sda3/UBA/Algoritmos 2/Clase2/build" "/mnt/sda3/UBA/Algoritmos 2/Clase2/build" "/mnt/sda3/UBA/Algoritmos 2/Clase2/build/CMakeFiles/libreta.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/libreta.dir/depend


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
include CMakeFiles/ej10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej10.dir/flags.make

CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o: CMakeFiles/ej10.dir/flags.make
CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o: ../tests/test_recordatorios.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/sda3/UBA/Algoritmos 2/Clase2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o -c "/mnt/sda3/UBA/Algoritmos 2/Clase2/tests/test_recordatorios.cpp"

CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/sda3/UBA/Algoritmos 2/Clase2/tests/test_recordatorios.cpp" > CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.i

CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/sda3/UBA/Algoritmos 2/Clase2/tests/test_recordatorios.cpp" -o CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.s

CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o.requires:

.PHONY : CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o.requires

CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o.provides: CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o.requires
	$(MAKE) -f CMakeFiles/ej10.dir/build.make CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o.provides.build
.PHONY : CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o.provides

CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o.provides.build: CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o


# Object files for target ej10
ej10_OBJECTS = \
"CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o"

# External object files for target ej10
ej10_EXTERNAL_OBJECTS =

ej10: CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o
ej10: CMakeFiles/ej10.dir/build.make
ej10: libgtest.a
ej10: libgtest_main.a
ej10: CMakeFiles/ej10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/sda3/UBA/Algoritmos 2/Clase2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej10.dir/build: ej10

.PHONY : CMakeFiles/ej10.dir/build

CMakeFiles/ej10.dir/requires: CMakeFiles/ej10.dir/tests/test_recordatorios.cpp.o.requires

.PHONY : CMakeFiles/ej10.dir/requires

CMakeFiles/ej10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej10.dir/clean

CMakeFiles/ej10.dir/depend:
	cd "/mnt/sda3/UBA/Algoritmos 2/Clase2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/sda3/UBA/Algoritmos 2/Clase2" "/mnt/sda3/UBA/Algoritmos 2/Clase2" "/mnt/sda3/UBA/Algoritmos 2/Clase2/build" "/mnt/sda3/UBA/Algoritmos 2/Clase2/build" "/mnt/sda3/UBA/Algoritmos 2/Clase2/build/CMakeFiles/ej10.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ej10.dir/depend


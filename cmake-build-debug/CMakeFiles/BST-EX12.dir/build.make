# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/kwd/Desktop/clion-2019.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kwd/Desktop/clion-2019.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/kwd/Desktop/c++ projects/BST-EX12"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/kwd/Desktop/c++ projects/BST-EX12/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/BST-EX12.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BST-EX12.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BST-EX12.dir/flags.make

CMakeFiles/BST-EX12.dir/main.cpp.o: CMakeFiles/BST-EX12.dir/flags.make
CMakeFiles/BST-EX12.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kwd/Desktop/c++ projects/BST-EX12/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BST-EX12.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BST-EX12.dir/main.cpp.o -c "/home/kwd/Desktop/c++ projects/BST-EX12/main.cpp"

CMakeFiles/BST-EX12.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BST-EX12.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kwd/Desktop/c++ projects/BST-EX12/main.cpp" > CMakeFiles/BST-EX12.dir/main.cpp.i

CMakeFiles/BST-EX12.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BST-EX12.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kwd/Desktop/c++ projects/BST-EX12/main.cpp" -o CMakeFiles/BST-EX12.dir/main.cpp.s

# Object files for target BST-EX12
BST__EX12_OBJECTS = \
"CMakeFiles/BST-EX12.dir/main.cpp.o"

# External object files for target BST-EX12
BST__EX12_EXTERNAL_OBJECTS =

BST-EX12: CMakeFiles/BST-EX12.dir/main.cpp.o
BST-EX12: CMakeFiles/BST-EX12.dir/build.make
BST-EX12: /usr/lib/x86_64-linux-gnu/libglut.so
BST-EX12: /usr/lib/x86_64-linux-gnu/libOpenGL.so
BST-EX12: /usr/lib/x86_64-linux-gnu/libGLX.so
BST-EX12: /usr/lib/x86_64-linux-gnu/libGLU.so
BST-EX12: CMakeFiles/BST-EX12.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/kwd/Desktop/c++ projects/BST-EX12/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BST-EX12"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BST-EX12.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BST-EX12.dir/build: BST-EX12

.PHONY : CMakeFiles/BST-EX12.dir/build

CMakeFiles/BST-EX12.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BST-EX12.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BST-EX12.dir/clean

CMakeFiles/BST-EX12.dir/depend:
	cd "/home/kwd/Desktop/c++ projects/BST-EX12/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/kwd/Desktop/c++ projects/BST-EX12" "/home/kwd/Desktop/c++ projects/BST-EX12" "/home/kwd/Desktop/c++ projects/BST-EX12/cmake-build-debug" "/home/kwd/Desktop/c++ projects/BST-EX12/cmake-build-debug" "/home/kwd/Desktop/c++ projects/BST-EX12/cmake-build-debug/CMakeFiles/BST-EX12.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BST-EX12.dir/depend


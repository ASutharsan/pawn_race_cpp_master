# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /Users/Samira/Desktop/C++/pawn_race_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Samira/Desktop/C++/pawn_race_cpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pawn_race_cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pawn_race_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pawn_race_cpp.dir/flags.make

CMakeFiles/pawn_race_cpp.dir/src/PawnRace/PawnRace.cpp.o: CMakeFiles/pawn_race_cpp.dir/flags.make
CMakeFiles/pawn_race_cpp.dir/src/PawnRace/PawnRace.cpp.o: ../src/PawnRace/PawnRace.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Samira/Desktop/C++/pawn_race_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pawn_race_cpp.dir/src/PawnRace/PawnRace.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pawn_race_cpp.dir/src/PawnRace/PawnRace.cpp.o -c /Users/Samira/Desktop/C++/pawn_race_cpp/src/PawnRace/PawnRace.cpp

CMakeFiles/pawn_race_cpp.dir/src/PawnRace/PawnRace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pawn_race_cpp.dir/src/PawnRace/PawnRace.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Samira/Desktop/C++/pawn_race_cpp/src/PawnRace/PawnRace.cpp > CMakeFiles/pawn_race_cpp.dir/src/PawnRace/PawnRace.cpp.i

CMakeFiles/pawn_race_cpp.dir/src/PawnRace/PawnRace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pawn_race_cpp.dir/src/PawnRace/PawnRace.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Samira/Desktop/C++/pawn_race_cpp/src/PawnRace/PawnRace.cpp -o CMakeFiles/pawn_race_cpp.dir/src/PawnRace/PawnRace.cpp.s

# Object files for target pawn_race_cpp
pawn_race_cpp_OBJECTS = \
"CMakeFiles/pawn_race_cpp.dir/src/PawnRace/PawnRace.cpp.o"

# External object files for target pawn_race_cpp
pawn_race_cpp_EXTERNAL_OBJECTS =

pawn_race_cpp: CMakeFiles/pawn_race_cpp.dir/src/PawnRace/PawnRace.cpp.o
pawn_race_cpp: CMakeFiles/pawn_race_cpp.dir/build.make
pawn_race_cpp: CMakeFiles/pawn_race_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Samira/Desktop/C++/pawn_race_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pawn_race_cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pawn_race_cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pawn_race_cpp.dir/build: pawn_race_cpp

.PHONY : CMakeFiles/pawn_race_cpp.dir/build

CMakeFiles/pawn_race_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pawn_race_cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pawn_race_cpp.dir/clean

CMakeFiles/pawn_race_cpp.dir/depend:
	cd /Users/Samira/Desktop/C++/pawn_race_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Samira/Desktop/C++/pawn_race_cpp /Users/Samira/Desktop/C++/pawn_race_cpp /Users/Samira/Desktop/C++/pawn_race_cpp/cmake-build-debug /Users/Samira/Desktop/C++/pawn_race_cpp/cmake-build-debug /Users/Samira/Desktop/C++/pawn_race_cpp/cmake-build-debug/CMakeFiles/pawn_race_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pawn_race_cpp.dir/depend


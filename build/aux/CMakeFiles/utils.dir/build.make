# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build

# Include any dependencies generated for this target.
include aux/CMakeFiles/utils.dir/depend.make

# Include the progress variables for this target.
include aux/CMakeFiles/utils.dir/progress.make

# Include the compile flags for this target's objects.
include aux/CMakeFiles/utils.dir/flags.make

aux/CMakeFiles/utils.dir/utils.cpp.o: aux/CMakeFiles/utils.dir/flags.make
aux/CMakeFiles/utils.dir/utils.cpp.o: ../aux/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object aux/CMakeFiles/utils.dir/utils.cpp.o"
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/aux && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utils.dir/utils.cpp.o -c /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/aux/utils.cpp

aux/CMakeFiles/utils.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/utils.cpp.i"
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/aux && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/aux/utils.cpp > CMakeFiles/utils.dir/utils.cpp.i

aux/CMakeFiles/utils.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/utils.cpp.s"
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/aux && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/aux/utils.cpp -o CMakeFiles/utils.dir/utils.cpp.s

# Object files for target utils
utils_OBJECTS = \
"CMakeFiles/utils.dir/utils.cpp.o"

# External object files for target utils
utils_EXTERNAL_OBJECTS =

aux/libutils.a: aux/CMakeFiles/utils.dir/utils.cpp.o
aux/libutils.a: aux/CMakeFiles/utils.dir/build.make
aux/libutils.a: aux/CMakeFiles/utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libutils.a"
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/aux && $(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean_target.cmake
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/aux && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
aux/CMakeFiles/utils.dir/build: aux/libutils.a

.PHONY : aux/CMakeFiles/utils.dir/build

aux/CMakeFiles/utils.dir/clean:
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/aux && $(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean.cmake
.PHONY : aux/CMakeFiles/utils.dir/clean

aux/CMakeFiles/utils.dir/depend:
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/aux /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/aux /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/aux/CMakeFiles/utils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : aux/CMakeFiles/utils.dir/depend

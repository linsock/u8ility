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
include u8/core_string/CMakeFiles/mstr.dir/depend.make

# Include the progress variables for this target.
include u8/core_string/CMakeFiles/mstr.dir/progress.make

# Include the compile flags for this target's objects.
include u8/core_string/CMakeFiles/mstr.dir/flags.make

u8/core_string/CMakeFiles/mstr.dir/mstr.cpp.o: u8/core_string/CMakeFiles/mstr.dir/flags.make
u8/core_string/CMakeFiles/mstr.dir/mstr.cpp.o: ../u8/core_string/mstr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object u8/core_string/CMakeFiles/mstr.dir/mstr.cpp.o"
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/u8/core_string && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mstr.dir/mstr.cpp.o -c /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/u8/core_string/mstr.cpp

u8/core_string/CMakeFiles/mstr.dir/mstr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mstr.dir/mstr.cpp.i"
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/u8/core_string && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/u8/core_string/mstr.cpp > CMakeFiles/mstr.dir/mstr.cpp.i

u8/core_string/CMakeFiles/mstr.dir/mstr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mstr.dir/mstr.cpp.s"
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/u8/core_string && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/u8/core_string/mstr.cpp -o CMakeFiles/mstr.dir/mstr.cpp.s

# Object files for target mstr
mstr_OBJECTS = \
"CMakeFiles/mstr.dir/mstr.cpp.o"

# External object files for target mstr
mstr_EXTERNAL_OBJECTS =

u8/core_string/libmstr.a: u8/core_string/CMakeFiles/mstr.dir/mstr.cpp.o
u8/core_string/libmstr.a: u8/core_string/CMakeFiles/mstr.dir/build.make
u8/core_string/libmstr.a: u8/core_string/CMakeFiles/mstr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmstr.a"
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/u8/core_string && $(CMAKE_COMMAND) -P CMakeFiles/mstr.dir/cmake_clean_target.cmake
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/u8/core_string && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mstr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
u8/core_string/CMakeFiles/mstr.dir/build: u8/core_string/libmstr.a

.PHONY : u8/core_string/CMakeFiles/mstr.dir/build

u8/core_string/CMakeFiles/mstr.dir/clean:
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/u8/core_string && $(CMAKE_COMMAND) -P CMakeFiles/mstr.dir/cmake_clean.cmake
.PHONY : u8/core_string/CMakeFiles/mstr.dir/clean

u8/core_string/CMakeFiles/mstr.dir/depend:
	cd /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/u8/core_string /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/u8/core_string /Users/linsock/PROJECTS/Studio_Interviews/testcli/testcli/u8lib/build/u8/core_string/CMakeFiles/mstr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : u8/core_string/CMakeFiles/mstr.dir/depend


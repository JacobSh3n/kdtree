# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /snap/cmake/955/bin/cmake

# The command to remove a file.
RM = /snap/cmake/955/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jbshen1/kdtreeLinux/KDTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jbshen1/kdtreeLinux/KDTree

# Include any dependencies generated for this target.
include CMakeFiles/KDTree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/KDTree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/KDTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KDTree.dir/flags.make

CMakeFiles/KDTree.dir/kdmygod.cpp.o: CMakeFiles/KDTree.dir/flags.make
CMakeFiles/KDTree.dir/kdmygod.cpp.o: kdmygod.cpp
CMakeFiles/KDTree.dir/kdmygod.cpp.o: CMakeFiles/KDTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jbshen1/kdtreeLinux/KDTree/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KDTree.dir/kdmygod.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KDTree.dir/kdmygod.cpp.o -MF CMakeFiles/KDTree.dir/kdmygod.cpp.o.d -o CMakeFiles/KDTree.dir/kdmygod.cpp.o -c /home/jbshen1/kdtreeLinux/KDTree/kdmygod.cpp

CMakeFiles/KDTree.dir/kdmygod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KDTree.dir/kdmygod.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jbshen1/kdtreeLinux/KDTree/kdmygod.cpp > CMakeFiles/KDTree.dir/kdmygod.cpp.i

CMakeFiles/KDTree.dir/kdmygod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KDTree.dir/kdmygod.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jbshen1/kdtreeLinux/KDTree/kdmygod.cpp -o CMakeFiles/KDTree.dir/kdmygod.cpp.s

# Object files for target KDTree
KDTree_OBJECTS = \
"CMakeFiles/KDTree.dir/kdmygod.cpp.o"

# External object files for target KDTree
KDTree_EXTERNAL_OBJECTS =

KDTree: CMakeFiles/KDTree.dir/kdmygod.cpp.o
KDTree: CMakeFiles/KDTree.dir/build.make
KDTree: CMakeFiles/KDTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jbshen1/kdtreeLinux/KDTree/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable KDTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KDTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KDTree.dir/build: KDTree
.PHONY : CMakeFiles/KDTree.dir/build

CMakeFiles/KDTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/KDTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/KDTree.dir/clean

CMakeFiles/KDTree.dir/depend:
	cd /home/jbshen1/kdtreeLinux/KDTree && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jbshen1/kdtreeLinux/KDTree /home/jbshen1/kdtreeLinux/KDTree /home/jbshen1/kdtreeLinux/KDTree /home/jbshen1/kdtreeLinux/KDTree /home/jbshen1/kdtreeLinux/KDTree/CMakeFiles/KDTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KDTree.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/cmake/805/bin/cmake

# The command to remove a file.
RM = /snap/cmake/805/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/laur/Desktop/TextEditor/build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/laur/Desktop/TextEditor/build

# Utility rule file for TextEditor_autogen.

# Include the progress variables for this target.
include CMakeFiles/TextEditor_autogen.dir/progress.make

CMakeFiles/TextEditor_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/laur/Desktop/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target TextEditor"
	/snap/cmake/805/bin/cmake -E cmake_autogen /home/laur/Desktop/TextEditor/build/CMakeFiles/TextEditor_autogen.dir/AutogenInfo.json ""

TextEditor_autogen: CMakeFiles/TextEditor_autogen
TextEditor_autogen: CMakeFiles/TextEditor_autogen.dir/build.make

.PHONY : TextEditor_autogen

# Rule to build all files generated by this target.
CMakeFiles/TextEditor_autogen.dir/build: TextEditor_autogen

.PHONY : CMakeFiles/TextEditor_autogen.dir/build

CMakeFiles/TextEditor_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TextEditor_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TextEditor_autogen.dir/clean

CMakeFiles/TextEditor_autogen.dir/depend:
	cd /home/laur/Desktop/TextEditor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/laur/Desktop/TextEditor/build /home/laur/Desktop/TextEditor/build /home/laur/Desktop/TextEditor/build /home/laur/Desktop/TextEditor/build /home/laur/Desktop/TextEditor/build/CMakeFiles/TextEditor_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TextEditor_autogen.dir/depend

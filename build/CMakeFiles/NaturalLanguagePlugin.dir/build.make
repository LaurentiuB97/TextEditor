# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/cmake/858/bin/cmake

# The command to remove a file.
RM = /snap/cmake/858/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/laur/Desktop/TextEditor/TextEditor/build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/laur/Desktop/TextEditor/TextEditor/build

# Include any dependencies generated for this target.
include CMakeFiles/NaturalLanguagePlugin.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/NaturalLanguagePlugin.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/NaturalLanguagePlugin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NaturalLanguagePlugin.dir/flags.make

__/src/moc_EditorInterface.cpp: /home/laur/Desktop/TextEditor/TextEditor/src/EditorInterface.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating __/src/moc_EditorInterface.cpp"
	cd /home/laur/Desktop/TextEditor/TextEditor/build/__/src && /usr/lib/qt5/bin/moc @/home/laur/Desktop/TextEditor/TextEditor/build/__/src/moc_EditorInterface.cpp_parameters

CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.o: CMakeFiles/NaturalLanguagePlugin.dir/flags.make
CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.o: __/src/moc_EditorInterface.cpp
CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.o: CMakeFiles/NaturalLanguagePlugin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.o -MF CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.o.d -o CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/build/__/src/moc_EditorInterface.cpp

CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/build/__/src/moc_EditorInterface.cpp > CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.i

CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/build/__/src/moc_EditorInterface.cpp -o CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.s

CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.o: CMakeFiles/NaturalLanguagePlugin.dir/flags.make
CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.o: /home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp
CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.o: CMakeFiles/NaturalLanguagePlugin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.o -MF CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.o.d -o CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp

CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp > CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.i

CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp -o CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.s

# Object files for target NaturalLanguagePlugin
NaturalLanguagePlugin_OBJECTS = \
"CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.o" \
"CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.o"

# External object files for target NaturalLanguagePlugin
NaturalLanguagePlugin_EXTERNAL_OBJECTS =

libNaturalLanguagePlugin.a: CMakeFiles/NaturalLanguagePlugin.dir/__/src/moc_EditorInterface.cpp.o
libNaturalLanguagePlugin.a: CMakeFiles/NaturalLanguagePlugin.dir/home/laur/Desktop/TextEditor/TextEditor/plugins/NaturalLanguagePlugin/NaturalLanguagePlugin.cpp.o
libNaturalLanguagePlugin.a: CMakeFiles/NaturalLanguagePlugin.dir/build.make
libNaturalLanguagePlugin.a: CMakeFiles/NaturalLanguagePlugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libNaturalLanguagePlugin.a"
	$(CMAKE_COMMAND) -P CMakeFiles/NaturalLanguagePlugin.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NaturalLanguagePlugin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NaturalLanguagePlugin.dir/build: libNaturalLanguagePlugin.a
.PHONY : CMakeFiles/NaturalLanguagePlugin.dir/build

CMakeFiles/NaturalLanguagePlugin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NaturalLanguagePlugin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NaturalLanguagePlugin.dir/clean

CMakeFiles/NaturalLanguagePlugin.dir/depend: __/src/moc_EditorInterface.cpp
	cd /home/laur/Desktop/TextEditor/TextEditor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/laur/Desktop/TextEditor/TextEditor/build /home/laur/Desktop/TextEditor/TextEditor/build /home/laur/Desktop/TextEditor/TextEditor/build /home/laur/Desktop/TextEditor/TextEditor/build /home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles/NaturalLanguagePlugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NaturalLanguagePlugin.dir/depend

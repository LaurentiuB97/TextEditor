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
include CMakeFiles/TextEditor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TextEditor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TextEditor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TextEditor.dir/flags.make

CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.o: CMakeFiles/TextEditor.dir/flags.make
CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.o: TextEditor_autogen/mocs_compilation.cpp
CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.o: CMakeFiles/TextEditor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.o -MF CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/build/TextEditor_autogen/mocs_compilation.cpp

CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/build/TextEditor_autogen/mocs_compilation.cpp > CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.i

CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/build/TextEditor_autogen/mocs_compilation.cpp -o CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.s

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.o: CMakeFiles/TextEditor.dir/flags.make
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.o: /home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.o: CMakeFiles/TextEditor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.o -MF CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.o.d -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp > CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.i

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.s

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.o: CMakeFiles/TextEditor.dir/flags.make
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.o: /home/laur/Desktop/TextEditor/TextEditor/src/main.cpp
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.o: CMakeFiles/TextEditor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.o -MF CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.o.d -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/src/main.cpp

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/src/main.cpp > CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.i

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/src/main.cpp -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.s

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.o: CMakeFiles/TextEditor.dir/flags.make
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.o: /home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.o: CMakeFiles/TextEditor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.o -MF CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.o.d -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp > CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.i

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.s

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.o: CMakeFiles/TextEditor.dir/flags.make
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.o: /home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.o: CMakeFiles/TextEditor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.o -MF CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.o.d -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp > CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.i

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.s

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.o: CMakeFiles/TextEditor.dir/flags.make
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.o: /home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.o: CMakeFiles/TextEditor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.o -MF CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.o.d -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp > CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.i

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.s

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.o: CMakeFiles/TextEditor.dir/flags.make
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.o: /home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.o: CMakeFiles/TextEditor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.o -MF CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.o.d -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp > CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.i

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.s

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.o: CMakeFiles/TextEditor.dir/flags.make
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.o: /home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.o: CMakeFiles/TextEditor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.o -MF CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.o.d -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp > CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.i

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.s

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.o: CMakeFiles/TextEditor.dir/flags.make
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.o: /home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.o: CMakeFiles/TextEditor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.o -MF CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.o.d -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp > CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.i

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.s

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.o: CMakeFiles/TextEditor.dir/flags.make
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.o: /home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.o: CMakeFiles/TextEditor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.o -MF CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.o.d -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp > CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.i

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.s

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.o: CMakeFiles/TextEditor.dir/flags.make
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.o: /home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp
CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.o: CMakeFiles/TextEditor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.o -MF CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.o.d -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp > CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.i

CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp -o CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.s

# Object files for target TextEditor
TextEditor_OBJECTS = \
"CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.o" \
"CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.o" \
"CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.o" \
"CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.o" \
"CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.o" \
"CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.o" \
"CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.o" \
"CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.o" \
"CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.o" \
"CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.o"

# External object files for target TextEditor
TextEditor_EXTERNAL_OBJECTS =

/home/laur/Desktop/TextEditor/TextEditor/TextEditor: CMakeFiles/TextEditor.dir/TextEditor_autogen/mocs_compilation.cpp.o
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/mainwindow.cpp.o
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/main.cpp.o
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/StringManipulator.cpp.o
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/TextHighLight.cpp.o
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/PunctuationMark.cpp.o
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Utils.cpp.o
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/HighLighter.cpp.o
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/ModifyText.cpp.o
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/Theme.cpp.o
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: CMakeFiles/TextEditor.dir/home/laur/Desktop/TextEditor/TextEditor/src/SettingsManager.cpp.o
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: CMakeFiles/TextEditor.dir/build.make
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.9.5
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.9.5
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
/home/laur/Desktop/TextEditor/TextEditor/TextEditor: CMakeFiles/TextEditor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable /home/laur/Desktop/TextEditor/TextEditor/TextEditor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TextEditor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TextEditor.dir/build: /home/laur/Desktop/TextEditor/TextEditor/TextEditor
.PHONY : CMakeFiles/TextEditor.dir/build

CMakeFiles/TextEditor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TextEditor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TextEditor.dir/clean

CMakeFiles/TextEditor.dir/depend:
	cd /home/laur/Desktop/TextEditor/TextEditor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/laur/Desktop/TextEditor/TextEditor/build /home/laur/Desktop/TextEditor/TextEditor/build /home/laur/Desktop/TextEditor/TextEditor/build /home/laur/Desktop/TextEditor/TextEditor/build /home/laur/Desktop/TextEditor/TextEditor/build/CMakeFiles/TextEditor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TextEditor.dir/depend


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
CMAKE_COMMAND = /snap/cmake/882/bin/cmake

# The command to remove a file.
RM = /snap/cmake/882/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/laur/Desktop/TextEditor/TextEditor/UnitTests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/laur/Desktop/TextEditor/TextEditor/UnitTests

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o: test_autogen/mocs_compilation.cpp
CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/UnitTests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o -MF CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/UnitTests/test_autogen/mocs_compilation.cpp

CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/UnitTests/test_autogen/mocs_compilation.cpp > CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.i

CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/UnitTests/test_autogen/mocs_compilation.cpp -o CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.s

CMakeFiles/test.dir/main_test.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/main_test.cpp.o: main_test.cpp
CMakeFiles/test.dir/main_test.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/UnitTests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/main_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/main_test.cpp.o -MF CMakeFiles/test.dir/main_test.cpp.o.d -o CMakeFiles/test.dir/main_test.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/UnitTests/main_test.cpp

CMakeFiles/test.dir/main_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/main_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/UnitTests/main_test.cpp > CMakeFiles/test.dir/main_test.cpp.i

CMakeFiles/test.dir/main_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/main_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/UnitTests/main_test.cpp -o CMakeFiles/test.dir/main_test.cpp.s

CMakeFiles/test.dir/TestTextEditor.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/TestTextEditor.cpp.o: TestTextEditor.cpp
CMakeFiles/test.dir/TestTextEditor.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/UnitTests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.dir/TestTextEditor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/TestTextEditor.cpp.o -MF CMakeFiles/test.dir/TestTextEditor.cpp.o.d -o CMakeFiles/test.dir/TestTextEditor.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/UnitTests/TestTextEditor.cpp

CMakeFiles/test.dir/TestTextEditor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/TestTextEditor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/UnitTests/TestTextEditor.cpp > CMakeFiles/test.dir/TestTextEditor.cpp.i

CMakeFiles/test.dir/TestTextEditor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/TestTextEditor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/UnitTests/TestTextEditor.cpp -o CMakeFiles/test.dir/TestTextEditor.cpp.s

CMakeFiles/test.dir/StringManipulator.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/StringManipulator.cpp.o: StringManipulator.cpp
CMakeFiles/test.dir/StringManipulator.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/UnitTests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test.dir/StringManipulator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/StringManipulator.cpp.o -MF CMakeFiles/test.dir/StringManipulator.cpp.o.d -o CMakeFiles/test.dir/StringManipulator.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/UnitTests/StringManipulator.cpp

CMakeFiles/test.dir/StringManipulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/StringManipulator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/UnitTests/StringManipulator.cpp > CMakeFiles/test.dir/StringManipulator.cpp.i

CMakeFiles/test.dir/StringManipulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/StringManipulator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/UnitTests/StringManipulator.cpp -o CMakeFiles/test.dir/StringManipulator.cpp.s

CMakeFiles/test.dir/PunctuationMark.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/PunctuationMark.cpp.o: PunctuationMark.cpp
CMakeFiles/test.dir/PunctuationMark.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/UnitTests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/test.dir/PunctuationMark.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/PunctuationMark.cpp.o -MF CMakeFiles/test.dir/PunctuationMark.cpp.o.d -o CMakeFiles/test.dir/PunctuationMark.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/UnitTests/PunctuationMark.cpp

CMakeFiles/test.dir/PunctuationMark.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/PunctuationMark.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/UnitTests/PunctuationMark.cpp > CMakeFiles/test.dir/PunctuationMark.cpp.i

CMakeFiles/test.dir/PunctuationMark.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/PunctuationMark.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/UnitTests/PunctuationMark.cpp -o CMakeFiles/test.dir/PunctuationMark.cpp.s

CMakeFiles/test.dir/TextHighLight.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/TextHighLight.cpp.o: TextHighLight.cpp
CMakeFiles/test.dir/TextHighLight.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/UnitTests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/test.dir/TextHighLight.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/TextHighLight.cpp.o -MF CMakeFiles/test.dir/TextHighLight.cpp.o.d -o CMakeFiles/test.dir/TextHighLight.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/UnitTests/TextHighLight.cpp

CMakeFiles/test.dir/TextHighLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/TextHighLight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/UnitTests/TextHighLight.cpp > CMakeFiles/test.dir/TextHighLight.cpp.i

CMakeFiles/test.dir/TextHighLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/TextHighLight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/UnitTests/TextHighLight.cpp -o CMakeFiles/test.dir/TextHighLight.cpp.s

CMakeFiles/test.dir/Utils.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/Utils.cpp.o: Utils.cpp
CMakeFiles/test.dir/Utils.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/UnitTests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/test.dir/Utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/Utils.cpp.o -MF CMakeFiles/test.dir/Utils.cpp.o.d -o CMakeFiles/test.dir/Utils.cpp.o -c /home/laur/Desktop/TextEditor/TextEditor/UnitTests/Utils.cpp

CMakeFiles/test.dir/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/Utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laur/Desktop/TextEditor/TextEditor/UnitTests/Utils.cpp > CMakeFiles/test.dir/Utils.cpp.i

CMakeFiles/test.dir/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/Utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laur/Desktop/TextEditor/TextEditor/UnitTests/Utils.cpp -o CMakeFiles/test.dir/Utils.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/test.dir/main_test.cpp.o" \
"CMakeFiles/test.dir/TestTextEditor.cpp.o" \
"CMakeFiles/test.dir/StringManipulator.cpp.o" \
"CMakeFiles/test.dir/PunctuationMark.cpp.o" \
"CMakeFiles/test.dir/TextHighLight.cpp.o" \
"CMakeFiles/test.dir/Utils.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/test_autogen/mocs_compilation.cpp.o
test: CMakeFiles/test.dir/main_test.cpp.o
test: CMakeFiles/test.dir/TestTextEditor.cpp.o
test: CMakeFiles/test.dir/StringManipulator.cpp.o
test: CMakeFiles/test.dir/PunctuationMark.cpp.o
test: CMakeFiles/test.dir/TextHighLight.cpp.o
test: CMakeFiles/test.dir/Utils.cpp.o
test: CMakeFiles/test.dir/build.make
test: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.9.5
test: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.9.5
test: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/laur/Desktop/TextEditor/TextEditor/UnitTests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/laur/Desktop/TextEditor/TextEditor/UnitTests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/laur/Desktop/TextEditor/TextEditor/UnitTests /home/laur/Desktop/TextEditor/TextEditor/UnitTests /home/laur/Desktop/TextEditor/TextEditor/UnitTests /home/laur/Desktop/TextEditor/TextEditor/UnitTests /home/laur/Desktop/TextEditor/TextEditor/UnitTests/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend


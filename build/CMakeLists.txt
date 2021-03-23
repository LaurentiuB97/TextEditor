cmake_minimum_required(VERSION 3.1.0)
project(TextEditor)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")
set(SOURCE_FILES ../src/mainwindow.cpp
		../src/mainwindow.ui
		../src/main.cpp
                ../src/StringManipulator.cpp
                ../src/TextHighLight.cpp
                ../src/PunctuationMark.cpp
                ../src/Utils.cpp
		../src/HighLighter.cpp
                ../src/ModifyText.cpp
)
add_executable(TextEditor ${SOURCE_FILES})
target_link_libraries(TextEditor Qt5::Widgets)

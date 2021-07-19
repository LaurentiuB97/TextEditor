cmake_minimum_required(VERSION 3.1.0)
project(test)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
	set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(SOURCE_FILES main_test.cpp
                TestTextEditor.cpp
                StringManipulator.cpp
                PunctuationMark.cpp
                TextHighLight.cpp
                Utils.cpp
)
add_executable(test ${SOURCE_FILES})
target_link_libraries(test -lcppunit Qt5::Core Qt5::Widgets)

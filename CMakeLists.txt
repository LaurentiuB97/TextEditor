cmake_minimum_required(VERSION 3.1.0)
project(TextEditor)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
	set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
qt5_add_resources(RESOURCE_FILES ./resources.qrc)
set(SOURCE_FILES mainwindow.ui
		mainwindow.cpp
		main.cpp
                StringManipulator.cpp
                TextHighLight.cpp
                PunctuationMark.cpp
                Utils.cpp
                InsertText.cpp
                ModifyText.cpp
)
add_executable(TextEditor ${SOURCE_FILES})
target_link_libraries(TextEditor Qt5::Widgets)

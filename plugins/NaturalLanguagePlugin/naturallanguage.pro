TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../../src
HEADERS         += \
                   NaturalLanguagePlugin.h \
                   ../../src/Theme.h \
                   ../../src/StringManipulator.h\
                   ../../src/TabWidget.h\
                   ../../src/Availability.h
SOURCES         += \
                   NaturalLanguagePlugin.cpp\
                   ../../src/Theme.cpp \
                   ../../src/StringManipulator.cpp\
                   ../../src/TabWidget.cpp\
                   ../../src/Availability.cpp
TARGET          = $$qtLibraryTarget(NaturalLanguagePlugin)
DESTDIR         = ../
EXAMPLE_FILES = naturallanguageplugin.json

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/tools/naturallanguageplugin/plugins
INSTALLS += target

CONFIG += install_ok

TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../../src
HEADERS         += \
                   NaturalLanguagePlugin.h \
                   ../../src/Theme.h \
                   ../../src/StringManipulator.h
SOURCES         += \
                   NaturalLanguagePlugin.cpp\
                   ../../src/Theme.cpp \
                   ../../src/StringManipulator.cpp
TARGET          = $$qtLibraryTarget(NaturalLanguagePlugin)
DESTDIR         = ../
EXAMPLE_FILES = naturallanguageplugin.json

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/tools/naturallanguageplugin/plugins
INSTALLS += target

CONFIG += install_ok

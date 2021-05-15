TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../../src
HEADERS         += \
                   CppPlugin.h \
		           HighLighter.h\
                   ../../src/Theme.h \
                   ../../src/TabWidget.h
                   
SOURCES         += \
                   CppPlugin.cpp\
                   HighLighter.cpp\
                   ../../src/Theme.cpp \
                   ../../src/TabWidget.cpp
TARGET          = $$qtLibraryTarget(CppPlugin)
DESTDIR         = ../
EXAMPLE_FILES = cppplugin.json

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/tools/cppplugin/plugins
INSTALLS += target

CONFIG += install_ok

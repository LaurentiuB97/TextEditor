TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../../src
HEADERS         += \
                   TranslatorPlugin.h \
                   ../../src/Theme.h \
                   ../../src/TabWidget.h
                   
SOURCES         += \
                   TranslatorPlugin.cpp\
                   ../../src/Theme.cpp \
                   ../../src/TabWidget.cpp
TARGET          = $$qtLibraryTarget(TranslatorPlugin)
DESTDIR         = ../
EXAMPLE_FILES = translatorplugin.json

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/tools/translatorplugin/plugins
INSTALLS += target

CONFIG += install_ok

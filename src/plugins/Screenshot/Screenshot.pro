TARGET = $$qtLibraryTarget(Screenshot)

SOURCES += ScreenshotPlugin.cpp

HEADERS += ScreenshotPlugin.h

PLUGIN_DIR = $$PWD
include(../../plugins.pri)

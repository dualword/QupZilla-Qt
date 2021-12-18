TARGET = $$qtLibraryTarget(UserAgentManager)

SOURCES += UIManagerPlugin.cpp

HEADERS += UIManagerPlugin.h

RESOURCES += useragentmanager.qrc

FORMS += 
    
TRANSLATIONS += 

PLUGIN_DIR = $$PWD
include(../../plugins.pri)

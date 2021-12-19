TARGET = $$qtLibraryTarget(UserAgentManager)

SOURCES += UAManagerPlugin.cpp

HEADERS += UAManagerPlugin.h

RESOURCES += useragentmanager.qrc

FORMS += 
    
TRANSLATIONS += 

PLUGIN_DIR = $$PWD
include(../../plugins.pri)

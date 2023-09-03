TARGET = $$qtLibraryTarget(NetworkTraffic)

SOURCES += src/NetworkInterceptor.cpp src/NetworkTrafficSidebar.cpp src/NetworkTraffic.cpp  

HEADERS += src/NetworkInterceptor.h src/NetworkTrafficSidebar.h src/NetworkTraffic.h  

RESOURCES += networktraffic.qrc

PLUGIN_DIR = $$PWD
include(../../plugins.pri)

#-------------------------------------------------
#
# Project created by QtCreator 2019-04-05T17:38:56
#
#-------------------------------------------------

QT       -= gui

TARGET = GGEngine
TEMPLATE = lib

DEFINES += GGE_BUILD_DLL

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GGEngine_Core/application.cpp \
    GGEngine_Core/log.cpp

HEADERS += \
        ggengine.h \
    GGEngine_Core/application.h \
    GGEngine_Core/core.h \
    GGEngine_Core/entrypoint.h \
    GGEngine_Core/log.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

# Logging
INCLUDEPATH += $$PWD/../GGEngine/Logging/include
DEPENDPATH += $$PWD/../GGEngine/Logging/include

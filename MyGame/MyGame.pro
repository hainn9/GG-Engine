TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle


SOURCES += \
    GameApp.cpp

# GGEngine lib
macx: LIBS += -L$$OUT_PWD/../GGEngine/ -lGGEngine

INCLUDEPATH += $$PWD/../GGEngine
DEPENDPATH += $$PWD/../GGEngine

# Logging
INCLUDEPATH += $$PWD/../GGEngine/Logging/include
DEPENDPATH += $$PWD/../GGEngine/Logging/include

# Modern OpenGL library (GLAD)
#INCLUDEPATH += $$PWD/../GGEngine/GLAD/include
#DEPENDPATH += $$PWD/../GGEngine/GLAD/include

# Support runtime library : Multi-thread debug DLL

TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle


SOURCES += \
    GameApp.cpp

macx: LIBS += -L$$OUT_PWD/../GGEngine/ -lGGEngine

INCLUDEPATH += $$PWD/../GGEngine
DEPENDPATH += $$PWD/../GGEngine
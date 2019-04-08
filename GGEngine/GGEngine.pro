#-------------------------------------------------
#
# Project created by QtCreator 2019-04-05T17:38:56
#
#-------------------------------------------------

QT       -= gui

TARGET = GGEngine
TEMPLATE = lib

DEFINES += GGE_BUILD_DLL
# If want to build GGEngine as static library
#CONFIG += staticlib
#DEFINES += GGE_BUILD_STATIC


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
    GGEngine_Core/log.cpp \
    GGEngine_Core/opengl_window.cpp \
    GGEngine_Core/layerstack.cpp \
    GLAD/glad.c \
    imgui/imgui_demo.cpp \
    imgui/imgui_draw.cpp \
    imgui/imgui_impl_glfw.cpp \
    imgui/imgui_impl_opengl3.cpp \
    imgui/imgui_widgets.cpp \
    imgui/imgui.cpp \
    GGEngine_Core/imgui_layer.cpp \
    GGEngine_Core/window_input.cpp

HEADERS += \
        ggengine.h \
    GGEngine_Core/application.h \
    GGEngine_Core/core.h \
    GGEngine_Core/entrypoint.h \
    GGEngine_Core/log.h \
    GGEngine_Core/Event/event.h \
    GGEngine_Core/Event/applicationevent.h \
    GGEngine_Core/Event/mouseevent.h \
    GGEngine_Core/Event/keyevent.h \
    GGEngine_Core/window.h \
    GGEngine_Core/opengl_window.h \
    GGEngine_Core/layer.h \
    GGEngine_Core/layerstack.h \
    GLAD/glad/glad.h \
    GLAD/KHR/khrplatform.h \
    imgui/imconfig.h \
    imgui/imgui_impl_glfw.h \
    imgui/imgui_impl_opengl3.h \
    imgui/imgui_internal.h \
    imgui/imgui.h \
    imgui/imstb_rectpack.h \
    imgui/imstb_textedit.h \
    imgui/imstb_truetype.h \
    GGEngine_Core/imgui_layer.h \
    GGEngine_Core/input.h \
    GGEngine_Core/window_input.h \
    GGEngine_Core/keycodes.h \
    GGEngine_Core/mousebuttoncodes.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

# Logging
INCLUDEPATH += $$PWD/Logging/include
DEPENDPATH += $$PWD/Logging/include

# Static library for GLFW
macx: LIBS += -L$$PWD/GLFW/ -lglfw3

INCLUDEPATH += $$PWD/GLFW/include
DEPENDPATH += $$PWD/GLFW/include

macx: PRE_TARGETDEPS += $$PWD/GLFW/libglfw3.a
QMAKE_LFLAGS += -F/System/Library/Frameworks/
LIBS += -framework OpenGL \
        -framework Cocoa \
        -framework CoreVideo \
        -framework IOKit \

# Modern OpenGL library (GLAD)
#INCLUDEPATH += $$PWD/GLAD/include
#DEPENDPATH += $$PWD/GLAD/include

# Support runtime library : Multi-thread debug DLL

#-------------------------------------------------
#
# Project created by QtCreator 2019-05-31T09:58:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LaberintoInterfaz
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    rectangle.cpp \
    grafomatriz.cpp \
    prim.cpp \
    controlador.cpp \
    kruskal.cpp \
    puntosdearticulacion.cpp \
    recorregrafo.cpp \
    profundidad.cpp \
    dijkstra.cpp \
    timer.cpp

HEADERS += \
    rectangle.h \
    list.h \
    arraylist.h \
    vista.h \
    dijkstra.h \
    grafomatriz.h \
    linkedlist.h \
    node.h \
    prim.h \
    controlador.h \
    kruskal.h \
    puntosdearticulacion.h \
    recorregrafo.h \
    profundidad.h \
    kvpair.h \
    personaje.h \
    timer.h \
    padre.h

FORMS += \
        prueba.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#-------------------------------------------------
#
# Project created by QtCreator 2016-11-23T22:52:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    dialog2.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    dialog2.h \
    course.h \
    room.h \
    state.h \
    population.h \
    geneticai.h

FORMS    += mainwindow.ui \
    dialog.ui \
    dialog2.ui

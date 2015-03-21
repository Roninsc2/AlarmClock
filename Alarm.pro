#-------------------------------------------------
#
# Project created by QtCreator 2015-03-17T22:16:19
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Alarm
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    sound.cpp \
    activationtime.cpp

HEADERS  += widget.h \
    sound.h \
    activationtime.h

FORMS    += widget.ui

QMAKE_CXXFLAGS += -std=c++11 -Werror


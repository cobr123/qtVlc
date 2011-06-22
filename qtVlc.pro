#-------------------------------------------------
#
# Project created by QtCreator 2011-06-22T09:32:07
#
#-------------------------------------------------

QT       += core gui

TARGET = qtVlc
TEMPLATE = app

LIBS += -I"C:\Users\rtabulov\qt\qtVlc\vlcSrc\include"
LIBS += -L"C:\Users\rtabulov\qt\qtVlc\vlcBin" #if you are at windows os
LIBS += -llibvlc

SOURCES += main.cpp \
    vlc_on_qt.cpp

HEADERS  += \
    vlc_on_qt.h

FORMS    +=

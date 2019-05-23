QT += core concurrent gui
#QT -= gui

CONFIG += c++11

TARGET = Assignment
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    imagecreator.cpp \
    imageproperty.cpp \
    taskhandler.cpp \
    workerthread.cpp

HEADERS += \
    imagecreator.h \
    imageproperty.h \
    taskhandler.h \
    workerthread.h

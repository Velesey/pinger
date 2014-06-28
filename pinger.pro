#-------------------------------------------------
#
# Project created by QtCreator 2014-06-26T16:49:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pinger
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    systray.qrc


target.path = $${PREFIX}/bin
INSTALLS += target

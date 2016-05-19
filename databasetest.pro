#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T15:45:43
#
#-------------------------------------------------

QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = databasetest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainwindow2.cpp \
    dbmanager.cpp

HEADERS  += mainwindow.h \
    mainwindow2.h \
    dbmanager.h

FORMS    += mainwindow.ui \
    mainwindow2.ui

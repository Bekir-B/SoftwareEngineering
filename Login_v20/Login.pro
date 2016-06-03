#-------------------------------------------------
#
# Project created by QtCreator 2016-05-20T10:56:45
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Login
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    mainwindow.cpp \
    register.cpp \
    payment.cpp \
    ticket.cpp \
    database.cpp \
    adminaddflight.cpp \
    flights.cpp \
    admineditflight.cpp \
    ticket_cancellation.cpp \
    customer_details.cpp \
    mainwindow_customer.cpp

HEADERS  += login.h \
    mainwindow.h \
    register.h \
    payment.h \
    ticket.h \
    database.h \
    adminaddflight.h \
    flights.h \
    admineditflight.h \
    ticket_cancellation.h \
    customer_details.h \
    mainwindow_customer.h

FORMS    += login.ui \
    mainwindow.ui \
    register.ui \
    payment.ui \
    ticket.ui \
    adminaddflight.ui \
    flights.ui \
    admineditflight.ui \
    ticket_cancellation.ui \
    customer_details.ui \
    mainwindow_customer.ui

RESOURCES += \
    resource.qrc

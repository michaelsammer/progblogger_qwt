#-------------------------------------------------
#
# Project created by QtCreator 2016-08-03T08:08:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HelloQWT
TEMPLATE = app


SOURCES += main.cpp\
        helloqwt.cpp

HEADERS  += helloqwt.h

FORMS    += helloqwt.ui

# set paths to QWT
QWT_LOCATION = C:\qwt-6.1.2

INCLUDEPATH''= $${QWT_LOCATION}/include/
LIBS += -L$${QWT_LOCATION}/lib -lqwt

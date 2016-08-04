#-------------------------------------------------
#
# Project created by QtCreator 2016-08-04T07:57:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CustomQWT
TEMPLATE = app


SOURCES += main.cpp\
        customqwt.cpp

HEADERS  += customqwt.h

FORMS    += customqwt.ui

# set paths to QWT
QWT_LOCATION = C:\qwt-6.1.2

INCLUDEPATH''= $${QWT_LOCATION}/include/
LIBS += -L$${QWT_LOCATION}/lib -lqwt

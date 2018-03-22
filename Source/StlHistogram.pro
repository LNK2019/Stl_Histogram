#-------------------------------------------------
#
# Project created by QtCreator 2018-03-21T20:15:28
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StlHistogram
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    stldata.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    stldata.h \
    point.h \
    triangle.h

FORMS    += mainwindow.ui

#-------------------------------------------------
#
# Project created by QtCreator 2017-05-06T18:02:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Baseball-Project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    date.cpp \
    address.cpp \
    souvenir.cpp \
    stadium.cpp \
    stadiumtree.cpp \
    stadiumdatetree.cpp

HEADERS  += mainwindow.h \
    date.h \
    address.h \
    binarytree.h \
    souvenir.h \
    stadium.h \
    stadiumdatecomparator.h \
    stadiumtree.h \
    stadiumdatetree.h

FORMS    += mainwindow.ui

DISTFILES += \
    README.md

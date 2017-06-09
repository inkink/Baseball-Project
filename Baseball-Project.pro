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
    shoppingcart.cpp \
    stadiumdatetree.cpp \
    stadiumteamtree.cpp \
    stadiumtree.cpp \
    graph.cpp

HEADERS  += mainwindow.h \
    date.h \
    address.h \
    binarytree.h \
    souvenir.h \
    stadium.h \
    shoppingcart.h \
    stadiumdatetree.h \
    stadiumteamtree.h \
    stadiumtree.h \
    graph.h

FORMS    += mainwindow.ui

DISTFILES += \
    README.md \
    input.txt

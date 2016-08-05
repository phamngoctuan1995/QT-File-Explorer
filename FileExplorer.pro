#-------------------------------------------------
#
# Project created by QtCreator 2016-07-29T10:13:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QTPLUGIN += gif

TARGET = FileExplorer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filedelegate.cpp \
    myfilesystemmodel.cpp \
    myfilemodel.cpp \
    mylistview.cpp

HEADERS  += mainwindow.h \
    filedelegate.h \
    myfilesystemmodel.h \
    myfilemodel.h \
    mylistview.h

FORMS    += mainwindow.ui

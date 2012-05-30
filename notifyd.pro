#-------------------------------------------------
#
# Project created by QtCreator 2012-01-06T17:01:14
#
#-------------------------------------------------

QT       += core dbus gui

TARGET    = notifyd
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES +=  main.cpp \
            notifyadaptor.cpp \
            notifyd.cpp \
            notificationitem.cpp

HEADERS +=  notifyadaptor.h \
            notifyd.h \
            notificationitem.h

FORMS +=    notificationitem.ui

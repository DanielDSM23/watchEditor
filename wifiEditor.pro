QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    addclient.cpp \
    main.cpp \
    watchEditor.cpp \
    wifieditor.cpp \
    console.cpp

HEADERS += \
    about.h \
    addclient.h \
    watchEditor.h \
    wifieditor.h \
    console.h

FORMS += \
    about.ui \
    addclient.ui \
    watchEditor.ui \
    wifieditor.ui \
    console.ui


QT += sql
QT += serialport
QT += core

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


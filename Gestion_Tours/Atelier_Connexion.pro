QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = Atelier_Connexion
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    G_Tours.cpp \
    main.cpp \
    connection.cpp

HEADERS += \
    G_Tours.h \
    connection.h

FORMS += \
    G_Tours.ui


QT += charts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


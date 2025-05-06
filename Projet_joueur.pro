CONFIG += c++17
QT += core gui sql widgets network printsupport serialport uitools charts

SOURCES += \
    arduinomanager.cpp \
    main.cpp \
    mainwindow.cpp \
    Joueur.cpp \
    connection.cpp \
    player.cpp \
    ../equipe_window/equipe_window.cpp \
    ../equipe_window/g_equipe.cpp \
    ../untitled1/stade.cpp \
    ../untitled1/stadewindow.cpp \
    ../Gestion_Tours/G_Tours.cpp

HEADERS += \
    arduinomanager.h \
    mainwindow.h \
    Joueur.h \
    connection.h \
    player.h \
    ../equipe_window/equipe_window.h \
    ../equipe_window/g_equipe.h \
    ../untitled1/stade.h \
    ../untitled1/stadewindow.h \
    ../Gestion_Tours/G_Tours.h

FORMS += \
    Joueur.ui \
    mainwindow.ui \
    ../equipe_window/equipe_window.ui \
    ../Gestion_Tours/G_Tours.ui \
    ../untitled1/stadewindow.ui

INCLUDEPATH += ../equipe_window ../untitled1 ../Gestion_Tours

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

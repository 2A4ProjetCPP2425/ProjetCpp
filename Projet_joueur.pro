CONFIG += c++17
QT += core gui sql widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    Joueur.cpp \
    connection.cpp \
    player.cpp

HEADERS += \
    mainwindow.h \
    Joueur.h \
    connection.h \
    player.h

FORMS += \
    Joueur.ui \
    mainwindow.ui

# Règles par défaut pour le déploiement.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin

# Ajouter l'installation seulement si target.path n'est pas vide
!isEmpty(target.path): INSTALLS += target

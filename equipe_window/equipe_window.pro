TEMPLATE = app          # Déclare le projet comme une application
QT += core gui widgets sql  # Modules Qt nécessaires
CONFIG += c++17

# Fichiers sources
SOURCES += main.cpp \
           equipe_window.cpp \
           connection.cpp \
           g_equipe.cpp

# Fichiers d'en-tête
HEADERS += equipe_window.h \
           connection.h \
           g_equipe.h

# Fichiers UI
FORMS += equipe_window.ui

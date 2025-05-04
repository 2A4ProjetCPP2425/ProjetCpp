QT += core gui sql quick widgets network printsupport charts

CONFIG += c++11

# Emit warnings for deprecated Qt features
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    connection.cpp \
    main.cpp \
    stadewindow.cpp \
    stade.cpp

HEADERS += \
    connection.h \
    stadewindow.h \
    stade.h

FORMS += \
    stadewindow.ui

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

# Diagnostic message to confirm sources are recognized
message("Sources: $$SOURCES")

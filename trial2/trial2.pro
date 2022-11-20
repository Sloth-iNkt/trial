QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    easywindow.cpp \
    howtoplay.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    mediumwindow.cpp \
    review.cpp

HEADERS += \
    dialog.h \
    easywindow.h \
    howtoplay.h \
    mainmenu.h \
    mainwindow.h \
    mediumwindow.h \
    questions.h \
    review.h

FORMS += \
    dialog.ui \
    easywindow.ui \
    howtoplay.ui \
    mainmenu.ui \
    mainwindow.ui \
    mediumwindow.ui \
    review.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

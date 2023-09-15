QT       += core gui sql





greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add.cpp \
    count1.cpp \
    deletedetails.cpp \
    displaydetails.cpp \
    highest.cpp \
    lowest.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    menu1.cpp \
    modifydetails.cpp \
    searchdetails.cpp

HEADERS += \
    add.h \
    count1.h \
    deletedetails.h \
    displaydetails.h \
    highest.h \
    lowest.h \
    mainwindow.h \
    menu.h \
    menu1.h \
    modifydetails.h \
    searchdetails.h

FORMS += \
    add.ui \
    count1.ui \
    deletedetails.ui \
    displaydetails.ui \
    highest.ui \
    lowest.ui \
    mainwindow.ui \
    menu.ui \
    menu1.ui \
    modifydetails.ui \
    searchdetails.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc \
    src.qrc

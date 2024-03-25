QT       += core gui
LIBS += -lnids
LIBS += -lpcap
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choose_patternfile.cpp \
    main.cpp \
    set_parameters.cpp \
    show_detection.cpp \
    wait.cpp \
    widget.cpp

HEADERS += \
    choose_patternfile.h \
    set_parameters.h \
    show_detection.h \
    wait.h \
    widget.h

FORMS += \
    choose_patternfile.ui \
    set_parameters.ui \
    show_detection.ui \
    wait.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    demo4_resource/首页图.jpg

RESOURCES += \
    resource.qrc


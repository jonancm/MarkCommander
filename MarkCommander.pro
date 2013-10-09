#-------------------------------------------------
#
# Project created by QtCreator 2011-03-16T22:14:07
#
#-------------------------------------------------

QT       += core gui webkit

TARGET = MarkCommander
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    exception.cpp \
    errorcodes.cpp \
    terminal.cpp \
    rhinolang.cpp \
    cmdlineedit.cpp \
    rhinoprog.cpp \
    rhino_xr4.cpp \
    matrix.cpp

HEADERS  += \
    rhino_xr4.hpp \
    matrix.hpp \
    cmdlineedit.hpp \
    errorcodes.hpp \
    exception.hpp \
    mainwindow.hpp \
    rhinolang.hpp \
    rhinoprog.hpp \
    terminal.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc \
    files.qrc

INCLUDEPATH += ../qextserialport/src

#LIBS += -L../qextserialport/src-build-desktop/build -lqextserialportd1
#LIBS += -L../qextserialport/src-build-desktop/build -lqextserialport1
#macx:LIBS += -L../qextserialport-build-desktop-Desktop_Qt_4_7_4_for_GCC__Qt_SDK__Debug/src/build -lqextserialportd
macx:LIBS += -L../qextserialport-build-desktop-Desktop_Qt_4_7_4_for_GCC__Qt_SDK__Release/src/build -lqextserialport

win32:RC_FILE = MarkCommander.rc
macx:ICON = appicon.icns















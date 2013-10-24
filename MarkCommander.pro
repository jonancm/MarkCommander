#-------------------------------------------------
#
# Project created by QtCreator 2011-03-16T22:14:07
#
#-------------------------------------------------

QT       += core gui webkit

TARGET = MarkCommander
TEMPLATE = app

SOURCES += \
	src/terminal.cpp \
	src/rhino_xr4.cpp \
	src/rhinoprog.cpp \
	src/rhinolang.cpp \
	src/matrix.cpp \
	src/mainwindow.cpp \
	src/main.cpp \
	src/exception.cpp \
	src/errorcodes.cpp \
	src/cmdlineedit.cpp

HEADERS += \
	src/terminal.hpp \
	src/rhino_xr4.hpp \
	src/rhinoprog.hpp \
	src/rhinolang.hpp \
	src/matrix.hpp \
	src/mainwindow.hpp \
	src/exception.hpp \
	src/errorcodes.hpp \
	src/cmdlineedit.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc \
    files.qrc

INCLUDEPATH += ../qextserialport/src

LIBS += -L../qextserialport-build-desktop-Qt_4_8_3_in_PATH__System__Release -lqextserialport
#LIBS += -L../qextserialport/src-build-desktop/build -lqextserialport1
#macx:LIBS += -L../qextserialport-build-desktop-Desktop_Qt_4_7_4_for_GCC__Qt_SDK__Debug/src/build -lqextserialportd
#macx:LIBS += -L../qextserialport-build-desktop-Desktop_Qt_4_7_4_for_GCC__Qt_SDK__Release/src/build -lqextserialport

win32:RC_FILE = MarkCommander.rc
macx:ICON = appicon.icns

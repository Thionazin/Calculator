TEMPLATE = app

QT = core gui

RC_FILE = calculator.rc

TARGET = Calculator

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    src/addClassWindow.cpp \
    src/gpaCalculator.cpp \
    src/gpaSolver.cpp \
    src/main.cpp \
    src/normalCalculator.cpp \
    src/window.cpp

HEADERS += \
    headers/addClassWindow.h \
    headers/gpaCalculator.h \
    headers/gpaSolver.h \
    headers/normalCalculator.h \
    headers/window.h

RESOURCES += \
    resources/resources.qrc

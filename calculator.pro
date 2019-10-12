TEMPLATE = app

QT = core gui

RC_FILE = calculator.rc

TARGET = Calculator

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    src/gpaCalculator.cpp \
    src/main.cpp \
    src/normalCalculator.cpp \
    src/window.cpp

HEADERS += \
    headers/gpaCalculator.h \
    headers/normalCalculator.h \
    headers/window.h

RESOURCES += \
    resources/resources.qrc

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    classes\planet.cpp \
    classes\solver.cpp \

HEADERS += \
    classes\solver.h \
    classes\planet.h \

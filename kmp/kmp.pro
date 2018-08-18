TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    tvector.cpp \
    kmp.cpp

HEADERS += \
    tvector.h \
    kmp.h \
    iomethods.h

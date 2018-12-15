TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    tvector.cpp \
    tinput.cpp \
    talgoritmkmp.cpp

HEADERS += \
    tvector.h \
    tinput.h \
    talgoritmkmp.h \
    kmp_typedefs.h

DISTFILES += \
    ../run-kmp-Desktop-Debug/input.txt \
    ../run-kmp-Desktop-Debug/output.txt

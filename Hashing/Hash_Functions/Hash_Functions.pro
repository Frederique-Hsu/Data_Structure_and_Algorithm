TEMPLATE = app
CONFIG += console c++2a
CONFIG -= app_bundle qt

LIBS += -lgtest

SOURCES += \
    hash_functions.cpp \
    main.cpp

HEADERS += \
    hash_functions.hpp

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lgtest

SOURCES += \
        binary_search_tree/tree.c \
        main.cpp

HEADERS += \
    binary_search_tree/element.h \
    binary_search_tree/tree.h

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lgtest -lgmock -lpthread

SOURCES += \
        IntCell.cpp \
        main.cpp \
        utest_IntCell.c++ \
        utest_Lvalue_Rvalue_reference.c++ \
        utest_Vector_String.c++

HEADERS += \
    IntCell.hpp

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lgtest -lgmock -lpthread

SOURCES += \
        UTest_Matrix.c++ \
        main.cpp

HEADERS += \
    Matrix.hpp \
    Matrix_impl.hpp

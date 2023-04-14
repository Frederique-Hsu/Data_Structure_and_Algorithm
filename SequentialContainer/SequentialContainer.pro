TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lgtest -lgmock -lpthread

SOURCES += \
        List/IteratorException.cpp \
        List/UTest_List.c++ \
        Vector/UTest_Vector.c++ \
        main.cpp

HEADERS += \
    List/IteratorException.hpp \
    List/List.hpp \
    List/List_impl.hpp \
    Vector/Vector.hpp \
    Vector/Vector_impl.hpp

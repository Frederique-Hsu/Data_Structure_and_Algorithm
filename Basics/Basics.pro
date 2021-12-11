TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lgtest -lgmock -lpthread

SOURCES += \
        BigFive/IntCell.cpp \
        BigFive/utest_IntCell.c++ \
        Functions.cpp \
        main.cpp \
        utest_Functions.c++ \
        utest_Lvalue_Rvalue_reference.c++ \
        utest_Vector_String.c++

HEADERS += \
    BigFive/IntCell.hpp \
    Functions.hpp \
    Swap.hpp \
    Swap_impl.hpp

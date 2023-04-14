TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lgtest -lgmock -lpthread

SOURCES += \
        Class_Templates/Square.cpp \
        Class_Templates/utest_MemoryCell.c++ \
        Class_Templates/utest_Square.c++ \
        Function_Objects/CaseInsensitiveCompare.cpp \
        Function_Objects/utest_Functor.c++ \
        Function_Templates/utest_FunctionTemplates.c++ \
        main.cpp

HEADERS += \
    Class_Templates/MemoryCell.hpp \
    Class_Templates/MemoryCell_impl.hpp \
    Class_Templates/Square.hpp \
    Function_Objects/CaseInsensitiveCompare.hpp \
    Function_Templates/Function_Templates.hpp \
    Function_Templates/Function_Templates_impl.hpp

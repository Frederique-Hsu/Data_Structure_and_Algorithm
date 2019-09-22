TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../Pointers_in_Class/HasPtr.cpp \
        ../Sales_Item/Sales_item.cpp \
        ../Sales_Item/Screen.cpp \
        main.cpp \
        testing_pointers_in_class.cpp \
        unit_testing.cpp

HEADERS += \
    ../Pointers_in_Class/HasPtr.h \
    ../Sales_Item/Sales_item.h \
    ../Sales_Item/Screen.h \
    testing_pointers_in_class.h \
    unit_testing.h

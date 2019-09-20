TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../Sales_Item/Sales_item.cpp \
        ../Sales_Item/Screen.cpp \
        main.cpp \
        unit_testing.cpp

HEADERS += \
    ../Sales_Item/Sales_item.h \
    ../Sales_Item/Screen.h \
    unit_testing.h

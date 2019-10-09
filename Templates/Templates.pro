TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../Utility_Classes_Libraries/Sales_Item/Sales_item.cpp \
    List.cpp \
    Source.cpp \
    class_template.cpp \
    function_template.cpp \
    testing.cpp

HEADERS += \
    ../Utility_Classes_Libraries/Sales_Item/Sales_item.h \
    List.h \
    Screen.h \
    class_template.h \
    function_template.h \
    misc.h \
    testing.h

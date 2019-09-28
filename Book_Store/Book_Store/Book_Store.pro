TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../../Utility_Classes_Libraries/Sales_Item/Bulk_item.cpp \
    ../../Utility_Classes_Libraries/Sales_Item/Disc_item.cpp \
    ../../Utility_Classes_Libraries/Sales_Item/Item_base.cpp \
    ../../Utility_Classes_Libraries/Sales_Item/Sales_item.cpp \
    Main.cpp \
    misc.cpp \
    testing.cpp

HEADERS += \
    ../../Utility_Classes_Libraries/Sales_Item/Bulk_item.h \
    ../../Utility_Classes_Libraries/Sales_Item/Disc_item.h \
    ../../Utility_Classes_Libraries/Sales_Item/Item_base.h \
    ../../Utility_Classes_Libraries/Sales_Item/Sales_item.h \
    misc.h \
    testing.h

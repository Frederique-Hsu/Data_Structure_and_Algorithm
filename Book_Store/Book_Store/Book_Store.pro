TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../../Utility_Classes_Libraries/Items/Bulk_item.cpp \
    ../../Utility_Classes_Libraries/Items/Disc_item.cpp \
    ../../Utility_Classes_Libraries/Items/Item_base.cpp \
    Main.cpp \
    misc.cpp \
    testing.cpp

HEADERS += \
    ../../Utility_Classes_Libraries/Items/Bulk_item.h \
    ../../Utility_Classes_Libraries/Items/Disc_item.h \
    ../../Utility_Classes_Libraries/Items/Item_base.h \
    misc.h \
    testing.h

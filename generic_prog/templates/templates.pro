TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    bookstore_app/Basket.cpp \
    bookstore_app/Bulk_item.cpp \
    bookstore_app/Disc_item.cpp \
    bookstore_app/Item_base.cpp \
    bookstore_app/Sales_item.cpp \
    class_template/misc.cpp \
    function_template.cpp \
    generic_handle/utilizing_handle.cpp \
    main.cpp \
    testing.cpp

HEADERS += \
    bookstore_app/Basket.h \
    bookstore_app/Bulk_item.h \
    bookstore_app/Disc_item.h \
    bookstore_app/Item_base.h \
    bookstore_app/Sales_item.h \
    class_template/List.h \
    class_template/Queue.h \
    class_template/QueueItem.h \
    class_template/Screen.h \
    class_template/misc.h \
    function_template.h \
    generic_handle/Handle.h \
    generic_handle/utilizing_handle.h \
    testing.h

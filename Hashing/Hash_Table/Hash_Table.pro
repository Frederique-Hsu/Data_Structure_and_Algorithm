TEMPLATE = app
CONFIG += console c++2a
CONFIG -= app_bundle qt

LIBS += -lgtest -lpthread

SOURCES += \
    main.cpp \
    probing_hash_table/probing_hash_table.cpp \
    probing_hash_table/test_probing_hash_table.c++ \
    separate_chaining_hash_table/employee.cpp \
    separate_chaining_hash_table/test_hash_table.c++


HEADERS += \
    hash.hpp \
    hash_impl.hpp \
    probing_hash_table/probing_hash_table.hpp \
    separate_chaining_hash_table/employee.hpp \
    separate_chaining_hash_table/hash_table.hpp \
    separate_chaining_hash_table/hash_table_impl.hpp \
    separate_chaining_hash_table/test_hash_table.h++

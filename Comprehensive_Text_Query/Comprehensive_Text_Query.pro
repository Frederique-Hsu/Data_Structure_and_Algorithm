TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../Utility_Classes_Libraries/TextQuery/BinaryQuery.cpp \
    ../Utility_Classes_Libraries/TextQuery/NotQuery.cpp \
    ../Utility_Classes_Libraries/TextQuery/Query.cpp \
    ../Utility_Classes_Libraries/TextQuery/Query_base.cpp \
    ../Utility_Classes_Libraries/TextQuery/TextQuery.cpp \
    ../Utility_Classes_Libraries/TextQuery/WordQuery.cpp \
    Main.cpp

HEADERS += \
    ../Utility_Classes_Libraries/TextQuery/BinaryQuery.h \
    ../Utility_Classes_Libraries/TextQuery/NotQuery.h \
    ../Utility_Classes_Libraries/TextQuery/Query.h \
    ../Utility_Classes_Libraries/TextQuery/Query_base.h \
    ../Utility_Classes_Libraries/TextQuery/TextQuery.h \
    ../Utility_Classes_Libraries/TextQuery/WordQuery.h

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../unity.test.framework/extras/fixture/unity_fixture.c \
        ../unity.test.framework/extras/memory/unity_memory.c \
        ../unity.test.framework/unity.c \
        linked_list/LinkedList.c \
        linked_list/Test_LinkedList.c \
        main.c \
        sequential_list/SqList.c \
        sequential_list/Test_SqList.c

HEADERS += \
    ../unity.test.framework/extras/bdd/unity_bdd.h \
    ../unity.test.framework/extras/fixture/unity_fixture.h \
    ../unity.test.framework/extras/fixture/unity_fixture_internals.h \
    ../unity.test.framework/extras/memory/unity_memory.h \
    ../unity.test.framework/unity.h \
    ../unity.test.framework/unity_internals.h \
    linked_list/LinkedList.h \
    linked_list/Test_LinkedList.h \
    pre_defines.h \
    sequential_list/SqList.h

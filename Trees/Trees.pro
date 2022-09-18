TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lgtest -lgmock -lpthread

SOURCES += \
        Binary_Search_Tree/binary_search_tree_utest.c++ \
        main.cpp

HEADERS += \
    Binary_Search_Tree/binary_search_tree.hpp \
    Binary_Search_Tree/binary_search_tree_impl.hpp \
    binary_tree_node.hpp \
    tree_node.hpp

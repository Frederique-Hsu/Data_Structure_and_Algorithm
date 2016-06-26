#==================================================================================================
# Project		: Linked_Lists
# File name		: Makefile
# Description	: This script demonstrates how to build this "Linked_Lists" project.
# Creator		: Frederick Hsu
# Creation date : Sun.	26 June, 2016
# Copyright(C)	2016	All rights reserved.
#
#==================================================================================================


OBJS = main.o intSLList.o test.o

Linked_Lists.o : $(OBJS)
	g++ $(OBJS) -o Linked_Lists.o

main.o : main.cpp test.h
	g++ -c main.cpp

test.o : test.cpp test.h
	g++ -c test.cpp

intSLList.o : intSLList.cpp intSLList.h
	g++ -c intSLList.cpp

.PHONY : clean
clean :
	-rm -f $(OBJS) Linked_Lists.o
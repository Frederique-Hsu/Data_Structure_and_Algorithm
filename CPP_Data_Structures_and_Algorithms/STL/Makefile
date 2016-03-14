#==============================================================================
# Project		: STL
# File name		: Makefile
# Dewcription	: The build script for the STL project.
# Creator		: Frederick Hsu
# Creation date	: Monday,	14 March, 2016
# Copyright(C)	2016	All rights reserved.
#
#==============================================================================


OBJS = main.o test.o function_object.o test_function_object.o

STL.o : $(OBJS)
	g++ $(OBJS) -o STL.o


main.o : main.cpp test.h
	g++ -c main.cpp

test.o : test.cpp test.h
	g++ -c test.cpp

function_object.o : function_object.cpp function_object.h
	g++ -c function_object.cpp

test_function_object.o : test_function_object.cpp test_function_object.h
	g++ -c test_function_object.cpp

.PHONY : clean
clean :
	-rm -rf STL.o $(OBJS)
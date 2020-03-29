# File name		: Makefile
# Description	: This script defines how to build the souce code.
# Creator		: Frederique Hsu
# Creation date	: Sun.	29 March 2020
# Copyright(C)	2020	All rights reserved.
#

OPTIONS = -Wall -std=c++14
DEBUG = -g

OBJS = main.o function_template.o class_template/Queue.o class_template/QueueItem.o \

templates : $(OBJS)
	g++ $(DEBUG) $(OPTIONS) $(OBJS) -o templates

main.o : main.cpp
	g++ $(DEBUG) $(OPTIONS) -c main.cpp

function_template.o : function_template.cpp function_template.h
	g++ $(DEBUG) $(OPTIONS) -c function_template.cpp

Queue.o : Queue.cpp Queue.h QueueItem.h
	g++ $(DEBUG) $(OPTIONS) -c Queue.cpp

QueueItem.o : QueueItem.cpp QueueItem.h
	g++ $(DEBUG) $(OPTIONS) -c QueueItem.cpp


.PHONY : clean
clean :
	-rm -frv $(OBJS) templates *.d
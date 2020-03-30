# File name		: Makefile
# Description	: This script defines how to build the souce code.
# Creator		: Frederique Hsu
# Creation date	: Sun.	29 March 2020
# Copyright(C)	2020	All rights reserved.
#

OPTIONS = -Wall -std=c++14
DEBUG = -g

OBJS = main.o testing.o class_template/misc.o function_template.o generic_handle/utilizing_handle.o

templates : $(OBJS)
	g++ $(DEBUG) $(OPTIONS) $(OBJS) -o templates

main.o : main.cpp testing.h generic_handle/utilizing_handle.h
	g++ $(DEBUG) $(OPTIONS) -c main.cpp

testing.o : testing.cpp testing.h class_template/Queue.h class_template/List.h class_template/Screen.h \
function_template.h
	g++ $(DEBUG) $(OPTIONS) -c testing.cpp

misc.o : misc.cpp misc.h
	g++ $(DEBUG) $(OPTIONS) -c misc.cpp

function_template.o : function_template.cpp function_template.h
	g++ $(DEBUG) $(OPTIONS) -c function_template.cpp

utilizing_handle.o : utilizing_handle.cpp utilizing_handle.h Handle.h
	g++ $(DEBUG) $(OPTIONS) -c utilizing_handle.cpp

.PHONY : clean
clean :
	-rm -frv $(OBJS) templates *.d *.o
#=====================================================================
# Project		: pointer_and_struct
# File name		: Makefile
# Description	: The build script for current project.
# Creator		: Frederick Hsu
# Creation date	: Thu.	03 March, 2016
#
#=====================================================================

OBJS = Node.o test.o main.o quoted_variable.o RefClass.o function_pointer.o

pointer_and_struct.o : $(OBJS)
	g++ $(OBJS) -o pointer_and_struct.o

Node.o : Node.cpp Node.h
	g++ -c Node.cpp

test.o : test.cpp test.h Node.h quoted_variable.h RefClass.h function_pointer.h
	g++ -c test.cpp

main.o : main.cpp test.h
	g++ -c main.cpp

quoted_variable.o : quoted_variable.cpp quoted_variable.h
	g++ -c quoted_variable.cpp

RefClass.o : RefClass.cpp RefClass.h
	g++ -c RefClass.cpp

function_pointer.o : function_pointer.cpp function_pointer.h
	g++ -c function_pointer.cpp

.PHONY : clean
clean :
	-rm -f $(OBJS) pointer_and_struct.o
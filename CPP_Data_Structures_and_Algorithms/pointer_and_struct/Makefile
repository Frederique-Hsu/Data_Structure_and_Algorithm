#=====================================================================
# Project		: pointer_and_struct
# File name		: Makefile
# Description	: The build script for current project.
# Creator		: Frederick Hsu
# Creation date	: Thu.	03 March, 2016
#
#=====================================================================

OBJS = Node.o test.o main.o

pointer_and_struct.o : $(OBJS)
	g++ $(OBJS) -o pointer_and_struct.o

Node.o : Node.cpp Node.h
	g++ -c Node.cpp

test.o : test.cpp test.h Node.h
	g++ -c test.cpp

main.o : main.cpp test.h
	g++ -c main.cpp


.PHONY : clean
clean :
	-rm -f $(OBJS) pointer_and_struct.o
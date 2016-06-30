#==============================================================================
# Project		: Random_Access_File
# File name		: Makefile
# Dewcription	: The build script for the Random_Access_File project.
# Creator		: Frederick Hsu
# Creation date	: Sunday, 03 April, 2016
# Copyright(C)	2016	All rights reserved.
#
#==============================================================================


OBJS = main.o test.o database.o personal.o student.o 

Random_Access_File.o : $(OBJS)
	g++ $(OBJS) -o Random_Access_File.o


main.o : main.cpp test.h
	g++ -c main.cpp

test.o : test.cpp test.h database.h student.h personal.h
	g++ -c test.cpp

personal.o : personal.cpp personal.h 
	g++ -c personal.cpp

student.o : student.cpp student.h
	g++ -c student.cpp

database.o : database.cpp database.h
	g++ -c database.cpp

.PHONY : clean
clean :
	-rm -rf Random_Access_File.o $(OBJS)
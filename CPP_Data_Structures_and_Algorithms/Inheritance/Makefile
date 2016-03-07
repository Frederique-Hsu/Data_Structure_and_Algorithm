#==========================================================================
# Project		: Inheritance
# File name		: Makefile
# Description	: The build script for "Inheritance" project.
# Creator		: Frederick Hsu
# Creation date	: Sun. 28 Feb., 2016
# Copyright(C)	2016	All rights reserved.
#
#==========================================================================


OBJS = main.o test.o BaseClass.o Derived1Level1.o Derived2Level1.o DerivedLevel2.o


Inheritance.o : $(OBJS)
	g++ $(OBJS) -o Inheritance.o


main.o : main.cpp test.h
	g++ -c main.cpp

test.o : test.cpp test.h Derived1Level1.h Derived2Level1.h DerivedLevel2.h
	g++ -c test.cpp

BaseClass.o : BaseClass.cpp BaseClass.h
	g++ -c BaseClass.cpp

Derived1Level1.o : Derived1Level1.cpp Derived1Level1.h
	g++ -c Derived1Level1.cpp

Derived2Level1.o : Derived2Level1.cpp Derived2Level1.h
	g++ -c Derived2Level1.cpp

DerivedLevel2.o : DerivedLevel2.cpp DerivedLevel2.h
	g++ -c DerivedLevel2.cpp

.PHONY : clean
clean :
	-rm -f $(OBJS) Inheritance.o
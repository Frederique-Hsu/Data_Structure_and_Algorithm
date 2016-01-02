#===============================================================================
# Project name		: Tree
# File name			: Makefile
# Description		: This is the build script on how to compile the Tree project.
# Author			: Frederick Hsu (徐贊)
# Creation date		: Jan. 01, 2016
# Copyright(C)		2016	All rights reserved.
#
#===============================================================================


Objects = Tree_Project_Main.o Test.o

Tree : $(Objects)
	gcc -o Tree $(Objects)


Tree_Project_Main.o : Tree_Project_Main.c Test.h
	gcc -c Tree_Project_Main.c

Test.o : Test.c Test.h
	gcc -c Test.c

.PHONY : clean
clean :
	-rm -f Tree $(Objects)
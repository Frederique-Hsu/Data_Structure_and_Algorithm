#=============================================================================
# Project		: How2Make
# File name		: Makefile
# Description	: The project build script
# Author		: Frederick Hsu
# Creation date	: Wed.	24 Feb., 2016
# Copyright(C)	2016	All rights reserved.
#
#=============================================================================


OBJS = main.o kbd.o command.o display.o insert.o search.o files.o utils.o

How2Make.o : $(OBJS)
	gcc $(OBJS) -o How2Make.o

main.o : main.c defs.h
	gcc -c main.c

kbd.o : kbd.c defs.h command.h
	gcc -c kbd.c

command.o : command.c defs.h buffer.h
	gcc -c command.c

display.o : display.c defs.h buffer.h
	gcc -c display.c

insert.o : insert.c defs.h buffer.h
	gcc -c insert.c

search.o : search.c defs.h buffer.h
	gcc -c search.c

files.o : files.c defs.h buffer.h command.h
	gcc -c files.c

utils.o : utils.c defs.h
	gcc -c utils.c



clean :
	rm How2Make.o $(OBJS)
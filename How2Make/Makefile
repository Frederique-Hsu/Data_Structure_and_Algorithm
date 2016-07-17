#=============================================================================
# Project       : How2Make
# File name     : my_makefile
# Description   : The project build script
# Author        : Frederick Hsu
# Creation date : Sat.  9 July, 2016
# Copyright(C)  2016    All rights reserved.
#
#=============================================================================


all : How2Make

# which compiler
CC = gcc

# where to install
INSTDIR = 

# where are the included files kept
INCLUDE = 

# options for debug
CDFLAGS = -g3 -O0 -Wall

# options for release
CRFLAGS = -O3 -Wall

# Local libraries
MYLIB = mylib.a

# objects to generate
OBJS = main.o kbd.o command.o display.o insert.o search.o files.o utils.o

How2Make : $(OBJS)
	$(CC) $(OBJS) -o How2Make

main.o : main.c defs.h

kbd.o : kbd.c defs.h command.h

command.o : command.c defs.h buffer.h

display.o : display.c defs.h buffer.h

insert.o : insert.c defs.h buffer.h

search.o : search.c defs.h buffer.h

files.o : files.c defs.h buffer.h command.h

utils.o : utils.c defs.h


# 自动生成依赖关系 ： gcc -MM 选项
	gcc -MM main.c kbd.c command.c display.c insert.c search.c files.c utils.c > depends.txt


clean :
	-rm -f $(OBJS) How2Make
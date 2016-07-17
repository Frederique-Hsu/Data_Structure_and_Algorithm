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
LIBS = libtest.a

# objects to generate
OBJS = main.o kbd.o command.o display.o insert.o search.o files.o utils.o

# List all objects
# 首先使用wildcard函数获取工作目录下的.c文件列表，之后将列表中所有文件名的后缀.c替换成.o
# 这样就可以得到在当前目录可生成的.o文件列表。
# 因此在不需要列出所有的.o文件，就可以将当前工作目录下的所有的.c文件进行编译，并最后链接成为一个可执行文件
objects := $(patsubst %.c, %.o, $(wildcard *.c))

How2Make : $(objects)
	$(CC) $(objects) -o How2Make

insert.o: insert.c defs.h buffer.h
search.o: search.c defs.h buffer.h
defines.o: defines.c defs.h
display.o: display.c defs.h buffer.h
kbd.o: kbd.c defs.h command.h
utils.o: utils.c defs.h
command.o: command.c defs.h command.h
files.o: files.c defs.h buffer.h command.h
main.o: main.c defs.h


clean :
# -rm -f $(OBJS) How2Make
	-rm -f *.o How2Make


print : *.c
	lpr -p $?
	touch print
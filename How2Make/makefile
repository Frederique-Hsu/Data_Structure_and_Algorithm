#=============================================================================
# Project       : How2Make
# File name     : my_makefile
# Description   : The project build script
# Author        : Frederick Hsu
# Creation date : Sat.  9 July, 2016
# Copyright(C)  2016    All rights reserved.
#
#=============================================================================


all : How2Make Prog1 Prog2
.PHONY : all

# which compiler
CC = gcc

# where to install
INSTDIR = 

# where are the included files kept
INCLUDE = 

# create the static library
AR = ar

# argument for creating the static library
ARFLAGS = rv

# options for debug
CDFLAGS = -g3 -O0 -Wall

# options for release
CRFLAGS = -O3 -Wall

# Local libraries
LIBS = libtest.a

# sub directories
SUBDIRS = src utils

# objects to generate
OBJS = main.o kbd.o command.o display.o insert.o search.o files.o proc.o clean.o

# List all objects
# 首先使用wildcard函数获取工作目录下的.c文件列表，之后将列表中所有文件名的后缀.c替换成.o
# 这样就可以得到在当前目录可生成的.o文件列表。
# 因此在不需要列出所有的.o文件，就可以将当前工作目录下的所有的.c文件进行编译，并最后链接成为一个可执行文件
# objects := $(patsubst %.c, %.o, $(wildcard *.c))

VPATH = src
vpath %.h headers
# vpath %.c src

.PHONY : all

How2Make : $(OBJS)
	$(CC) $(OBJS) -o How2Make

insert.o: insert.c defs.h buffer.h
search.o: search.c defs.h buffer.h
defines.o: defines.c defs.h
display.o: display.c defs.h buffer.h
kbd.o: kbd.c defs.h command.h
command.o: command.c defs.h command.h
files.o: files.c defs.h buffer.h command.h
main.o: main.c defs.h
# proc.o: proc.c headers/error_code.h headers/type_defines.h
proc.o: proc.c error_code.h type_defines.h
clean.o: clean.c clean.h
# utils.o: utils/utils.c utils/../defs.h

libtest.a : sum.o memcp.o
	$(AR) $(ARFLAGS) $@ $^

#==================================================================================================================

Prog1 : prog1.o check.o
	gcc prog1.o check.o -o Prog1

prog1.o: prog1.c check.h
check.o: check.c check.h

#==================================================================================================================

Prog2 : prog2.o sort.o test.o
	gcc prog2.o sort.o test.o -o Prog2

prog2.o: prog2.c prog2.h test.h
sort.o: sort.c sort.h test.h
test.o: test.c test.h

#==================================================================================================================

.PHONY : clean		# 將clean聲明為偽目標
clean :
# -rm -f $(OBJS) 
	-rm -f *.o How2Make Prog1 Prog2
# -rm -f $(objects) How2Make


.PHONY : subdirs $(SUBDIRS)
subdirs : $(SUBDIRS)
$(SUBDIRS) :
	$(MAKE) -C $@

print : *.c
	lpr -p $?
	touch print
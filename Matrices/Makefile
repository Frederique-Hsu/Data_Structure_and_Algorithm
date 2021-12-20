# File name		: Makefile
# Description	: This script tells how to build current project.
# Author		: Frederique Hsu
# Date			: Sun.	05 Dec. 2021
#


PROJECT = Matrices

CXX = g++
CXXFLAGS = -Wall -pg -std=c++17
INCLUDES = 
LIBS = -lgtest -lgmock -lpthread
BUILD_OPTIONS = -DDEBUG -DUNUMPLEMENTED

SRC_EXTENSIONS = .c .cpp .c++ .cxx .cc
HDR_EXTENSIONS = .h .hpp .h++ .hxx .hh

CUR_DIR = .
DIRS = $(shell find $(CUR_DIR) -maxdepth 5 -type d)
SOURCES = $(foreach dir, $(DIRS), $(wildcard $(addprefix $(dir)/*, $(SRC_EXTENSIONS))))
HEADERS = $(foreach dir, $(DIRS), $(wildcard $(addprefix $(dir)/*, $(HDR_EXTENSIONS))))
OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))

.PHONY : all clean rebuild show

all : $(PROJECT)

$(PROJECT) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

%.o : %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(BUILD_OPTIONS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(BUILD_OPTIONS)

%.o : %.c++
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(BUILD_OPTIONS)

%.o : %.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(BUILD_OPTIONS)

%.o : %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(BUILD_OPTIONS)

clean :
	-rm -frv $(OBJECTS)
	-rm -frv *.out
	-rm -frv $(PROJECT)

rebuild : clean all

show :
	@echo "DIRS = " $(DIRS)
	@echo "SOURCES = " $(SOURCES)
	@echo "HEADERS = " $(HEADERS)
	@echo "OBJECTS = " $(OBJECTS)

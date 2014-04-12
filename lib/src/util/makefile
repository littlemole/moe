#################################################
# linux makefile for libutil
#################################################

#################################################
# compiler
#################################################

CC = g++

# debug mode

DEBUG = -g
REENTRANT = -D_REENTRANT
INCLUDE = -I../../include

release : override DEBUG = -O3

# compiler flags

CPPFLAGS = -Wall $(DEBUG) $(REENTRANT) $(INCLUDE)

#################################################
# the lib to build
#################################################

# dirs and path to lib
SRC = .
BUILD = ./../../build
LIB = ../../libutil.a

# OBJects for this library
OBJ = istr.o regex.o Str.o util.o X.o

#################################################
# usually no need to change anything below
#################################################

.SUFFIXES: .cpp

#################################################
# actual build rules
#################################################

#################################################
# rule to compile .o files from .cpp source
#################################################

$(BUILD)/%.o: $(SRC)/%.cpp 
	$(CC) -c $^ -o $@ $(CPPFLAGS)

#################################################
# rule to compile all (default rule)
# effectivly redirects to next rule
#################################################

all: $(LIB)

#################################################
# rule to compile the lib file from .o files
#################################################

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)
	ranlib $(LIB)

#################################################
# release rule to compile the lib file from .o files
#################################################

release: $(LIB)

#################################################
# make clean
#################################################

clean:
	-rm -f $(LIB)
	-rm -f *.o

install:


deinstall:

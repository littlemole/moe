#################################################
# linux makefile for libxml
#################################################

#################################################
# compiler
#################################################

CC = g++

# debug mode

DEBUG = -g
REENTRANT = -D_REENTRANT

release : override DEBUG = -O3

# compiler flags

CPPFLAGS = $(DEBUG) $(REENTRANT) -I../../include

#################################################
# the lib to build
#################################################

# dirs and path to lib
SRC = .
BUILD = ./../../build
LIB = ../../libxml.a

# the libs source objs to build from
OBJS = xml.o document.o dom.o patex.o

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

$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)
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
	-rm -f $(OBJS)

install:


deinstall:


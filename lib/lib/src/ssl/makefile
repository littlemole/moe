#################################################
# linux makefile for libnet
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

CPPFLAGS = $(DEBUG) $(REENTRANT) -I./../../include 

#################################################
# the lib to build
#################################################

# dirs and path to lib
SRC = .
BUILD = ./../../build
LIB = ../../libossl.a

# the libs source objs to build from
OBJS = cert.o sslstream.o ossl.o

#################################################
# usually no need to change anything below
#################################################

# source objs for lib with abs path
OBJ = $(patsubst %,$(BUILD)/%,$(OBJS))

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
	-rm -f $(OBJ)

install:


deinstall:

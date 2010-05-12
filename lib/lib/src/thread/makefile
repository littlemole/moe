#################################################
# linux makefile for libthread
#################################################

#################################################
# compiler
#################################################

CC = g++

# debug mode

DEBUG = -g
REENTRANT = -D_REENTRANT

release : override DEBUG = -O3
profile : override DEBUG = -g -pg

# compiler flags

CPPFLAGS = -Wall $(DEBUG) $(REENTRANT) -I../../include

#################################################
# the lib to build
#################################################

# dirs and path to lib
SRC = .
BUILD = ./../../build
LIB = ../../libthread.a

# the libs source objs to build from
OBJS = sync.o systhread.o signal.o

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
# profile rule to compile the lib file from .o files
#################################################

profile: $(LIB)

#################################################
# make clean
#################################################

clean:
	-rm -f $(LIB)
	-rm -f $(OBJ)

install:


deinstall:

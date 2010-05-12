#################################################
# linux makefile for libmolsql (mysql bindings)
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

CPPFLAGS = $(DEBUG) $(REENTRANT) $(INCLUDE)

#################################################
# mysql specific
#################################################

MYSQLFLAGS=mysql_config --cflags
MYSQLLIBS=mysql_config --libs

#################################################
# the lib to build
#################################################

# dirs and path to lib
SRC = .
BUILD = ./../../build
LIB = ../../libmolsql.a

# OBJects for this library
OBJ = $(BUILD)/sql.o

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
	$(CC) `$(MYSQLFLAGS)` $(CPPFLAGS) -c $^ -o $@ 

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
	-rm -f $(BUILD)/*.o

install:


deinstall:

#################################################
# linux master makefile for molib static libs
#################################################

#################################################
# path config
#################################################

SRC = ./src
BUILD = ./build
LIBDIR = .

#################################################
# usually no need to change anything below
#################################################

#################################################
# actual build rules
#################################################

#################################################
# rule to compile all (default rule)
#################################################

all: 
	make -C$(SRC)/util 
	make -C$(SRC)/thread
	make -C$(SRC)/tcp
	make -C$(SRC)/ssl
	make -C$(SRC)/http
	make -C$(SRC)/xml
	make -C$(SRC)/mysql


#################################################
# release rule 
#################################################

release: 
	make -C$(SRC)/util release
	make -C$(SRC)/thread release
	make -C$(SRC)/tcp release
	make -C$(SRC)/ssl release
	make -C$(SRC)/http release
	make -C$(SRC)/xml release
	make -C$(SRC)/mysql release

#################################################
# make clean
#################################################

clean:
	make -C$(SRC)/util clean
	make -C$(SRC)/thread clean
	make -C$(SRC)/tcp clean
	make -C$(SRC)/ssl clean
	make -C$(SRC)/http clean
	make -C$(SRC)/xml clean
	make -C$(SRC)/mysql clean


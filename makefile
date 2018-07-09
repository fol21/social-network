### C/C++ project template makefile ####

CC=gcc
CPP=g++


#### Project Structure ####
INCLUDE_DIR= ./include
OBJ_DIR = ./obj
SOURCE_DIR=./src
TEST_DIR=./test
BIN_DIR=./bin
OUT_DIR=./out
CFLAGS=-I. -I$(INCLUDE_DIR)  -ggdb
OBJS := $(wildcard **/*.o) $(wildcard *.o)
TEST_OBJS := $(filter-out obj/$(MAIN).o, ${OBJS})

#### Definitions ####
CMPLR := $(CC)
MAIN = main


.PHONY: clean dirs all

#### Project Build tasks ####

all: clean dirs ${MAIN}.o graph.o helpers.o
	make ${MAIN}

#### Project setup tasks ####

dirs: clean
	mkdir out/ obj/

#### Clean project tasks ####
clean:
	rm -rf  *.o **/*.o out/* out/ obj/
  
#### test gen tasks ####
test.o: ${TEST_DIR}/teste.c 
	$(CMPLR) -c  -o ${OBJ_DIR}/$@ $< $(CFLAGS)

test: ${TEST_OBJS}
	$(CMPLR) -o ${TEST_DIR}/$@ $^  $(CFLAGS)

##### Object gen tasks ####
$(MAIN).o: $(MAIN).c 
	$(CMPLR) -o ${OBJ_DIR}/$@ -c $< $(CFLAGS)

%.o: ${SOURCE_DIR}/%.c 
	$(CMPLR) -o ${OBJ_DIR}/$@ -c $< $(CFLAGS)

#### Executable gen tasks ####
$(MAIN) : ${OBJS}
	$(CMPLR) -o ${OUT_DIR}/$@ ${OBJS} $(CFLAGS)

# Our C compiler
CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

BIN = hello birthdays printf numbers wages absolute bits complex linked-list-demo

.PHONY: all clean

all: $(BIN)

# update all object files when Makefile changes, as we might have
# changed CFLAGS
$(OBJ): Makefile

clean:
	rm -f $(BIN) $(OBJ)

# generate prerequisites using GCC - deps.mk is included below so will
# always be rebuilt
deps.mk:
	gcc -MM $(SRC) > deps.mk

include deps.mk

# specific prerequisites
linked-list-demo: linked-list-demo.o linked-list.o
wages: wages.o input-functions.o
absolute: absolute.o input-functions.o

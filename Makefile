CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
BIN = hello birthdays printf numbers wages absolute bits complex linked-list-demo

.PHONY: all clean

all: $(BIN)

# rebuild all when Makefile changes, in case CFLAGS changed
$(OBJ): Makefile

clean:
	rm -f $(BIN) $(OBJ) deps.mk

# generate prerequisites using GCC
include deps.mk
deps.mk:
	gcc -MM $(SRC) > deps.mk

# specific prerequisites
linked-list-demo: linked-list.o
wages: input-functions.o
absolute: input-functions.o

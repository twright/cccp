CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
BIN = hello birthdays printf numbers wages absolute bits pointer1 complex-demo linked-list-demo

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
wages absolute birthdays: input-functions.o
complex-demo: complex.o
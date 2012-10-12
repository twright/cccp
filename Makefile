# C compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -pedantic -D_FORTIFY_SOURCE=2 -Wunsafe-loop-optimizations -funsafe-loop-optimizations -O2 -flto -fno-builtin -march=native
WHOLE_PROGRAM_FLAGS = -fwhole-program

# Binaries
BINS = hello birthdays printf numbers wages absolute bits complex linked-list-demo
BIN_OBJS = $(addsuffix .o,$(BINS))

# Headers
HEADERS = input-functions linked-list
HEADER_OBJS = $(addsuffix .o,$(HEADERS))

.PHONY: main clean debug

# Compile all binaries with standard flags
main: $(BINS)

# Compile all binaries with debugging symbols
debug: CFLAGS += -ggdb
debug: main

# Remove all binaries
clean:
	-rm $(BIN_OBJS) $(HEADER_OBJS) $(BINS)

.SECONDEXPANSION:

# Add header files as dependancies of header objects
$(HEADER_OBJS): $$(patsubst %.o, %.h, $$@)

# Compile all of the executable files
$(BINS): $$@.o
	$(CC) $(WHOLE_PROGRAM_FLAGS) $(CFLAGS) -o $@ $^

# All of the header file dependancies of each executable
wages absolute: $$@.o input-functions.o

linked-list-demo: $$@.o linked-list.o
# Our C compiler
CC = gcc

# Are we compiling in debug mode?
DEBUG = 1

# The standard compiler flags
CFLAGS = -Wall -pedantic -D_FORTIFY_SOURCE=2 -Wunsafe-loop-optimizations

# Add compiler flags depending on whether DEBUG is set or not
ifeq ($(DEBUG), 0)
CFLAGS += -O2 -flto -fno-builtin -march=native
WFLAGS = -fwhole-program
else
CFLAGS += -ggdb
endif

# Executables
EXES = hello birthdays printf numbers wages absolute bits complex linked-list-demo
EXE_OBJS = $(addsuffix .o,$(EXES))

# Headers
LIBS = input-functions linked-list
LIB_OBJS = $(addsuffix .o,$(basename $(LIBS)))

main: $(EXES)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	-rm $(EXE_OBJS) $(LIB_OBJS) $(EXES)

.SECONDEXPANSION:

# Add header files as dependancies of header objects
$(LIB_OBJS): $$(patsubst %.o, %.h, $$@)

# Compile all of the executable files
$(EXES): $$@.o
	$(CC) $(WFLAGS) $(CFLAGS) -o $@ $^

# All of the header file dependancies of each executable
wages absolute: $$@.o input-functions.o

linked-list-demo: $$@.o linked-list.o
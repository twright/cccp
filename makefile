CC = gcc
DEBUG = 1

# Flags
ifeq ($(DEBUG), 0)
CFLAGS = -Wall -pedantic -O3 -flto -fno-builtin
WFLAGS = -fwhole-program
else
CFLAGS = -Wall -pedantic -ggdb
WFLAGS =
endif

# Objects
HELLO_OBJECTS = hello.o
BIRTHDAY_OBJECTS = birthdays.o
PRINTF_OBJECTS = printf.o
NUMBERS_OBJECTS = numbers.o
WAGES_OBJECTS = wages.o
ABSOLUTE_OBJECTS = absolute.o
OBJECTS = $(HELLO_OBJECTS) $(BIRTHDAY_OBJECTS) $(PRINTF_OBJECTS) $(NUMBERS_OBJECTS) $(WAGES_OBJECTS) $(ABSOLUTE_OBJECTS)

# Executables
EXES = hello birthdays printf numbers wages absolute

main: $(EXES)

hello: $(HELLO_OBJECTS)
	$(CC) $(WFLAGS) $(CFLAGS) -o hello $(HELLO_OBJECTS)

birthdays: $(BIRTHDAY_OBJECTS)
	$(CC) $(WFLAGS) $(CFLAGS) -o birthdays $(BIRTHDAY_OBJECTS)

printf: $(PRINTF_OBJECTS)
	$(CC) $(WFLAGS) $(CFLAGS) -o printf $(PRINTF_OBJECTS)

numbers: $(NUMBERS_OBJECTS)
	$(CC) $(WFLAGS) $(CFLAGS) -o numbers $(NUMBERS_OBJECTS)

wages: $(WAGES_OBJECTS)
	$(CC) $(WFLAGS) $(CFLAGS) -o wages $(WAGES_OBJECTS)

absolute: $(ABSOLUTE_OBJECTS)
	$(CC) $(WFLAGS) $(CFLAGS) -o absolute $(ABSOLUTE_OBJECTS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	-rm $(OBJECTS) $(EXES)

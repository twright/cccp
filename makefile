CC = gcc
CFLAGS = -Wall -pedantic -O3 -flto -fno-builtin
WFLAGS = -fwhole-program
HELLO_OBJECTS = hello.o
BIRTHDAY_OBJECTS = birthdays.o
PRINTF_OBJECTS = printf.o
NUMBERS_OBJECTS = numbers.o
WAGES_OBJECTS = wages.o
EXES = hello birthdays printf numbers wages

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

.PHONY: clean
clean:
	-rm $(HELLO_OBJECTS) $(EXES)

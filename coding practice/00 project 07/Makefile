CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = main.o bit_flags.o

bit_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o bit_driver $(OBJECTS)
bit_flags.o: bit_flags.c
	$(CC) $(CFLAGS) -c bit_flags.c -o bit_flags.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
clean:
	rm bit_driver $(OBJECTS)

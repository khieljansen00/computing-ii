CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = stack.o main.o
# OBJECTS = main.o

# string_driver: $(OBJECTS)
# $(CC) $(CFLAGS) -o string_driver $(OBJECTS)
main: stack.o main.o
	$(CC) $(CFLAGS) -o main stack.o main.o
stack.o: stack.o
	$(CC) $(CFLAGS) -c stack.c -o stack.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
clean:
	rm main $(OBJECTS)
# rm string_driver $(OBJECTS)

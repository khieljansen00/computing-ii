CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = project6.o rational.o

rational_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o rational_driver $(OBJECTS)
rational.o: rational.c
	$(CC) $(CFLAGS) -c rational.c -o rational.o
project6.o: project6.c
	$(CC) $(CFLAGS) -c project6.c -o project6.o
clean:
	rm rational_driver $(OBJECTS)
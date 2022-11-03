CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = my_string.o sort.o main.o
# OBJECTS = main.o

# string_driver: $(OBJECTS)
# $(CC) $(CFLAGS) -o string_driver $(OBJECTS)
sorting: $(OBJECTS)
	$(CC) $(CFLAGS) -o sorting $(OBJECTS)
sort.o: sort.c
	$(CC) $(CFLAGS) -c sort.c -o sort.o
my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
clean:
	rm sorting $(OBJECTS)

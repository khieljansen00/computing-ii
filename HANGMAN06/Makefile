CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = my_string.o generic_vector.o side-main.o
# OBJECTS = main.o

# string_driver: $(OBJECTS)
# $(CC) $(CFLAGS) -o string_driver $(OBJECTS)
./lab07: $(OBJECTS)
	$(CC) $(CFLAGS) -o lab07 $(OBJECTS)
my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
generic_vector.o: generic_vector.c
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o
side-main.o: side-main.c
	$(CC) $(CFLAGS) -c side-main.c -o side-main.o
# main.o: main.c
# $(CC) $(CFLAGS) -c main.c -o main.o
clean:
	rm lab07 $(OBJECTS)
# rm string_driver $(OBJECTS)

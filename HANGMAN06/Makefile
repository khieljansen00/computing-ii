CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = my_string.o unit_test.o test_def.o
# OBJECTS = main.o

# string_driver: $(OBJECTS)
# $(CC) $(CFLAGS) -o string_driver $(OBJECTS)
unit_test: my_string.o unit_test.o test_def.o
	$(CC) $(CFLAGS) -o unit_test unit_test.o test_def.o my_string.o
my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
unit_test.o: unit_test.c
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
test_def.o: test_def.c
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o
# main.o: main.c
# $(CC) $(CFLAGS) -c main.c -o main.o
clean:
	rm unit_test $(OBJECTS)
# rm string_driver $(OBJECTS)

CC=gcc
CFLAGS=-std=gnu11 -Wall  -g

all: princ.o my_ints.o my_strings.o
	$(CC) $(CFLAGS) princ.o my_ints.o my_strings.o -o princ
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f princ



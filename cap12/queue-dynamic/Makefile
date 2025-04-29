CC=gcc
CFLAGS=-std=gnu11 -Wall  -g

all: person.o queue.o demo-queue-dynamic.o
	$(CC) $(CFLAGS) person.o queue.o demo-queue-dynamic.o -o demo-queue-dynamic
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f demo-queue-dynamic



CC=gcc
CFLAGS=-std=gnu11 -Wall  -g

all: node.o queue.o demo-queue-arr.o
	$(CC) $(CFLAGS) node.o queue.o demo-queue-arr.o -o demo-queue-arr
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f demo-queue-arr



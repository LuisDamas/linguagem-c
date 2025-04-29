CC=gcc
CFLAGS=-std=gnu11 -Wall  -g

all: item.o list.o demo-list-dynamic.o
	$(CC) $(CFLAGS) item.o list.o demo-list-dynamic.o -o demo-list-dynamic
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f demo-list-dynamic



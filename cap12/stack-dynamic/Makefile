CC=gcc
CFLAGS=-std=gnu11 -Wall  -g

all: item.o stack.o demo-stack-dynamic.o
	$(CC) $(CFLAGS) item.o stack.o demo-stack-dynamic.o -o demo-stack-dynamic
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f demo-stack-dynamic


